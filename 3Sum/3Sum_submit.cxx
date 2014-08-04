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
using namespace std;

void heapAdjust( vector<int>& inlist, int s, int m){

	int rc = inlist[s];
        for(int j = 2*s; j <= m; j*=2){
		if( j<m && inlist[j] < inlist[j+1] ) j++;
		if( rc >= inlist[j] ) break;

		inlist[s] = inlist[j]; s = j;
        }
	
	inlist[s] = rc;

}

void heapSort( vector<int>& inlist ){

	for(int i = (inlist.size()-1)/2; i >= 0; --i) heapAdjust(inlist,i,inlist.size()-1);

        for(int i = inlist.size()-1; i > 0; --i){
	
		inlist[0] ^= inlist[i];
                inlist[i] ^= inlist[0];
                inlist[0] ^= inlist[i];

		heapAdjust(inlist,0,i-1);
	}

}

//find target in a sorted array num within the range [lowb, highb]
int findtarget( vector<int>& num, int lowb, int highb, int target ){
	
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

bool exist(vector<vector<int> > &result, vector<int> &triplet){ 	//triplets in both result and 'triplet' are ordered
	
	int ntriplets = result.size();
	if(ntriplets==0) return false;
	int ntri_size = triplet.size();
	bool identical = true;
	for(int itri = 0; itri < ntriplets; itri++){
		vector<int> result_tri = result[itri];
		identical = true;
		for(int i = 0; i < 3; i++){
			if(result_tri[i]!=triplet[i]){
				identical=false;
				break;
			}
		}
		if(identical)return identical;	

	}
	return identical;

}

vector<vector<int> > threeSum(vector<int>& num){

	//first sort the array
	heapSort(num);
	cout<<"after heap sort: "<<endl;
        for(int i = 0; i < num.size(); i++)cout<<"num["<<i<<"] = "<<num[i]<<endl;	

	int low = 0;
	int high = num.size() - 1;
	
	vector<vector<int> > result;
	int ntriplets = 0;
	for(int ilow = 0; ilow < num.size() - 1; ilow++){
		for(int ihigh = num.size() - 1; ihigh > ilow + 1; ihigh--){

			int target = -(num[ilow] + num[ihigh]);
			int pos = findtarget(num,ilow+1,ihigh-1,target); //try to locate the target value within [low+1,high-1];
			
			if(pos == ihigh)break;	//all the elements within [low+1, high-1] are smaller than the target, break out of ihigh loop, move 'low' up
			else if(pos == ilow)continue; //all the elements within [low+1, high-1] are larger than the target, move 'high' down
			else if(pos == -1)continue; //didn't find target, move 'high' down
			else{
				vector<int> triplet(3);
				triplet[0] = num[ilow];
				triplet[1] = target;
				triplet[2] = num[ihigh];
				int result_size = result.size();
				if(exist(result,triplet))continue;	//search in the current result list for identical triplet
			 	result.push_back(triplet);
				ntriplets++;
				//move to the next target
			}
		}
	}
	
	return result;
} 

int main(){
	
	const int nelements = 13;
	int myints[nelements] = {-1,0,1,2,-1,4,-6,-5,5,-4,-8,7,-2}; 
	vector<int> inputs (myints, myints + sizeof(myints) / sizeof(int) );
//	for(int i = 0; i < nelements; i++)cout<<"input["<<i<<"] = "<<inputs[i]<<endl;                     
	vector<vector<int> > results;
	results = threeSum(inputs);
	
	int ntriplets = results.size();
	cout<<"ntriplets = "<<ntriplets<<endl;
	for(int itri = 0; itri < ntriplets; itri++){
		
		vector<int> result = results[itri];
		cout<<"( "<<result[0]<<", "<<result[1]<<", "<<result[2]<<" )"<<endl;
	
	}
	
	return 1;

}
	
