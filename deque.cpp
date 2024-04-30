#include <fstream>
#include <iostream>
#include "deque.h"

using namespace std;

// Utility function to resize the blockmap when needed
void Deque::resizeBlockmap(int newCapacity) {
  int** newBlockmap = new int*[newCapacity];
  int newHead = (newCapacity - capacity) / 2;
  int newTail = newHead + numElements;
  
  for (int i = 0; i < capacity; i++) {
    newBlockmap[newHead + i] = blockmap[head + i];
  }
  
  delete[] blockmap;
  blockmap = newBlockmap;
  capacity = newCapacity;
  head = newHead;
  tail = newTail;
}



Deque::Deque(){
  blockSize = 10;
  capacity = 4;
  head = 1;
  tail = 1;
  numElements = 0;
  
  blockmap = new int*[capacity];
  
  for (int i = 0; i < capacity; i++) {
    blockmap[i] = NULL;
  }
}


Deque::~Deque() {
  for (int i = head; i < tail; i++) {
    delete[] blockmap[i];
  }
  delete[] blockmap;
}


void Deque::push_front(int value) {
  if (head == 0) {
    resizeBlockmap(capacity * 2);
  }
  head--;
  if (blockmap[head] == NULL) {
    blockmap[head] = new int[blockSize];
  }
  blockmap[head][0] = value;
  numElements++;
}

void Deque::push_back(int value) {
  if (tail == capacity) {
    resizeBlockmap(capacity * 2);
  }
  if (blockmap[tail] == NULL) {
    blockmap[tail] = new int[blockSize];
  }
  blockmap[tail][0] = value;
  tail++;
  numElements++;
}

void Deque::pop_front() {
  if (numElements == 0) {
    cout << "Deque is empty, cannot pop front." << endl;
    return;
  }
  if (blockmap[head] != NULL) {
    delete[] blockmap[head];
    blockmap[head] = NULL;
  }
  head++;
  numElements--;
}

void Deque::pop_back() {
  if (numElements == 0) {
    cout << "Deque is empty, cannot pop back." << endl;
    return;
  }
  tail--;
  if (blockmap[tail] != NULL) {
    delete[] blockmap[tail];
    blockmap[tail] = NULL;
  }
  numElements--;
}

int Deque::front() {
  if (numElements == 0) {
    cout << "Deque is empty." << endl;
    return -1; // Error code for empty deque
  }
  return blockmap[head][0];
}

int Deque::back() {
  if (numElements == 0) {
    cout << "Deque is empty." << endl;
    return -1; // Error code for empty deque
  }
  return blockmap[tail - 1][0];
}

bool Deque::empty() {
  return numElements == 0;
}

int Deque::size() {
  return numElements;
}

int Deque::operator[](int index) {
  if (index >= numElements) {
    cout << "Index out of bounds." << endl;
    return -1; // Error code for invalid index
  }
  return blockmap[head + index][0];
}

void Deque::read_from_file(string file_name) {
  numElements = 0;
  ifstream infile;
  infile.open(file_name);
  if(!infile) {
    cout << "ERROR: There was an issue opening the file, please try again" << endl;
  }
  int number;
  bool pushToFront = true; // Flag to alternate between pushing to front and back

  while (infile >> number) {
    if (pushToFront) {
      push_front(number);
      cout << "Pushing " << number << " to the front" << endl;
    } else {
      push_back(number);
      cout << "Pushing " << number << " to the back" << endl;
    }
    pushToFront = !pushToFront; // Toggle the flag for the next iteration
    
  }
  

  infile.close();  
}
