#include <stdio.h>
#include <string.h>

#include <fstream>
#include <sstream>

#include "gtest/gtest.h"
#include "linked_stack.h"
#include "linked_queue.h"
#include "parser.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";

  return RUN_ALL_TESTS();
}

class ParserTest : public ::testing::Test {
 protected:
  std::string setup(std::string path) {
    std::stringstream buffer;
    std::ifstream file(path);
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
  }

  Parser parser1{setup("assets/dataset01.xml")};
  Parser parser2{setup("assets/dataset02.xml")};
  Parser parser3{setup("assets/dataset03.xml")};
  Parser parser4{setup("assets/dataset04.xml")};
  Parser parser5{setup("assets/dataset05.xml")};
  Parser parser6{setup("assets/dataset06.xml")};
};

TEST_F(ParserTest, ParseFileReturnsTrueWhenValidXML) {
  ASSERT_TRUE(parser1.parse_file());
  ASSERT_TRUE(parser4.parse_file());
  ASSERT_TRUE(parser6.parse_file());
}

TEST_F(ParserTest, ParseFileReturnsFalseWhenInvalidXML) {
  ASSERT_FALSE(parser2.parse_file());
  ASSERT_FALSE(parser3.parse_file());
  ASSERT_FALSE(parser5.parse_file());
}

TEST_F(ParserTest, MatchReturnsTrueWhenMatches) {
  ASSERT_TRUE(parser1.match("<oi>", "</oi>"));
  ASSERT_TRUE(parser1.match("<tchau>", "</tchau>"));
}

TEST_F(ParserTest, MatchReturnsFalseWhenDontMatch) {
  ASSERT_FALSE(parser1.match("<oi>", "</io>"));
}

class LinkedStackTest : public ::testing::Test {
 protected:
  structures::LinkedStack<int> stack{};

  void fill(void) {
    for (auto i = 0; i < 10; i++) {
      stack.push(i);
    }
  }
};

TEST_F(LinkedStackTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(stack.empty());
}

TEST_F(LinkedStackTest, EmptyReturnsFalseWhenNotEmpty) {
  stack.push(0);
  ASSERT_FALSE(stack.empty());
}

TEST_F(LinkedStackTest, ClearStackSuccessfully) {
  fill();
  stack.clear();
  ASSERT_EQ(0, stack.size());
}

TEST_F(LinkedStackTest, PushIncreasesSize) {
  stack.push(1);
  ASSERT_EQ(1, stack.size());
}

TEST_F(LinkedStackTest, PushPushesData) {
  stack.push(1);
  ASSERT_EQ(1, stack.top());

  stack.push(2);
  ASSERT_EQ(2, stack.top());
}

TEST_F(LinkedStackTest, PopDecreasesSize) {
  fill();
  stack.pop();

  ASSERT_EQ(stack.size(), 10 - 1);

  stack.pop();
  ASSERT_EQ(stack.size(), 10 - 2);
}

TEST_F(LinkedStackTest, PopCorrectElement) {
  fill();
  for (auto i = 0u; i < 10; ++i) {
    ASSERT_EQ((10 - 1) - i, stack.pop());
  }
}

TEST_F(LinkedStackTest, PopFromEmptyThrowsError) {
  ASSERT_THROW(stack.pop(), std::out_of_range);

  fill();
  for (auto i = 0u; i < 10; ++i) {
    ASSERT_EQ((10 - 1) - i, stack.pop());
  }

  ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST_F(LinkedStackTest, TopReturnsTopElement) {
  fill();
  for (auto i = 0u; i < 10; ++i) {
    ASSERT_EQ(9 - i, stack.top());
    stack.pop();
  }
}

TEST_F(LinkedStackTest, TopOnEmptyThrowsError) {
  ASSERT_THROW(stack.top(), std::out_of_range);
}

TEST_F(LinkedStackTest, TopAsLhsWorks) {
  fill();
  stack.top() = -2;
  ASSERT_EQ(-2, stack.top());
}

class LinkedQueueTest : public ::testing::Test {
 protected:
  structures::LinkedQueue<int> queue{};

  void fill(void) {
    for (auto i = 0; i < 10; i++) {
      queue.enqueue(i);
    }
  }
};

TEST_F(LinkedQueueTest, SizeReturnsCorrectValue) {
  ASSERT_EQ(0, queue.size());

  fill();
  ASSERT_EQ(10, queue.size());
}

TEST_F(LinkedQueueTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(queue.empty());
}

TEST_F(LinkedQueueTest, EmptyReturnsFalseWhenNotEmpty) {
  fill();
  ASSERT_FALSE(queue.empty());
}

TEST_F(LinkedQueueTest, EnqueueIncreasesSize) {
  queue.enqueue(1);
  ASSERT_EQ(1, queue.size());
  queue.enqueue(1);
  ASSERT_EQ(2, queue.size());
}

TEST_F(LinkedQueueTest, EnqueuesData) {
  for (auto i = 0; i < 10; i++) {
    queue.enqueue(i);
    ASSERT_EQ(i, queue.back());
  }
}

TEST_F(LinkedQueueTest, BackReturnCorrectElement) {
  for (auto i = 0; i < 10; i++) {
    queue.enqueue(i);
    ASSERT_EQ(i, queue.back());
  }
}

TEST_F(LinkedQueueTest, BackThrowsErrorOnEmptyQueue) {
  ASSERT_THROW(queue.back(), std::out_of_range);
}

TEST_F(LinkedQueueTest, BackWorksAsLhs) {
  fill();
  queue.back() = -2;
  ASSERT_EQ(-2, queue.back());
}

TEST_F(LinkedQueueTest, ClearSetsSize0) {
  fill();
  queue.clear();
  ASSERT_EQ(0, queue.size());
}

TEST_F(LinkedQueueTest, DequeueDecreasesSize) {
  fill();
  for (auto i = 9; i >= 0; i--) {
    queue.dequeue();
    ASSERT_EQ(i, queue.size());
  }
}

TEST_F(LinkedQueueTest, DequeueThrowsErrorWhenEmpty) {
  ASSERT_THROW(queue.dequeue(), std::out_of_range);
}

TEST_F(LinkedQueueTest, DequeueReturnsCorrectElement) {
  fill();

  for (auto i = 0; i < 10; i++) {
    ASSERT_EQ(i, queue.dequeue());
  }
}
