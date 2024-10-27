#include "tests.h"

TEST(vector_constructor, default_constructor) {
  mo::vector<int> int_vector;
  mo::vector<double> double_vector;

  EXPECT_TRUE(int_vector.empty());
  EXPECT_TRUE(double_vector.empty());
}

TEST(vector_constructor, size) {
  mo::vector<int> int_vector(3);
  mo::vector<double> double_vector(3);

  EXPECT_EQ(int_vector.size(), 3);
  EXPECT_EQ(double_vector.size(), 3);
}

TEST(vector_constructor, size_zero) {
  mo::vector<int> int_vector(0);
  mo::vector<double> double_vector(0);
  EXPECT_FALSE(int_vector.size());
  EXPECT_FALSE(double_vector.size());
}

TEST(vector_constructor, size_negative) {
  EXPECT_ANY_THROW(mo::vector<int> int_vector(-1));
  EXPECT_ANY_THROW(mo::vector<double> double_vector(-1));
}

TEST(vector_constructor, init_list) {
  mo::vector<int> int_vector = {1, 2, 3, 4, -5};
  mo::vector<double> double_vector = {1.1, 2.2, -3.5};

  EXPECT_EQ(double_vector[0], 1.1);
  EXPECT_EQ(int_vector[4], -5);
  EXPECT_ANY_THROW(int_vector[5]);
}

TEST(vector_constructor, copy) {
  mo::vector<int> int_vector = {1, 3, 5};
  mo::vector<int> copy(int_vector);

  EXPECT_EQ(copy.size(), 3);
  EXPECT_EQ(copy[1], 3);
}

TEST(vector_constructor, move) {
  mo::vector<int> int_vector = {1, 3, 5, 7};
  mo::vector<int> move(std::move(int_vector));

  EXPECT_EQ(move.size(), 4);
  EXPECT_TRUE(int_vector.empty());
  EXPECT_EQ(move[1], 3);
}

TEST(vector_constructor, operator_) {
  mo::vector<int> int_vector = {1, 2, 3, 5, 7};
  mo::vector<int> int_vector2;
  mo::vector<int> eq_vector = {1, 2, 3, 5, 7};

  int_vector2 = std::move(int_vector);
  EXPECT_TRUE(int_vector2 == eq_vector);
  EXPECT_TRUE(int_vector.empty());
}

TEST(vector_access_to_element, at) {
  mo::vector<int> int_vector = {1, 2, 3, 5, 7};

  EXPECT_EQ(int_vector.at(4), 7);
}

TEST(vector_access_to_element, at_wrong) {
  mo::vector<int> int_vector = {1, 2, 3, 5, 7};

  ASSERT_ANY_THROW(int_vector.at(10));
}

TEST(vector_access_to_element, operator_at) {
  mo::vector<int> int_vector = {1, 2, 3, 5, 7};

  EXPECT_EQ(int_vector[2], int_vector.at(2));
}

TEST(vector_access_to_element, operator_at_wrong) {
  mo::vector<int> int_vector = {1, 2, 3, 5, 7};

  ASSERT_ANY_THROW(int_vector.at(15));
}

TEST(vector_access_to_element, front) {
  mo::vector<int> int_vector = {99, 2, 3, 5, 7};

  EXPECT_EQ(int_vector.front(), 99);
}

TEST(vector_access_to_element, front_wrong) {
  mo::vector<int> int_vector;

  ASSERT_ANY_THROW(int_vector.front());
}

TEST(vector_access_to_element, back) {
  mo::vector<int> int_vector = {1, 2, 3, 5, 99};

  EXPECT_EQ(int_vector.back(), 99);
}

TEST(vector_access_to_element, back_wrong) {
  mo::vector<int> int_vector;

  ASSERT_ANY_THROW(int_vector.back());
}

TEST(vector_access_to_element, data) {
  mo::vector<int> int_vector = {99, 2, 3, 5, 7};
  int *value = int_vector.data();

  EXPECT_EQ(*value, 99);
}

TEST(vector_iterators, begin) {
  mo::vector<int> int_vector = {99, 2, 3, 5, 7};
  mo::vector<int>::iterator it = int_vector.begin();

  EXPECT_EQ(*it, 99);
}

TEST(vector_iterators, end) {
  mo::vector<int> int_vector = {1, 2, 3, 5, 7, 99};

  EXPECT_EQ(int_vector.end(), int_vector.begin() + int_vector.size());
}

TEST(vector_capacity, empty) {
  mo::vector<int> int_vector;
  mo::vector<int> int_vector2(2);

  EXPECT_TRUE(int_vector.empty());
  EXPECT_FALSE(int_vector2.empty());
}

TEST(vector_capacity, size) {
  mo::vector<int> int_vector;
  mo::vector<int> int_vector2(2);

  EXPECT_EQ(int_vector.size(), 0);
  EXPECT_EQ(int_vector2.size(), 2);
}

TEST(vector_capacity, max_size) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5};

  EXPECT_TRUE(int_vector.max_size() >= int_vector.size());
}

TEST(vector_capacity, reserve) {
  mo::vector<int> int_vector(3);
  EXPECT_EQ(int_vector.capacity(), 3);

  int_vector.reserve(17);
  EXPECT_EQ(int_vector.capacity(), 17);
}

TEST(vector_capacity, reserve_max_size) {
  mo::vector<int> int_vector(3);

  ASSERT_ANY_THROW(int_vector.reserve(int_vector.max_size() + 1));
}

TEST(vector_capacity, reserve_eq_size) {
  mo::vector<int> int_vector(3);
  EXPECT_EQ(int_vector.capacity(), 3);

  int_vector.reserve(3);
  EXPECT_EQ(int_vector.capacity(), 3);
}

TEST(vector_capacity, shrink) {
  mo::vector<int> int_vector = {1, 2, 3};

  EXPECT_EQ(int_vector.capacity(), 3);

  int_vector.reserve(17);

  EXPECT_EQ(int_vector.capacity(), 17);

  int_vector.shrink_to_fit();

  EXPECT_EQ(int_vector.capacity(), 3);
}

TEST(vector_modifiers, clear) {
  mo::vector<int> int_vector(3);

  EXPECT_FALSE(int_vector.empty());

  int_vector.clear();

  EXPECT_TRUE(int_vector.empty());
}

TEST(vector_modifiers, insert) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  mo::vector<int> eq_vector = {99, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int_vector.insert(int_vector.begin(), 99);

  EXPECT_EQ(int_vector.at(0), 99);
  EXPECT_TRUE(int_vector == eq_vector);
}

TEST(vector_modifiers, insert2) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  mo::vector<int> eq_vector = {1, 2, 3, 99, 4, 5, 6, 7, 8, 9};
  int_vector.insert(int_vector.begin() + 3, 99);

  EXPECT_EQ(int_vector.at(3), 99);
  EXPECT_TRUE(int_vector == eq_vector);
}

TEST(vector_modifiers, insert_wrong) {
  mo::vector<int> int_vector = {1, 2, 3};
  ASSERT_ANY_THROW(int_vector.insert(int_vector.begin() + 10, 10));
}

TEST(vector_modifiers, erase) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  mo::vector<int> eq_vector = {2, 3, 4, 5, 6, 7, 8, 9};
  int_vector.erase(int_vector.begin());
  EXPECT_TRUE(int_vector == eq_vector);
}

TEST(vector_modifiers, erase2) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  mo::vector<int> eq_vector = {1, 2, 3, 5, 6, 7, 8, 9};
  int_vector.erase(int_vector.begin() + 3);
  EXPECT_TRUE(int_vector == eq_vector);
}

TEST(vector_modifiers, erase_wrong) {
  mo::vector<int> int_vector = {1, 2, 3};
  ASSERT_ANY_THROW(int_vector.erase(int_vector.begin() + 10));
}

TEST(vector_modifiers, push_back) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  mo::vector<int> eq_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 99};
  int_vector.push_back(99);

  EXPECT_TRUE(int_vector == eq_vector);
}

TEST(vector_modifiers, pop_back) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  mo::vector<int> eq_vector = {1, 2, 3, 4, 5, 6, 7, 8};

  int_vector.pop_back();
  EXPECT_TRUE(int_vector == eq_vector);
}

TEST(vector_modifiers, swap) {
  mo::vector<int> int_vector = {1, 2, 3};
  mo::vector<int> int_vector2 = {4, 5, 6, 7};
  mo::vector<int> eq_vector = {4, 5, 6, 7};
  mo::vector<int> eq_vector2 = {1, 2, 3};
  int_vector.swap(int_vector2);

  EXPECT_TRUE(int_vector == eq_vector);
  EXPECT_TRUE(int_vector2 == eq_vector2);
}

TEST(vector_modifiers, eq_wrong) {
  mo::vector<int> int_vector = {1, 2, 3};
  mo::vector<int> int_vector2 = {4, 5, 6, 7};

  EXPECT_FALSE(int_vector == int_vector2);
}

TEST(vector, insert_many) {
  mo::vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  mo::vector<int> eq_vector = {1, 99, 88, 77, 2, 3, 4, 5, 6, 7, 8, 9};
  int_vector.insert_many(int_vector.begin() + 1, 99, 88, 77);
  EXPECT_TRUE(int_vector == eq_vector);
}

TEST(vector, insert_many_back) {
  mo::vector<int> int_vector = {1, 2, 3};
  mo::vector<int> eq_vector = {1, 2, 3, 99, 88, 77};
  int_vector.insert_many_back(99, 88, 77);
  EXPECT_TRUE(int_vector == eq_vector);
}