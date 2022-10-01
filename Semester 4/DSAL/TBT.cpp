//============================================================================
// Name        : TBT.cpp
// Author      : Reet
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
	int data;
	bool lbit;
	bool rbit;
	Node *left;
	Node *right;
public:
	Node()
	{
		data = 0;
		lbit = rbit = false
	}
	friend class Queue;
	friend class TBT;
};

class Queue
{
	int front;
	int rear;
	int size;
	Node **Q;
public:
	Queue()
    {
		front = rear = -1;
		size = 10;
		Q = new Node *[size];
    }
	Queue(int size)
	{
		front = rear = -1;
		this->size = size;
		Q = new Node *[size];
	}
	void insertQ(Node*);
	Node *deleteQ();
	int isEmpty();
};

void Queue::insertQ(Node *ptr)
{
	if(rear == size + 1)
	{
		cout<<"\nQueue is full.";
	}
	else
	{
		rear++;
		Q[rear] = ptr;
	}
}

Node * Queue::deleteQ()
{
	Node *ptr = NULL;
	if(front == NULL)
	{
		cout<<"\nQueue is empty.";
	}
	else
	{
		ptr = Q[front + 1];
		front++;
	}
	return ptr;
}

int Queue::isEmpty()
{
	if(front == NULL)
	return -1;
}

class TBT
{
	Node *header;
public:
	TBT()
    {
		header = NULL;
    }
	void createTBT();
	void inorder(Node *);
	void prorder(Node *);
};

void TBT::createTBT()
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
