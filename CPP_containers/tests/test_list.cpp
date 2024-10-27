#include "tests.h"

TEST(List, default_constructor) {
  mo::list<int> list_int;
  mo::list<double> list_double;

  EXPECT_TRUE(list_int.empty());
  EXPECT_TRUE(list_double.empty());
}

TEST(List, size) {
  mo::list<int> list_int(3);
  mo::list<double> list_double(5);

  EXPECT_EQ(list_int.size(), 3);
  EXPECT_EQ(list_double.size(), 5);
}

TEST(List, init_list) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(list_int.size(), 3);
  EXPECT_EQ(list_double.size(), 5);
}

TEST(List, copy_constructor) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  mo::list<int> copy_list_int(list_int);
  mo::list<double> copy_list_double(list_double);

  EXPECT_EQ(copy_list_int.size(), 3);
  EXPECT_EQ(copy_list_double.size(), 5);
}

TEST(List, move_constructor) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  mo::list<int> move_list_int(std::move(list_int));
  mo::list<double> move_list_double(std::move(list_double));

  EXPECT_EQ(move_list_int.size(), 3);
  EXPECT_EQ(move_list_double.size(), 5);
}

TEST(List, copy_assignment) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  mo::list<int> copy_list_int = list_int;
  mo::list<double> copy_list_double = list_double;

  EXPECT_EQ(copy_list_int.size(), 3);
  EXPECT_EQ(copy_list_double.size(), 5);
}

TEST(List, move_assignment) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  mo::list<int> move_list_int = std::move(list_int);
  mo::list<double> move_list_double = std::move(list_double);

  EXPECT_EQ(move_list_int.size(), 3);
  EXPECT_EQ(move_list_double.size(), 5);
}

TEST(List, destructor) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  list_int.~list();
  list_double.~list();

  EXPECT_TRUE(list_int.empty());
  EXPECT_TRUE(list_double.empty());
}

TEST(List, front) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_double.front(), 1.1);
}

TEST(List, front_empty) {
  mo::list<int> list_int;
  mo::list<double> list_double;

  EXPECT_THROW(list_int.front(), std::out_of_range);
  EXPECT_THROW(list_double.front(), std::out_of_range);
}

TEST(List, back) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(list_int.back(), 5);
  EXPECT_EQ(list_double.back(), 5.5);
}

TEST(List, back_empty) {
  mo::list<int> list_int;
  mo::list<double> list_double;

  EXPECT_THROW(list_int.back(), std::out_of_range);
  EXPECT_THROW(list_double.back(), std::out_of_range);
}

TEST(List, begin) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(*list_int.begin(), 1);
  EXPECT_EQ(*list_double.begin(), 1.1);
}

TEST(List, end) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<int>::iterator it = list_int.end();
  mo::list<int>::iterator it_2 = list_int.begin();
  for (int i = 0; i < 3; i++) it_2++;
  EXPECT_EQ(it, it_2);
}

TEST(List, clear) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  list_int.clear();
  list_double.clear();

  EXPECT_TRUE(list_int.empty());
  EXPECT_TRUE(list_double.empty());
}

TEST(List, empty) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_FALSE(list_int.empty());
  EXPECT_FALSE(list_double.empty());
}

TEST(List, max_size) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(list_int.max_size(), 4611686018427387903);
  EXPECT_EQ(list_double.max_size(), 2305843009213693951);
}
TEST(List, insert_begin) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  list_int.insert(list_int.begin(), 2);
  list_double.insert(list_double.begin(), 2.2);
  EXPECT_EQ(list_int.front(), 2);
  EXPECT_EQ(list_double.front(), 2.2);
  EXPECT_EQ(list_int.size(), 4);
  EXPECT_EQ(list_double.size(), 6);
}

TEST(List, insert_end) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  list_int.insert(list_int.end(), 2);
  list_double.insert(list_double.end(), 2.2);
  EXPECT_EQ(list_int.back(), 2);
  EXPECT_EQ(list_double.back(), 2.2);
  EXPECT_EQ(list_int.size(), 4);
  EXPECT_EQ(list_double.size(), 6);
}

TEST(List, insert_in_empty) {
  mo::list<int> list_int;
  mo::list<double> list_double;
  list_int.insert(list_int.begin(), 2);
  list_double.insert(list_double.begin(), 2.2);
  EXPECT_EQ(list_int.front(), 2);
  EXPECT_EQ(list_double.front(), 2.2);
  EXPECT_EQ(list_int.size(), 1);
  EXPECT_EQ(list_double.size(), 1);
}

TEST(List, insert_middle) {
  mo::list<int> list_int = {1, 2};
  mo::list<double> list_double = {1.1, 2.2};
  auto it_int = list_int.begin();
  auto it_doible = list_double.begin();
  it_int++;
  it_doible++;
  list_int.insert(it_int, 9);
  list_double.insert(it_doible, 9.9);

  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_double.front(), 1.1);
  EXPECT_EQ(list_int.back(), 2);
  EXPECT_EQ(list_double.back(), 2.2);
  EXPECT_EQ(list_int.size(), 3);
  EXPECT_EQ(list_double.size(), 3);
}

TEST(List, erase) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  list_int.erase(list_int.begin());
  list_double.erase(list_double.begin());
  EXPECT_EQ(list_int.front(), 3);
  EXPECT_EQ(list_double.front(), 2.2);
  EXPECT_EQ(list_int.size(), 2);
  EXPECT_EQ(list_double.size(), 4);
}

TEST(List, erase_empty) {
  mo::list<int> list_int;
  mo::list<double> list_double;
  EXPECT_THROW(list_int.erase(list_int.begin()), std::out_of_range);
  EXPECT_THROW(list_double.erase(list_double.begin()), std::out_of_range);
}

TEST(List, erase_back) {
  mo::list<int> list_int = {1, 2, 3};
  mo::list<double> list_double = {1.1, 2.2, 3.3};
  auto it_int = list_int.begin();
  auto it_doible = list_double.begin();
  for (int i = 0; i < 2; i++) {
    it_int++;
    it_doible++;
  }
  list_int.erase(it_int);
  list_double.erase(it_doible);
  EXPECT_EQ(list_int.back(), 2);
  EXPECT_EQ(list_double.back(), 2.2);

  EXPECT_EQ(list_int.size(), 2);
  EXPECT_EQ(list_double.size(), 2);
}

TEST(List, push_back) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  list_int.push_back(9);
  list_double.push_back(9.9);
  EXPECT_EQ(list_int.back(), 9);
  EXPECT_EQ(list_double.back(), 9.9);
  EXPECT_EQ(list_int.size(), 4);
  EXPECT_EQ(list_double.size(), 6);
}

TEST(List, pop_back) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  list_int.pop_back();
  list_double.pop_back();
  EXPECT_EQ(list_int.back(), 3);
  EXPECT_EQ(list_double.back(), 4.4);
  EXPECT_EQ(list_int.size(), 2);
  EXPECT_EQ(list_double.size(), 4);
}

TEST(List, pop_back_one) {
  mo::list<int> list_int = {1};
  mo::list<double> list_double = {1.1};
  list_int.pop_back();
  list_double.pop_back();
  EXPECT_TRUE(list_int.empty());
  EXPECT_TRUE(list_double.empty());
}

TEST(List, pop_back_empty) {
  mo::list<int> list_int;
  mo::list<double> list_double;
  EXPECT_THROW(list_int.pop_back(), std::out_of_range);
  EXPECT_THROW(list_double.pop_back(), std::out_of_range);
}

TEST(List, push_front) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  list_int.push_front(9);
  list_double.push_front(9.9);
  EXPECT_EQ(list_int.front(), 9);
  EXPECT_EQ(list_double.front(), 9.9);
  EXPECT_EQ(list_int.size(), 4);
  EXPECT_EQ(list_double.size(), 6);
}

TEST(List, push_front_empty) {
  mo::list<int> list_int;
  mo::list<double> list_double;
  list_int.push_front(9);
  list_double.push_front(9.9);
  EXPECT_EQ(list_int.front(), 9);
  EXPECT_EQ(list_double.front(), 9.9);
  EXPECT_EQ(list_int.size(), 1);
  EXPECT_EQ(list_double.size(), 1);
}

TEST(List, pop_front) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  list_int.pop_front();
  list_double.pop_front();
  EXPECT_EQ(list_int.front(), 3);
  EXPECT_EQ(list_double.front(), 2.2);
  EXPECT_EQ(list_int.size(), 2);
  EXPECT_EQ(list_double.size(), 4);
}

TEST(List, pop_front_one) {
  mo::list<int> list_int = {1};
  mo::list<double> list_double = {1.1};
  list_int.pop_front();
  list_double.pop_front();
  EXPECT_TRUE(list_int.empty());
  EXPECT_TRUE(list_double.empty());
}

TEST(List, pop_front_empty) {
  mo::list<int> list_int;
  mo::list<double> list_double;
  EXPECT_THROW(list_int.pop_front(), std::out_of_range);
  EXPECT_THROW(list_double.pop_front(), std::out_of_range);
}

TEST(List, swap) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  mo::list<int> list_int_1 = {9, 8, 7};
  mo::list<double> list_double_1 = {9.9, 8.8, 7.7, 6.6, 5.5};
  list_int.swap(list_int_1);
  list_double.swap(list_double_1);
  EXPECT_EQ(list_int.front(), 9);
  EXPECT_EQ(list_double.front(), 9.9);
  EXPECT_EQ(list_int_1.front(), 1);
  EXPECT_EQ(list_double_1.front(), 1.1);
  EXPECT_EQ(list_int.size(), 3);
  EXPECT_EQ(list_double.size(), 5);
  EXPECT_EQ(list_int_1.size(), 3);
  EXPECT_EQ(list_double_1.size(), 5);
}

TEST(List, merge) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  mo::list<int> list_int_1 = {9, 8, 7};
  mo::list<double> list_double_1 = {9.9, 8.8, 7.7, 6.6, 5.5};
  list_int.merge(list_int_1);
  list_double.merge(list_double_1);

  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_int.back(), 9);

  EXPECT_EQ(list_double.front(), 1.1);
  EXPECT_EQ(list_double.back(), 9.9);

  EXPECT_EQ(list_int.size(), 6);
  EXPECT_EQ(list_double.size(), 10);
  EXPECT_TRUE(list_int_1.empty());
  EXPECT_TRUE(list_double_1.empty());
}

TEST(List, merge_not_equal_size) {
  mo::list<int> list_int = {1, 3, 5};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4, 5.5};
  mo::list<int> list_int_1 = {9, 8};
  mo::list<double> list_double_1 = {9.9, 8.8, 7.7};
  list_int.merge(list_int_1);
  list_double.merge(list_double_1);

  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_int.back(), 9);

  EXPECT_EQ(list_double.front(), 1.1);
  EXPECT_EQ(list_double.back(), 9.9);

  EXPECT_EQ(list_int.size(), 5);
  EXPECT_EQ(list_double.size(), 8);
  EXPECT_TRUE(list_int_1.empty());
  EXPECT_TRUE(list_double_1.empty());
}

TEST(List, splice) {
  mo::list<int> list_int = {1, 2, 3, 4};
  mo::list<int> list_int_2 = {5, 6, 7};
  auto pos = list_int.begin();
  pos++;
  EXPECT_EQ(*pos, 2);
  list_int.splice(pos, list_int_2);
  EXPECT_EQ(*pos, 2);
  pos = list_int.begin();
  pos++;
  EXPECT_EQ(*pos, 5);
  pos++;
  EXPECT_EQ(*pos, 6);
  pos++;
  EXPECT_EQ(*pos, 7);
  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_int.back(), 4);
  EXPECT_EQ(list_int.size(), 7);
  EXPECT_TRUE(list_int_2.empty());
}

TEST(List, reverse) {
  mo::list<int> list_int = {1, 2, 3, 4};
  mo::list<double> list_double = {1.1, 2.2, 3.3, 4.4};
  list_int.reverse();
  list_double.reverse();
  EXPECT_EQ(list_int.front(), 4);
  EXPECT_EQ(list_int.back(), 1);
  EXPECT_EQ(list_int.size(), 4);
  EXPECT_EQ(list_double.front(), 4.4);
  EXPECT_EQ(list_double.back(), 1.1);
  EXPECT_EQ(list_double.size(), 4);
}

TEST(List, unique) {
  mo::list<int> list_int = {1, 2, 3, 3, 3, 4};
  list_int.unique();
  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_int.back(), 4);
  EXPECT_EQ(list_int.size(), 4);
}

TEST(List, sort) {
  mo::list<int> list_int = {5, 1, 7, 9, 5, 3};
  mo::list<double> list_double = {4.4, 1.1, 7.7, 9.9, 5.5, 3.3};
  list_int.sort();
  list_double.sort();
  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_int.back(), 9);
  EXPECT_EQ(list_int.size(), 6);
  EXPECT_EQ(list_double.front(), 1.1);
  EXPECT_EQ(list_double.back(), 9.9);
  EXPECT_EQ(list_double.size(), 6);
}

TEST(List, insert_many) {
  mo::list<int> list_int = {1, 2, 3, 4};

  list_int.insert_many(list_int.cbegin(), 99, 88, 77);

  EXPECT_EQ(list_int.front(), 99);
  EXPECT_EQ(list_int.back(), 4);
  EXPECT_EQ(list_int.size(), 7);
}

TEST(List, insert_many_back) {
  mo::list<int> list_int = {1, 2, 3, 4};
  list_int.insert_many_back(99, 88, 77);
  EXPECT_EQ(list_int.front(), 1);
  EXPECT_EQ(list_int.back(), 77);
  EXPECT_EQ(list_int.size(), 7);
}

TEST(List, insert_many_front) {
  mo::list<int> list_int = {1, 2, 3, 4};
  list_int.insert_many_front(99, 88, 77);
  EXPECT_EQ(list_int.front(), 99);
  EXPECT_EQ(list_int.back(), 4);
  EXPECT_EQ(list_int.size(), 7);
}