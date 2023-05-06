#include "ListArr.h"
#include <string>
using namespace std;

// Listo
ListArr::ListArr(int capacity)
{
    this->capacity = capacity;
    Node *node = new Node(capacity);
    total_num_elements = 0;
    nodeCount = 1;
    head = node;
}

// Listo
void ListArr::searchIndex(int i, NodeSummary *TreeRoot, Node* target){
    NodeSummary *current = TreeRoot;
    if (i<0 || i > total_num_elements-1)
    {
        throw "No exite el indice indicado";
        return;
    } else if(i <= current->Summaryleft_child->total_size){
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
       
        target->arr->insert(target->arr->begin(), v);
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
    AuxiliarVector.clear();

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
    NodeSummaryFirstLevel.clear();
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
    int left_element;
    if(head->arr->size()>0){
        left_element = head->arr->at(0);
        head->arr->erase(head->arr->begin());
        head->num_elements--;
        total_num_elements--;
    }
    if(head->arr->size()<=0){
        head = head->next;
        nodeCount--;
    } 
    updateTree();
    return left_element;
}

// Pendiente
int ListArr::delete_right()
{   
    if (TreeRoot == nullptr) {
        return 0;
    }

    // Empezamos en la raíz
    NodeSummary* currentSummary = TreeRoot;

    // Bajamos hasta el nodo de la derecha más profundo
    while (currentSummary->Summaryright_child != nullptr) {
        currentSummary = currentSummary->Summaryright_child;
    }

    // Accedemos al nodo correspondiente en el nivel inferior
    Node* current = currentSummary->right_child;

    // Si el nodo está vacío, no hay nada que eliminar
    if (current == nullptr || current->num_elements == 0) {
        return 0;
    }
    // Almacenamos el último elemento del arreglo antes de eliminarlo
    int last_element = current->arr->back();

    // Eliminamos el último elemento del arreglo del nodo
    
    vector<int> *aux = new vector<int>;
    for(int i=1; i<current->num_elements;i++){
        aux[i-1]=current->arr[i];
    }
    delete[] current->arr;
    current->arr = aux;
    current->num_elements - 1;
    // Retornamos el último elemento eliminado del arreglo
    
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
    if (head == nullptr)
    { // ESTO QUIZA SE PUEDE ELIMINAR
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
            for (int i = current->num_elements; i > 0; i--)
            {
                current->arr[i] = current->arr[i - 1];
            }
            current->arr->insert(current->arr->begin(), v);
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

//Función terminada
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

//Funcion lista
bool ListArr::find(int v){
    Node *aux = head; // Guardamos la ubicacion de head.
    while(aux!=nullptr){
        for (int i = 0; i < capacity; i++){
        if (aux->arr->at(i) == v) { // Si encuentra el dato en el arreglo retorna true.
            cout<<"Se ha encontrado el elemento "<< v <<" en ListArr."<<endl;
            return true;
            }
        }
        aux= aux->next;
    }
    cout<<"No se ha encontrado el elemento "<< v <<" en ListArr."<<endl;
    return false;
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

//Funcion Lista
void ListArr::deleteTree(NodeSummary *node){

  if (node == nullptr) {
    return;
  }
    deleteTree(node->Summaryleft_child);
    deleteTree(node->Summaryright_child);
  
  delete node;
}

//Funcion Lista
void ListArr::updateTree(){
    deleteTree(TreeRoot);
    createSummaryNodes(head);
}



