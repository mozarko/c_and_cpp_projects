#include "tests.h"

TEST(Set_Constructor, No_Arg) {
  mo::set<int> _set;
  EXPECT_EQ(_set.empty(), 1);
}

TEST(Set_Constructor, Initializer_List) {
  mo::set<int> _set({11, 2, 99, 0});
  EXPECT_EQ(_set.empty(), 0);
}

TEST(Set_Constructor, Copy) {
  mo::set<int> _set({11, 2, 99, 0});
  mo::set<int> set_copy(_set);
  auto j = set_copy.begin();
  for (auto i = _set.begin(); i != _set.end(); ++i) {
    ASSERT_TRUE(i->key_ == j->key_);
    ++j;
  }
}

TEST(Set_Constructor, Move) {
  mo::set<int> _set({11, 2, 99, 0});
  mo::set<int> set_copy(_set);
  mo::set<int> set_moved(std::move(_set));
  auto j = set_moved.begin();
  for (auto i = set_copy.begin(); i != set_copy.end(); ++i) {
    ASSERT_TRUE(i->key_ == j->key_);
    ++j;
  }
  EXPECT_EQ(_set.empty(), 1);
}

TEST(Set_Operator, Move_Assignment) {
  mo::set<std::string> first({"this", "world", "is mine"});
  mo::set<std::string> copy(first);
  mo::set<std::string> second;
  second = std::move(first);
  auto j = second.begin();
  for (auto i = copy.begin(); i != copy.end(); ++i) {
    ASSERT_TRUE(i->key_ == j->key_);
    ++j;
  }
  EXPECT_EQ(first.empty(), 1);
}

TEST(Set_Iterator, Begin) {
  mo::set<std::string> _set({"this", "world", "is mine"});
  auto i = _set.begin();
  EXPECT_EQ(i->key_, "is mine");
}

TEST(Set_Iterator, End) {
  mo::set<std::string> _set({"this", "world", "is mine"});
  auto i = _set.end();
  EXPECT_EQ(i->key_, "world");
}

TEST(Set_Iterator, Increment) {
  mo::set<std::string> _set({"this", "world", "is mine"});
  auto i = _set.begin();
  ++i;
  EXPECT_EQ(i->key_, "this");
  i++;
  EXPECT_EQ(i->key_, "world");
}

TEST(Set_Iterator, Decrement_Test_0) {
  mo::set<int> _set({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  auto i = _set.end();
  --i;
  EXPECT_EQ(i->key_, 5);
  i--;
  EXPECT_EQ(i->key_, 4);
}

TEST(Set_Iterator, Decrement_Test_1) {
  mo::set<int> _set({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  auto i = _set.end();
  int j = 5;
  while (i != _set.begin()) {
    --i;
    EXPECT_EQ(i->key_, j);
    --j;
  }
}

TEST(Set_Capacity, Size_Check) {
  mo::set<int> _set({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  EXPECT_EQ(_set.size(), 6);
  _set.clear();
  EXPECT_EQ(_set.empty(), 1);
  EXPECT_EQ(_set.max_size(), std::numeric_limits<size_t>::max() / sizeof(int));
  EXPECT_EQ(_set.size(), 0);
}

TEST(Set_Capacity, Insert_Test_0) {
  mo::set<int> _set;
  _set.insert(9);
  auto i = _set.begin();
  EXPECT_EQ(i->key_, 9);
}

TEST(Set_Modifiers, Insert_Test_1) {
  mo::set<int> _set({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  _set.insert(90);
  EXPECT_EQ(_set.contains(90), 1);
}

/*TEST(set_insert, insert_many_test_0) {
  mo::set<int> _set({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  auto v = _set.insert_many(1, 90, 10);
  EXPECT_EQ(_set.contains(90), 1);
  EXPECT_EQ(_set.contains(10), 1);
  EXPECT_EQ(v[0].second, 0);
  EXPECT_EQ(v[1].second, 1);
  EXPECT_EQ(v[2].second, 1);
}*/

TEST(Set_Modifiers, Erase_Test) {
  mo::set<int> _set({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  auto i = _set.insert(8).first;
  _set.erase(i);
  EXPECT_EQ(_set.contains(8), 0);
}

TEST(Set_Modifiers, Swap_Test) {
  mo::set<int> _set({5, 4, 1, 0, 12, 1, 4, 3, 2});
  mo::set<int> set_copy(_set);
  mo::set<int> _s({9, 20, 30, 40});
  mo::set<int> s_copy(_s);
  _set.swap(_s);
  auto it = _s.begin();
  for (auto i = set_copy.begin(); i != set_copy.end(); ++i) {
    EXPECT_EQ(i->key_, it->key_);
    ++it;
  }
  it = _set.begin();
  for (auto i = s_copy.begin(); i != s_copy.end(); ++i) {
    EXPECT_EQ(i->key_, it->key_);
    ++it;
  }
}

TEST(Set_Modifiers, Merge_Test_0) {
  mo::set<int> _set({5, 0, 12, 1, 4, 3, 2});
  mo::set<int> _s({13, 10, 6, 9, 7, 11, 8});
  _set.merge(_s);
  int i = 0;
  for (auto it = _set.begin(); it != _set.end(); ++it)
    EXPECT_EQ(it->key_, i++);
}

TEST(Set_Lookup, contains_test_0) {
  mo::set<int> _set({5, 0, 12, 1, 4, 3, 2});
  _set.insert(33);
  EXPECT_EQ(_set.contains(33), 1);
  EXPECT_EQ(_set.contains(36), 0);
}

TEST(Set_Lookup, find_test_0) {
  mo::set<int> _set({5, 0, 12, 1, 4, 3, 2});
  int k = 5;
  auto i = _set.find(k);
  for (auto it = _set.begin(); it != _set.end(); ++it) {
    if (it->key_ == k) {
      EXPECT_EQ(it, i);
    }
  }
}
