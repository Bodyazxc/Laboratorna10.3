#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna10.3/Laboratorna10.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest103
{
	TEST_CLASS(UnitTest103)
	{
	public:
		
        TEST_METHOD(TestMethod1)

        {
            Room* rooms = new Room[100];
            int count = 0;

            
            AddRoom(rooms, count);

            Assert::AreEqual(count, 1);
            Assert::AreEqual(rooms[0].phone_number, 0);  
            delete[] rooms;
           
        }
     
          
	};
}
