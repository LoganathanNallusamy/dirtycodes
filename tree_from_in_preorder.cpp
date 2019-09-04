#include<iostream>
#include<string>
using namespace std;

/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node { 
    char data; 
    struct node* left; 
    struct node* right; 
}node; 

void printInorder(node *root) 
{
	if (!root) return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}
node *get_node(char data)
{
	node *n = new node;
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int search(char in[], int st, int end, char s)
{
	for(int i = st; i <=end; ++i)
	{
		if(s == in[i])
		    return i;
	}
	cout<<"Search for the element "<<s<<" is not found"<<endl;
	return -1;
}


node *buildTree(char in[], char pre[], int st_in, int end_in)
{
	static int pre_index = 0;	
	if (st_in > end_in)	return NULL;		
	cout<<"Creating node for "<< pre[pre_index]<<"with start "<<st_in<<" end "<<end_in<<endl;	
	node *new_node = get_node(pre[pre_index++]);
	
	if(st_in == end_in)	return new_node;

	int index = search(in, st_in, end_in, new_node->data);
	if (index == -1 )
		return NULL;
	
	new_node->left = buildTree(in, pre, st_in, index -1);	
	new_node->right = buildTree(in, pre, index + 1, end_in);
	return new_node;	
}

/* Driver program to test above functions */
int main() 
{ 
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
    node* root = buildTree(in, pre, 0, len - 1); 
  
    /* Let us test the built tree by printing Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n"); 
    printInorder(root);
    return 0; 
} 
