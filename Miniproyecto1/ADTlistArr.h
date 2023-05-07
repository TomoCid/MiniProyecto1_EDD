#ifndef _ADTlistArr
#define _ADTlistArr
using namespace std;
class ADTlistArr{

    public:
    virtual int size() = 0;
    virtual int delete_left() = 0;
    virtual int delete_right() = 0;
    virtual void insert_left(int v) = 0;
    virtual void insert_right(int v) = 0;
    virtual void insert(int v, int i) = 0;
    virtual void print() = 0;
    virtual bool find(int v) = 0;
};

#endif