#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}node_t; 
typedef struct final
{
    int min;
    int max;
    int size;
    int is_bst;
    int ans;
}final_t;
 


 
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                      malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
int min(int x, int y)
{
	if (x<y)
		return x;
	return y;
}

int max(int x,int y)
{
	if (x>y)
		return x;
	return y;

}

final_t largest_bst_util(node_t *root) 
{
	if(root == NULL)
	{
		return {INT_MIN, INT_MAX, 0, true, 0};
	}
	if (!root->left && !root->right)
	{
		return {root->data, root->data, 1, true, 1};
	} 
	final_t lc = largest_bst_util(root->left);
	final_t rc  = largest_bst_util(root->right);
	if (lc.is_bst && rc.is_bst && rc.min > root->data && lc.max < root->data)
	{
		final ret;
		ret.min = min(lc.min, min(root->data, rc.min));
		ret.max = max(lc.max, max(root->data, rc.max));
		ret.size = 1 + lc.size + rc.size;
		ret.is_bst = true;
		ret.ans = ret.size;
		return ret;		
	}
	else
		printf("node %d is not BST\n", root->data);	
	
	final ret ;
	ret.size = 1 + lc.size + rc.size;
	ret.is_bst = false;
	if (lc.is_bst) {
		ret.ans = lc.ans;
	}else if(rc.is_bst) {
		ret.ans = rc.ans;
	} else
		ret.ans = 0;
	return ret;		
}

int largestBST(node_t *root)
{
	final_t info = {0};
	info = largest_bst_util(root);
	return info.ans;

}


/* Driver program to test above functions*/
int main() 
{ 
    /* Let us construct the following Tree 
          50 
       /       \ 
     10         60 
    /  \       /   \ 
   5   20    55      70 
            /  \    /  \ 
          51    52 65    80 
  */
  
  struct node *root = newNode(50); 
  root->left        = newNode(10); 
  root->right       = newNode(60); 
  root->left->left  = newNode(5); 
  root->left->right = newNode(20); 
  root->right->left  = newNode(55); 
  root->right->left->left  = newNode(51); 
  root->right->left->right  = newNode(52); 
  root->right->right = newNode(70); 
  root->right->right->left = newNode(65); 
  root->right->right->right = newNode(80); 
  
  /* The complete tree is not BST as 45 is in right subtree of 50. 
     The following subtree is the largest BST 
        60 
      /  \ 
    55    70 
   /     /  \ 
 45     65    80 
  */
  printf(" Size of the largest BST is %d \n", largestBST(root)); 
  
  getchar(); 
  return 0; 
} 
