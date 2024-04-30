/**
 * @file deque.h
 * @author Gerardo Gonzalez & Daniel Way
 * @date 2024-04-29
 * @brief This is a header file for deque.cpp
 * 
 * This is a header file for deque.cpp that supports the exact same functions for a deque data structure
 */


#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>


/**
 * This is a class called Deque that supports the exact function of the deque data structure 
 *
 * @class Deque deque.h "Deque/deque.h"
 * @brief a class made to recreate a deque data structure 
 *
 */
class Deque {
private:
  int** blockmap; // Internal memory blockmap (pointer to pointers)
  int blockSize; // Size of each block
  int capacity; // Total number of blocks in the blockmap
  int head; // Index of the head of the deque
  int tail; // Index of the tail of the deque
  int numElements; // Number of elements in the deque
  
  // Utility function to resize the blockmap when needed
  void resizeBlockmap(int newCapacity);
  
public:
  Deque();  
  
  ~Deque();
  
  void push_front(int value);
  
  void push_back(int value);
  
  void pop_front();
  
  void pop_back();
  
  int front();
  
  int back();
  
  bool empty();
  
  int size();
  
  int operator[](int index);

  void read_from_file(std::string file_name);
};
#endif //DEQUE_H
