#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct Tree {
	int x;
	struct Tree *left;
	struct Tree *right;
	Tree(int x) :x(x),left(NULL),right(NULL) {

	}
};

string serialise(Tree *root) {
	if (!root) {
		return "#";
	}

	return (to_string(root->x)+","+serialise(root->left)+","+serialise(root->right));

}
int main() {

	string s;
	Tree *root = new Tree(1);

	root->left = new Tree(2);
	root->right = new Tree(3);

	root->right->left = new Tree(4);	
	root->right->right = new Tree(5);

	string str = serialise(root);
	cout<<"String is "<<str<<endl;	
	return 0;

}


