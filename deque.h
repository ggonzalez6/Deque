#ifndef DEQUE_H
#define DEQUE_H

class Deque {
 private:
  int** blockmap;
  int size;
  int mapSize;
  int blockSize;
  int first_block;
  int first_element;
  int front_index;
  int back_index;

 public:
  Deque();
  ~Deque();
  void push_front();
  void push_back();
  void pop_front();
  void pop_back();
  int front();
  int back();
  bool empty();
  int getSize();
  //operator[];
#endif //DEQUE_H
