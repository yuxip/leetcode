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


int main(){

  int myints[5] = {2,7,11,15,22};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  std::vector<int> idx = twoSum(fifth,33);
  for (std::vector<int>::iterator it = idx.begin(); it != idx.end(); ++it)std::cout << *it << ' ';
  std::cout << '\n';

  return 1;
}
