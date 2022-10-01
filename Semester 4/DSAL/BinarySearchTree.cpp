//============================================================================
// Name        : BST.cpp
// Author      : Reet
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;


class Node{
	Node *left;
	Node *right;
	string word;
	string def;
public:
	Node(string word = "", string def = "")
	{
		this->word = word;
		this->def = def;
		left = right = NULL;
	}
	friend class BST;
};

class BST{
	Node *root;
public:
	BST()
	{
		root = NULL;
	}
	void createBST(); //c
	void insertWord(string, string); //c
	void updateDef(string); //c
	bool searchWord(Node *, string); //c
	void deleteWord(Node *, string);
	Node *inorderS(Node *);
	void displayAsc(Node *); //c
	void displayDesc(Node *); //c
	Node* getRoot();
};

Node* BST::getRoot(){
	return root;
}
void BST::createBST()
{
	int n;
	string word, def;
	cout<<"Please enter the number of words you would like to insert in the dictionary.\nNo. of words: ";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"\nPlease enter the word.\nWord: ";
		cin>>word;
		cout<<"\nPlease enter the definition.\nDefinition: ";
		cin.ignore();
		getline(cin, def);
		insertWord(word, def);
	}
}

void BST::insertWord(string word, string def)
{
	Node *ptr = root, *ptr2, *ptr3;
	if(root == NULL)
	{
		root = new Node(word, def);
		return;
	}
	while(ptr != NULL)
	{
		ptr2 = ptr;
		if(ptr->word == word)
		{
			cout<<"\nYou have already inserted this word in the dictionary.";
			return;
		}
		else if(ptr->word > word)
		{
			ptr = ptr->left;
		}
		else if(ptr->word < word)
		{
			ptr = ptr->right;
		}
	}
	ptr3= new Node(word, def);
	if(word > ptr2->word)
	{
		ptr2->right = ptr3;
	}
	else
	{
		ptr2->left = ptr3;
	}
}

bool BST::searchWord(Node *ptr, string word)
{
	if(!root)
	{
		return false;
	}
	Node* cur = root;
	while(cur->word != word)
	{
		if (cur->word > word)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}

		if(cur == NULL)
		{
			return false;
		}
	}
   return true;
}

void BST::updateDef(string word)
{
	Node *ptr = root;
	string def;
	while(ptr != NULL)
	{
		if(ptr->word.compare(word) == 0)
		{
			cout<<"\nPlease enter the new definition of the word.\nDefinition: ";
			cin>>def;
			ptr->def = def;
			cout<<"\nThe definition of the word has been updated.\n";
			break;
		}
		else if(ptr->word < word)
		{
			ptr = ptr->right;
		}
		else if(ptr->word > word)
		{
			ptr = ptr->left;
		}
	}
}

void BST::displayAsc(Node *ptr){
	if(ptr)
	{
		displayAsc(ptr->left);
		cout<<ptr->word<<" ";
		displayAsc(ptr->right);
	}
}

void BST::displayDesc(Node *ptr)
{
	if(ptr)
	{
		displayDesc(ptr->right);
		cout<<ptr->word<<" ";
		displayDesc(ptr->left);
	}
}

void BST::deleteWord(Node *ptr, string word)
{
	if(root == NULL)
	{
		cout<<"\nThe dictionary is empty. You cannot delete any words.\n";
		return;
	}
	else if(ptr->word > word)
	{
		deleteWord(ptr->left, word);
	}
	else if(ptr->word < word)
	{
		deleteWord(ptr->right, word);
	}
	else
	{
		if(ptr->left == NULL && ptr->right == NULL)
		{
			delete ptr;
			ptr = NULL;
		}
		else if(ptr->left && ptr->right)
		{
			Node *ptr2 = inorderS(ptr);
			ptr2->word = ptr->word;
			ptr2->def = ptr->def;
			deleteWord(ptr2, ptr2->word);
		}
		else
		{
			if(ptr->left)
			{
				Node *cur = ptr;
				ptr = ptr->left;
				delete cur;
			}
			if(ptr->right)
			{
				Node *cur = ptr;
				ptr = ptr->right;
				delete cur;
			}
		}
	}
}

Node *BST::inorderS(Node *ptr)
{
	Node *ptr2 = ptr->right;
	while(ptr2)
	{
		ptr2->left;
	}
	return ptr2;
}

int main() {
	BST B;
	int option;
	bool check;
	char ch = 'Y';
	string word, def;
	B.createBST();
	do
	{
		cout<<"\n\nS.NO.   OPTION\n";
		cout<<" 1.     Insert a Word\n";
		cout<<" 2.     Search for a Word\n";
		cout<<" 3.     Update a Word\n";
		cout<<" 4.     Delete a Word\n";
		cout<<" 5.     Display the Words in Alphabetical Order (A-Z)\n";
		cout<<" 6.     Display the Words in Alphabetical Order (Z-A)\n";
		cout<<" 7.     Exit\n";
		cout<<"\nPlease enter an option.\nOption: ";
		cin>>option;
		switch(option)
		{
		case 1:
			cout<<"\n\nOPTION 1: Insert a Word\n";
			cout<<"Please enter the word.\nWord: ";
			cin>>word;
			cout<<"\nPlease enter the definition.\nDefiniton: ";
			cin.ignore();
			getline(cin, def);
			B.insertWord(word, def);
			break;
		case 2:
			cout<<"\n\nOPTION 2: Search for a Word\n";
			cout<<"\nPlease enter a word to search.\nWord: ";
			cin>>word;
			check = B.searchWord(B.getRoot(), word);
			if(check == true)
			{
				cout<<"\nThis word is present in the dictionary.\n";
			}
			else if(check == false)
			{
				cout<<"\nThis word is not present in the dictionary.\n";
			}
			break;
		case 3:
			cout<<"\n\nOPTION 3: Update a Word\n";
			cout<<"\nPlease enter the word you would like to update.\nWord: ";
			cin>>word;
			check = B.searchWord(B.getRoot(), word);
			if(check)
			{
				B.updateDef(word);
			}
			else
			{
				cout<<"\nThis word is not present in the dictionary.\nThus, it cannot be updated.\n";
			}
			break;
		case 4:
			cout<<"\n\nOPTION 4: Delete a Word\n";
			cout<<"\nPlease enter the word you would like to delete.\nWord: ";
			cin>>word;
			check = B.searchWord(B.getRoot(), word);
			if(check)
			{
				B.deleteWord(B.getRoot(), word);
				cout<<"\nThe word has been deleted.\n";
			}
			else
			{
				cout<<"\nThis word is not present in the dictionary.\nThus, it cannot be deleted.\n";
			}
			break;
		case 5:
			cout<<"\n\nOPTION 5: Display the Words in Alphabetical Order (A-Z)\n";
			B.displayAsc(B.getRoot());
			break;
		case 6:
			cout<<"\n\nOPTION 6: Display the Words in Alphabetical Order (Z-A)\n";
			B.displayDesc(B.getRoot());
			break;
		case 7:
			cout<<"\n\nOPTION 7: Exit\n";
			cout<<"\nExiting...";
			return 0;
			break;
		default:
			cout<<"\n\nInvalid Option";
			break;
		}
		cout<<"\n\nDo you want to continue? (Y/N)\n";
		cin>>ch;
	}while(ch == 'Y' || ch == 'y');
	return 0;
}
