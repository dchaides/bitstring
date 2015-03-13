
#include<string.h>
#include<iostream>
#include "bitmap.h"

using namespace std;



int main(int argc, char *argv[]) {

	unsigned char bitmap1[125] = {};

	bitmap bitmap2(bitmap1, sizeof(bitmap1));

	cout << sizeof(bitmap1);

	
	return (0);
}
















