#include "pch.h"
#include "CppUnitTest.h"
#include "../Program/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(met_max)
		{
			int mass[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			Assert::AreEqual(max_(mass, 10), 9);
			Assert::AreEqual(max__<int>(mass, 10), 9);
		}
	};
}
