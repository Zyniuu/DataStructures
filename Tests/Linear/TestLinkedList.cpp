#include <gtest/gtest.h>
#include "../../DataStructures/Linear/LinkedList/LinkedList.hpp"

// Test case: constructor
TEST(LinkedListTests, ConstructorInitializesEmptyList)
{
    LinkedList<int> list;
    EXPECT_EQ(list.length(), 0);
}

// Test case: 'travel' method
TEST(LinkedListTests, TravelFunctionCorrectness)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}

// Test case: inserting at the head
TEST(LinkedListTests, InsertAtHead)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 0);

    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.get(0), 20);
    EXPECT_EQ(list.get(1), 10);
}

// Test case: inserting in the middle and at the end
TEST(LinkedListTests, InsertAtMiddleAndEnd)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(30, 1);
    list.insert(20, 1);

    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}

// Test case: head removal
TEST(LinkedListTests, RemoveFromHead)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 0);
    list.remove(0);

    EXPECT_EQ(list.length(), 1);
    EXPECT_EQ(list.get(0), 10);
}

// Test case: end removal
TEST(LinkedListTests, RemoveFromEnd)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.remove(1);

    EXPECT_EQ(list.length(), 1);
    EXPECT_EQ(list.get(0), 10);
}

// Test case: removing from the middle
TEST(LinkedListTests, RemoveFromMiddle)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    list.remove(1);

    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 30);
}

// Test case: large number of entries
TEST(LinkedListTests, LargeListPerformance)
{
    LinkedList<int> list;

    const int NUM_ELEMENTS = 1000;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        list.insert(i, i);
    }

    EXPECT_EQ(list.length(), NUM_ELEMENTS);

    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        EXPECT_EQ(list.get(i), i);
    }
}

// Test case: removing every element
TEST(LinkedListTests, RemoveAllElements)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);

    list.remove(2);
    list.remove(1);
    list.remove(0);

    EXPECT_EQ(list.length(), 0);
}

// Test case: mixed operations
TEST(LinkedListTests, MixedOperations)
{
    LinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(15, 1);

    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.get(1), 15);

    list.remove(1);

    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.get(1), 20);

    list.insert(25, 1);

    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.get(1), 25);
}