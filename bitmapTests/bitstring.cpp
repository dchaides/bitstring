
#include "bitstring.h"



//used to evalutate an indiviual bit, 00000001, 00000010, 00000100 etc.
const unsigned int bitstring::bits[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

//instantiate bitstring from a set number of bits to 0, if not able to be divided by 8 evenly then add an extra [8 - (bits%8)] bits
bitstring::bitstring(unsigned int bits)
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

//instantiates bitstring from a char* bitstring
//set number of bits = total characters in string * 8
bitstring::bitstring(unsigned char* bitString, unsigned int strlength)
{
	len = strlength * 8;
	privateBits = new unsigned char[strlength];
	memcpy(privateBits, bitString, strlength);
}


//delete dynamic bits
bitstring::~bitstring()
{
	delete[] privateBits;
}

//getter function for length of bit string
unsigned int bitstring::size() {
	return len;

}

//set a bit in a character array to true = 1 or false = 0
void bitstring::setbit(unsigned char* arr, unsigned int n, bool val) {
	if (val) arr[n / 8] |= bitstring::bits[n % 8];
	else
		arr[n / 8] &= ~bitstring::bits[n % 8];
}


void bitstring::setbit(unsigned int n, bool val) {
	if (val) privateBits[n / 8] |= bitstring::bits[n % 8];
	else
		privateBits[n / 8] &= ~bitstring::bits[n % 8];
}

//set a bit within the
bool bitstring::checkbit(unsigned char* arr, unsigned int n) {
	return ((arr[n / 8] & bitstring::bits[n % 8]) == bitstring::bits[n % 8]);
}

//find a "free bit" in the character array. This is the location of the first bit set to 0
const unsigned int bitstring::findFreeBit(unsigned char* arr) {

	unsigned int pos = 0;
	unsigned char* byte = arr;

	while (((*byte & bitstring::bits[pos % 8]) == bitstring::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//instanced checks bit of character array stored within an object
bool bitstring::checkbit(unsigned int n) {
	return ((privateBits[n / 8] & bitstring::bits[n % 8]) == bitstring::bits[n % 8]);
}

//find a free bit stored within the object
unsigned int bitstring::findFreeBit() {

	unsigned int pos = 0;
	unsigned char* byte = privateBits;

	while (((*byte & bitstring::bits[pos % 8]) == bitstring::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//instanced checks bit of character array stored within an object starting a position pos
unsigned int bitstring::findFreeBit(unsigned int pos) {

	assert(pos < len);
	unsigned char* byte = privateBits;

	while (((*byte & bitstring::bits[pos % 8]) == bitstring::bits[pos % 8]))
	{
		pos++;
		if ((pos % 8) == 0) byte++;
	}

	return pos;
}

//get the character array stored within an object, the raw bits
unsigned char* bitstring::data() {
	return privateBits;

}

bitstring::reference bitstring::operator[](unsigned int i) 
{ 
	assert(i < this->len);
	return reference(&privateBits[i / 8], 1 << (i % 8)); 
}