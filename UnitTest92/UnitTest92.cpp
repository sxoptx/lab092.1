#include "pch.h"
#include "CppUnitTest.h"
#include "../lab092/Macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// формула гілки z > 3, записана через макроси
double Branch1(double x, double y, double z)
{
    return MAX(SQR(x - z), x - y);
}

// формула гілки z <= 3, записана через макроси
double Branch2(double x, double y, double z)
{
    return MAX(x * y, y * z) + MAX(z * x, y * z);
}

namespace UnitTestMacros
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // перевірка базових макросів
        TEST_METHOD(TestBasicMacros)
        {
            Assert::AreEqual(5.0, (double)MAX(2, 5));
            Assert::AreEqual(2.0, (double)MIN(2, 5));
            Assert::AreEqual(4.0, (double)ABS(-4));
            Assert::AreEqual(9.0, (double)SQR(3));
        }
        // z > 3: x = 2, y = 1, z = 7 -> max(25, 1) = 25
        TEST_METHOD(TestBranch1_SquareWins)
        {
            Assert::AreEqual(25.0, Branch1(2, 1, 7));
        }
        // z > 3: x = 5, y = 1, z = 4 -> max(1, 4) = 4
        TEST_METHOD(TestBranch1_LinearWins)
        {
            Assert::AreEqual(4.0, Branch1(5, 1, 4));
        }
        // z <= 3: x = 2, y = 3, z = 1 -> max(6, 3) + max(2, 3) = 9
        TEST_METHOD(TestBranch2_A)
        {
            Assert::AreEqual(9.0, Branch2(2, 3, 1));
        }
        // z <= 3: x = 1, y = 2, z = 3 -> max(2, 6) + max(3, 6) = 12
        TEST_METHOD(TestBranch2_B)
        {
            Assert::AreEqual(12.0, Branch2(1, 2, 3));
        }
    };
}