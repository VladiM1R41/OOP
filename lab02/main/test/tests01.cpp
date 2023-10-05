#include <gtest/gtest.h>
#include "Binary.h"


TEST(test_01, basic_test_set)
{
    Binary ds1 {'1','0','0','0','1','1'};
    Binary ds2{'1','1','1','0'};
    ASSERT_TRUE(ds1.is_bigger(ds2) == true);
}

TEST(test_02, basic_test_set)
{
    Binary ds1 {'1','0','0','0','1','1'};
    Binary ds2{'1','1','1','0'};
    ASSERT_TRUE(ds1.equals(ds2) == false);
}

TEST(test_03, basic_test_set)
{
    Binary ds1 {'1','0','0','0','1','1'};
    Binary ds2{'1','1','1','0'};
    ASSERT_TRUE(ds1.is_smaller(ds2) == false);
}

TEST(test_04, basic_test_set)

{
    Binary ds1 {'1','0','1'};
    Binary ds2{'1','0','1'};
    Binary ds5 = {'0','1','0','1',};
    ASSERT_TRUE(ds5.equals(ds1.add(ds2)) == true);
}

TEST(test_05, basic_test_set)
{   
    Binary ds1 {'1','0','1'};
    Binary ds2{'0','0','1'};
    Binary ds3 {'1'};

    ASSERT_TRUE(ds3.equals(ds1.remove(ds2)) == true);
}

// TEST(test_06, basic_test_set)
// {
//     ASSERT_TRUE(calculator(112233)==true);
// }

// TEST(test_07, basic_test_set)
// {
//     ASSERT_TRUE(calculator(-101)==false);
// }

// TEST(test_08, basic_test_set)
// {
//     ASSERT_TRUE(calculator(-931)==false);
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

