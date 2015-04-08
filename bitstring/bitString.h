// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BITSTRING_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BITSTRING_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BITSTRING_EXPORTS
#define BITSTRING_API __declspec(dllexport)
#else
#define BITSTRING_API __declspec(dllimport)
#endif

// This class is exported from the bitString.dll
class BITSTRING_API bitString {
private:
	static const unsigned int bits[];
	unsigned char* privateBits;
	unsigned int len;

public:
	bitString(void);
	bitString(unsigned char* bitstring, unsigned int strlength);
	bitString(unsigned int);
	~bitString();
	// TODO: add your methods here.

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

		
	};
	//TODO copy ctor., operator==, operator<
	bool checkbit(unsigned int n);
	void setbit(unsigned int n, bool val);
	unsigned int findFreeBit();
	unsigned int size();
	unsigned char* data();
	unsigned int totalMemory;
	static void setbit(unsigned char* arr, unsigned int n, bool val);
	bool checkbit(unsigned char* arr, unsigned int n);
	unsigned int findFreeBit(unsigned char* arr);
	unsigned int findFreeBit(unsigned int pos);
	bitString::reference operator[](unsigned int i);
};

extern BITSTRING_API int nbitString;

BITSTRING_API int fnbitString(void);
