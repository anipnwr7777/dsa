#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,int>> top_most_node;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void top_view(Node *root, int horizontal_level, int vertical_level){
	if(root == nullptr)
		return;

	if(top_most_node.count(horizontal_level) == 0){
		top_most_node[horizontal_level] = {vertical_level, root->key};
	}
	else{
		if(top_most_node[horizontal_level].first >= vertical_level){
			top_most_node[horizontal_level] = {vertical_level, root->key};
		}
	}
	
	top_view(root->left, horizontal_level - 1, vertical_level + 1);
	top_view(root->right, horizontal_level + 1, vertical_level + 1);
}

int main(){

	/*
	     root-> 3
			   / \
			  4   5
			 / \ / \
			7  8 10 11   
			    \
			     12
			      \
			      20
	*/

	Node *root = new Node(3);
	root->left = new Node(4);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(10);
	root->right->right = new Node(11);
	root->left->right->right = new Node(12);
	root->left->right->right->right = new Node(20);

	top_view(root, 0, 0);
	for(auto x:top_most_node){
		cout << x.second.second << " ";
	}
	cout << endl;
	
    return 0;
}