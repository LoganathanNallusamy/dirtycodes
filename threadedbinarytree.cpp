#include<iostream>
using namespace std;

typedef struct node
{
   int data;
   struct node *left, *right;
   bool is_right;
}node_t;

node_t  *insert(int data)
{
    node_t *node = (node_t *)calloc(1,sizeof(node_t));
    node->data = data;
    node->left = node->right = NULL;
    node->is_right = false;
    return node;	
}

node_t *insert_element(node_t *node, int data, node_t *prev)
{
	if(node == NULL)
	{
		node = insert(data);
		cout<<"Inserted "<<data;
		if (prev){
		  node->is_right = true;
		  node->right = prev;
		  cout<<"Previous data"<<prev->data<<" "<<endl;
		 }else {
		  cout<<"without previous data"<<endl;
		}
		return node;
	}

	if (data < node->data) {
		prev = node;
		node->left = insert_element(node->left, data, prev);
	}
        else if (data > node->data) {
		cout<<"Right insert with "<<data<<" "<<node->data<<"prev "<<prev->data<<endl;
		if (node->is_right)
		{
			node->right = NULL;
			node->right = insert_element(node->right, data, prev);
		} else
		{
			node->right = insert_element(node->right, data, NULL);

		}

	}

	return node;


}

node_t* leftmost(node_t *n) 
{ 
    if (n == NULL) 
       return NULL; 
  
    while (n->left != NULL) 
        n = n->left; 
  
    return n; 
} 
  
// C code to do inorder traversal in a threaded binary tree 
void inOrder(node_t *root) 
{ 
    node_t *cur = leftmost(root); 
    while (cur != NULL) 
    { 
        printf("%d ", cur->data); 
  
        // If this node is a thread node, then go to 
        // inorder successor 
        if (cur->is_right) 
            cur = cur->right; 
        else // Else go to the leftmost child in right subtree 
            cur = leftmost(cur->right); 
    } 
}

int main()
{
    node *root = NULL;
    root = insert_element(root, 6, NULL);	      	
    root = insert_element(root, 3, NULL);	      	
    root = insert_element(root, 1, NULL);	      	
    root = insert_element(root, 5, NULL);	      	
    root = insert_element(root, 8, NULL);	      	
    root = insert_element(root, 7, NULL);	      	
    root = insert_element(root, 11, NULL);	      	
   
   inOrder(root);		  	 


}
