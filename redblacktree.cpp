#include<iostream>
#include<string>

enum Color {RED, BLACK}; 
typedef struct Tree
{
   int data;
   bool color;
   struct Tree *left, *right, *parent;
 
   Tree(int d) {
      data = d;
      color = RED;
      left = right = parent = NULL; 
   }
}Tree;

Tree *bst_insert(Tree *root, Tree *data)
{
   if (!root) return data;

   if(data->data < root->data) {
       root->left = bst_insert(root->left, data);
       root->left->parent = root;
   } else if (data->data > root->data) {
       root->right = bst_insert(root->right, data);
       root->right->parent = root;
   }
   return root;  
}

void fixViolation(Tree *&root, Tree *&pt)
{
    Tree *parent = NULL;
    Tree *g_par  = NULL;

    while(root != pt && pt->color != BLACK &&
                         pt->parent->color == RED) {
          
         parent = pt->parent;
         g_par = parent->parent;
         if (g_par->left == parent) {
             Tree *uncle = g_par->right;

             if (uncle != NULL && 
                 uncle->color == RED ) {
             // case 1:
                 //fix the coloring            
                 parent->color = BLACK;
                 uncle->color  = BLACK;
                 g_par->color  = RED;
                 pt = g_par;
             } else {

             // case 2: 
                // uncle is absent or color is black
         	if (parent->right == pt) {
			//leftRotate(root, parent);
			pt = parent;
			parent = pt->parent;
                }        

	        //rotateright(root, g_par);
		//swap(parent->colo, g_par->color);
		pt = parent;  	 
             }
                 
 
         } else {
             Tree *uncle = g_par->left;
          
             if (uncle != NULL && uncle->color == RED) {
             // case 3:
                  // fix the coloring
                 parent->color = BLACK;
                 uncle->color  = BLACK;
                 g_par->color  = RED;
                 pt = g_par;

             } else {
             // case 4:  uncle is absent or color is black
		 if (parent->left == pt) {
               //       rightrotate(root,parent);
                      pt = parent;
                      parent = pt->parent;
                 }

		  //leftrotate(root,g_par);
		  //swap(parent->color, g_par->color);
		  pt = parent; 
             }


         }   

    }
    root->color = BLACK;


}
Tree *insert(Tree *root, int data)
{
      Tree *pt = new Tree(data);
      root =  bst_insert(root, pt);       
      fixViolation(root, pt); 
      return root; 
}

int main()
{
   
 Tree *root = NULL;
 root = insert(root, 7); 



}

