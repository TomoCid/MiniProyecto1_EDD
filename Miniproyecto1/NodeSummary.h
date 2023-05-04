#include <iostream>

using namespace std;

class NodeSummary{
    private:
        int total_capacity;
        int total_size;
        NodeSummary *left_child;
        NodeSummary *right_child;
    public:
    NodeSummary();
};