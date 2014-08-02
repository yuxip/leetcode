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

int Partition( std::vector<mypair>& sqlist, int low, int high, bool& lowmoved, bool& highmoved){

	lowmoved = false;
	highmoved = false;
	
	int mid = (low+high)/2;
	int pivot = -1;
	if(sqlist[low].value > sqlist[high].value){
		if(sqlist[low].value < sqlist[mid].value) pivot = low;
		else if(sqlist[high].value > sqlist[mid].value) pivot = high;
		else pivot = mid;
	}
	else if(sqlist[low].value > sqlist[mid].value) pivot = low;
	else{
		if(sqlist[high].value > sqlist[mid].value) pivot = mid;
		else pivot = high;
	}
	
	if(pivot!=low){
		int tmp_value = sqlist[low].value;
		sqlist[low].value = sqlist[pivot].value;
		sqlist[pivot].value = tmp_value;
		int tmp_pos = sqlist[low].pos;	
		sqlist[low].pos = sqlist[pivot].pos;
                sqlist[pivot].pos = tmp_pos;
	}

	int pivot_value = sqlist[low].value;
	int pivot_pos = sqlist[low].pos;
	while( low < high ){
		
		while(low < high && sqlist[high].value >= pivot_value){
			if(sqlist[high].value < sqlist[high-1].value && high > low+1)highmoved=true;
			--high;
		}
		sqlist[low].pos = sqlist[high].pos;
		sqlist[low].value = sqlist[high].value;
		while(low < high && sqlist[low].value <= pivot_value){
			if(sqlist[low].value > sqlist[low+1].value && low < high-1)lowmoved=true;
			++low;
		}
		sqlist[high].pos = sqlist[low].pos;
		sqlist[high].value = sqlist[low].value;
	}
	
	sqlist[low].value = pivot_value;
	sqlist[low].pos = pivot_pos;

	return low;
}

//partion --> QSort, recursively
//return bool variable indicating if any element has been moved during Partition()
void QSort( std::vector<mypair>& sqlist, int low, int high ){ 	
	
	if(low < high){
		bool lowmoved = false;
		bool highmoved = false;
		int pivotloc = Partition(sqlist, low, high, lowmoved, highmoved);
		if(lowmoved)QSort(sqlist,low,pivotloc-1);
		if(highmoved)QSort(sqlist,pivotloc+1,high);
	}
}

void QuickSort( std::vector<mypair>& sqlist ){
	
	QSort(sqlist,0,sqlist.size()-1);
	
}

//return the insertion location of target
int locateInsert( std::vector<mypair>& sqlist, int low, int high, int target ){

        while(low < high){

                int m = (low + high)/2;
                if(target>sqlist[m].value){     
                        low = m+1;
                }
                else{ 
                        high = m-1;
                }
        }
	
	if(sqlist[high+1].value==target) return high+2;
	return high + 1;

}

//find target in a sorted list vector<mypair>
int locateElement( std::vector<mypair>& sqlist, int low, int high, int target ){
	
	while(low < high){

                int m = (low + high)/2;
                if(target>sqlist[m].value){
                        low = m+1;
                }
                else if(target<sqlist[m].value){
                        high = m-1;
                }
		else{
			low = m;
			high = m;
		}
        }
	if(target==sqlist[high].value) return high; 
	else return -1;
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
	std::cout<<"after QuickSort()"<<std::endl;
	for(int i = 0; i < sqlist.size(); i++)std::cout<<sqlist[i].value<<" , pos = "<<sqlist[i].pos+1<<std::endl;
	
	int low = 0;
	int high = sqlist.size() - 1;
//	int loc = locateInsert(sqlist,low,high,target);
//	std::cout<<"loc = "<<loc<<std::endl;
	std::vector<int> idx(2);
	bool found = false;
        for(int it1 = 0; it1 < high; it1++){
                int tid2 = target - sqlist[it1].value;
		int id2loc = locateElement(sqlist, it1+1, high, tid2);		
		std::cout<<"it1 = "<<it1<<std::endl;
		std::cout<<"tid2 = "<<tid2<<std::endl;
		std::cout<<"search range: "<<it1+1<<" to "<<high<<std::endl;
		std::cout<<"id2loc = "<<id2loc<<std::endl;
		if(sqlist[id2loc].value==tid2){
			idx[0] = sqlist[it1].pos+1;
			idx[1] = sqlist[id2loc].pos+1;
			break;
		}
		
        }
	
	if(idx[0]>idx[1]){
		int tmp = idx[0];
		idx[0] = idx[1];
		idx[1] = tmp;
	}
	std::cout<<"idx[0] = "<<idx[0]<<", idx[1] = "<<idx[1]<<std::endl;
	return idx;
}

#include<fstream>
int main(){
	
	
//	std::fstream input("in.txt",std::ios::in);
//	std::vector<int> test(16023);
//	int i = 1;
//	while(i<=16023){
//		input>>test[i-1];
//		i++;
//	}
//	twoSum(test,16021);

	std::fstream input("in2.txt",std::ios::in);
	std::vector<int> test(282);
	int i = 1;
	while(i<=282){
		input>>test[i-1];
		i++;
	}
	twoSum(test,74);

//	int myints[4] = {0,3,5,0};
//	int myints[7] = {150,24,79,50,88,345,3};
//	int myints[9] = {3,2,1,-6,-3,8,88,345,6};
//	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//	twoSum(fifth,-9);	

	return 1;
}
