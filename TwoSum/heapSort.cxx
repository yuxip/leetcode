//implement heap sort
#include<vector>
void heapAdjust( std::vector<int>& inlist, int s, int m){

	//the elements between [s+1,m] is a complete binary
	//tree, now re-arrange [s,m] such that [s,m] is a 
	//complete binary tree, with the largest element on the top
	
	int rc = inlist[s];
	for(int j = 2*s; j <= m; j*=2){	//go to the daughter(s) of the current node
		if( j<m && inlist[j] < inlist[j+1] ) j++; //following the larger daughter	
		if( rc >= inlist[j] ) break; //stop searching
		
		//other wise go to the larger daughter and keep searching
		inlist[s] = inlist[j]; s = j;
	}
	
	//rc should be inserted to s;
	inlist[s] = rc;	

}


void heapSort( std::vector<int>& inlist ){

	//inlist index starts from 0
	//construct the master heap on all elements in inlist
	//starting from the last non-terminal(non-leaf) node
	for(int i = (inlist.size()-1)/2; i >= 0; --i) heapAdjust(inlist,i,inlist.size()-1);

	for(int i = inlist.size()-1; i > 0; --i){
		//swap the heap top(maximum elements among those still in the heap) with
		//the last element of the unsorted list (0,i-1)

		inlist[0] ^= inlist[i];
		inlist[i] ^= inlist[0];
		inlist[0] ^= inlist[i];
		
		heapAdjust(inlist,0,i-1); //re-arrange the remaining heap so that it becomes a complete binary tree
	}
	
	
}

#include<fstream>
#include<iostream>
int main(){


        std::fstream input("in2.txt",std::ios::in);
        std::vector<int> test(282);
        int i = 1;
        while(i<=282){
                input>>test[i-1];
                i++;
        }
	
	heapSort(test);
	
//	std::cout<<"after heap sort: "<<std::endl;
//	for(int i = 0; i < 282; i++)std::cout<<test[i]<<std::endl;
	
	return 1;
}
