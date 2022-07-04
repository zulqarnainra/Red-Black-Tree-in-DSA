#pragma once
#include"Tree.h"
#include"RBT.h"

bool check = false;
template<class T>
class RBT :public Tree<T>
{
	bool checkBalance(Node<T>* GGP, Node<T>* GP, Node<T>* P, Node<T>* C)
	{

		if ((P->data < GP->data) && (C->colour == 'R' && P->colour == 'R') && (GP->right != nullptr && GP->right->colour == 'R'))
		{
			if (GP != Tree<T>::root)
				GP->colour = 'R';
			P->colour = 'B';
			GP->right->colour = 'B';
			return true;
		}
		else if ((P->data > GP->data) && (C->colour == 'R' && P->colour == 'R') && (GP->left != nullptr && GP->left->colour == 'R'))
		{
			if (GP != Tree<T>::root)
				GP->colour = 'R';

			P->colour = 'B';
			GP->left->colour = 'B';
			return true;
		}




		if (P->data<GP->data && C->data>P->data && (GP->right == nullptr || GP->right->colour == 'B'))
		{
			swap(C->data, P->data);
			P->left = P->right;
			P->right = nullptr;
			return true;
		}

		else if (P->data > GP->data && C->data < P->data && (GP->left == nullptr || GP->left->colour == 'B'))
		{
			swap(C->data, P->data);
			P->right = P->left;
			P->left = nullptr;

			return true;
		}



		if (P->colour == 'R' && (P->data < GP->data && C->data < P->data) && (P->colour = 'R' && C->colour == 'R') && (GP->right == nullptr || GP->right->colour == 'B'))
		{
			GP->left = P->right;
			P->right = GP;
			if (GP == Tree<T>::root)
				Tree<T>::root = P;
			else if (GP->data < GGP->data)
				GGP->left = P;
			else
				GGP->right = P;

			P->colour = 'B';
			GP->colour = 'R';
		}





		if (P->colour == 'R' && (P->data > GP->data && C->data > P->data) && (P->colour = 'R' && C->colour == 'R') && (GP->left == nullptr || GP->left->colour == 'B'))
		{
			GP->right = P->left;
			P->left = GP;
			if (GP == Tree<T>::root)
				Tree<T>::root = P;
			else if (GP->data > GGP->data)
				GGP->right = P;
			else
				GGP->left = P;

			P->colour = 'B';
			GP->colour = 'R';

		}

		return false;
	}

	bool SEARCH(Node<T>*, Node<T>*);
	void PREORDER(Node<T>*);
	void PREORDER2(Node<T>*);
	void POSTORDER(Node<T>*);
	void INORDER(Node<T>*);
	void INORDER2(Node<T>*);
	void POSTORDER2(Node<T>*);
	void DESTROY(Node<T>*&);

public:
	void insert(T);
	void inorder();
	bool search(T);
	void preorder();
	void postorder();
	void preorder2();
	void inorder2();
	void postorder2();
	T searchParent(T);
	void destroy();
};

template<class T>
void RBT<T>::insert(T value)
{
	Node<T>* n = new Node<T>;
	n->left = nullptr;
	n->right = nullptr;
	n->data = value;
	n->colour = 'R';
	n->count = 1;

	//Case 1
	if (Tree<T>::root == nullptr)
	{
		Tree<T>::root = n;
		Tree<T>::root->colour = 'B';
	}

	else {
		Node<T>* GGP = Tree<T>::root;
		Node<T>* GP = Tree<T>::root;
		Node<T>* P = Tree<T>::root;
		Node<T>* C = Tree<T>::root;

		while (true)
		{
			GGP = GP;
			GP = P;
			P = C;

			if (value < C->data)
			{
				if (C->left == nullptr)
				{
					C->left = n;
					C = C->left;
					break;
				}
				C = C->left;
			}
			else if (value > C->data)
			{
				if (C->right == nullptr)
				{
					C->right = n;
					C = C->right;
					break;
				}
				C = C->right;
			}
			else
			{
				n->count = n->count + 1;
				break;
			}

		}

		//Case 2
		if (P->colour == 'B')
			return;

		RBT<T>::checkBalance(GGP, GP, P, C);

	}
}

template<class T>
void RBT<T>::DESTROY(Node<T>*& p)
{
	if (p != nullptr)
	{
		if ((p->left == nullptr) && (p->right == nullptr))
		{
			delete p;
			p = nullptr;
		}
		else
		{
			RBT<T>::DESTROY(p->left);
			RBT<T>::DESTROY(p->right);
			RBT<T>::DESTROY(p);
		}
	}
	return;
}
template<class T>
T RBT<T>::searchParent(T value)
{
	Node<T>* P = Tree<T>::root;
	Node<T>* C = Tree<T>::root;
	if (Tree<T>::root == nullptr)
		return 0;
	while (true)
	{
		P = C;
		if (Tree<T>::root->data == value)
		{
			return 0;
		}
		if (value < C->data)
		{
			if (C->left->data == value)
			{
				return P->data;
				C = C->left;
				break;
			}
			C = C->left;
		}
		else if (value > C->data)
		{
			if (C->right->data == value)
			{
				return P->data;
				C = C->right;
				break;
			}
			C = C->right;
		}

	}
	return 0;
}
template<class T>
void RBT<T>::postorder()
{
	if (Tree<T>::root != nullptr)
		RBT<T>::POSTORDER(Tree<T>::root);

	else
		cout << "RBT<T> is Empty" << endl;
}
template<class T>
void RBT<T>::POSTORDER(Node<T>* p)
{
	if (p != nullptr)
	{
		RBT<T>::POSTORDER(p->left);
		RBT<T>::POSTORDER(p->right);
		cout << p->data << " " << p->colour << endl;
	}
}


template<class T>
void RBT<T>::postorder2()
{
	if (Tree<T>::root != nullptr)
		RBT<T>::POSTORDER2(Tree<T>::root);

	else
		cout << "RBT<T> is Empty" << endl;
}
template<class T>
void RBT<T>::POSTORDER2(Node<T>* p)
{
	if (p != nullptr)
	{
		RBT<T>::POSTORDER2(p->right);
		RBT<T>::POSTORDER2(p->left);
		cout << p->data << " " << p->colour << endl;
	}
}
template<class T>
void RBT<T>::inorder()
{
	if (Tree<T>::root != nullptr)
		RBT<T>::INORDER(Tree<T>::root);

	else
		cout << "RBT<T> is Empty" << endl;
}
template<class T>
void RBT<T>::INORDER(Node<T>* p)
{
	if (p != nullptr)
	{
		RBT<T>::INORDER(p->left);
		cout << p->data << " ";
		cout << p->colour << endl;
		RBT<T>::INORDER(p->right);
	}
}
template<class T>
void RBT<T>::inorder2()
{
	if (Tree<T>::root != nullptr)
		RBT<T>::INORDER2(Tree<T>::root);

	else
		cout << "RBT<T> is Empty" << endl;
}
template<class T>
void RBT<T>::INORDER2(Node<T>* p)
{
	if (p != nullptr)
	{
		RBT<T>::INORDER2(p->right);
		cout << p->data << " ";
		cout << p->colour << endl;
		RBT<T>::INORDER2(p->left);
	}
}
template<class T>
void RBT<T>::PREORDER(Node<T>* p)
{
	if (p != nullptr)
	{
		cout << p->data << " " << p->colour << endl;
		RBT<T>::PREORDER(p->left);
		RBT<T>::PREORDER(p->right);
	}
}
template<class T>
void RBT<T>::preorder()
{
	if (Tree<T>::root != nullptr)
		RBT<T>::PREORDER(Tree<T>::root);

	else
		cout << "RBT<T> is Empty" << endl;
}
template<class T>
void RBT<T>::PREORDER2(Node<T>* p)
{
	if (p != nullptr)
	{
		cout << p->data << " " << p->colour << endl;
		RBT<T>::PREORDER2(p->right);
		RBT<T>::PREORDER2(p->left);
	}
}
template<class T>
void RBT<T>::preorder2()
{
	if (Tree<T>::root != nullptr)
		RBT<T>::PREORDER2(Tree<T>::root);

	else
		cout << "RBT<T> is Empty" << endl;
}
template<class T>
bool RBT<T>::SEARCH(Node<T>* r, Node<T>* n)
{
	if (r != nullptr)
	{
		if (n->data == r->data)
			return true;
		else if (n->data > r->data)
			return RBT<T>::SEARCH(r->right, n);
		else if (n->data < r->data)
			return RBT<T>::SEARCH(r->left, n);
	}
	return false;
}
template<class T>
bool RBT<T>::search(T value)
{
	Node<T>* n = new Node<T>;
	n->left = nullptr;
	n->right = nullptr;
	n->data = value;

	if (Tree<T>::root != nullptr)
	{
		return RBT<T>::SEARCH(Tree<T>::root, n);
	}
	else
		cout << "RBT is Empty" << endl;
	return 0;
}


template<class T>
void RBT<T>::destroy()
{
	if (Tree<T>::root != nullptr)
		RBT<T>::DESTROY(Tree<T>::root);
	else
	{
		cout << "\nRBT is Empty\n";
	}

}
