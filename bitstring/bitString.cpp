// bitString.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "bitString.h"
#include <stdexcept>

/*
// This is an example of an exported variable
BITSTRING_API int nbitString=0;

// This is an example of an exported function.
BITSTRING_API int fnbitString(void)
{
	return 42;
}
*/

BITSTRING_API const unsigned int bitString::bits[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

// This is the constructor of a class that has been exported.
// see bitString.h for the class definition
//default constructor of 8 bits
bitString::bitString(){
	privateBits = new unsigned char[1]();
}

//instantiate bitString from a set number of bits to 0, if not able to be divided by 8 evenly then add an extra [8 - (bits%8)] bits
bitString::bitString(unsigned int bits)
{
	len = bits;

	if ((bits % 8) != 0)
	{
		privateBits = new unsigned char[(bits / 8) + 1]();
	}
	else
	{
		privateBits = new unsigned char[(bits / 8)]();
	}
}

//instantiates bitString from a char* bitString
//set number of bits = total characters in string * 8
bitString::bitString(unsigned char* bitString, unsigned int strlength)
{
	len = strlength * 8;
	privateBits = new unsigned char[strlength];
	memcpy(privateBits, bitString, strlength);
}


//delete dynamic bits
bitString::~bitString()
{
	delete[] privateBits;
}

//getter function for length of bit string
unsigned int bitString::size() {
	return len;

}

//set a bit in a character array to true = 1 or false = 0
void bitString::setbit(unsigned char* arr, unsigned int n, bool val) {
	if (val) arr[n / 8] |= bitString::bits[n % 8];
	else
		arr[n / 8] &= ~bitString::bits[n % 8];
}


void bitString::setbit(unsigned int n, bool val) {
	if (val) privateBits[n / 8] |= bitString::bits[n % 8];
	else
		privateBits[n / 8] &= ~bitString::bits[n % 8];
}

//set a bit within the
bool bitString::checkbit(unsigned char* arr, unsigned int n) {
	return ((arr[n / 8] & bitString::bits[n % 8]) == bitString::bits[n % 8]);
}

//find a "free bit" in the character array. This is the location of the first bit set to 0
unsigned int bitString::findFreeBit(unsigned char* arr) {

	unsigned int pos = 0;
	unsigned char* byte = arr;

	while (((*byte & bitString::bits[pos % 8]) == bitString::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//instanced checks bit of character array stored within an object
bool bitString::checkbit(unsigned int n) {
	return ((privateBits[n / 8] & bitString::bits[n % 8]) == bitString::bits[n % 8]);
}

//find a free bit stored within the object
unsigned int bitString::findFreeBit() {

	unsigned int pos = 0;
	unsigned char* byte = privateBits;

	while (((*byte & bitString::bits[pos % 8]) == bitString::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//instanced checks bit of character array stored within an object starting a position pos
unsigned int bitString::findFreeBit(unsigned int pos) {

	if (pos > len)  throw new std::out_of_range("bitString out of bounds");
	unsigned char* byte = privateBits;

	while (((*byte & bitString::bits[pos % 8]) == bitString::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//get the character array stored within an object, the raw bits
unsigned char* bitString::data() {
	return privateBits;

}

bitString::reference bitString::operator[](unsigned int i)
{
	if (i >= len) throw new std::out_of_range("bitString out of bounds");
	else
		return reference(&privateBits[i / 8], 1 << (i % 8));
}