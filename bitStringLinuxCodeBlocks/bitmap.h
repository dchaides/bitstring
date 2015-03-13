#ifndef BITMAP_H_INCLUDED
#define BITMAP_H_INCLUDED


#include <cassert>

class bitmap
{
private:
    static const unsigned int bits[];
    unsigned char* privateBits;
    unsigned int len;

public:
    bitmap(unsigned char* bitString, unsigned int strlength);
    bitmap(unsigned int);
    ~bitmap();

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
        } else {
        *dataptr &= ~mask;
        }
        return *this;
    }

  //TODO copy ctor., operator==, operator<
    };


    bool checkbit(unsigned int n);
    void setbit(unsigned int n, bool val);
    unsigned int findFreeBit();
    unsigned int size();
    unsigned char* data();
    unsigned int totalMemory;
    static void bitmap::setbit(unsigned char* arr,unsigned int n, bool val);
    const static bool checkbit(unsigned char* arr,unsigned int n);
    const static unsigned int findFreeBit(unsigned char* arr);
    bool operator[] (unsigned int nIndex) const { assert(nIndex >= 0 && nIndex < len); return this->checkbit(nIndex); };
    reference operator[](unsigned int i) { return reference(&privateBits[i/8], 1 << (i%8)); }



};



#endif // BITMAP_H_INCLUDED
