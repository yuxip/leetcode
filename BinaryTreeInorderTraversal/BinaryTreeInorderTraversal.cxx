//Given a binary tree, return the inorder traversal of its nodes' values.
//For example: Given binary tree {1,#,2,3}
//return [1,3,2].


// Definition for binary tree
//

#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct TreeNode {
	
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNone(int x) : val(x), left(NULL), right(NULL) {}

}TNode;

vector<int> inorderTraversal( TreeNode *root ){

	vector<int> result;
	if(root==NULL) return result;
	
	//inorder traverse the left subtree
	TreeNode* lchild = root->left;
	if(lchild)result = inorderTraversal(lchild);
	//read the current node
	int valnode = root->val;
	//append the current node to lsub
	result.push_back(valnode);
	
	TreeNode* rchild = root->right;
	vector<int> rsub;
	if(rchild)rsub = inorderTreversal(rchild);
	//append rsub to the end of (lsub+valnode)
	result.insert( result.end(), rsub.begin(), rsub.end() );
	
	return result;
}

int main(){
	
	const int nnodes = 4;
	Char_t stree[nnodes] = {'1','#','2','3'};
	if(stree[0]=='#'){
		cout<<"tree root can not be null"<<endl;
		return 0;
	}
	
	//root
	TreeNode* root = new TreeNode(atoi(&stree[0]));
	
	int i = 1;
	while(	
		
		
		
