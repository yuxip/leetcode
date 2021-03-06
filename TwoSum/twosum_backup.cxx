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
	
	//compare sqlist[low].value, sqlist[high].value and sqlist[[(low+high)/2]].value, take
	//the median to be pivot, then exchange sqlist[pivot] and sqlist[low]	
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

	int pivot_value = sqlist[low].value; //first element in range serve as pivot
	int pivot_pos = sqlist[low].pos;
	while( low < high ){
		
		while(low < high && sqlist[high].value >= pivot_value){
			if(sqlist[high].value < sqlist[high-1].value && high > low+1)highmoved=true;
			--high;
		}
		//if( low!=high ) highmoved = true;
		//swap element [high] and pivot (already saved)
		sqlist[low].pos = sqlist[high].pos;
		sqlist[low].value = sqlist[high].value;
		while(low < high && sqlist[low].value <= pivot_value){
			if(sqlist[low].value > sqlist[low+1].value && low < high-1)lowmoved=true;
			++low;
		}
		sqlist[high].pos = sqlist[low].pos;
		sqlist[high].value = sqlist[low].value;
	}
	
	//fill in pivot 
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
	//	std::cout<<"pivotloc = "<<pivotloc<<", lowmoved = "<<lowmoved<<", highmoved = "<<highmoved<<std::endl;
		if(lowmoved)QSort(sqlist,low,pivotloc-1);
		if(highmoved)QSort(sqlist,pivotloc+1,high);
	//	QSort(sqlist,low,pivotloc-1);
	//	QSort(sqlist,pivotloc+1,high);
	}
	//else do nothing
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
                else{
                        high = m-1;
                }
        }
	if(target==sqlist[high].value) return high; 
	else return -1;
}

//std::vector<int> twoSum(std::vector<int> &numbers, int target) {
void twoSum(std::vector<int> &numbers, int target) {

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
	int loc = locateInsert(sqlist,low,high,target);
	std::cout<<"loc = "<<loc<<std::endl;
	std::vector<int> idx(2);
	bool found = false;
        for(int it1 = 0; it1 < loc; it1++){
                int tid2 = target - sqlist[it1].value;
		int id2loc = locateElement(sqlist, it1+1, loc-1, tid2);		
	//	std::cout<<"it1 = "<<it1<<std::endl;
	//	std::cout<<"tid2 = "<<tid2<<std::endl;
	//	std::cout<<"id2loc = "<<id2loc<<std::endl;
		if(sqlist[id2loc].value==tid2){
		//	std::cout<<"it1 = "<<it1<<std::endl;
		//	std::cout<<"tid2 = "<<tid2<<std::endl;
		//	std::cout<<"id2loc = "<<id2loc<<std::endl;
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
//	return idx;
	
	
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


//	int myints[4] = {0,4,3,1};
//	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//	twoSum(fifth,7);	

	return 1;
}
