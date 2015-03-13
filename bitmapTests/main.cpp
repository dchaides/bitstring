
#include<string.h>
#include<iostream>
#include "bitstring.h"

using namespace std;



int main(int argc, char *argv[]) {

	cout << "initialize a bitstring of size 125\n";
	unsigned char bitstring1[125] = {};
	

	bitstring bitstring2(bitstring1, sizeof(bitstring1));

	cout << bitstring1[125];
	

	
	return (0);
}
















