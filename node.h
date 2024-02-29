#include<iostream>
#include"player.h"
using namespace std;
template <class T>



class Node{
	T data;
	Node* next;
	
	public:
		Node(T&);
		//setters
		void setData(T&);
		void setNext(Node*);
		//getters
		T& getData();
		Node* getNext();
		
};
