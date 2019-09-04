#include<iostream>
#include<string>
using namespace std;

/* A binary tree node has data, pointer to left 
   child and a pointer to right child */
typedef struct Node { 
    int data; 
    Node *left, *right; 
}node ; 

node *get_node(int n1)
{
      node *n = new node;
      n->data = n1;
      n->left = n->right = NULL;
      return n;	
}

void in_order(node *root)
{
     if (!root) return;

     in_order(root->left);
     cout<<root->data<<" ";
     in_order(root->right);       
}

void post_order(node *root)
{
     if (!root) return;
     post_order(root->left);
     post_order(root->right);       
     cout<<root->data<<" ";

}




int k = 0; 
int search(int in[], int data, int st, int end)
{
	for(int i = st; i <= end; ++i)
	{
	     if(in[i] == data) return i;

	}
	cout<<data<<" not found on tree with len = "<<end<<endl;
	return -1;

}


node *buildTree(int in[], int post[], int st, int end)
{
      static int post_index = end;
      cout<<"Build tree with st= "<<st<<" end= "<<end<<" "<<endl;	       	     
      if (st > end ) return NULL; 

      node *new_node  = get_node(post[post_index]);
      --post_index;
 
      cout<<"Adding the new node "<<new_node->data<<endl;      	 
      if (st == end) return new_node; 	 	
      int in_index = search(in, new_node->data, st, end);
      if(in_index == -1) return NULL;
	
      new_node->right = buildTree(in, post, in_index + 1, end);			
      new_node->left = buildTree(in, post, st,in_index - 1 );
      return new_node;	

}

 
void preOrder(node *root)
{
	if(!root) return;
	
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

// Driver code 
int main() 
{ 
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
    int n = sizeof(in) / sizeof(in[0]); 
    k = n;
    node* root = buildTree(in, post,0, n-1); 
    cout << "In order of the constructed tree : \n"; 
    in_order(root); 
    cout << "Post order of the constructed tree : \n"; 
    post_order(root); 
    return 0; 
} 

