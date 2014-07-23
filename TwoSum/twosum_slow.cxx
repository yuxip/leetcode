#include <vector>
#include <iostream>
std::vector<int> twoSum(std::vector<int> &numbers, int target) {

        std::vector<int> idx(2);
        bool found = false;
        for(int it1 = 0; it1 < numbers.size(); it1++){
                int tid2 = target - numbers[it1];
                for(int it2 = it1+1; it2 < numbers.size(); it2++){
                        if(numbers[it2]==tid2){
                                idx[0] = it1+1;
                                idx[1] = it2+1;
                                found = true;
                                break;
                        }
                }
                if(found)break;
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
