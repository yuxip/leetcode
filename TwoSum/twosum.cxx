//Given an array of integers, find two numbers such that they add up to a specific target number.

//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

//You may assume that each input would have exactly one solution.

//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2 

//quick sort the array 'numbers' O(nlog(n)), then search in the region < target (in 2 parts,
//(min, target/2) and (target/2, max) 

#include <vector>
#include <iostream>

typedef struct{
	int pos;
	int value;
}mypair;


//quick sort -- Partition, update pivot position

int Partition( std::vector<mypair>& sqlist, int low, int high ){

	int pivot_value = sqlist[low].value; //first element in range serve as pivot
	int pivot_pos = sqlist[low].pos;
	while( low < high ){
		
		while(low < high && sqlist[high].value >= pivot_value) --high;
		//swap element [high] and pivot (already saved)
		sqlist[low].pos = sqlist[high].pos;
		sqlist[low].value = sqlist[high].value;
		while(low < high && sqlist[low].value <= pivot_value) ++low;
		sqlist[high].pos = sqlist[low].pos;
		sqlist[high].value = sqlist[low].value;
	}
	
	//fill in pivot 
	sqlist[low].value = pivot_value;
	sqlist[low].pos = pivot_pos;

	return low;
}

//partion --> QSort, recursively
void QSort( std::vector<mypair>& sqlist, int low, int high ){ 	
	
	if(low < high){
		int pivotloc = Partition(sqlist, low, high);
		QSort(sqlist,low,pivotloc-1);
		QSort(sqlist,pivotloc+1,high);
	}
	//else do nothing
}

void QuickSort( std::vector<mypair>& sqlist ){
	
	QSort(sqlist,0,sqlist.size()-1);
	
}

//find target in a sorted list vector<mypair>. If it doesn't exist return the inertion location
int locate( std::vector<mypair>& sqlist, int low, int high, int target ){

        while(low < high){

                int m = (low + high)/2;
                if(target>sqlist[m].value){     
                        low = m+1;
                }
                else{ 
                        high = m-1;
                }
        }
	
	if(target==sqlist[high].value) return high;	
	else return high + 1;

}

std::vector<int> twoSum(std::vector<int> &numbers, int target) {

	std::vector<mypair> sqlist;
	for(int i = 0; i < numbers.size(); i++){
		mypair mp;
		mp.pos = i;
		mp.value = numbers[i];
		sqlist.push_back(mp);
	}
	
	QuickSort(sqlist);
	
	int low = 0;
	int high = sqlist.size() - 1;
	int loc = locate(sqlist,low,high,target);	

	std::vector<int> idx(2);
        for(int it1 = 0; it1 < loc; it1++){
                int tid2 = target - sqlist[it1].value;
		int tid2loc = locate(sqlist,it1,loc,tid2);
                if(sqlist[tid2loc].value==tid2){
			idx[0] = sqlist[it1].pos+1;
			idx[1] = sqlist[tid2loc].pos+1;
                        break;
                }
        }
	
	if(idx[0]>idx[1]){
		int tmp = idx[0];
		idx[0] = idx[1];
		idx[1] = tmp;
	}
        return idx;
	
	
}

#include<fstream>
int main(){
	
	
	std::fstream input("in.txt",std::ios::in);
	std::vector<int> test(16023);
	int i = 1;
	while(i<=16023){
		input>>test[i-1];
		i++;
	}
	twoSum(test,16021);
	
	return 1;
}