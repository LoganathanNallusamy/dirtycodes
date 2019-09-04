#include<iostream>
#include<string>
#include<queue>
using namespace std;

enum  colour {
 RED = 1,
 BLACK = 2	
};

typedef struct node{
 
       int data;
       bool color;
       struct node *left, *right, *parent;
}node;

void level_order(node *root)
{
     if (!root) return;

     queue<node *> q;
     q.push(root);
  
     while(!q.empty()) {

	node *pop = q.front();
	q.pop();
        if(pop->left) {
	    q.push(pop->left);
        }
        if(pop->right) {
	    q.push(pop->right);
        }
	string s = "RED";
        if (pop->color == BLACK)
                s= "BLACK";       
	cout<<" "<<pop->data << "=>"<< s << " ";
     } 
     cout<<endl;	
	
}

node *insert_node(node *root, node *pt)
{
    if (!root) {
       return pt;
    }

    if (pt->data < root->data) {
	root->left = insert_node(root->left, pt);
	root->left->parent = root;
    } else if (pt->data > root->data) {
	root->right = insert_node(root->right, pt);
	root->right->parent = root;
    } else {
	cout<<"Duplicate element: "<<pt->data<<endl;
    }
    return root;	
}

void
rightrotate(node *&root, node *&pt) {

    node *left  = pt->left;
    node *parent = pt->parent;


    left->parent = parent;
    if (parent)
    { 
        if (parent->right == pt) 
		parent->right = left;
	else
		parent->left = left;
    } else 
	root = left;

    node *right = left->right;

    left->right = pt;
    pt->parent = left;
    pt->left = right;
    if(right) 	
	right->parent = pt;
}


void
leftrotate(node *&root, node *&pt)
{
    node *parent = pt->parent;
    node *right = pt->right;
        		
    pt->right = right->left;
    if(right->left)
	right->left->parent = pt;
     
    if(parent) {
	if(parent->left == pt)
		parent->left = right;
	else
		parent->right = right;
    } else
	root = right;
 
    right->left = pt;
    pt->parent = right;     
}


void fixViolation(node *&root, node *&pt)
{
    node *parent = NULL;
    node *g_parent = NULL;

    while(pt->parent != NULL && pt->parent->color == RED) {

	    parent = pt->parent;
	    g_parent = parent->parent;
	// if parent is on left side of gparent then focus on left
	if ( g_parent->left == parent) {

	    node *uncle = g_parent->right;

	    if (uncle != NULL && uncle->color == RED) {
                uncle->color = BLACK;
		parent->color = BLACK;
		g_parent->color = RED;
		pt = g_parent; // switch the pt to g_parent 
            } else {

	        if (parent->right == pt) {
		    leftrotate(root, parent);
		    pt = parent;
		    parent = pt->parent;	
		
		}	
                rightrotate(root, g_parent);
	        swap(g_parent->color, parent->color);
		pt = parent;		
            } 		
	// if parent is on right side of gparent then focus on left
        } else  {

	     node *uncle = g_parent->left;
	     if (uncle != NULL &&
		uncle->color == RED) {
		uncle->color = BLACK;
		parent->color = BLACK;
		g_parent->color = RED;
		pt = g_parent; // switch the pt to g_parent 
	     } else {

	        if (parent->left == pt) {
			rightrotate(root, parent);
			pt = parent;
			parent  = pt->parent;
		} 	

		leftrotate(root, g_parent);
	        swap(g_parent->color, parent->color);
		pt = parent;		
	     }     	

        }	

    }

    root->color = BLACK;

}


node *insert(node *root1, int data)
{
    node *pt = new node();
    pt->data = data;
    pt->left = pt->right = pt->parent = NULL;
    pt->color = RED; 
    node *root = insert_node(root1, pt);
    fixViolation(root, pt); 
    return root;	
}



int main()
{
	
    node *root = NULL;
    root = insert(root, 10);
    level_order(root);	
    root = insert(root, 20);
    level_order(root);	
    root = insert(root, -10);
    level_order(root);	
    root = insert(root, 15);
    level_order(root);	
    root = insert(root, 17);
    level_order(root);	
    root = insert(root, 40);
    level_order(root);	
    root = insert(root, 50);
    level_order(root);	
    root = insert(root, 60);
     
    level_order(root);
}
