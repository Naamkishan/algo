#include <gtest/gtest.h>
#include "Queue.h"

TEST(TestQueue, Initialisation) {
  ASSERT_NO_THROW(Queue<int> queue);
}

TEST(TestQueue, Enqueue) {
  Queue<int> queue;
  queue.enqueue(10);
  ASSERT_TRUE(queue.size() == 1);
}

TEST(TestQueue, Dequeue) {
  Queue<int> queue;
  queue.enqueue(10);
  ASSERT_TRUE(queue.dequeue() == 10);
}

TEST(TestQueue, QueueEmpty) {
  Queue<int> queue;
  ASSERT_TRUE(queue.empty());
}

TEST(TestQueue, QueueUnderflow) {
  Queue<int> queue;
  ASSERT_THROW(queue.dequeue(), std::out_of_range);
}


TEST(TestQueue, MultiOps) {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  ASSERT_TRUE(queue.size() == 4);
  ASSERT_TRUE(queue.dequeue() == 1);
  ASSERT_TRUE(queue.dequeue() == 2);
  ASSERT_TRUE(queue.size() == 2);
  queue.enqueue(10);
  queue.enqueue(20);
  ASSERT_TRUE(queue.size() == 4);
  ASSERT_TRUE(queue.dequeue() == 3);
  ASSERT_TRUE(queue.dequeue() == 4);
  ASSERT_TRUE(queue.dequeue() == 10);
  ASSERT_TRUE(queue.dequeue() == 20);
}



int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
