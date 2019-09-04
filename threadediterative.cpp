

// Insertion in Threaded Binary Search Tree. 
#include<stdio.h>
#include<stdlib.h>

using namespace std; 
  
struct Node 
{ 
    struct Node *left, *right; 
    int info; 
  
    // True if left pointer points to predecessor 
    // in Inorder Traversal 
    bool lthread; 
  
    // True if right pointer points to predecessor 
    // in Inorder Traversal 
    bool rthread; 
}; 
  

// Insert a Node in Binary Threaded Tree 
struct Node *insert(struct Node *root, int ikey) 
{ 
    // Searching for a Node with given value 
    Node *ptr = root; 
    Node *par = NULL; // Parent of key to be inserted

    printf("Insert %d called\n", ikey); 
    while (ptr != NULL) 
    { 
        // If key already exists, return 
        if (ikey == (ptr->info)) 
        { 
            printf("Duplicate Key !\n"); 
            return root; 
        } 
  
        par = ptr; // Update parent pointer 
  
        // Moving on left subtree. 
        if (ikey < ptr->info) 
        { 
            if (ptr -> lthread == false) 
                ptr = ptr -> left; 
            else
                break; 
        } 
  
        // Moving on right subtree. 
        else
        { 
            if (ptr->rthread == false) 
                ptr = ptr -> right; 
            else
                break; 
        } 
    } 
	
    Node *temp = (Node *)calloc(1, sizeof(struct Node));

    temp->info = ikey;  
    temp->left = NULL;
    temp->right = NULL;	
    temp->lthread = temp->rthread = false;
     if (root == NULL )
     {
	printf("root is NULL\n");
	root = temp;
	return root;
     }
     ptr = par;	
    if (ikey < ptr->info) {
	printf("key %d less than %d lthread(%d)\n", ikey, ptr->info, ptr->lthread);
	if (ptr->lthread) {
		Node *tleft = ptr->left;
		ptr->left = temp;
		ptr->lthread = false;
		temp->lthread = true;
		temp->left = tleft;
		temp->rthread = true;
		temp->right = ptr;
		printf("Data %d, predece %d, success %d \n", temp->info, temp->left->info, temp->right->info);

	} else {
		ptr->left = temp;
	        temp->right = ptr;
        	temp->rthread = true;
	}
    } else if (ikey > ptr->info) {
	printf("key %d greater than %d rthread(%d)\n", ikey, ptr->info, ptr->rthread);
	if (ptr->rthread) {
		Node *tright = ptr->right;
		printf(" data %d\n", ptr->right->info);
		ptr->right = temp;
		ptr->rthread = false;
        	temp->rthread = true;
		temp->right = tright;
        	temp->lthread = true;
		temp->left = ptr;
		printf("inorder predece %d\n", ptr->info);	
		printf("Data %d, predece %d, success %d \n", temp->info, temp->left->info, temp->right->info);
		
	} else {
		ptr->right = temp;
		temp->left = ptr;
		temp->lthread = true;
	}
        	  	
   }
   printf("Returning from insert %d\n", root->info);
   return root; 

}

// Returns inorder successor using rthread 
struct Node *inorderSuccessor(struct Node *ptr) 
{ 
    // If rthread is set, we can quickly find 
    if (ptr -> rthread == true) 
        return ptr->right; 
  
    // Else return leftmost child of right subtree 
    ptr = ptr -> right; 
    while (ptr && ptr -> lthread == false) 
        ptr = ptr -> left; 
    return ptr; 
} 
  
// Printing the threaded tree 
void inorder(struct Node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
  
    // Reach leftmost node 
    struct Node *ptr = root, *prev = NULL;
    while (ptr != NULL) 
    {
	prev = ptr;
        ptr = ptr -> left; 
    }
  
    // One by one print successors
    ptr = prev;
     printf("logu %d \n", ptr->info);
    while (ptr != NULL) 
    { 
        printf("logu %d ",ptr -> info); 
        ptr = inorderSuccessor(ptr); 
    } 
   
    #if 0  
    ptr = inorderSuccessor(ptr); 
     printf(" logu %d ",ptr -> info); 
    ptr = inorderSuccessor(ptr); 
     printf(" logu %d ",ptr -> info); 
    ptr = inorderSuccessor(ptr); 
     printf(" logu %d ",ptr -> info); 
    ptr = inorderSuccessor(ptr); 
     printf(" logu %d ",ptr -> info); 
    ptr = inorderSuccessor(ptr); 
     printf(" logu %d ",ptr -> info); 
    ptr = inorderSuccessor(ptr); 
     printf(" logu %d ",ptr -> info); 
    ptr = inorderSuccessor(ptr); 
     printf(" logu %d ",ptr -> info); 
    ptr = inorderSuccessor(ptr);
    if(ptr) 	 
     printf(" logu %d ",ptr -> info); 
    else
	printf("ptr is NULL\n");
    #endif
} 

// Driver Program 
int main() 
{ 
    struct Node *root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 30); 
    root = insert(root, 5); 
    root = insert(root, 16); 
    root = insert(root, 14); 
    root = insert(root, 17); 
    root = insert(root, 13); 
    inorder(root); 
  
    return 0; 
}  
