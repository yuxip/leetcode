//Given an array of integers, every element appears twice except for one. Find that single one.

//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

#include <iostream>

int singleNumber(int A[], int n) {

	int sum = 0;
	for(int i = 0; i < n; i++){
		
		sum = sum^A[i];
	}        
	
	return sum;
}


int main(){
	
	int A[7] = {1,2,3,2,1,5,5};
	int single = singleNumber(A,7);
	std::cout<<"single = "<<single<<std::endl;

	return 1;
}
