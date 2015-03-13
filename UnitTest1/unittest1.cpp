#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\bitstring\bitstring.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace bitStringTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(testConstructor1)
		{	
			 //test constructor with dynamic char array of length 1
			 unsigned char* data = new unsigned char[1];
			 data[0] = (char)255;
			 bitstring bitstring1 = bitstring::bitstring(data, 1);
			 Assert::AreEqual(*data, *bitstring1.data(), L"nessage", LINE_INFO());

		}

	};
}