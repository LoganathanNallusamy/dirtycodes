#include<iostream>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};
 
// Create and return a pointer of new Node.
Node *createNode(int x)
{
    Node *p = new Node;
    p -> data = x;
    p -> left = p -> right = NULL;
    return p;
}
 
// Insert a new Node in Binary Search Tree.
void insertNode(struct Node *root, int x)
{
    Node *p = root, *q = NULL;
 
    while (p != NULL)
    {
        q = p;
        if (p -> data < x)
            p = p -> right;
        else
            p = p -> left;
    }
 
    if (q == NULL)
        p = createNode(x);
    else
    {
        if (q -> data < x)
            q -> right = createNode(x);
        else
            q -> left = createNode(x);
    }
}
int find_element(struct Node *root, int a)
{
         if (root == NULL)
		return -1;
	 if (root->data == a)
		return 1;

	 int lc =-1, rc =-1;
	 if (a < root->data)
	     lc = find_element(root->left, a);			
         else if (a > root->data)
	    rc = find_element(root->right, a);
	 if (lc == -1)
	    lc = 0;
         if (rc == -1)
	    rc = 0;
	 if (lc == rc)
	     return 0;
	 else
	     return (lc > rc ? lc+1: rc + 1 );	 	  

}
int max_val(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int max_element_util(struct Node *root, int a, int b)
{
	if (root == NULL)
		return -1;
	int lc = -1, rc =-1;
	if (a < root->data && b < root->data)
	lc =	max_element_util(root->left, a, b);
	else if (a > root->data && b > root->data)
	rc =	max_element_util(root->right, a, b); 

	if (lc == -1 && rc == -1 ) {
		
	cout<<"\nFinding length at"<< root->data<<endl;
	int left = find_element(root, a);
	cout<<"\nDistance btw "<<root->data<<"and"<<a<<" "<<left<<endl;
	int right = find_element(root, b);
	cout<<"\nDistance btw "<<root->data<<"and"<<b<<" "<<right<<endl;
	
	int max = left+ right - 1;
	cout<<"Distance bet "<<a<<"and "<<b<<" is"<<max<<endl;
	return max_val(max_val(lc,rc), max);
	} else if (rc == -1 )
	{
		return lc;
	} else
		return rc;
}

void max_element(struct Node *root, int a, int b)
{
   
     cout<<"Max element bet "<<a<<" and "<<b<<" is "<<max_element_util(root, a, b)<<endl;	 

}
 
int main()
{
    int arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 };
    int a = 10, b = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Creating the root of Binary Search Tree
    struct Node *root = createNode(arr[0]);
 
    // Inserting Nodes in Binary Search Tree
    for (int i = 1; i < n; i++)
        insertNode(root, arr[i]);

    max_element(root, a, b);		
    return 0;
}
