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
		std::cout<<"pivotloc = "<<pivotloc<<", lowmoved = "<<lowmoved<<", highmoved = "<<highmoved<<std::endl;
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
	int loc = locate(sqlist,low,high,target);
	if(loc<=3)loc=3;	
	std::cout<<"loc = "<<loc<<std::endl;
	std::vector<int> idx(2);
        for(int it1 = 0; it1 < loc; it1++){
                int tid2 = target - sqlist[it1].value;
		int tid2loc = locate(sqlist,it1,loc,tid2);
                if(sqlist[tid2loc].value==tid2){
			std::cout<<"tid2loc = "<<tid2loc<<std::endl;
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
	
	std::cout<<"idx[0] = "<<idx[0]<<", idx[1] = "<<idx[1]<<std::endl;
//	return idx;
	
	
}

#include<fstream>
int main(){
	
	
/*	std::fstream input("in.txt",std::ios::in);
	std::vector<int> test(16023);
	int i = 1;
	while(i<=16023){
		input>>test[i-1];
		i++;
	}
	twoSum(test,16021);
*/

	int myints[4] = {0,4,3,0};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	twoSum(fifth,0);	

	return 1;
}
