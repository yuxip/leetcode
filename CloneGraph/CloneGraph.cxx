//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors./*OJ's undirected graph serialization:
//
//Nodes are labeled uniquely.
//We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//
//As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//    Second node is labeled as 1. Connect node 1 to node 2.
//    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//
//    Visually, the graph looks like the following:
//
//                   1
//                  / \
//                 /   \
//                0 --- 2
//                     / \
//                     \_/
 
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class UndirectedGraphNode {

public:
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x): label(x) {};
};                

map<int, UndirectedGraphNode*> mymap; //store the pointer of already created nodes

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
	
	if(node==NULL) return NULL;

	int label = node->label;
	UndirectedGraphNode* new_node = NULL;
	if(mymap[label]){
		 return mymap[label]; //node already exists, return its location on the heap;
	}
		
	else{
		new_node = new UndirectedGraphNode(label);
		mymap[label] = new_node;
		
		//loop over its neighbors and create them
		for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin(); it != node->neighbors.end(); ++it){
			UndirectedGraphNode* i_neighbor = cloneGraph(*it);
			(new_node->neighbors).push_back(i_neighbor);
		}
	}
	
	return new_node;
}

//Print the labels of node and its neghbors
void PrintLabel(UndirectedGraphNode* node){
	cout<<"node label: "<<node->label<<endl;
	for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin(); it != node->neighbors.end(); ++it){
                cout<<"neghbor of label: "<<node->label<<", label = "<<(*it)->label<<endl;
        }
}
//test
int main(){
	
	//create 0:
	UndirectedGraphNode* node_0 = new UndirectedGraphNode(0);
	
	//create 1:
	UndirectedGraphNode* node_1 = new UndirectedGraphNode(1);
	
	//create 2:
	UndirectedGraphNode* node_2 = new UndirectedGraphNode(2);
		
	node_0->neighbors.push_back(node_1);
	node_0->neighbors.push_back(node_2);
	
	node_1->neighbors.push_back(node_0);
	node_1->neighbors.push_back(node_2);
	
	node_2->neighbors.push_back(node_0);
	node_2->neighbors.push_back(node_1);
	node_2->neighbors.push_back(node_2);
	
	cout<<"after construction"<<endl;
	UndirectedGraphNode* new_node = cloneGraph(node_0);
	if(new_node==NULL){
		cout<<"new_node is NULL"<<endl;
		return 0;
	}
	PrintLabel(new_node);
	for(vector<UndirectedGraphNode*>::iterator it = new_node->neighbors.begin(); it != new_node->neighbors.end(); ++it){
		PrintLabel(*it);
	}	
	
	return 1;
}
                                   
