#include <gtest/gtest.h>
#include "list.hpp"
#include "Allocator.hpp"

TEST(ListTest, push_backElements) {
    List<int> list;
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);

    ASSERT_EQ(list.size(), 3);
}

TEST(ListTest, insertElements) {
    List<int> list;
    list.push_back(0);
    //std::cout <<"!!"<< *list.begin() << std::endl;
    list.insert(list.begin(),2);
    list.insert(++list.begin(),1);
    //for(auto i:list ) std::cout << i << std::endl;
    ASSERT_EQ(list.size(), 3);
}

TEST(ListTest, eraseElements) {
    List<int> list;
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    for (int i = 0; i < 3; ++i){
        list.erase(list.begin());
    }
    ASSERT_EQ(list.size(), 0);
}


TEST(ListTest, IteratorTest1) {
    List<int> list;
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);

    int expected_output = 0;

    List<int>::ListIterator it = list.begin();
    ASSERT_EQ(*it, expected_output);
}

TEST(ListTest, IteratorTest2) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    int expected_output = 6; 
    List<int>::ListIterator it = list.begin();
    int ans = 1;
    while (it != list.end()) {
        ans *= *it;
        ++it;
    }

    ASSERT_EQ(ans, expected_output);
}

TEST(AllocatorTest, AllocateMemory) {
    Allocator<int, 10> allocator;
    int* ptr = allocator.allocate(3); 

    ASSERT_NE(ptr, nullptr);

    allocator.deallocate(ptr, 3); 
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}