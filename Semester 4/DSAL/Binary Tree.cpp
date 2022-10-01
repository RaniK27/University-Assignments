/*Beginning with an empty binary tree, Construct binary tree by inserting the values in the order given.
After constructing a binary tree perform following operations on it-
-Perform in-order, pre-order, and post-order traversal implement both recursive and non-recursive methods)
-Change a tree so that the roles of the left and right pointers are swapped at every node
-Find the height of tree
-Copy this tree to another [operator=]
-Count number of leaves, number of internal nodes.
-Erase all nodes in a binary tree.*/

#include <iostream>
using namespace std;

template <typename T, int size>
class Stack
{
	T *stack;
	int top;

public:
	Stack();
	void pop();
	void push(T const &val);
	T getTop();
	void display();
	bool isEmpty();
};

template <typename T, int size>
Stack<T, size>::Stack()
{
	top = -1;
	stack = new T[size];
}

template <typename T, int size>
void Stack<T, size>::pop()
{
	if (top == -1)
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{
		top--;
	}
}

template <typename T, int size>
bool Stack<T, size>::isEmpty()
{
	return top == -1;
}

template <typename T, int size>
void Stack<T, size>::push(T const &val)
{
	if (top < size - 1)

	{
		top++;
		stack[top] = val;
	}
	else
	{
		cout << "stack overflow" << endl;
		top = -1;
	}
}

template <typename T, int size>
void Stack<T, size>::display()
{
	for (int i = 0; i < top + 1; i++)

	{
		cout << stack[i] << " ";
	}
	cout << endl;
}

template <typename T, int size>
T Stack<T, size>::getTop()
{
	return stack[top];
}

class Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
public:
    Node(int data)
    {
        this->data = data;
    }
    friend class BinaryTree;
};

class BinaryTree
{
    Node *root;
public:
    BinaryTree()
    {
    	root = NULL;
    };
    void create(int data)
    {
        if (root)
        {
            insert(root, data);
        }
        else
        {
            root = new Node(data);
        }
    }

    Node* insert(Node *ptr, int data)
    {
        Node *ptr2;
        if (ptr == NULL)
        {
            ptr2 = new Node(data);
            return ptr2;
        }
        else
        {
            char choice;
            cout<<"\nWould you like to insert the node on the left or right? (L/R)\n";
            cin>>choice;
            if (choice == 'l' or choice == 'L')
            {
                ptr->left = insert(ptr->left, data);
            }
            else
            {
                ptr->right = insert(ptr->right, data);
            }
        }
        return ptr;
    }

    void Rpreorder(Node* ptr)
    {
        if (ptr)
        {
            cout<<ptr->data<<" ";
            Rpreorder(ptr->left);
            Rpreorder(ptr->right);
        }
    }

    void Rpostorder(Node* ptr)
    {
        if(ptr)
        {
            Rpostorder(ptr->left);
            Rpostorder(ptr->right);
            cout<<ptr->data<<" ";
        }
    }

    void Rinorder(Node* ptr)
    {
        if(ptr)
        {
            Rinorder(ptr->left);
            cout<<ptr->data<<" ";
            Rinorder(ptr->right);
        }
    }

    void Inorder()
    {
        Stack<Node*,100> s;
        Node* ptr = getRoot();
        while(ptr || !(s.isEmpty()))
        {
            while(ptr)
            {
                s.push(ptr);
                ptr = ptr->left;
            }
            if(s.isEmpty())
            {
                return ;
            }
            ptr = s.getTop();
            s.pop();
            cout<<ptr->data<<" ";
            ptr = ptr->right;
        }
    }

    void Preorder()
    {
        Stack<Node*,100> s;
        Node* ptr = getRoot();
        while(ptr || !(s.isEmpty()))
        {
            while(ptr)
            {
                cout<<ptr->data<<" ";
                if(ptr->right)
                {
                    s.push(ptr->right);
                }
                ptr = ptr->left;
            }
            if(s.isEmpty())
            {
                return ;
            }
            ptr = s.getTop();
            s.pop();
        }
    }

    void Postorder()
    {
        Node * ptr = getRoot(), *ptr2, *temp = new Node('#');
        Stack<Node*,100> s;
        while(true)
        {
            while(ptr)
            {
                s.push(ptr);
                if(ptr->right)
                {
                    s.push(ptr->right);
                    s.push(temp);
                }
                ptr = ptr->left;
            }
			if(s.isEmpty())
			{
				if(ptr2)
				{
					cout<<ptr2->data<<" ";
					ptr = NULL;
				}
				return;
			}
			else
			{
				ptr2 = s.getTop();
				s.pop();
			}
			while(ptr2 != temp && !(s.isEmpty()))
			{
				cout<<ptr2->data<<" ";
				ptr2 = s.getTop();
				s.pop();
			}
			if(!s.isEmpty())
			{
				ptr = s.getTop();
				s.pop();
			}
        }
    }

    Node* getRoot()
    {
        return root;
    }

    void destroyRecursive(Node* ptr)
    {
        if(ptr)
        {
            destroyRecursive(ptr->right);
            destroyRecursive(ptr->left);
            delete ptr;
        }
    }
    void operator=(const BinaryTree &B)
    {
    	root = copyTree(B.root);
    }
    Node* copyTree(Node* ptr)
    {
        if (ptr == NULL)
        {
            return NULL;
        }
        Node* copy = new Node(ptr->data);
        copy->left = copyTree(ptr->left);
        copy->right = copyTree(ptr->right);
        return copy;
    }
    int treeHeight(Node* ptr)
    {
        if(!ptr)
        {
            return -1;
        }
        int hl = treeHeight(ptr->left);
        int hr = treeHeight(ptr->right);
        if (hl > hr)
            return(hl + 1);
        else
        	return(hr + 1);
    }

    int mirrorTree(Node* ptr)
    {
        if(!ptr)
        {
            return 0;
        }
        int l = mirrorTree(ptr->left);
        int r = mirrorTree(ptr->right);
        Node* temp = ptr->left;
        ptr->left = ptr->right;
        ptr->right = temp;
        return max(l,r) + 1;
    }

    int  leafCount(Node* ptr)
    {
        if(!ptr)
        {
            return 0;
        }
        if(!ptr->left && !ptr->right)
        {
            return 1;
        }
        int l = leafCount(ptr->left);
        int r = leafCount(ptr->right);
        return l + r;
    }

    int nonleafCount(Node* ptr)
    {
       if(ptr == NULL || (ptr->left == NULL && ptr->right == NULL))
       {
          return 0;
       }
       return 1 + nonleafCount(ptr->left) + nonleafCount(ptr->right);
    }

    ~BinaryTree()
    {
        destroyRecursive(getRoot());
    }
};

int main()
{
    BinaryTree B, B1;
    char choice = 'Y', ch = 'Y';
    int value, option1;
    cout<<"Please enter the value for Root Node.\nRoot Node Value: ";
    cin>>value;
    B.create(value);
    while (choice == 'Y' || choice == 'y')
    {
        cout<<"\nWould you like to add another node to the tree? (Y/N)\n";
        cin>>choice;
        if (choice == 'Y' || choice == 'y')
        {
            cout <<"\nPlease enter the value for the node.\nNode Value: ";
            cin>>value;
            B.insert(B.getRoot(), value);
        }
    }
	do
	{
		cout<<"\n\nS.NO.   OPTION\n";
		cout<<" 1.     Traversal of Tree\n";
		cout<<" 2.     Mirror of Tree\n";
		cout<<" 3.     Height of Tree\n";
		cout<<" 4.     Copy Tree\n";
		cout<<" 5.     Count Number of Internal and External Nodes\n";
		cout<<"\nPlease enter an option.\nOption: ";
		cin>>option1;
		switch(option1)
		{
		case 1:
			cout<<"\n\nOPTION 1: Traversal of Tree\n";
			char option2;
			cout<<"\nS.NO.   TRAVERSAL TYPE\n";
			cout<<" A.     In-order Traversal\n";
			cout<<" B.     Pre-order Traversal\n";
			cout<<" C.     Post-order Traversal\n";
			cout<<" D.     Recursive In-order Traversal\n";
			cout<<" E.     Recursive Pre-order Traversal\n";
			cout<<" F.     Recursive Post-order Traversal\n";
			cout<<"\nPlease enter an option.\nOption: ";
			cin>>option2;
			switch(option2)
			{
			case 'A':
				cout<<"\n\nOPTION A: In-order Traversal\n";
				B.Inorder();
				break;
			case 'B':
				cout<<"\n\nOPTION B: Pre-order Traversal\n";
				B.Preorder();
				break;
			case 'C':
				cout<<"\n\nOPTION C: Post-order Traversal\n";
				B.Postorder();
				break;
			case 'D':
				cout<<"\n\nOPTION D: Recursive In-order Traversal\n";
				B.Rinorder(B.getRoot());
				break;
			case 'E':
				cout<<"\n\nOPTION E: Recursive Pre-order Traversal\n";
				B.Rpreorder(B.getRoot());
				break;
			case 'F':
				cout<<"\n\nOPTION F: Recursive Post-order Traversal\n";
				B.Rpostorder(B.getRoot());
				break;
			default:
				cout<<"\n\nInvalid Option";
				break;
			}
			break;
		case 2:
			cout<<"\n\nOPTION 2: Mirror of Tree\n";
			B.mirrorTree(B.getRoot());
			cout<<"\nTree has been mirrored.";
			cout<<"\nRecursive In-order Traversal of Mirrored Tree:\n";
			B.Rinorder(B.getRoot());
			break;
		case 3:
			cout<<"\n\nOPTION 3: Height of Tree\n";
			cout<<"\nHeight of the Tree is: "<<B.treeHeight(B.getRoot());
			break;
		case 4:
			cout<<"\n\nOPTION 4: Copy Tree\n";
			B1 = B;
			cout<<"\nTree has been copied.";
			cout<<"\nRecursive In-order Traversal of Copied Tree:\n";
			B1.Rinorder(B1.getRoot());
			break;
		case 5:
			cout<<"\n\nOPTION 5: Count Number of Internal and External Nodes\n";
			cout<<"\nNumber of Internal Nodes: "<<B.nonleafCount(B.getRoot());
			cout<<"\nNumber of External Nodes: "<<B.leafCount(B.getRoot());
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


