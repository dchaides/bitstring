#ifndef bitstring_H_INCLUDED
#define bitstring_H_INCLUDED


#include<cassert>
#include<string.h>
#include<iostream>

class bitstring
{
private:
	static const unsigned int bits[];
	unsigned char* privateBits;
	unsigned int len;

public:
	bitstring(unsigned char* bitString, unsigned int strlength);
	bitstring(unsigned int);
	~bitstring();

	class reference {
		unsigned char *dataptr;
		unsigned char mask;
	public:
		//constructor just initializing members
		reference(unsigned char *dataptr_, unsigned char mask_) : dataptr(dataptr_), mask(mask_) {}

		//conversion to bool
		operator bool() const {
			//just like in the getter, but the bitmask is stored now locally
			return *dataptr & mask;
		}

		//sets one single bit represented by mask to b
		reference& operator=(bool b) {
			if (b) {
				*dataptr |= mask;
			}
			else {
				*dataptr &= ~mask;
			}
			return *this;
		}

		//TODO copy ctor., operator==, operator<
	};


	bool checkbit(unsigned int n);
	void setbit(unsigned int n, bool val);
	unsigned int findFreeBit();
	unsigned int bitstring::findFreeBit(unsigned int pos);
	unsigned int size();
	unsigned char* data();
	unsigned int totalMemory;
	static void bitstring::setbit(unsigned char* arr, unsigned int n, bool val);
	bool checkbit(unsigned char* arr, unsigned int n);
	const static unsigned int findFreeBit(unsigned char* arr);
	bitstring::reference operator[](unsigned int i);

};



#endif // bitstring_H_INCLUDED
