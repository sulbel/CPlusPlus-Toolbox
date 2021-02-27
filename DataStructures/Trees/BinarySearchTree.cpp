#include <iostream>
#include <fstream>

using namespace std;

class BinarySearchTree
{
	private:
		struct node
		{
			node* left;
			node* right;
			int key;
		};
		
	private:
		node* root;
		
	public:
		BinarySearchTree();
		bool isEmpty();
		void insert(int);
		void remove(int);
};

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

bool BinarySearchTree::isEmpty() 
{
	return (root==NULL);
}

void BinarySearchTree::insert(int value)
{
	node* ptr = new node;
	node* parent;
	
	ptr->key = value;
	ptr->left = NULL;
	ptr->right = NULL;
	parent = NULL;
	
	if (isEmpty())
	{
		root = ptr;
	}
	
	else 
	{
		node* pos = root;
		while (pos != NULL)
		{
			parent = pos;
			if (ptr->key < pos->key)
			{
				pos = pos->left;
			}
			
			else if (ptr->key > pos->key)
			{
				pos = pos->right;
			}				
			
			else if (ptr->key == pos->key)
			{
				ptr->left = pos->left;
				ptr->right = NULL;
				pos->left = ptr;
			}
		}
		
		if (ptr->key < parent->key)
		{
			parent->left = ptr;
		}
		
		else if (ptr->key > parent->key)
		{
			parent->right = ptr;
		}
	
	}
	cout << "insert success"<<endl;
	
}

void BinarySearchTree::remove(int value)
{
	if (isEmpty())
	{
		cout << "The tree is already empty" << endl;
		return;
	}
	
	node* position;
	node* parent;
	position = root;
	
	bool found = false;
	while (position != NULL)
	{
		if (position->key == value)
		{
			found = true;
			break;
		}
		
		else 
		{
			parent = position;
			if (value < position->key)
			{
				position = position->left;
			}
			
			else if (value > position->key)
			{
				position = position->right;
			}
		}
	}
	
	if (!found)
	{
		cout << "The value to delete was not found in the tree." << endl;
		return;
	}
	
	if (position->left == NULL && position->right == NULL)
	{
		if(parent->left == position)
		{
			parent->left = NULL;
		}
		
		else 
		{
			parent->right = NULL;
		}
		
		delete position;
		cout << "delete success"<<endl;
		return;
	}
	
	else if ((position->left == NULL && position->right != NULL) || (position->left != NULL && position->right == NULL))
	{
		if (position->left == NULL && position->right != NULL)
		{
			if (parent->left == position)
			{
				parent->left = position->right;
				delete position;
			}
			
			else 
			{
				parent->right = position->right;
				delete position;
			}
		}
		
		else
		{
			if (parent->left == position)
			{
				parent->left = position->left;
				delete position;
			}
			
			else 
			{
				parent->right = position->left;
				delete position;
			}
		}
		cout << "delete success"<<endl;
		
		return;
	}
	
	else if (position->left != NULL && position->right != NULL)
	{
		node* rightroot;
		rightroot = position->right;
		if ((rightroot->left == NULL) && (rightroot->right == NULL))
		{
			position = rightroot;
			delete rightroot;
			position->right = NULL;
		}
		
		else
		{
			if ((position->right)->left != NULL)
			{
				node* rightpos;
				node* rightleft;
				rightpos = position->right;
				rightleft = (position->right)->left;
				
				while (rightleft->left != NULL)
				{
					rightpos = rightleft;
					rightleft = rightleft->left;
				}
				
				position->key = rightleft->key;
				delete rightleft;
				rightpos->left = NULL;
			}
			
			else 
			{
				position->key = rightroot->key;
				position->right = NULL;
				delete rightroot;
			}
		}
		cout << "delete success"<<endl;
		
		return;
	}
}

int main()
{
	BinarySearchTree bst;
	bst.insert(5);
	cout << "5 inserted" <<endl;
	bst.insert(3);
	cout << "3 insert"<<endl;
	bst.insert(9);
	bst.insert(15);
	cout << "9 and 15 insert"<<endl;
	bst.remove(9);
	cout << "isempty returns: " << bst.isEmpty() << endl;
	//cout << "9 deleted"<<endl;
	
	return 0;
}