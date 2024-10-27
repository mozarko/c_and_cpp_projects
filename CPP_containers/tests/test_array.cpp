#include "tests.h"

TEST(Array_Constructor, Default_Empty) {
  mo::array<int, 0> array;

  EXPECT_EQ(array.empty(), 1);
}

TEST(Array_Constructor, Default_Not_Empty) {
  mo::array<double, 5> array;

  EXPECT_EQ(array.empty(), 0);
}

TEST(Array_Constructor, Initializer_List) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.size(), 3);
}

TEST(Array_Constructor, Copy) {
  mo::array<int, 3> array = {1, 2, 3};
  mo::array<int, 3> copy(array);

  EXPECT_EQ(copy.size(), 3);
}

TEST(Array_Constructor, Move) {
  mo::array<int, 3> array = {1, 2, 3};
  mo::array<int, 3> move(std::move(array));

  EXPECT_EQ(array.empty(), 1);
  EXPECT_EQ(move.size(), 3);
}

TEST(Array_Constructor, Operator_Assig) {
  mo::array<int, 3> array = {1, 2, 3};
  mo::array<int, 3> move;
  move = std::move(array);

  EXPECT_EQ(move.size(), 3);
  ASSERT_ANY_THROW(move[4]);
}

TEST(Array_Element_Access, At) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.at(1), 2);
}

TEST(Array_Element_Access, At_OutOfRange) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_THROW(array.at(7), std::out_of_range);
}

TEST(Array_Element_Access, Operator_At) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array[1], 2);
}

TEST(Array_Element_Access, Front) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.front(), 1);
}

TEST(Array_Element_Access, Fron_Wrong) {
  mo::array<int, 0> array;

  ASSERT_ANY_THROW(array.front());
}

TEST(Array_Element_Access, Back) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.back(), 3);
}

TEST(Array_Element_Access, Back_Wrong) {
  mo::array<int, 0> array;

  ASSERT_ANY_THROW(array.back());
}

TEST(Array_Element_Access, Data) {
  mo::array<int, 3> array = {1, 2, 3};
  int *value = array.data();

  EXPECT_EQ(value[0], 1);
}

TEST(Array_Iterators, Begin) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(*(array.begin()), 1);
}

TEST(Array_Iterators, End) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.end(), array.begin() + 3);
}

TEST(Array_Capacity, Empty) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.empty(), 0);
}

TEST(Array_Capacity, Size) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.size(), 3);
}

TEST(Array_Capacity, Max_Size) {
  mo::array<int, 3> array = {1, 2, 3};

  EXPECT_EQ(array.max_size(), 3);
}

TEST(Array_Modifiers, Swap) {
  mo::array<int, 3> array = {1, 2, 3};
  mo::array<int, 3> array2 = {4, 5, 6};
  array.swap(array2);

  EXPECT_EQ(array.front(), 4);
  EXPECT_EQ(array.back(), 6);
  EXPECT_EQ(array2.front(), 1);
  EXPECT_EQ(array2.back(), 3);
}

TEST(Array_Modifiers, Fill) {
  mo::array<int, 3> array = {1, 2, 3};
  array.fill(5);

  EXPECT_EQ(array.front(), 5);
  EXPECT_EQ(array.back(), 5);
}
