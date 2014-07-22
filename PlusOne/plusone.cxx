//Given a non-negative number represented as an array of digits, plus one to the number.
//The digits are stored such that the most significant digit is at the head of the list.


#include <vector>
#include <iostream>
#include <stack>
std::vector<int> plusOne(std::vector<int> &digits){
	
	int sum = 1;
	for(std::vector<int>::reverse_iterator rit = digits.rbegin(); rit != digits.rend(); rit++){
		sum += (*rit);
		(*rit) = sum%10;
		sum /= 10;
	}
	
	std::vector<int> output;
	if(sum)output.push_back(sum);
	for(std::vector<int>::iterator it = digits.begin(); it != digits.end(); it++)output.push_back(*it);	
	
	return output;
}
	
int main(){
	
	int myints[] = {1,9};
	std::vector<int> a (myints, myints + sizeof(myints) / sizeof(int) );
	std::vector<int> b = plusOne(a);
	
	for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it)std::cout << *it <<' ';
  	std::cout << '\n';
	
	return 1;
}
