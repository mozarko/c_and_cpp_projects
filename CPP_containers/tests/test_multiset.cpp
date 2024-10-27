#include "tests.h"

TEST(multiset_constructor, no_arg) {
  mo::multiset<int> _multiset;
  EXPECT_EQ(_multiset.empty(), 1);
}

TEST(multiset_constructor, initializer_list) {
  mo::multiset<int> _multiset({11, 2, 99, 0});
  EXPECT_EQ(_multiset.empty(), 0);
}

TEST(multiset_constructor, copy) {
  mo::multiset<int> _multiset({11, 2, 99, 0});
  mo::multiset<int> multiset_copy(_multiset);
  auto j = multiset_copy.begin();
  for (auto i = _multiset.begin(); i != _multiset.end(); ++i) {
    ASSERT_TRUE(i->key_ == j->key_);
    ++j;
  }
}

TEST(multiset_constructor, move) {
  mo::multiset<int> _multiset({11, 2, 99, 0});
  mo::multiset<int> multiset_copy(_multiset);
  mo::multiset<int> multiset_moved(std::move(_multiset));
  auto j = multiset_moved.begin();
  for (auto i = multiset_copy.begin(); i != multiset_copy.end(); ++i) {
    ASSERT_TRUE(i->key_ == j->key_);
    ++j;
  }
  EXPECT_EQ(_multiset.empty(), 1);
}

TEST(multiset_operator, move_assignment) {
  mo::multiset<std::string> first({"this", "world", "is mine"});
  mo::multiset<std::string> copy(first);
  mo::multiset<std::string> second;
  second = std::move(first);
  auto j = second.begin();
  for (auto i = copy.begin(); i != copy.end(); ++i) {
    ASSERT_TRUE(i->key_ == j->key_);
    ++j;
  }
  EXPECT_EQ(first.empty(), 1);
}

TEST(multiset_iterator, begin) {
  mo::multiset<std::string> _multiset({"this", "world", "is mine"});
  auto i = _multiset.begin();
  EXPECT_EQ(i->key_, "is mine");
}

TEST(multiset_iterator, end) {
  mo::multiset<std::string> _multiset({"this", "world", "is mine"});
  auto i = _multiset.end();
  EXPECT_EQ(i->key_, "world");
}

TEST(multiset_iterator_operator, increment) {
  mo::multiset<std::string> _multiset({"this", "world", "is mine"});
  auto i = _multiset.begin();
  ++i;
  EXPECT_EQ(i->key_, "this");
  i++;
  EXPECT_EQ(i->key_, "world");
}

TEST(multiset_iterator_operator, decrement) {
  mo::multiset<int> _multiset({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  auto i = _multiset.end();
  --i;
  EXPECT_EQ(i->key_, 5);
  i--;
  EXPECT_EQ(i->key_, 4);
}

TEST(multiset_iterator_operator, decrement_test_1) {
  mo::multiset<int> ms({1, 5, 3, 4, 2, 0});
  auto i = ms.end();
  int j = 5;
  while (i != ms.begin()) {
    --i;
    EXPECT_EQ(i->key_, j);
    --j;
  }
}

TEST(multiset_size, size_check) {
  mo::multiset<int> _multiset({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  EXPECT_EQ(_multiset.size(), 10);
  _multiset.clear();
  EXPECT_EQ(_multiset.empty(), 1);
  EXPECT_EQ(_multiset.max_size(),
            std::numeric_limits<size_t>::max() / sizeof(int));
  EXPECT_EQ(_multiset.size(), 0);
}

TEST(multiset_insert, insert_test_0) {
  mo::multiset<int> _multiset;
  _multiset.insert(9);
  auto i = _multiset.begin();
  EXPECT_EQ(i->key_, 9);
}

TEST(multiset_insert, insert_test_1) {
  mo::multiset<int> _multiset({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  _multiset.insert(90);
  EXPECT_EQ(_multiset.contains(90), 1);
}

/*TEST(multiset_insert, insert_many_test_0) {
  mo::multiset<int> _multiset({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  auto v = _multiset.insert_many(1, 90, 10);
  EXPECT_EQ(_multiset.contains(90), 1);
  EXPECT_EQ(_multiset.contains(10), 1);
  EXPECT_EQ(_multiset.count(1), 3);
  EXPECT_EQ(v[0].second, 1);
  EXPECT_EQ(v[1].second, 1);
  EXPECT_EQ(v[2].second, 1);
}*/

TEST(multiset_erase, erase_test_0) {
  mo::multiset<int> _multiset({5, 4, 1, 0, 2, 1, 4, 3, 3, 2});
  auto i = _multiset.find(5);
  _multiset.erase(i);
  EXPECT_EQ(_multiset.contains(5), 0);
}

TEST(multiset_swap, swap_test_0) {
  mo::multiset<int> _multiset({5, 4, 1, 0, 12, 1, 4, 3, 2});
  mo::multiset<int> multiset_copy(_multiset);
  mo::multiset<int> _s({9, 20, 30, 40});
  mo::multiset<int> s_copy(_s);
  _multiset.swap(_s);
  auto it = _s.begin();
  for (auto i = multiset_copy.begin(); i != multiset_copy.end(); ++i) {
    EXPECT_EQ(i->key_, it->key_);
    ++it;
  }
  it = _multiset.begin();
  for (auto i = s_copy.begin(); i != s_copy.end(); ++i) {
    EXPECT_EQ(i->key_, it->key_);
    ++it;
  }
}

TEST(multiset_merge, merge_test_0) {
  mo::multiset<int> _multiset({5, 0, 12, 1, 4, 3, 2});
  mo::multiset<int> _s({13, 10, 6, 9, 7, 11, 8});
  _multiset.merge(_s);
  int i = 0;
  for (auto it = _multiset.begin(); it != _multiset.end(); ++it)
    EXPECT_EQ(it->key_, i++);
}

TEST(multiset_contains, contains_test_0) {
  mo::multiset<int> _multiset({5, 0, 12, 1, 4, 3, 2});
  _multiset.insert(33);
  EXPECT_EQ(_multiset.contains(33), 1);
  EXPECT_EQ(_multiset.contains(36), 0);
}

TEST(multiset_find, find_test_0) {
  mo::multiset<int> _multiset({5, 0, 12, 1, 4, 3, 2});
  int k = 5;
  auto i = _multiset.find(k);
  for (auto it = _multiset.begin(); it != _multiset.end(); ++it) {
    if (it->key_ == k) {
      EXPECT_EQ(it, i);
    }
  }
}

TEST(multiset_equal_range, equal_range_test_0) {
  mo::multiset<int> _multiset({5, 0, 4, 12, 1, 4, 3, 2, 4, 4});
  int k = 4;
  auto pair = _multiset.equal_range(k);
  int _c = 0;
  for (auto i = pair.first; i != pair.second; ++i) {
    EXPECT_EQ(i->key_, k);
    _c++;
  }
  EXPECT_EQ(_c, _multiset.count(k));
}

TEST(multiset_bounds, equal_bounds_test_0) {
  mo::multiset<int> _multiset({5, 0, 4, 12, 1, 4, 3, 2, 4, 4});
  int k = 4;
  auto _end = _multiset.upper_bound(k);
  int _c = 0;
  for (auto i = _multiset.lower_bound(k); i != _end; ++i) {
    EXPECT_EQ(i->key_, k);
    _c++;
  }
  EXPECT_EQ(_c, _multiset.count(k));
}
