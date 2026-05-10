#include<iostream>
using namespace std;

struct node
{
	int value;
	node*left;
	node*right;
};
node*  findmin(node*root)
{
	while(root->left!=NULL)root=root->left;
	return root;
}
struct node*deletenode(node*root,int data){
	if(root==NULL)
	{
		return root;
	}
	else if(data<root->value)
	{
		root->left=deletenode(root->left,data);
	}
	else if(data>root->value)
	{
		root->right=deletenode(root->right,data);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
		}
	//case 2
	else if(root->left==NULL)
	{
		node* temp=root;
		root=root->right;
		delete temp;
	}
	else if(root->right==NULL)
	{
		node* temp=root;
		root=root->left;
		delete temp;
	}
	//case 3
	else
	{
		node* temp=findmin(root->right);
		root->value=temp->value;
		root->right=deletenode(root->right,temp->value);
		}
	}
	return root;
}
//previous part
//function to visit nodes in inorder
void inorder(node* root){
	if(root==NULL)return;
	
	
	inorder(root->left);           //visit left subtree
	cout<<root->value<<"\t";       //print data
	inorder(root->right);          //visit right subtree
}
//function to insert node in binary tree
node* insert(node* root,char data){
	if(root==NULL){
		root=new node();
		root->value=data;
		root->left=root->right=NULL;
	}
	else if(data<=root->value)
	root->left=insert(root->left,data);
	else
	root->right=insert(root->right,data);
	return root;
}

int main(){
	node* root=NULL;
	root=insert(root,6);
	root=insert(root,11);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,2);
	root=insert(root,12);
	//print nodes in inorder
	cout<<"inorder: ";
	inorder(root);
	cout<<"\n";
	//deleting node with value 6,change this value to test other
	root=deletenode(root,6);
	//print nodes
	cout<<"inorder: ";
	inorder(root);
	cout<<"\n";
}
