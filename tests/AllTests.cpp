#include <fstream>

#include "gtest/gtest.h"
#include "linked_stack.h"
#include "parser.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";

  return RUN_ALL_TESTS();
}

class ParserTest : public ::testing::Test {
 protected:
  std::ifstream file1{"assets/dataset01.xml"};
  std::ifstream file4{"assets/dataset04.xml"};
  std::ifstream file6{"assets/dataset06.xml"};
  Parser parser1{file1};
  Parser parser4{file4};
  Parser parser6{file6};

  std::ifstream file2{"assets/dataset02.xml"};
  std::ifstream file3{"assets/dataset03.xml"};
  std::ifstream file5{"assets/dataset05.xml"};
  Parser parser2{file2};
  Parser parser3{file3};
  Parser parser5{file5};
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
