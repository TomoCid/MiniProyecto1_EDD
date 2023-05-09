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

void ListArr::searchIndex(int &i, NodeSummary *TreeRoot, Node* &target){//O(log(n))
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

void ListArr::insert(int v,int i)//O(log n)
{
    if(i==0 && head->num_elements==0 && head->next==nullptr){
        head->arr->push_back(v);
        head->num_elements++;
        total_num_elements++;
        updateTree();
        return;
    }
    Node *target = nullptr;
    searchIndex(i, TreeRoot, target);

    if (target != nullptr)
    {
        
        if (target->num_elements < capacity)
        {

            target->arr->insert(target->arr->begin() + i, v);
            target->num_elements++;
            total_num_elements++;
            updateTree();
        }
        else
        {
            if ( (target->next != nullptr && target->next->num_elements == capacity) || target->next == nullptr){ 
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
                target->next->arr->insert(target->next->arr->begin(),target->arr->back());
                target->arr->at(i) = v;
                target->next->num_elements++;
                total_num_elements++;
                updateTree();
            }
        }
    }
    else
    {
        throw "Nodo Nulo";
        return;
    }
}

void ListArr::createSummaryNodes(vector<NodeSummary *> PrevSummaryNodes)//O(nodeCount)
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
    if (PrevSummaryNodes.size() % 2 == 1)
    {
        NodeSummary *summary = new NodeSummary();
        AuxiliarVector.push_back(summary);

        summary->total_capacity = PrevSummaryNodes[0]->total_capacity;
        summary->total_size = PrevSummaryNodes[0]->total_size;
        summary->Summaryleft_child = PrevSummaryNodes[0];
        summary->Summaryright_child = nullptr;
    }
    PrevSummaryNodes.clear();
    createSummaryNodes(AuxiliarVector);
}

void ListArr::createSummaryNodes(Node *root) //O(nodeCount)
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
    if (nodeCount % 2 == 1)
    {
        NodeSummary *summary = new NodeSummary();
        NodeSummaryFirstLevel.push_back(summary);
        summary->total_capacity = current->capacity;
        summary->total_size = current->num_elements;
        summary->left_child = current;
        summary->right_child = nullptr;
    }
    createSummaryNodes(NodeSummaryFirstLevel);
}

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

int ListArr::delete_right()
{                                   
    if (TreeRoot == nullptr)
    {
        throw "No hay más elementos en listArr";
        return -1;
    }               
    // Empezamos en la raíz
    NodeSummary *currentSummary = TreeRoot;

    // Bajamos hasta el nodo de la derecha más profundo
    while (currentSummary->Summaryright_child != nullptr || currentSummary->Summaryleft_child != nullptr)
    {
        if (currentSummary->Summaryright_child != nullptr) {
            currentSummary = currentSummary->Summaryright_child;
        }
    else {
        currentSummary = currentSummary->Summaryleft_child;
        }
    }
                                                                                               
    // Accedemos al nodo correspondiente en el nivel inferior
    Node *current = new Node(capacity);
    if(currentSummary->right_child!=nullptr){
        current=currentSummary->right_child; 
    }else if (currentSummary->left_child!= nullptr){
        current = currentSummary->left_child; 
    } else if (current == nullptr){
        throw "No hay más elementos en su listArr";
        return 0; 
    }
    // Almacenamos el último elemento del arreglo antes de eliminarlo
    int last_element = current->arr->back();

    // Eliminamos el último elemento del arreglo del nodo
    current->arr->pop_back();
    current->num_elements--;
    total_num_elements--;

    if (current->arr->size() <= 0)
    {
        nodeCount--;
        current = nullptr;
    }
    // Retornamos el último elemento eliminado del arreglo
    updateTree();
    return last_element;
}

int ListArr::size()//O(1)
{
    return total_num_elements;
}

void ListArr::insert_left(int v)//O(n)
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

void ListArr::insert_right(int v)
{
    if (TreeRoot == nullptr)
    {
        if(head->arr->size()<capacity){
            head->arr->push_back(v);
            head->num_elements++;
            total_num_elements++;
            updateTree();
        }
        return;
    }
    NodeSummary *currentSummary = TreeRoot;
    while (currentSummary->Summaryright_child != nullptr || currentSummary->Summaryleft_child != nullptr)
    {
        if (currentSummary->Summaryright_child != nullptr)
        {
            currentSummary = currentSummary->Summaryright_child;
        }
        else
        {
            currentSummary = currentSummary->Summaryleft_child;
        }
    }
    Node *current = new Node(capacity);
    if (currentSummary->right_child != nullptr)
    {
        current = currentSummary->right_child;
    }
    else if (currentSummary->left_child != nullptr)
    {
        current = currentSummary->left_child;
    }
    else if (current == nullptr)
    {
        throw "No hay más elementos en su listArr";
        return;
    }
    if (current->num_elements < capacity)
    {
        current->arr->push_back(v);
        current->num_elements++;
        total_num_elements++;
        updateTree();
    }
    else
    {
        Node *newNode = new Node(capacity);
        nodeCount++;
        current->next=newNode;
        newNode->arr->push_back(v);
        newNode->num_elements++;
        total_num_elements++;
        updateTree();
    }
}

void ListArr::print() //O(n)
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

bool ListArr::find(int v) //O(n) y O(1) en espacio
{
    Node *aux = head; 
    while (aux != nullptr)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (aux->arr->at(i) == v)
            { 
                return true;
            }
        }
        aux = aux->next;
    }
    return false;
}

int ListArr::getHeight()//O(log nodeCounts)
{
    int h = 0;
    while (pow(2, h) >= nodeCount)
    {
        h++;
    }
    return h;
}

void ListArr::deleteTree(NodeSummary *node)//O(nodeCount)
{

    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->Summaryleft_child);
    deleteTree(node->Summaryright_child);

    delete node;
}

void ListArr::updateTree()//O(nodeCount + log n)
{
    deleteTree(TreeRoot);
    createSummaryNodes(head);
}
