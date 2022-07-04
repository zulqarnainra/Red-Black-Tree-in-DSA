#include<iostream>
#include<fstream>
#include"RBT.h"


using namespace std;


int main()
{

	RBT<int> obj;

	int choice = 0;
	do {
		cout << "Press 1 to insert Values in Tree ";
		cout << "\nPress 2 for searching Value in Tree";
		cout << "\nPress 3 for pre-Order Taversal NLR ";
		cout << "\nPress 4 for In-Order Traversal LNR";
		cout << "\nPress 5 for post-Order Traversal LRN ";
		cout << "\nPress 6 for pre-Order Traversal 2 NRL ";
		cout << "\nPress 7 for In-Order Traversal 2 RNL";
		cout << "\nPress 8 for post-Order Traversal 2 RLN ";
		cout << "\nPress 9 to displaying Parent of Node present in Tree";
		cout << "\nPress 10 to read Values from file input.txt to create RBT";
		cout << "\nPress 11 to destroy complete Tree";
		cout << "\nPress 12 to Exit";
		cout << "\nEnter Your Choice : ";
		cin >> choice;

		if (choice == 1)
		{
			int value;
			cout << "\n\nEnter Value to Add in RBT : ";
			cin >> value;
			obj.insert(value);
			cout << "\n\n-----Value Inserted -------\n\n";
		}
		else if (choice == 2)
		{
			int value;
			cout << "\n\nEnter Value to Search : ";
			cin >> value;
			if (obj.search(value))
			{
				cout << "\n------Value Found-------\n\n";
			}
			else
				cout << "\n--------Value Not Found-------\n\n";
		}
		else if (choice == 3)
		{
			cout << endl << "\n------Pre-Order---------\n";
			obj.preorder();
			cout << endl;
		}
		else if (choice == 4)
		{
			cout << endl << "\n------In-Order---------\n";
			obj.inorder();
			cout << endl;
		}
		else if (choice == 5)
		{
			cout << endl << "\n------Post-Order---------\n";
			obj.postorder();
			cout << endl;
		}
		else if (choice == 6)
		{
			cout << endl << "\n------Pre-Order 2---------\n";
			obj.preorder2();
			cout << endl;
		}
		else if (choice == 7)
		{
			cout << endl << "\n------In-Order 2---------\n";
			obj.inorder2();
			cout << endl;
		}
		else if (choice == 8)
		{
			cout << endl << "\n------Post-Order 2---------\n";
			obj.postorder2();
			cout << endl;
		}
		else if (choice == 9)
		{
			int value;
			cout << "Enter Node to find Parent : ";
			cin >> value;
			if (obj.searchParent(value) == 0)
			{
				cout << "\n-------No Parent--------\n";
			}
			else
				cout << "\nParent :" << obj.searchParent(value);
			cout << endl;
		}
		else if (choice == 10)
		{
			int x;
			ifstream indata;
			indata.open("data.txt");
			while  (!indata.eof())
			{
				indata >> x;
				obj.insert(x);
			}
			cout << "\n-----Values Added From File Successfully--------\n\n";
		}
		
		else if (choice == 11)
		{
			obj.destroy();
			cout << "\n-------RBT Destroyed--------\n\n";
		}

	} while (choice < 12);

}