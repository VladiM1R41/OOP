#include <gtest/gtest.h>
#include "calculator.h"


TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(calculator(123)==true);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(calculator(00000)==true);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(calculator(0)==true);
}

TEST(test_04, basic_test_set)

{
    ASSERT_TRUE(calculator(32222)==false);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(calculator(12343789)==false);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(calculator(112233)==true);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(calculator(-101)==true);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(calculator(-931)==false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

