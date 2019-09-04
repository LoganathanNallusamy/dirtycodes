#include<iostream>
#include<queue>
using namespace std;
// Node for BST/Min-Heap
typedef struct Node
{
    int data;
    Node *left, *right;
}Node;

typedef struct list_node
{
	int data;
	list_node *next;

}list_node;

// Utility function for allocating node for BST
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node * bst_to_list(Node** root, Node **head)
{
	if (*root == NULL)
		return NULL;

	Node *temp = *root;
	bst_to_list(&temp->left, head);

	static Node  *prev = NULL;
	if (prev == NULL)
	{	
	    prev = temp;
	    *head = temp;
	    cout<<"First elements " <<prev->data<<" "; 
	} else {
	    prev->right = temp;
	    cout<<" "<<temp->data; 
	}
	prev = temp;
	bst_to_list(&temp->right, head); 
	return prev;	

}

void bsttoll(Node* root)
{
	Node *list = NULL;
	Node *head = bst_to_list(&root, &list);
	cout<<endl<<"COnversion is done"<<endl;
	while(list != NULL)
	{
		cout<<" "<<list->data<<" ";
		list = list->right;
	}
}

// Utility function to print Min-heap level by level
void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)  return;
 
    // Create an empty queue for level order traversal
    queue<Node *> q;
    q.push(root);
 
    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}


int main()
{

     Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
 
    printLevelOrder(root);

    bsttoll(root);   

}
