#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\bitstring\bitString.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace bitStringTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestConstructor1)
		{
			//test the default constructor
			bitstring bitstring1 = bitstring::bitstring();
			
			Assert::AreEqual(false, bitstring1[0]);
			
			

		}

	};
}