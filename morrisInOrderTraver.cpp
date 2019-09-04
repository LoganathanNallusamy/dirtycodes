#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree tNode has data, pointer to left child 
   and a pointer to right child */
struct tNode { 
    int data; 
    struct tNode* left; 
    struct tNode* right; 
}; 

void MorrisTraversal(struct tNode* root)
{
   struct tNode *current = root;
 
   while (current != NULL)
   {
	if (current->left == NULL )
	{
		printf("  %d ", current->data);
		current = current->right;
	} else {
		struct tNode *left = current->left;
		//find the inorder predecessor for current and make the link to it.
		// while making the link,   do not print the data.
		// while breaking the link, print the data   
		while(left->right != current &&
			left->right != NULL) {
		       	left = left->right; 		
		}
		if (left->right) 
		{
			left->right = NULL;
			printf(" %d ", current->data);
			current = current->right;				
	
		} else {
		     left->right = current;
	             current = current->left;		 
		}		
	}
   }	



}
  
/* Helper function that allocates a new tNode with the 
   given data and NULL left and right pointers. */
struct tNode* newtNode(int data) 
{ 
    struct tNode* node = new tNode; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
/* Driver program to test above functions*/

int main() 
{ 
  
    /* Constructed binary tree is 
            1 
          /   \ 
        2      3 
      /  \ 
    4     5 
  */
    struct tNode* root = newtNode(1); 
    root->left = newtNode(2); 
    root->right = newtNode(3); 
    root->left->left = newtNode(4); 
    root->left->right = newtNode(5); 
  
    MorrisTraversal(root); 
  
    return 0; 
} 


