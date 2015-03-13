#include<string.h>
#include<iostream>
#include "bitmap.h"

using namespace std;

//used to evalutate an indiviual bit, 00000001, 00000010, 00000100 etc.
const unsigned int bitmap::bits[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

//instantiate bitmap from a set number of bits to 0, if not able to be divided by 8 evenly then add an extra [8 - (bits%8)] bits
bitmap::bitmap(unsigned int bits)
{
	len = bits;

	if ((bits % 8) != 0)
	{
		privateBits = new unsigned char[(bits % 8) + 1]();
		totalMemory = (bits / 8) + 1;
	}
	else
	{
		privateBits = new unsigned char[(bits % 8)]();
		totalMemory = (bits / 8);
	}
}

//instantiates bitmap from a char* bitstring
//set number of bits = total characters in string * 8
bitmap::bitmap(unsigned char* bitString, unsigned int strlength)
{
	len = strlength * 8;
	privateBits = new unsigned char[strlength];
	memcpy(privateBits, bitString, strlength);
}


//delete dynamic bits
bitmap::~bitmap()
{
	delete[] privateBits;
}

//getter function for length of bit string
unsigned int bitmap::size() {
	return len;

}

//set a bit in a character array to true = 1 or false = 0
void bitmap::setbit(unsigned char* arr, unsigned int n, bool val) {
	if (val) arr[n / 8] |= bitmap::bits[n % 8];
	else
		arr[n / 8] &= ~bitmap::bits[n % 8];
}


void bitmap::setbit(unsigned int n, bool val) {
	if (val) privateBits[n / 8] |= bitmap::bits[n % 8];
	else
		privateBits[n / 8] &= ~bitmap::bits[n % 8];
}

//set a bit within the
bool bitmap::checkbit(unsigned char* arr, unsigned int n) {
	return ((arr[n / 8] & bitmap::bits[n % 8]) == bitmap::bits[n % 8]);
}

//find a "free bit" in the character array. This is the location of the first bit set to 0
const unsigned int bitmap::findFreeBit(unsigned char* arr) {

	unsigned int pos = 0;
	unsigned char* byte = arr;

	while (((*byte & bitmap::bits[pos % 8]) == bitmap::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//instanced checks bit of character array stored within an object
bool bitmap::checkbit(unsigned int n) {
	return ((privateBits[n / 8] & bitmap::bits[n % 8]) == bitmap::bits[n % 8]);
}

//find a free bit stored within an object
unsigned int bitmap::findFreeBit() {

	unsigned int pos = 0;
	unsigned char* byte = privateBits;

	while (((*byte & bitmap::bits[pos % 8]) == bitmap::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//get the character array stored within an object, the raw bits
unsigned char* bitmap::data() {
	return privateBits;

}

bitmap::reference bitmap::operator[](unsigned int i) { return reference(&privateBits[i / 8], 1 << (i % 8)); }