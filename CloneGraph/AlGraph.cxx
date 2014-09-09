//implement adjacency list for graph structure
//and depth first / breath first traversal

const int MAX_VERTEX_NUM = 20;

#include<cstdlib>

class ArcNode {   //edges

public:
	ArcNode() { adjvex = -1; nextarc = NULL; label = -9999; };	
	int adjvex;	//the other end of the edge
	ArcNode* nextarc; //next edge (with the common head node)
	int label;
};

class VNode { //head node --> to form a static array

public:	
	VNode() { label = -9999; firstarc = NULL; };
	int label;
	ArcNode* firstarc; //first edge in linked list
};

#include<list>
#include<iostream>
#include<set>
#include<cmath>

class AlGraph{
	
public:
	AlGraph() {};
	VNode vertices[MAX_VERTEX_NUM];
	int vexnum, arcnum; //number of nodes and edges;
	
	//build graph by interpreting a serialize graph sgraph (e.g = {'0','1','2','#','1','2','#','2','2'}, characters represent the (unique) label of each node, index of sgraph represents rel. position of each node in the graph)
	int createAlGraph( std::list<char> sgraph );
	
	//depth first traverse
	//void DFSTraverse( int (*visit)(int v) ); //call (*visit)() with argument v for each node during DFS traversal 	

	//bool visited[MAX_VERTEX_NUM]; //flags for graph traversal

private:
	
	//DFS(int v); //helper function for DFSTraverse; depth-first visit the vth node of the current graph
	
};

//read serialized graph sgraph and build a undirected graph by implementing adjacency list
int AlGraph::createAlGraph( std::list<char> sgraph ){
	
	//make sure the number of nodes is less than or equal to MAX_VERTEX_NUM
	std::set<char> labels;
	for(std::list<char>::iterator it = sgraph.begin(); it != sgraph.end(); it++){
		if((*it)!='#') labels.insert(*it);	
	}
	
	int nnodes = labels.size();
	std::cout<<"total number of nodes = "<<nnodes<<std::endl;
	
	vexnum = nnodes;

	//construct nodes
	int inode = 0;
	for(std::set<char>::iterator it=labels.begin(); it!=labels.end(); ++it){
		
		vertices[inode].label = isdigit(*it) ? (*it) - '0' : -9999;
		vertices[inode].firstarc = NULL;
		inode++;
	}//vertices[] follow the same order as labels
	
	ArcNode* prenode = NULL;
	inode = -1;
	arcnum = 0;
	std::list<char>::iterator it = sgraph.begin();	
	while(it!=sgraph.end()){

		for(int jnode = 0; jnode < nnodes; jnode++){

			int itlabel = isdigit(*it) ? (*it) - '0' : -9999;
			if(vertices[jnode].label == itlabel){
				inode = jnode;
				break;
			}	
		}
		
		if(inode == -1){
			std::cout<<"did not find head node for it = "<<(*it)<<std::endl;
			return -1;
		}
		//current head node is vertices[inode]	
		
		prenode = NULL;

		it++;
		while((*it)!='#'&&it!=sgraph.end()){	//neighbors

			//append edges as linked list
			ArcNode* edge = new ArcNode();
			int itlabel = isdigit(*it) ? (*it) - '0' : -9999;
			edge->label = itlabel;

			//search for the node index in the head node array
			int adjverx = -1;
			for(int jnode = 0; jnode < nnodes; jnode++){
				int tmplabel = vertices[jnode].label;
				if(tmplabel==itlabel){
					adjverx = jnode;						
					break;
				}
			}
			if(adjverx == -1){
				std::cout<<"did not find adjverx for node it = "<<(*it)<<std::endl;
				return -1;
			}
							
			edge->adjvex = adjverx;

			if(prenode == NULL){	//first edge following head node
				vertices[inode].firstarc = edge;
				prenode = edge;
				arcnum++;
			}
			else{
				prenode->nextarc = edge;
				arcnum++;
			}
			
			prenode = edge;
			it++;
		}//while, it can be '#' or sgraph.end()

			
		//(*it) == '#', switch to new head node
		if(prenode == NULL)vertices[inode].firstarc = NULL;	//empty edge list						
		else prenode->nextarc = NULL;
		
		//(*it) == '#', loop over the edge list of PREVIOUS head nodes to see if the current head node exists
		//if so, add this head node to the edge list of current head node
		for(int jnode = 0; jnode < inode; jnode++){
			if(vertices[jnode].firstarc == NULL)continue;
			ArcNode* jarc = vertices[jnode].firstarc;
			while(jarc){
				if(jarc->label == vertices[inode].label){
					ArcNode* edge = new ArcNode();
					edge->label = vertices[jnode].label;
					edge->adjvex = jnode;
					if(prenode) prenode->nextarc = edge;
					else vertices[inode].firstarc = edge;
					prenode = edge;
					arcnum++;
					break;
				}
				
				jarc = jarc->nextarc; 
			}
		}
		
		if(it==sgraph.end())break;
		else it++;
	}//outter while, it++ by the for loop, skip '#'
	
	arcnum /= 2.0;
	std::cout<<"arcnum == "<<arcnum<<std::endl;
	//check the created AlGraph
	std::cout<<"vexnum = "<<vexnum<<", arcnum = "<<ceil(arcnum)<<std::endl;
	for(int jnode = 0; jnode < nnodes; jnode++){
		
		int label = vertices[jnode].label;
		std::cout<<"head node "<<label<<" --> ";
		ArcNode* jarc = vertices[jnode].firstarc;
		while(jarc){
			std::cout<<jarc->label<<" --> ";	//adjacency list of the current head node
			jarc = jarc->nextarc;
		}
		std::cout<<" NULL"<<std::endl;
	}
	

	return 1;
}			
	

int main(){
	
	char sgc[9] = {'0','1','2','#','1','2','#','2','2'};
	std::list<char> sgraph;
	for(int i = 0; i < 9; i++)sgraph.push_back(sgc[i]);
	
	AlGraph* ag = new AlGraph();
	ag->createAlGraph(sgraph);
	
	return 1;
}
