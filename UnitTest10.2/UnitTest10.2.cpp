#include "pch.h"
#include "CppUnitTest.h"
#include "../Project10.2/project10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool c;
			char sym = ' ';
			char previous_sym = '.';
			c = Condition(sym, previous_sym);
			Assert::AreEqual(c, true);
		}
	};
}
