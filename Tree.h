#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class Tree
{
protected:
	Node<T>* root;

public:
	virtual void insert(T) = 0;
	virtual bool search(T) = 0;
	virtual void inorder() = 0;
	virtual void preorder() = 0;
	virtual void postorder() = 0;
	virtual void preorder2() = 0;
	virtual void inorder2() = 0;
	virtual void postorder2() = 0;
	virtual T searchParent(T) = 0;
	virtual void destroy() = 0;
	Tree();
};
template<class T>
Tree<T>::Tree()
{
	root = nullptr;
}

