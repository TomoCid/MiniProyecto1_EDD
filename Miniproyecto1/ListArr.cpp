#include "ListArr.h"
#include <string>

using namespace std;

ListArr::ListArr(int capacity)
{
    this->capacity = capacity;
    Node *node = new Node(capacity);
    total_num_elements = 0;
    nodeCount = 1;
    head = node;
}

void ListArr::searchIndex(int &i, NodeSummary *TreeRoot, Node* &target){
    NodeSummary *current = TreeRoot;
    if (i<0 || i > total_num_elements - 1)
    {
        throw "No exite el indice indicado";
        return;
    }

    if(current->Summaryleft_child==nullptr && i<current->left_child->num_elements){
        target = current->left_child;
        return;
    }else if(current->Summaryright_child==nullptr && i>=current->left_child->num_elements){
        i = i - current->left_child->num_elements;
        target = current->right_child;
        return;
    }

    if(i < current->Summaryleft_child->total_size){
        if (current->Summaryleft_child != nullptr)
        {
            searchIndex(i, current->Summaryleft_child, target);
        }
        else
        {
            target = current->left_child;
            return; 
        }
    }
    else
    {
        if (current->Summaryright_child != nullptr)
        {
            i = i - current->Summaryleft_child->total_size;
            searchIndex(i, current->Summaryright_child, target);
            
        }
        else
        {
            target = current->right_child; 
            return;
        }
    }

}

void ListArr::insert(int v,int i)
{
    Node *target = nullptr;
    cout<<"I1: "<<i<<endl;
    searchIndex(i, TreeRoot, target);
    cout << "Logre encontrar el nodo, ahora insercion" << endl;
    cout << "[Capacity] : " << target->capacity << " [Size]: " << target->num_elements << endl;
    cout << "Primer elemento : " << target->arr->at(0) << endl;

    if (target != nullptr)
    {
        
        if (target->num_elements < capacity)
        {
            cout<<"Caso 1: Insertar en el mismo nodo"<<endl;
            target->arr->insert(target->arr->begin() + i, v);
            target->num_elements++;
            total_num_elements++;
            updateTree();
        }
        else
        {
            if ( (target->next != nullptr && target->next->num_elements == capacity) || target->next == nullptr){ //CASO NODO SIGUIENTE LLENO
                cout<<"Caso 2: Crear nodo nuevo"<<endl;
                cout<<"VALOR DE I "<<i<<endl;
                Node *newNode = new Node(capacity);
                nodeCount++;
                Node* aux = target->next;
                target->next = newNode;
                newNode->next = aux;
                
                int auxElement = target->arr->at(i);
                target->arr->at(i) = v;
                newNode->arr->push_back(auxElement);
                newNode->num_elements++;                
                total_num_elements++;
                updateTree();
            }else if(target->next != nullptr && target->next->num_elements<capacity){
                cout<<"Caso 3: Mover a nodo siguiente con espacio"<<endl;
                target->next->arr->insert(target->arr->begin(),target->arr->back());
                target->arr->at(i) = v;
                target->next->num_elements++;
                total_num_elements++;
                updateTree();
            }
        }
    }
    else
    {
        cout << "error en insert" << endl;
        throw "Nodo Nulo";
        return;
    }
}

// Función terminada
void ListArr::createSummaryNodes(vector<NodeSummary *> PrevSummaryNodes)
{
    vector<NodeSummary *> AuxiliarVector;
    AuxiliarVector.clear();

    if (PrevSummaryNodes.size() == 1)
    {
        TreeRoot = PrevSummaryNodes[0];
        return;
    }
    int aux = PrevSummaryNodes.size();
    for (int i = 0; i < aux / 2; i++)
    {
        NodeSummary *summary = new NodeSummary();
        AuxiliarVector.push_back(summary);
        summary->total_capacity = PrevSummaryNodes[0]->total_capacity + PrevSummaryNodes[1]->total_capacity;
        summary->total_size = PrevSummaryNodes[0]->total_size + PrevSummaryNodes[1]->total_size;
        summary->Summaryleft_child = PrevSummaryNodes[0];
        summary->Summaryright_child = PrevSummaryNodes[1];

        if (PrevSummaryNodes.size() > 2)
        {
            PrevSummaryNodes.erase(PrevSummaryNodes.begin(), PrevSummaryNodes.begin() + 2);
        }
        else
        {
            break;
        }
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

    PrevSummaryNodes.clear();
    createSummaryNodes(AuxiliarVector);
}

// Función terminada
void ListArr::createSummaryNodes(Node *root)
{
    vector<NodeSummary *> NodeSummaryFirstLevel;
    NodeSummaryFirstLevel.clear();
    Node *current = root;

    if (nodeCount != 1)
    {
        for (int i = 0; i < nodeCount / 2; ++i)
        {
            NodeSummary *summary = new NodeSummary();
            cout << "He creado un nodo resumen nivel 1" << endl;
            NodeSummaryFirstLevel.push_back(summary);
            cout << "Tamaño NodeSummaryFirstLevel:" << NodeSummaryFirstLevel.size() << endl;

            summary->total_capacity = current->capacity + current->next->capacity;
            summary->total_size = current->num_elements + current->next->num_elements;
            summary->left_child = current;
            summary->right_child = current->next;

            cout << "Nodo nivel 1 [Capacity]: " << summary->total_capacity << " --";
            cout << "Nodo nivel 1 [Size]: " << summary->total_size << endl;

            current = current->next->next;
        }
    }
    // Crear nodo resumen para el último nodo solitario si el número de nodos es impar
    if (nodeCount % 2 == 1)
    {
        NodeSummary *summary = new NodeSummary();
        cout << "He creado un nodo resumen nivel 1" << endl;
        NodeSummaryFirstLevel.push_back(summary);
        cout << "Tamaño NodeSummaryFirstLevel:" << NodeSummaryFirstLevel.size() << endl;

        summary->total_capacity = current->capacity;
        summary->total_size = current->num_elements;
        summary->left_child = current;
        summary->right_child = nullptr;

        cout << "Nodo nivel 1 [Capacity]: " << summary->total_capacity << " --";
        cout << "Nodo nivel 1 [Size]: " << summary->total_size << endl;
    }

    // Llamada recursiva para crear nodos resumen de los nodos resumen
    createSummaryNodes(NodeSummaryFirstLevel);
}

// En proceso
int ListArr::delete_left()
{
    int left_element;
    if (head->arr->size() > 0)
    {
        left_element = head->arr->at(0);
        head->arr->erase(head->arr->begin());
        head->num_elements--;
        total_num_elements--;
    }
    if (head->arr->size() <= 0)
    {
        head = head->next;
        nodeCount--;
    }
    updateTree();
    return left_element;
}

// Pendiente
int ListArr::delete_right()
{
    if (TreeRoot == nullptr)
    {
        return 0;
    }

    // Empezamos en la raíz
    NodeSummary *currentSummary = TreeRoot;

    // Bajamos hasta el nodo de la derecha más profundo
    while (currentSummary->Summaryright_child != nullptr)
    {
        currentSummary = currentSummary->Summaryright_child;
    }

    // Accedemos al nodo correspondiente en el nivel inferior
    Node *current = currentSummary->right_child;
    if (current == nullptr)
        current = currentSummary->left_child;
    if (current == nullptr)
        return 0;

    // Almacenamos el último elemento del arreglo antes de eliminarlo
    int last_element = current->arr->back();

    // Eliminamos el último elemento del arreglo del nodo
    current->arr->pop_back();
    current->num_elements--;
    total_num_elements--;

    if (current->arr->size() <= 0)
    {
        current = nullptr;
        nodeCount--;
    }
    // Retornamos el último elemento eliminado del arreglo
    createSummaryNodes(head);
    return last_element;
}

//"Listo a medias" (Requiere que los metodos insert queden finalizados, por si hay que hacer algun cambio)
int ListArr::size()
{
    return total_num_elements;
}

//"Listo a medias" (La idea es que en base al metodo insert aplicarlo en insert_left)
void ListArr::insert_left(int v)
{
    Node *current = head;

    if (current->num_elements == current->capacity)
    {
        Node *new_node = new Node(capacity);
        head = new_node;
        head->next = current;
        new_node->arr->insert(new_node->arr->begin(), v);
        new_node->num_elements++;
        total_num_elements++;
        nodeCount++;
    }
    else
    {
        current->arr->insert(current->arr->begin(), v);
        current->num_elements++;
        total_num_elements++;
    }

    if (TreeRoot != nullptr)
    {
        updateTree();
    }
    else
    {
        createSummaryNodes(head);
    }
}

//"Listo a medias" (La idea es que en base al metodo insert aplicarlo en insert_right)
void ListArr::insert_right(int v)
{
    if (head == nullptr)
    {
        head = new Node(capacity);
        head->arr->insert(head->arr->begin(), v);
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
            new_node->arr->insert(new_node->arr->begin(), v);
            new_node->num_elements++;
            total_num_elements++;
            nodeCount++;
            current->next = new_node;
        }
        else
        {
            current->arr->push_back(v);
            current->num_elements++;
            total_num_elements++;
        }
    }
    createSummaryNodes(head);
}

// Función terminada
void ListArr::print()
{
    Node *current = head;
    while (current != nullptr)
    {
        for (int i = 0; i < current->num_elements; i++)
        {
            cout << current->arr->at(i) << " ";
        }
        current = current->next;
    }
    cout << endl;
}

// Funcion lista
bool ListArr::find(int v)
{
    Node *aux = head; // Guardamos la ubicacion de head.
    while (aux != nullptr)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (aux->arr->at(i) == v)
            { // Si encuentra el dato en el arreglo retorna true.
                cout << "Se ha encontrado el elemento " << v << " en ListArr." << endl;
                return true;
            }
        }
        aux = aux->next;
    }
    cout << "No se ha encontrado el elemento " << v << " en ListArr." << endl;
    return false;
}

// Función terminada (Sin uso, pero no está de mas)
int ListArr::getHeight()
{
    int h = 0;
    while (pow(2, h) >= nodeCount)
    {
        h++;
    }
    return h;
}

// Funcion Lista
void ListArr::deleteTree(NodeSummary *node)
{

    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->Summaryleft_child);
    deleteTree(node->Summaryright_child);

    delete node;
}

// Funcion Lista
void ListArr::updateTree()
{
    deleteTree(TreeRoot);
    createSummaryNodes(head);
}
