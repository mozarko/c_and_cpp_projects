#include "tests.h"

TEST(queue, default_constructor) {
  mo::queue<int> int_queue;
  mo::queue<double> double_queue;

  EXPECT_FALSE(int_queue.size());
  EXPECT_TRUE(int_queue.empty());

  EXPECT_FALSE(double_queue.size());
  EXPECT_TRUE(double_queue.empty());
}

TEST(queue, initializer_list) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};

  EXPECT_EQ(int_queue.front(), 1);
  EXPECT_EQ(int_queue.back(), 3);
  EXPECT_EQ(double_queue.front(), 1.1);
  EXPECT_EQ(double_queue.back(), 3.3);

  EXPECT_EQ(int_queue.size(), 3);
  EXPECT_FALSE(int_queue.empty());
  EXPECT_EQ(double_queue.size(), 3);
  EXPECT_FALSE(double_queue.empty());
}

TEST(queue, copy_constructor) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};

  mo::queue<int> copy_queue(int_queue);
  mo::queue<double> copy_double_queue(double_queue);

  EXPECT_EQ(copy_queue.size(), 3);
  EXPECT_FALSE(copy_queue.empty());

  EXPECT_EQ(copy_double_queue.size(), 3);
  EXPECT_FALSE(copy_double_queue.empty());
}

TEST(queue, move_constructor) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};

  mo::queue<int> move_queue(std::move(int_queue));
  mo::queue<double> move_double_queue(std::move(double_queue));

  EXPECT_EQ(move_queue.size(), 3);
  EXPECT_FALSE(move_queue.empty());

  EXPECT_EQ(move_double_queue.size(), 3);
  EXPECT_FALSE(move_double_queue.empty());
}

TEST(queue, copyassignment) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};

  mo::queue<int> copy_queue = int_queue;
  mo::queue<double> copy_double_queue = double_queue;

  EXPECT_EQ(copy_queue.size(), 3);
  EXPECT_FALSE(copy_queue.empty());

  EXPECT_EQ(copy_double_queue.size(), 3);
  EXPECT_FALSE(copy_double_queue.empty());
}

TEST(queue, operatorassignment) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<int> int_queue_empty;

  int_queue_empty = int_queue;

  EXPECT_EQ(int_queue_empty.size(), 3);
  EXPECT_EQ(int_queue_empty.front(), 1);
  EXPECT_EQ(int_queue_empty.back(), 3);
}

TEST(queue, move_assignment_operator) {
  mo::queue<int> q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);

  mo::queue<int> q2;
  q2.push(4);
  q2.push(5);

  // Проверяем состояние q2 перед присваиванием
  EXPECT_EQ(q2.size(), 2);
  EXPECT_EQ(q2.front(), 4);
  EXPECT_EQ(q2.back(), 5);

  // Перемещаем q1 в q2
  q2 = std::move(q1);

  // Проверяем, что q2 теперь содержит элементы из q1
  EXPECT_EQ(q2.size(), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);

  // Проверяем, что q1 теперь пустой
  EXPECT_EQ(q1.size(), 0);
}

TEST(queue, moveassignment) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};

  mo::queue<int> move_queue = std::move(int_queue);
  mo::queue<double> move_double_queue = std::move(double_queue);

  EXPECT_EQ(move_queue.size(), 3);
  EXPECT_FALSE(move_queue.empty());

  EXPECT_EQ(move_double_queue.size(), 3);
  EXPECT_FALSE(move_double_queue.empty());
}

TEST(queue, destructor) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};

  int_queue.~queue();
  double_queue.~queue();

  EXPECT_TRUE(int_queue.empty());
  EXPECT_TRUE(double_queue.empty());
}

TEST(queue, swap) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};
  mo::queue<int> swap_queue;
  mo::queue<double> swap_double_queue;

  int_queue.swap(swap_queue);
  double_queue.swap(swap_double_queue);

  EXPECT_EQ(swap_queue.front(), 1);
  EXPECT_EQ(swap_queue.back(), 3);
  EXPECT_EQ(swap_queue.size(), 3);
  EXPECT_FALSE(swap_queue.empty());

  EXPECT_EQ(swap_double_queue.front(), 1.1);
  EXPECT_EQ(swap_double_queue.back(), 3.3);
  EXPECT_EQ(swap_double_queue.size(), 3);
  EXPECT_FALSE(swap_double_queue.empty());
}

TEST(queue, push) {
  mo::queue<int> int_queue;
  mo::queue<double> double_queue;

  int_queue.push(1);
  int_queue.push(2);
  int_queue.push(3);
  double_queue.push(1.1);
  double_queue.push(2.2);
  double_queue.push(3.3);

  EXPECT_EQ(int_queue.front(), 1);
  EXPECT_EQ(int_queue.back(), 3);
  EXPECT_EQ(double_queue.front(), 1.1);
  EXPECT_EQ(double_queue.back(), 3.3);

  EXPECT_EQ(int_queue.size(), 3);
  EXPECT_FALSE(int_queue.empty());
  EXPECT_EQ(double_queue.size(), 3);
  EXPECT_FALSE(double_queue.empty());
}

TEST(queue, pop) {
  mo::queue<int> int_queue = {1, 2, 3};
  mo::queue<double> double_queue = {1.1, 2.2, 3.3};

  int_queue.pop();
  int_queue.pop();
  double_queue.pop();
  double_queue.pop();

  EXPECT_EQ(int_queue.size(), 1);
  EXPECT_EQ(int_queue.front(), 3);
  EXPECT_EQ(int_queue.back(), 3);

  EXPECT_EQ(double_queue.front(), 3.3);
  EXPECT_EQ(double_queue.back(), 3.3);
  EXPECT_EQ(double_queue.size(), 1);
}

TEST(queue, front_back_pop_error) {
  mo::queue<int> int_queue;

  EXPECT_THROW(int_queue.front(), std::out_of_range);
  EXPECT_THROW(int_queue.back(), std::out_of_range);
  EXPECT_THROW(int_queue.pop(), std::out_of_range);
}

TEST(queue, copy_assignment_operator) {
  mo::queue<int> q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);

  mo::queue<int> q2;
  q2.push(4);
  q2.push(5);

  // Проверяем состояние q2 перед присваиванием
  EXPECT_EQ(q2.size(), 2);
  EXPECT_EQ(q2.front(), 4);
  EXPECT_EQ(q2.back(), 5);

  // Копируем q1 в q2
  q2 = q1;

  // Проверяем, что q2 теперь содержит элементы из q1
  EXPECT_EQ(q2.size(), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);

  // Проверяем, что q1 остался неизменным
  EXPECT_EQ(q1.size(), 3);
  EXPECT_EQ(q1.front(), 1);
  EXPECT_EQ(q1.back(), 3);
}

TEST(queue, insert_many_back) {
  mo::queue<int> q1 = {1, 2, 3};
  q1.insert_many_back(4, 5, 6);
  EXPECT_EQ(q1.size(), 6);
  EXPECT_EQ(q1.front(), 1);
  EXPECT_EQ(q1.back(), 6);
}
