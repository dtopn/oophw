#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template <typename T> class LinkedList;
template <typename T> class ListNode{
	friend class LinkedList<T>;
public:
	ListNode(const T t): data(t), next(0){}
	~ListNode();
	T read_info();
	//ListNode* getNext();
private:
	ListNode* next;
	T data;
};

//#include "ListNode.h"

//template <typename T> ListNode<T>::ListNode(){
//    ;
//}


template <typename T> ListNode<T>::~ListNode(){
	if ( next )
		delete next;
}

template <typename T> T ListNode<T>::read_info(){
	return data;
}

//template <typename T> ListNode<T>* ListNode<T>::getNext(){
//	return next;
//}

#endif //LISTNODE_H