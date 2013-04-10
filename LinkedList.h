#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

template <typename T> class LinkedList {
public:
    ListNode<T> *getHead();
    ListNode<T> *getNext(ListNode<T> const *iterator);
    //void add(ListNode<T> &p);
    void add(T &val);
    void visitNode();
    LinkedList(): head(0), tail(0){}
	~LinkedList();
private:
    ListNode<T> *head, *tail;
    bool itsEmpty();
};

//#include "LinkedList.h"

//template <typename T>
//LinkedList<T>::LinkedList()
//{
//    head = new ListNode<T>;
//    head -> next = nullptr;
//}
/*
 template <typename T> ListNode<T>* LinkedList<T>::getNext(ListNode<T> *iterator)
 {
 ListNode<T> *p;
 p = head;
 int k;
 while(p && k < iterator){
 p = p -> next;
 k++;
 }
 return p;
 }
 */
//template <typename T>
//void LinkedList<T>::add(ListNode<T> &p){
//
//}

template <class T> void LinkedList<T>::add(T &val)
//void LinkedList<T>::add(ListNode<T> &p)
{
    //ListNode<T> *trver = head;
    //while((trver = getNext(trver)->next));
    //trver
    //getNext(<#ListNode<T> *iterator#>)->next =
    
    //ListNode<T> *trver,*q;
    //    trver = head;
    //    q = new ListNode<T>;
    //    q -> data = &p;
    //    while(trver -> next){
    //    trver = getNext(trver);
    //    }
    //    getNext(trver) = q;
    //    getNext(q) = nullptr;
    ListNode<T> *p = new ListNode<T>(val);
    if (itsEmpty()) {
	    head = tail = p;
    }
    else{
        tail->next = p;
        tail = tail->next;
    }
}


template <typename T> bool LinkedList<T>::itsEmpty() {
    return !head;
}

template <typename T> LinkedList<T>::~LinkedList<T>() {
    //delete head;
}

template <typename T> ListNode<T>* LinkedList<T>::getHead(){
	return head;
}

template <typename T> ListNode<T>* LinkedList<T>::getNext(ListNode<T> const *iterator){
	return iterator->next;
}
#endif //LINKEDLIST_H
