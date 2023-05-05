#include "ListArr.h"
#include <string>
using namespace std;

// Modificar para adaptarlo a la estructura de nodos
ListArr::ListArr(int capacity)
{
    this->capacity = capacity;
    Node *node = new Node(capacity);
    nodeCount = 1;
    head = node;
    total_num_elements = 0;
}

// Ya está casi listo, falta buscar la forma de implementarlo en insert
void ListArr::searchIndex(int i, NodeSummary *TreeRoot, Node* target){
    NodeSummary *current = TreeRoot;
    Node* target;
    if (i<0 || i > total_num_elements-1)
    {
        throw "No exite el indice indicado";
        return;
    }
    else if (i <= current->Summaryleft_child->total_size)
    {
        if (current->Summaryleft_child != nullptr)
        {
            searchIndex(i - current->Summaryleft_child->total_size, current->Summaryleft_child, target);
        }
        else
        {
            target = current->left_child; // Para el insert puede ser la misma funcion pero en esta linea colocar "== v", siendo v el numero a ingresar
        }
    }
    else
    {
        if (current->Summaryright_child != nullptr)
        {
            searchIndex(i - current->Summaryleft_child->total_size, current->Summaryright_child, target);
        }
        else
        {
            target = current->right_child; // Para el insert puede ser la misma funcion pero en esta linea colocar "== v", siendo v el numero a ingresar
        }
    }
}

// En proceso
void ListArr::insert(int v, int i){
    Node* target;
    searchIndex(i,TreeRoot, target); //target toma el valor del nodo donde se realizará la operacion insert()
    if (target->num_elements <= capacity - 1) {
		for (int j = 0; i<=capacity - i; j++) {
			target->arr[capacity - j] = target->arr[capacity - j - 1];
		}
		target->num_elements++;
        total_num_elements++;
	} else {
        return;
        //Continuar
    }
}

//Función terminada
void ListArr::createSummaryNodes(vector<NodeSummary *> PrevSummaryNodes)
{
    vector<NodeSummary *> AuxiliarVector;

    if (PrevSummaryNodes.size() == 1)
    {
        TreeRoot = PrevSummaryNodes[0];
        return;
    }
    // Crear nodos resumen de pares de nodos
    for (int i = 0; i < PrevSummaryNodes.size() / 2; ++i)
    {
        NodeSummary *summary = new NodeSummary();
        AuxiliarVector.push_back(summary);

        summary->total_capacity = PrevSummaryNodes[0]->total_capacity + PrevSummaryNodes[1]->total_capacity;
        summary->total_size = PrevSummaryNodes[0]->total_size + PrevSummaryNodes[1]->total_size;
        summary->Summaryleft_child = PrevSummaryNodes[0];
        summary->Summaryright_child = PrevSummaryNodes[1];

        PrevSummaryNodes.erase(PrevSummaryNodes.begin(), PrevSummaryNodes.begin() + 2);
    }
    // Crear nodo resumen para el último nodo solitario si el número de nodos es impar
    if (PrevSummaryNodes.size() % 2 == 1)
    {
        NodeSummary *summary = new NodeSummary();
        AuxiliarVector.push_back(summary);

        summary->total_capacity = PrevSummaryNodes[0]->total_capacity;
        summary->total_size = PrevSummaryNodes[0]->total_size;
        summary->Summaryleft_child = PrevSummaryNodes[0];
        summary->Summaryright_child = nullptr;
    }
    // Llamada recursiva para crear nodos resumen de los nodos resumen
    createSummaryNodes(AuxiliarVector);
}

//Función terminada
void ListArr::createSummaryNodes(Node *root)
{
    vector<NodeSummary *> NodeSummaryFirstLevel;
    Node *current = root;

    if (nodeCount != 1)
    {
        for (int i = 0; i < nodeCount / 2; ++i)
        {
            NodeSummary *summary = new NodeSummary();
            NodeSummaryFirstLevel.push_back(summary);

            summary->total_capacity = current->capacity + current->next->capacity;
            summary->total_size = current->num_elements + current->next->num_elements;
            summary->left_child = current;
            summary->right_child = current->next;

            current = current->next->next;
        }
    }
    // Crear nodo resumen para el último nodo solitario si el número de nodos es impar
    if (nodeCount % 2 == 1)
    {
        NodeSummary *summary = new NodeSummary();
        NodeSummaryFirstLevel.push_back(summary);

        summary->total_capacity = current->capacity;
        summary->total_size = current->num_elements;
        summary->left_child = current;
        summary->right_child = nullptr;
    }
    // Llamada recursiva para crear nodos resumen de los nodos resumen
    createSummaryNodes(NodeSummaryFirstLevel);
}

// En proceso
int ListArr::delete_left()
{
    //Será analogo a la funcion de abajo, elimine la anterior porque era de complejidad o(n) y la nueva es de o(log(n))
}

// Pendiente
int ListArr::delete_right()
{

    if (TreeRoot == nullptr)
    {
        return 0;
    }

    NodeSummary *current = TreeRoot;
    Node *target;
    while (current->Summaryright_child != nullptr)
    {
        current = current->Summaryright_child;
        if (current->right_child != nullptr)
        {
            target = current->right_child;
        }
    }

    if (target->num_elements > 0)
    {
        //target->arr; aqui se eliminar el ultimo elemento del arreglo (a la espera de usar vector c: )
    }
}

//"Listo a medias" (Requiere que los metodos insert queden finalizados, por si hay que hacer algun cambio)
int ListArr::size()
{
    return total_num_elements;
}

//"Listo a medias" (La idea es que en base al metodo insert aplicarlo en insert_left)
void ListArr::insert_left(int v)
{
    if (head == nullptr)
    { // ESTO QUIZA SE PUEDE ELIMINAR
        head = new Node(capacity);
        head->arr[0] = v;
        head->num_elements++;
        total_num_elements++;
        nodeCount++;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr && current->num_elements == current->capacity)
        {
            current = current->next;
        }

        if (current->num_elements == current->capacity)
        {
            Node *new_node = new Node(capacity);
            new_node->arr[0] = v;
            new_node->num_elements++;
            total_num_elements++;
            nodeCount++;
            current->next = new_node;
        }
        else
        {
            for (int i = current->num_elements; i > 0; i--)
            {
                current->arr[i] = current->arr[i - 1];
            }
            current->arr[0] = v;
            current->num_elements++;
            total_num_elements++;
        }
    }
    createSummaryNodes(head);
}

//"Listo a medias" (La idea es que en base al metodo insert aplicarlo en insert_right)
void ListArr::insert_right(int v)
{
    if (head == nullptr)
    { // En caso de que intentemos ingresar un elemento y no exista un nodo,creamos uno.
        head = new Node(capacity);
        head->arr[capacity - 1] = v; // Se ingresa el elemento en la posición más a la derecha
        head->num_elements++;        // Aumenta el contador de elementos del nodo
        total_num_elements++;              // Aumenta el contador de elementos global
        nodeCount++;
    }
    else
    {
        Node *current = head; // Recorremos todos los nodos para buscar el que tenga espacio
        while (current->next != nullptr && current->next->num_elements == current->capacity)
        { // Si el nodo que viene es vacio, entonces este es el ultimo nodo e ingresamos aqui,
            // si en los nodos que siguen se encuentra uno que no este lleno, nos detenemos ahi
            current = current->next;
        }

        if (current->num_elements == current->capacity)
        { // En caso de que ningun nodo tenga espacio para guardar el elemento, creamos un nodo nuevo
            Node *new_node = new Node(capacity);
            new_node->arr[capacity - 1] = v; // Se ingresa el elemento en la posición más a la derecha
            new_node->num_elements++;
            total_num_elements++;
            nodeCount++;
            current->next = new_node;
        }
        else
        { // Si hay espacio en el nodo actual, ingresaremos el elemento ahi
            for (int i = current->num_elements; i > 0; i--)
            { // Se mueven todos los elementos a la derecha para poder ingresar nuestro elemento a la izquierda
                current->arr[i] = current->arr[i - 1];
            }
            current->arr[0] = v; // Se ingresa el elemento en la posición más a la derecha
            current->num_elements++;
            total_num_elements++;
        }
    }
}

//Función terminada
void ListArr::print()
{
    Node *current = head;
    while (current != nullptr)
    {
        for (int i = 0; i < current->num_elements; i++)
        {
            cout << current->arr[i] << " ";
        }
        current = current->next;
    }
    cout << endl;
}
// La implementacion que dejaste actualmente es en base a recorrer todos los nodos, no usa arbol
//"Listo a medias" (En una de esas hay una forma más eficiente de implementarlo con NodeSummary, por lo que es una solucion temporal)
// Falta comprobar si funciona o hay algun error.
bool ListArr::find(int v){
    Node *aux = head; // Guardamos la ubicacion de head.
    for (int i = 0; i < capacity; i++){
        if (head->arr[i] == v) { // Si encuentra el dato en el arreglo retorna true.
            head = aux;
            cout<<"Se ha encontrado el elemento "<<v<<" en ListArr."<<endl;
            return true;
        }
    }
    if (head->next != nullptr){ // Si no, revisa si hay más nodos, y en el caso de que si, lo recorre.
        head = head->next;
        find(v);
    } else { // Si no quedan nodos, retorna false.
        head = aux;
        cout<<"No se ha encontrado el elemento "<<v<<" en ListArr."<<endl;
        return false;
    }
}

//Función terminada (Sin uso, pero no está de mas)
int ListArr::getHeight()
{
    int h = 0;
    while (pow(2, h) >= nodeCount)
    {
        h++;
    }
    return h;
}
