#include <iostream>
#include "List.h"

using namespace std;

template <class T>
class Queue{
private:
    List<T> l;
    int s;
public:
    Queue(){
    s=0;
    }
    Queue(T value,int initsize){
    List<T> l1(value,initsize);
    l=l1;
    s=initsize;
    }
    void push(T value){
       typename List<T>::Iterator itbeg = l.begin();
       l.insert(value,itbeg);
       s++;
    }
    void pop(){
    typename List<T>::Iterator itend = l.end();
    itend--;
    l.erase(itend);
    s--;
    }
    T &front(){
    typename List<T>::Iterator itend = l.end();
    itend--;
    return *itend;
    }
    int size(){
    return s;
    }
    ~Queue(){
    typename List<T>::Iterator it=l.begin();
    typename List<T>::Iterator it2=l.end();
    while(it!=it2){
        typename List<T>::Iterator itemp = it;
        delete itemp.inode;
        it++;
    }
    delete it2.inode;
    }
};


int main()
{
    Queue<int> q(1,15);
//    q.push(5);
//    q.push(98);
//    q.push(2);
//    q.push(2);
//    q.push(3);
//    q.push(10);
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;

    return 0;
}
