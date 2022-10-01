//============================================================================
// Name        : Graph.cpp
// Author      : Reet
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
private:
	int vertexNo;
	Node *next;
public:
	Node()
	{
		vertexNo = 0;
		next = NULL;
	}
	Node(int vertexNo)
	{
		this->vertexNo = vertexNo;
		next = NULL;
	}
	friend class Queue;
	friend class Graph;
};

class Queue
{
private:
	Node *front;
	Node *rear;
public:
	Queue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		if(front == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void insertQ(int vertexNo)
	{
		Node *nn = new Node(vertexNo);
		if(front == NULL)
		{
			front = rear = nn;
		}
		else
		{
			rear->next = nn;
			rear = nn;
		}
	}
	int deleteQ()
	{
		if(isEmpty())
		{
			cout<<"\nUnderflow";
			return -1;
		}
		else
		{
			int v;
			Node *nn;
			nn = front;
			v = front->vertexNo;
			front = front->next;
			delete nn;
			return v;
		}
	}
};
class Graph
{
private:
	Node **adjList;
	bool *visited;
	int vCount;
	int eCount;
	void addEdge(int src, int dest)
	{
		Node *nn = new Node(dest);
		nn->next = adjList[src];
		adjList[src] = nn;
	}
	void clearVisited()
	{
		for(int i = 0; i < vCount; i++)
		{
			visited[i] = false;
		}
	}
public:
	Graph(int vCount, int eCount)
	{
		this->vCount = vCount;
		this->eCount = eCount;
		adjList = new Node*[vCount];
		for(int i = 0; i < vCount; i++)
		{
			adjList[i] = NULL;
			visited[i] = false;
		}
	}
	void createGraph()
	{
		int src, dest;
		for(int i = 0; i < vCount; i++)
		{
			cout<<"Please enter the source vertex and destination vertex.\nSource Vertex: ";
			cin>>src;
			cout<<"\nDestination Vertex: ";
			cin>>dest;
			addEdge(src, dest);
			addEdge(dest, src);
		}
	}
	void diplayGraph()
	{
		cout<<"\nGraph: ";
		for(int i = 0; i < vCount; i++)
		{
			if(adjList[i] == NULL)
			{
				cout<<"\nNode "<<i<<" has no connection.";
			}
			else
			{
				cout<<"\nNode "<<i<<" is connected to ";
				Node *temp = adjList[i];
				while(temp != NULL)
				{
					cout<<temp->vertexNo;
					temp = temp->next;
				}
			}
		}
	}
	void dfs(int vertexNo)
	{
		cout<<vertexNo<<" ";
		visited[vertexNo] = true;
		Node *temp = adjList[vertexNo];
		while(temp)
		{
			if(visited[temp->vertexNo])
			{
				dfs(temp->vertexNo);
			}
			temp = temp->next;
		}
	}
	void bfs(int startV)
	{
		clearVisited();
		Queue Q;
		Q.insertQ(startV);
		visited[startV] = true;
		while(!Q.isEmpty())
		{
			int temp = Q.deleteQ();
			cout<<temp<<" ";
			Node *cur = adjList[temp];
			while(cur != NULL)
			{
				if(!visited[cur->vertexNo])
				{
					visited[cur->vertexNo] = true;
					Q.insertQ(cur->vertexNo);
				}
				cur = cur->next;
			}
		}
		clearVisited();
	}
};

int main() {
	int option, vCount, eCount, vertexNo;
	char ch = 'Y';
	cout<<"Please enter the number of vertices and edges.\nVertices: ";
	cin>>vCount;
	cout<<"\nEdges: ";
	cin>>eCount;
	Graph G(vCount, eCount);
	G.createGraph();
	do
	{
		cout<<"\nS.NO.	Option";
		cout<<"\n 1.	DFS";
		cout<<"\n 2.	BFS";
		cout<<"\n 3.	Display Graph";
		cout<<"\n 4.	Exit";
		cout<<"\n\nPlease enter an option.\nOption: ";
		cin>>option;
		switch(option)
		{
		case 1:
			cout<<"\nPlease enter the starting vertex.\nVertex: ";
			cin>>vertexNo;
			G.dfs(vertexNo);
			break;
		case 2:
			cout<<"\nPlease enter the starting vertex.\nVertex: ";
			cin>>vertexNo;
			G.bfs(vertexNo);
			break;
		case 3:
			G.diplayGraph();
			break;
		case 4:
			cout<<"\nExiting...";
			return 0;
			break;
		default:
			cout<<"\nInvalid Option";
			break;
		}
		cout<<"\nDo you want to continue? (Y/N)\n";
	}while(ch == 'Y' || ch == 'y');
	return 0;
}
