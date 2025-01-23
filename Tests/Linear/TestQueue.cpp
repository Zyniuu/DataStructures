#include <gtest/gtest.h>
#include "../../DataStructures/Linear/Queue/Queue.hpp"

// Test case: constructor
TEST(QueueTests, ConstructorInitializesEmptyQueue)
{
    Queue<int> queue;
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.size(), 0);
}

// Test case: push and size
TEST(QueueTests, PushIncreasesSize)
{
    Queue<int> queue;
    queue.push(1);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_FALSE(queue.isEmpty());
    queue.push(2);
    EXPECT_EQ(queue.size(), 2);
}

// Test case: front and back
TEST(QueueTests, FrontAndBackWorkCorrectly)
{
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(queue.front(), 1);
    EXPECT_EQ(queue.back(), 2);
}

// Test case: pop
TEST(QueueTests, PopDecreasesSizeAndRemovesFront)
{
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.pop();
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.front(), 2);
}

// Test case: isEmpty
TEST(QueueTests, IsEmptyReturnsTrueForEmptyQueue)
{
    Queue<int> queue;
    EXPECT_TRUE(queue.isEmpty());
    queue.push(1);
    EXPECT_FALSE(queue.isEmpty());
    queue.pop();
    EXPECT_TRUE(queue.isEmpty());
}

// Test case: destructor (ensuring no memory leaks)
TEST(QueueTests, DestructorCleansUpMemory)
{
    Queue<int> *queue = new Queue<int>();
    queue->push(1);
    queue->push(2);
    delete queue;
    SUCCEED(); // If no memory issues occur, the test passes
}

// Test case: handling empty queue pop
TEST(QueueTests, PopOnEmptyQueueDoesNothing)
{
    Queue<int> queue;
    EXPECT_NO_THROW(queue.pop());
    EXPECT_TRUE(queue.isEmpty());
}