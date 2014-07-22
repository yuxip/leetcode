//exchange two numbers without a temporary variable
#include <iostream>
int main(){
	
	int A = 3;
	int B = 5;
	
	std::cout<<"before swaping : A = "<<A<<", B = "<<B<<std::endl;
	
	B = A^B;
	A = B^A; //after this step A = B;
	B = B^A; // = A^B^B = A;
	
	std::cout<<"after swaping : A = "<<A<<", B = "<<B<<std::endl;
	
	return 1;
}
