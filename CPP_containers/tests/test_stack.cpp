#include "tests.h"

TEST(stack, default_constructor) {
  mo::stack<int> s_int;
  mo::stack<double> s_double;
  EXPECT_EQ(s_int.size(), 0);
}

TEST(stack, constructor_initializer_list) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<double> s_double({1.1, 2.2, 3.3});
  EXPECT_EQ(s_int.size(), 3);
  EXPECT_EQ(s_double.size(), 3);
}

TEST(stack, copy_constructor) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<int> s2_int(s_int);

  mo::stack<double> s_double({1.1, 2.2, 3.3});
  mo::stack<double> s2_double(s_double);

  EXPECT_EQ(s_int.top(), 3);
  EXPECT_EQ(s_double.top(), 3.3);

  EXPECT_EQ(s2_int.size(), 3);
  EXPECT_EQ(s2_double.size(), 3);

  EXPECT_EQ(s2_int.top(), s_int.top());
  EXPECT_EQ(s2_double.top(), s_double.top());
}

TEST(stack, move_constructor) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<int> s2_int(std::move(s_int));

  mo::stack<double> s_double({1.1, 2.2, 3.3});
  mo::stack<double> s2_double(std::move(s_double));

  EXPECT_EQ(s2_int.top(), 3);
  EXPECT_EQ(s2_double.top(), 3.3);

  EXPECT_EQ(s_double.size(), 0);
  EXPECT_EQ(s2_double.size(), 3);
  EXPECT_EQ(s_int.size(), 0);
  EXPECT_EQ(s2_int.size(), 3);
}

TEST(stack, destructor) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<double> s_double({1.1, 2.2, 3.3});

  s_int.~stack();
  s_double.~stack();

  EXPECT_EQ(s_int.size(), 0);
  EXPECT_EQ(s_double.size(), 0);
}

TEST(stack, assignment_operator) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<double> s_double({1.1, 2.2, 3.3});
  mo::stack<int> s2_int;
  mo::stack<double> s2_double;
  s2_int = s_int;
  s2_double = s_double;
  EXPECT_EQ(s2_int.top(), 3);
  EXPECT_EQ(s2_double.top(), 3.3);

  EXPECT_EQ(s2_int.size(), 3);
  EXPECT_EQ(s2_double.size(), 3);
}

TEST(stack, move_operator) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<int> s2_int;
  s2_int = std::move(s_int);

  mo::stack<double> s_double({1.1, 2.2, 3.3});
  mo::stack<double> s2_double;
  s2_double = std::move(s_double);

  EXPECT_EQ(s_int.size(), 0);
  EXPECT_EQ(s2_int.size(), 3);
  EXPECT_EQ(s2_int.top(), 3);
  EXPECT_EQ(s_double.size(), 0);
  EXPECT_EQ(s2_double.size(), 3);
  EXPECT_EQ(s2_double.top(), 3.3);
}

TEST(stack, clear) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<double> s_double({1.1, 2.2, 3.3});
  s_int.clear();
  s_double.clear();
  EXPECT_EQ(s_int.size(), 0);
  EXPECT_EQ(s_double.size(), 0);
}

TEST(stack, swap) {
  mo::stack<int> s_int({1, 2, 3});
  mo::stack<int> s2_int({4, 5});

  s_int.swap(s2_int);

  EXPECT_EQ(s_int.size(), 2);
  EXPECT_EQ(s2_int.size(), 3);
  EXPECT_EQ(s2_int.top(), 3);
  EXPECT_EQ(s_int.top(), 5);
}

TEST(stack, pop) {
  mo::stack<int> s_int({1, 2, 3});
  s_int.pop();

  EXPECT_EQ(s_int.size(), 2);
  EXPECT_EQ(s_int.top(), 2);
}

TEST(stack, top_pop_error) {
  mo::stack<int> s_int;

  EXPECT_THROW(s_int.top(), std::out_of_range);
  EXPECT_THROW(s_int.pop(), std::out_of_range);
}

TEST(stack, insert_many_back) {
  mo::stack<int> s_int({1, 2, 3});
  s_int.insert_many_back(4, 5, 6);
  EXPECT_EQ(s_int.top(), 6);
  EXPECT_EQ(s_int.size(), 6);
}
