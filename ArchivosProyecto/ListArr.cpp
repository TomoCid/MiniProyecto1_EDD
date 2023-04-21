#include "ListArr.h"

using namespace std;

ListArr ::ListArr()
{
    
}

int ListArr::size()
{
    return num_elements;
}

int ListArr::delete_left()
{
    if (head == nullptr)
    {
        // la lista está vacía
        return -1; // o cualquier otro valor para indicar que no se pudo eliminar
    }
    int deleted_value = head->arr[0];
    head->num_elements--;
    if (head->num_elements == 0)
    {
        // el primer nodo está vacío, hay que eliminarlo
        Node *old_head = head;
        head = head->next;
        delete old_head;
    }
    else
    {
        // el primer nodo aún tiene elementos, se mantiene en la lista
        for (int i = 0; i < head->num_elements; i++)
        {
            head->arr[i] = head->arr[i + 1];
        }
    }
    num_elements--;
    return deleted_value;
}

int ListArr::delete_right()
{
    if (head == nullptr)
    {
        // la lista está vacía
        return -1; // o cualquier otro valor para indicar que no se pudo eliminar
    }
    Node *current_node = head;
    while (current_node->next != nullptr)
    {
        current_node = current_node->next;
    }
    int deleted_value = current_node->arr[current_node->num_elements - 1];
    current_node->num_elements--;
    if (current_node->num_elements == 0)
    {
        // el último nodo está vacío, hay que eliminarlo
        Node *previous_node = head;
        while (previous_node->next != current_node)
        {
            previous_node = previous_node->next;
        }
        previous_node->next = nullptr;
        delete current_node;
    }
    num_elements--;
    return deleted_value;
}

void ListArr::insert_left(int v)
{
    if (head == nullptr)
    {
        // la lista está vacía, se crea el primer nodo
        head = new Node(b);
        head->arr[0] = v;
        head->num_elements++;
        num_elements++;
    }
    else if (head->num_elements < b)
    {
        // el primer nodo aún tiene espacio disponible, se inserta ahí
        for (int i = head->num_elements; i > 0; i--)
        {
            head->arr[i] = head->arr[i - 1];
        }
        head->arr[0] = v;
        head->num_elements++;
        num_elements++;
    }
    else
    {
        // se crea un nuevo nodo y se inserta antes del primer nodo
        Node *new_node = new Node(b);
        new_node->arr[0] = v;
        new_node->num_elements++;
        new_node->next = head;
        head = new_node;
        num_elements++;
    }
}

void ListArr::insert_right(int v)
{
    if (head == nullptr)
    {
        // la lista está vacía, se crea el primer nodo
        head = new Node(b);
        head->arr[0] = v;
        head->num_elements++;
        num_elements++;
    }
    else
    {
        Node *current_node = head;
        while (current_node->next != nullptr && current_node->num_elements == b)
        {
            // se busca el último nodo que no esté lleno
            current_node = current_node->next;
        }
        if (current_node->num_elements < b)
        {
            // se inserta en el último nodo no lleno
            current_node->arr[current_node->num_elements] = v;
            current_node->num_elements++;
            num_elements++;
        }
        else
        {
            // todos los nodos están llenos, se crea uno nuevo y se inserta
            Node *new_node = new Node(b);
            new_node->arr[0] = v;
            new_node->num_elements++;
            num_elements++;
            current_node->next = new_node;
        }
    }
}

void ListArr::insert(int v, int i)
{
    if (i < 0 || i > num_elements) {
        // índice inválido, no se hace nada
        return;
    }
    if (head == nullptr) {
        // la lista está vacía, se crea el primer nodo
        head = new Node(b);
        head->arr[0] = v;
        head->num_elements++;
        num_elements++;
    } else {
        Node *current_node = head;
        int current_index = 0;
        while (current_node->next != nullptr && current_index + current_node->num_elements < i) {
            // se busca el nodo que contiene el índice i
            current_index += current_node->num_elements;
            current_node = current_node->next;
        }
        if (current_node->num_elements == b) {
            // se crea un nuevo nodo si el actual está lleno
            Node *new_node = new Node(b);
            new_node->next = current_node->next;
            current_node->next = new_node;
            current_node = new_node;
        }
        // se inserta el valor v en el índice i
        int local_index = i - current_index;
        for (int j = current_node->num_elements; j > local_index; j--) {
            current_node->arr[j] = current_node->arr[j-1];
        }
        current_node->arr[local_index] = v;
        current_node->num_elements++;
        num_elements++;
    }
}

void ListArr::print()
{
    Node *current_node = head;
    while (current_node != nullptr) {
        for (int i = 0; i < current_node->num_elements; i++) {
            std::cout << current_node->arr[i] << " ";
        }
        current_node = current_node->next;
    }
    std::cout << std::endl;
}

bool ListArr::find(int v)
{
    Node *current_node = head;
    while (current_node != nullptr) {
        for (int i = 0; i < current_node->num_elements; i++) {
            if (current_node->arr[i] == v) {
                return true;
            }
        }
        current_node = current_node->next;
    }
    return false;
}


ListArr::NodeSummary ListArr::createNodeSummary(Node* left, Node* right) {
    NodeSummary summaryNode;
    summaryNode.total_capacity = left->b + right->b;
    summaryNode.total_size = left->num_elements + right->num_elements;
    summaryNode.left_child = left;
    summaryNode.right_child = right;
    return summaryNode;
}
