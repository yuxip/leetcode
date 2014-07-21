#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
int reverse(int x){
	
	std::stringstream strs;
	strs << x;
	std::string s = strs.str();
	int size = s.length();
	const char* pchar = s.c_str();
	std::stack<char> mystack;
	for(int i = 0; i < size; i++)mystack.push(pchar[i]);
	std::string sout;
	while(!mystack.empty()){
		sout.append(1,mystack.top());
		mystack.pop();
	}
	int result;
	std::istringstream convert(sout);
	convert >> result;
	if(x<0) result = -result;	

	return result;
}
	
	

int main(){
	
	int rev_result = reverse(-123);
	std::cout<<"result : "<<rev_result<<std::endl;
	
	return 1;
}
