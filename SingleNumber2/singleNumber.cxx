//Given an array of integers, every element appears three times except for one. Find that single one.

//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
#include <iostream>

int singleNumber(int A[], int n) {

	//assume 32-bit int type
	int sum = 0;
	int tmpbit = 0;
	for(int ibit = 0; ibit < 32; ibit++){
		tmpbit = 0;
		for(int i = 0; i < n; i++){
	
			tmpbit += (A[i]>>ibit) & 0x01; 
		}
		tmpbit = tmpbit%3;
		sum |= (tmpbit<<ibit);
		
	}
	
	return sum;

}


int main(){
	
	int A[1] = {1};
	int result = singleNumber(A,1);
	std::cout<<"result = "<<result<<std::endl;
	return 1;	
}
	
