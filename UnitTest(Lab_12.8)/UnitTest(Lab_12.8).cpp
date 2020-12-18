#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.8/Lab_12.8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab128
{
	TEST_CLASS(UnitTestLab128)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* first = NULL;
			Spusok* last = NULL;

			int kilkist;
			inform value;

			ifstream file_load;
			file_load.open("E:\\Моя папка. Навчання\\Student [IK-11] [Дорожовець]\\Lab_12.8\\Lab_12.8\\test.txt");
			kilkist = Start(file_load, first, last);
			file_load.close();

			Spusok* T = first;

			T = first;
			Spusok* G = first;
			Process(first, T, G, kilkist);

			T = first;
			int l = T->inf;
			Assert::AreEqual(l, 34);
		}
	};
}
