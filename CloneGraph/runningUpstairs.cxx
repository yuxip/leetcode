/*
 *  A child is running up a staircase with n steps, and can hop either 1
 *  step, 2 steps, or 3 steps at a time. Implement a method to count how many
 *  possible ways the child can run up the stairs.
 */

#include<iostream>

int runningUpstairs(int);

int runUpstairs(int stepNum, int* temp){
	
	if(stepNum<=0)return 0;
	
	else if(stepNum==1)return 1;
	else if(stepNum==2)return 2;
	else if(stepNum==3)return 4;
	
	else if(temp[stepNum]!=0) return temp[stepNum]; //re-use previous calculations
	else{
		temp[stepNum] = runningUpstairs(stepNum-1) + runningUpstairs(stepNum-2) + runningUpstairs(stepNum-3);
		return temp[stepNum];
	}
}

int runningUpstairs(int stepNum){
	
	int* temp = new int[stepNum+1];
	return runUpstairs(stepNum, temp);
}

int main(){
	
	for(int n_steps = 1; n_steps < 10; n_steps++){
		int steps = runningUpstairs(n_steps);
		std::cout<<"stepNum = "<<n_steps<<" has "<<steps<<" ways "<<std::endl;
	}
	
	return 1;
}
	
