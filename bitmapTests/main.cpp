
#include<string.h>
#include<iostream>
#include "bitstring.h"

using namespace std;



int main(int argc, char *argv[]) {

	cout << "1: test the default constructor of a bitstring size 1\n";
	bitstring bitstring1;
	try{
		cout << "2: initialize a bitstring of size 125\n";
		bitstring1 = bitstring::bitstring(125);
	}
	catch (exception & e){
		cerr  << "FAILED: "<< e.what() << endl;
	}
	
	


	try{
		cout << bitstring1[124];
	}
	catch (std::out_of_range err){
		cout << "PASSED";
	}
		
	

	

	
	return (0);
}
















