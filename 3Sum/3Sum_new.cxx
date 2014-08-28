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
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& num){

	//first sort the array
        sort(num.begin(), num.end());
	for(int i = 0; i < num.size(); i++)cout<<"num["<<i<<"] = "<<num[i]<<endl;	

	int n = num.size();
	
	set<vector<int> > res;
	vector<int> triplet;
	for(int ilow = 0; ilow < n - 2; ilow++){ //left most index
		
		//skip repeated elements
		if(ilow>0 && num[ilow] == num[ilow-1])continue;
		
		int jmid = ilow + 1; //middle index
		int kend = n - 1; //right most index
		
		while(jmid < kend){		
			
			int sum = num[ilow] + num[jmid] + num[kend];
			if(sum>0)kend--;
			else if(sum<0)jmid++;
			else{
				triplet.push_back(num[ilow]);
				triplet.push_back(num[jmid]);
				triplet.push_back(num[kend]);
				res.insert(triplet);
				triplet.clear();
				jmid++;
				while(num[jmid] == num[jmid-1])jmid++;
				kend--;
				while(kend < n-1 && num[kend] == num[kend+1])kend--;
			}
		}
	}
	
	set<vector<int> >::iterator it;
	vector<vector<int> > result;
	for(it=res.begin(); it!=res.end();it++){
		result.push_back(*it);
	}
	
	return result;
} 

int main(){
	
	const int nelements = 3;
	int myints[nelements] = {0,0,0}; 
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
	
