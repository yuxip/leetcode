//Given a binary tree, return the inorder traversal of its nodes' values.
//For example: Given binary tree {1,#,2,3}
//return [1,3,2].


// Definition for binary tree
//

#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<stack>

using namespace std;

class TreeNode {
	
public:
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	int val;
	TreeNode *left;
	TreeNode *right;

};

vector<int> inorderTraversal( TreeNode *root ){

	vector<int> result;
	if(root==NULL) return result;
	
	stack<TreeNode*> mystack;

	mystack.push(root);
	TreeNode* p = root->left;
	while(!mystack.empty() || p){
		
		while(p){
			mystack.push(p);
			p = p->left;
		}//until p becomes NULL

		p = mystack.top();
		result.push_back(p->val); //visit node
		mystack.pop();
		
		p = p->right;
	}
		
	return result;
}

TreeNode* createTree(char* stree, int nnodes, int inode){
	
	//calculate eff. node index in stree
	int shapes = 0;
	int level = floor(log(inode)/log(2)) + 1;
	for(int i = 1; i < inode/2; i++){ //count number of '#' before its parent
		if(stree[i-1]=='#'){
			int slevel = floor(log(i)/log(2)) + 1;
			if(slevel<level)shapes += pow(2,level-slevel);
		}
	}

	int enode = inode - shapes; //eff. node index (in stree)	
	cout<<"inode = "<<inode<<", enode = "<<enode<<endl;
	if(enode>nnodes) return NULL;
	else if(stree[enode-1]=='#') return NULL;
	else{
		
		//build node
		char c = stree[enode-1];
		int val = isdigit(c) ? c-'0' : 0;
		TreeNode* subt = new TreeNode(val);
		cout<<"inode = "<<inode<<" val = "<<val<<endl;
		//build left child
		TreeNode* lchild = createTree(stree, nnodes, 2*inode);
		subt->left = lchild;
		//build right child
		TreeNode* rchild = createTree(stree, nnodes, 2*inode+1);
		subt->right = rchild;
		
		return subt;
	}
}

int main(){
	
//	const int nnodes = 4;
//	char stree[nnodes] = {'1','#','2','3'};
	const int nnodes = 9;
	char stree[nnodes] = {'1','2','3','#','#','4','#','#','5'};
	if(stree[0]=='#'){
		cout<<"tree root can not be null"<<endl;
		return 0;
	}
	
	//root
	TreeNode* root = createTree(stree, nnodes, 1);
		
	vector<int> result = inorderTraversal(root);	
	for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
		cout<<*it<<' ';
	}
	
	cout<<endl;
	
	return 1;
}
