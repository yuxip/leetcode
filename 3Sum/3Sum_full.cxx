//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//    The solution set must not contain duplicate triplets.
//
//    For example, given array S = {-1 0 1 2 -1 -4},
//
//    A solution set is:
//    (-1, 0, 1)
//    (-1, -1, 2)


#include<vector>
#include<iostream>

void heapAdjust( std::vector<int>& inlist, int s, int m){

	int rc = inlist[s];
        for(int j = 2*s; j <= m; j*=2){
		if( j<m && inlist[j] < inlist[j+1] ) j++;
		if( rc >= inlist[j] ) break;

		inlist[s] = inlist[j]; s = j;
        }
	
	inlist[s] = rc;

}

void heapSort( std::vector<int>& inlist ){

	for(int i = (inlist.size()-1)/2; i >= 0; --i) heapAdjust(inlist,i,inlist.size()-1);

        for(int i = inlist.size()-1; i > 0; --i){
	
		inlist[0] ^= inlist[i];
                inlist[i] ^= inlist[0];
                inlist[0] ^= inlist[i];

		heapAdjust(inlist,0,i-1);
	}

}

//find target in a sorted array num within the range [lowb, highb]
int findtarget( std::vector<int>& num, int lowb, int highb, int target ){
	
	if(target<num[lowb]) return lowb-1;
	if(target>num[highb]) return highb+1;
	
	int low = lowb;
	int high = highb;
	
	while(low < high){
	
		int m = (low + high)/2;
                if(target>num[m]){
                        low = m+1;
                }
                else{
                        high = m;
                }
        }
        if(target==num[high]) return high;
        else return -1;
	
}

bool exist(std::vector<std::vector<int> > &result, std::vector<int> &triplet){ 	//triplets in both result and 'triplet' are ordered
	
	int ntriplets = result.size();
	if(ntriplets==0) return false;
	std::cout<<"exist::ntriplets = "<<ntriplets<<std::endl;
	int ntri_size = triplet.size();
	bool identical = true;
	for(int itri = 0; itri < ntriplets; itri++){
		std::vector<int> result_tri = result[itri];
		identical = true;
		for(int i = 0; i < 3; i++){
			std::cout<<" result_tri["<<i<<"] = "<<result_tri[i]<<", triplet["<<i<<"] = "<<triplet[i]<<std::endl;
			if(result_tri[i]!=triplet[i]){
				identical=false;
				break;
			}
		}	

	}
	std::cout<<"identical = "<<identical<<std::endl;
	if(identical)std::cout<<"exist!!"<<std::endl;
	return identical;

}

std::vector<std::vector<int> > threeSum(std::vector<int>& num){

	//first sort the array
	heapSort(num);
	std::cout<<"after heap sort: "<<std::endl;
	for(int i = 0; i < 6; i++)std::cout<<"num["<<i<<"] = "<<num[i]<<std::endl;	

	int low = 0;
	int high = num.size() - 1;
	
	std::vector<std::vector<int> > result;
	int ntriplets = 0;
	for(int ilow = low; ilow < num.size() - 1; ilow++){
		for(int ihigh = num.size() - 1; ihigh > ilow + 1; ihigh--){

		//	std::cout<<"ilow = "<<ilow<<", ihigh = "<<ihigh<<std::endl;
			int target = -(num[ilow] + num[ihigh]);
			int pos = findtarget(num,ilow+1,ihigh-1,target); //try to locate the target value within [low+1,high-1];
		//	std::cout<<"ilow = "<<ilow<<", ihigh = "<<ihigh<<", target = "<<target<<", pos = "<<pos<<std::endl;
			
			if(pos == ihigh)break;	//all the elements within [low+1, high-1] are smaller than the target, break out of ihigh loop, move 'low' up
			else if(pos == ilow)continue; //all the elements within [low+1, high-1] are larger than the target, move 'high' down
			else if(pos == -1)continue; //didn't find target, move 'high' down
			else{
				std::vector<int> triplet(3);
				triplet[0] = num[ilow];
				triplet[1] = target;
				triplet[2] = num[ihigh];
				int result_size = result.size();
				std::cout<<"result_size = "<<result_size<<std::endl;
				if(exist(result,triplet))continue;	//search in the current result list for identical triplet
				std::cout<<"found ("<<num[ilow]<<", "<<target<<", "<<num[ihigh]<<")"<<std::endl;
			 	result.push_back(triplet);
				ntriplets++;
				std::cout<<"ntriplets = "<<ntriplets<<std::endl;
				std::cout<<std::endl;
				//move to the next target
			}
		}
	}
	
	return result;
} 

int main(){
	
	int myints[6] = {-1,0,1,2,-1,4}; 
	std::vector<int> inputs (myints, myints + sizeof(myints) / sizeof(int) );
	for(int i = 0; i < 6; i++)std::cout<<"input["<<i<<"] = "<<inputs[i]<<std::endl;                     
	std::vector<std::vector<int> > results;
	results = threeSum(inputs);
	
	int ntriplets = results.size();
	std::cout<<"ntriplets = "<<ntriplets<<std::endl;
	for(int itri = 0; itri < ntriplets; itri++){
		
		std::vector<int> result = results[itri];
		std::cout<<"( "<<result[0]<<", "<<result[1]<<", "<<result[2]<<" )"<<std::endl;
	
	}
	
	return 1;

}
	
