//Given an array of integers, find two numbers such that they add up to a specific target number.

//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

//You may assume that each input would have exactly one solution.

//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2 

//quick sort the array 'numbers' O(nlog(n)), then search in the region < target (in 2 parts,
//(min, target/2) and (target/2, max) 

#include <vector>
#include <map>
#include <iostream>

//quick sort -- Partition, update pivot position
int Partition( std::vector<int>& sqlist, int low, int high ){

	int pivot_value = sqlist[low]; //first element in range serve as pivot
	while( low < high ){
		
		while(low < high && sqlist[high] >= pivot_value) --high;
		//swap element [high] and pivot (already saved)
		sqlist[low] = sqlist[high];
		while(low < high && sqlist[low] <= pivot_value) ++low;
		sqlist[high] = sqlist[low];
	}
	
	//fill in pivot 
	sqlist[low] = pivot_value;

	return low;
}

//partion --> QSort, recursively
void QSort( std::vector<int>& sqlist, int low, int high ){ 	
	
	if(low < high){
		int pivotloc = Partition(sqlist, low, high);
		QSort(sqlist,low,pivotloc-1);
		QSort(sqlist,pivotloc+1,high);
	}
	//else do nothing
}

void QuickSort( std::vector<int>& sqlist ){
	
	QSort(sqlist,0,sqlist.size()-1);
	
}


//std::vector<int> twoSum(std::vector<int> &numbers, int target) {
void twoSum(std::vector<int> &numbers, int target) {

	//build a map to record the element's initial position at the same time
	std::map<int,int> mymap;
	for(int i = 0; i < numbers.size(); i++)mymap[i] = numbers[i]; //i->key
	QucikSort(mymap);
	
	/*
	//find proper location of target by using binary search
	int low = 0;
	int high = numbers.size()-1;
	while(low < high){
		
		int m = (low + high)/2;
		if(target>numbers[m]){	//target is in upper half 
			low = m+1;
		}
		else{ //target is in lower half
			high = m-1;
		}
	}
	
	//insertion point is high + 1
	//search range (0 high)
	std::cout<<"search range (0, "<<high<<") "<<std::endl;
	*/
	
}


int main(){
	
	int myints[5] = {22,11,15,7,2};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	twoSum(fifth,33);
	
/*	QuickSort(fifth);
	std::cout<<"after quick sorting" <<std::endl;
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)std::cout << *it << ' ';
        std::cout << '\n';*/
	return 1;
}
