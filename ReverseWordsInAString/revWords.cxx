
#include <iostream>
#include <string>
#include <stack>
//pre-processing string. remove leading/trailing whitespaces and extra space in between words
std::string trim(std::string& str, const std::string& whitespace = " \t"){
	
	const std::size_t strBegin = str.find_first_not_of(whitespace);
	if(strBegin == std::string::npos)return ""; //empty string
	
	const std::size_t strEnd = str.find_last_not_of(whitespace);
	const std::size_t strRange = strEnd - strBegin + 1;
	
	return str.substr(strBegin, strRange);
}

std::string reduce( std::string& str, const std::string& fill = " ", const std::string& whitespace = " \t"){
	
	//trim
	std::string result = trim(str, whitespace);
	
	//remove extra whitespace between words
	std::size_t beginSpace = result.find_first_of(whitespace);
	while(beginSpace != std::string::npos){
		const std::size_t endSpace = result.find_first_not_of(whitespace, beginSpace);
		const std::size_t range = endSpace - beginSpace;
		result.replace(beginSpace,range,fill);
		
		const std::size_t newStart = beginSpace + fill.length();
		beginSpace = result.find_first_of(whitespace, newStart);
	}
	
	return result;
}

//str is already pre-processed	
void reverse( std::string& s){
	
	s = reduce(s);
	std::string fill = " ";
	std::string whitespace = " \t";
	std::stack<std::string> mystack; //each element contains a word;
	std::size_t beginWord = s.find_first_not_of(whitespace); //should always be the first character
	while(beginWord != std::string::npos){
		std::size_t newStart = beginWord;
		std::size_t endWord = s.find_first_of(whitespace, newStart);
		if(endWord==std::string::npos)endWord = s.size();
		std::size_t range = endWord - beginWord;
		mystack.push(s.substr(beginWord, range));
		if(endWord!=s.size())mystack.push(fill);
		beginWord = s.find_first_not_of(whitespace,endWord);
	}
	
	std::string result;
	while(!mystack.empty()){
		result.append(mystack.top());
		mystack.pop();
	}
		
	s = result;
}


//test
int main(){
	
	std::string input = "	the   sky is  blue   ";
	std::cout<<"input: "<<input<<std::endl;
	reverse(input);
	std::cout<<"output: "<<input<<std::endl;
	
	return 1;
}
		
