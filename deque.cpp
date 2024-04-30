/**
 * @file deque.cpp
 * @author Gerardo Gonzalez & Daniel Way
 * @date 2024-04-29
 * @brief this is where we implemented all of the members and methods from its' class
 * 
 * This is the .cpp file for deque.h, and it is also where we implement all of the members and methods from the Deque class.
 */

#include <fstream>
#include <iostream>
#include "deque.h"

using namespace std;



/**
 * This function is responsible for resizing the internal blockmap of the deque, updating the deque's capacity, and adjusting the 
 * head and tail positions accordingly. It ensures that the deque can accommodate more elements efficiently and maintains proper functionality.
 *
 *
 *
 * @param int newCapacity It's responsible for determining the size of the resized blockmap within the function
 *
 *
 *
 * @pre The function assumes that the resizeBlockmap method is called within the context of a Deque object instance.
 *   
 *      It expects newCapacity to be a non-negative integer value, indicating the desired capacity of the resized blockmap.
 *
 *      The head and numElements variables within the Deque object must be correctly initialized and updated to reflect the 
 *      current state of the deque.
 *      
 *      The blockmap pointer should point to a valid dynamically allocated array of pointers to integers.
 *
 *      The capacity variable should accurately represent the current capacity of the deque.
 * 
 *
 * 
 * @post The blockmap pointer is updated to point to a newly allocated array of pointers to integers, with a capacity equal to newCapacity.
 *
 *       The capacity variable of the Deque object is updated to reflect the new capacity of the resized blockmap.
 * 
 *       The head and tail variables are updated to reflect the new positions within the resized blockmap, ensuring that the elements of the 
 *       deque are correctly positioned.
 * 
 *       The elements of the deque are preserved, and their relative order is maintained after the resize operation.
 * 
 *       The memory allocated for the old blockmap is properly deallocated to prevent memory leaks.
 * 
 *       The function leaves the Deque object in a valid state, allowing subsequent operations on the deque to be performed correctly.
 * 
 */
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



/**
 * This is the constructor function which sets up the initial state of the deque data structure by initializing member variables and allocating * memory for the blockmap array. It ensures that the deque is empty and ready to accept elements.
 *
 * @pre 
 * 
 * @post All member variables of the Deque class are initialized 
 * 
 *       The deque is in valid initial state
 * 
 *       Memory is allocated for the blockmap array, ensuring that subsequent operations that involve adding elements to the deque won't result *       in memory errors due to uninitialized pointers.
 * 
 */
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



/**
 * This is the destructor which ensures that all memory allocated dynamically during the lifetime of a Deque object is properly deallocated to  * prevent memory leaks. It releases the memory used by both the blockmap array and the memory blocks it points to.
 *
 * @pre
 *  
 * @post Overall, the postcondition ensures that there are no memory leaks after the destructor is called, and the resources allocated by the 
 * Deque object are properly released. 
 * 
 */
Deque::~Deque() {
  for (int i = head; i < tail; i++) {
    delete[] blockmap[i];
  }
  delete[] blockmap;
}



/**
 * This function adds a new element to the front of the deque. It checks if there's enough space in the blockmap array, resizes it if 
 * necessary, moves the head pointer, allocates memory for a new block if required, inserts the new element into the deque, and updates the 
 * count of elements in the deque.
 *
 * 
 *
 * @param int value serves the purpose of specifying the value of the element that needs to be added to the front of the deque.
 * 
 * 
 * 
 * @pre The blockmap array must be initialized and allocated memory.
 * 
 *      The head pointer should be correctly positioned within the blockmap array.
 *
 *      The numElements counter should accurately reflect the number of elements currently in the deque.
 * 
 *      The blockSize variable should represent the size of each block in the blockmap array.
 * 
 *      The capacity variable should represent the total capacity of the blockmap array.
 * 
 * 
 * 
 * @post The blockmap array may be resized if necessary to accommodate the new element at the front of the deque.
 * 
 *       The head pointer is decremented to make space for the new element at the front.
 * 
 *       Memory may be allocated for a new block if the current block at the new head position is NULL.
 * 
 *       The new element specified by the int value parameter is added to the front of the deque.
 *  
 *       The numElements counter is incremented to reflect the addition of the new element.
 * 
 *       The deque maintains its integrity, ensuring that elements are properly ordered and accessible.
 * 
 */
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



/**
 * This function aims to add an element to the back of the deque by properly managing the capacity and memory allocation, ensuring the 
 * deque can grow dynamically as needed.
 *
 * 
 * @param int value serves the purpose of specifying the value of the element that needs to be added to the deque. When you call this 
 * function, you provide an integer value that you want to append to the end of the deque.
 * 
 * 
 * @pre The deque blockmap must be initialized and properly allocated memory.
 * 
 *      The tail index must be within the bounds of the deque (0 to capacity-1).
 * 
 *      The value parameter should be of type int.
 * 
 *  
 * @post The value has been successfully added to the back of the deque.
 * 
 *       The tail index has been updated to point to the next available slot in the deque.
 * 
 *       The numElements count has been incremented to reflect the addition of the new element.
 * 
 *       If resizing was necessary, the deque has been resized and all existing elements have been preserved.
 * 
 */
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



/**
 * This function performs the necessary checks to ensure the deque is not empty before attempting to remove an element from the front. 
 * If the deque is not empty, it deletes the memory of the front element, updates the head pointer to point to the next element, and decrements * the count of elements in the deque.
 *
 * 
 * @pre The Deque object must be properly initialized.
 *
 *      The blockmap array must be correctly allocated and initialized.
 *
 *      head and numElements variables must be correctly maintained and reflect the state of the deque.
 *
 *      No concurrent modification of the deque should occur during the execution of this function.
 * 
 * 
 * @post If the deque was not empty before calling pop_front(), the element at the front of the deque is removed.
 *
 *       If the deque was empty before calling pop_front(), no changes are made to the deque.
 *
 *       If an element is removed from the deque, the head pointer is incremented to point to the next element in the deque.
 *
 *       If an element is removed from the deque, the numElements variable is decremented to reflect the reduced size of the deque.
 *
 *       If an element is removed from the deque, the memory allocated for that element is properly deallocated.
 *
 *       The integrity of the deque structure is maintained after the removal of the front element.
 *
 *       The deque remains in a valid state after the function execution, ready for further operations.
 * 
 */
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



/**
 * This function essentially removes the last element from the Deque and deallocates the memory associated with it, if necessary.
 *
 *
 * @pre The Deque (blockmap) exists and is initialized.
 *      
 *      numElements represents the current number of elements in the Deque.
 * 
 *      tail points to the last element in the Deque (or beyond the last element if the Deque is empty).
 * 
 * 
 * @post If the Deque was empty before the function call, it remains unchanged.
 *
 *       If the Deque was not empty before the function call:
 *
 *       The last element in the Deque is removed.
 *
 *       If the memory for the block containing the last element was dynamically allocated, it is deallocated.
 *
 *       tail is moved to the previous position.
 *
 *       numElements is decremented by 1.
 * 
 */
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



/**
 * This function checks if the deque is empty. If it's empty, it prints an error message and returns -1. If it's not empty, it returns the
 *  element at the front of the deque.
 *
 * 
 * @pre The deque (Deque object) must be properly initialized.
 *  
 *      The blockmap array within the deque must be correctly populated.
 * 
 *      numElements should accurately reflect the number of elements currently stored in the deque.
 * 
 * 
 * @return int can return either an actual element from the deque or -1 if the deque is empty.
 * 
 * 
 * @post If the deque is empty:
 *
 *       The function prints "Deque is empty." to the standard output.
 *
 *       The function returns -1 as an error code to indicate an empty deque.
 *
 *       If the deque is not empty:
 *
 *       The function returns the element at the front of the deque.
 *
 *       The state of the deque remains unchanged after the function call.
 * 
 */
int Deque::front() {
  if (numElements == 0) {
    cout << "Deque is empty." << endl;
    return -1; // Error code for empty deque
  }
  return blockmap[head][0];
}



/**
 * This function checks if the deque is empty. If it's not empty, it retrieves and returns the element at the back of the deque. 
 * If it's empty, it prints a message and returns an error code (-1).
 *
 *
 * @pre The function assumes that the Deque object (this) on which it is called is properly initialized.
 * 
 *      It assumes that numElements accurately represents the number of elements currently stored in the Deque.
 *
 *      There are no other explicit preconditions mentioned in the function itself.
 * 
 *
 * @return int  represents the element at the back of the deque.
 * 
 * 
 * @post If the Deque is not empty, the function returns the element at the back of the Deque.
 *       
 *       If the Deque is empty, the function prints "Deque is empty." to the standard output and returns -1.
 *
 *       The state of the Deque (contents, size, etc.) remains unchanged after the function call, except for the case where an element is 
 *       removed from the Deque (when the Deque is not empty).
 *
 *       There are no memory leaks or resource leaks caused by the function.
 *
 *       The function does not modify any other state outside of the Deque object it is called upon.
 * 
 */
int Deque::back() {
  if (numElements == 0) {
    cout << "Deque is empty." << endl;
    return -1; // Error code for empty deque
  }
  return blockmap[tail - 1][0];
}



/**
 * This function provides a convenient way to check if the deque has any elements in it or not. It's a fundamental operation in data structures * like a deque because it allows users to verify the state of the deque before performing further operations, such as adding or removing 
 * elements.
 *
 * @pre
 * 
 * @return bool returns false, it indicates that the deque is not empty. This occurs when the condition numElements == 0 evaluates to 
 * false, meaning there is at least one element in the deque.
 * 
 * @post If the deque was empty before the function call, the function will return true.
 *
 *       If the deque had one or more elements before the function call, the function will return false.
 * 
 */
bool Deque::empty() {
  return numElements == 0;
}



/**
 * This function is a simple accessor method that retrieves the number of elements stored in the deque. It's an essential function for querying * the size of the deque, which is a fundamental operation in many deque-related algorithms and data structures.
 *
 * @pre 
 *
 * @return int returns the value of numElements.
 *
 * @post Guarantees the correctness of the returned size without affecting the deque's state.
 * 
 */
int Deque::size() {
  return numElements;
}



/**
 * This function is designed to provide access to elements within the deque using the [] operator, performing bounds checking to ensure 
 * that the provided index is valid. If the index is out of bounds, it returns an error code.
 *
 *
 * @param int index serves the purpose of specifying which element of the deque you want to access.
 *
 *
 * @pre The deque (blockmap) should be properly initialized and contain valid data.
 *      
 *      The numElements variable should accurately represent the number of elements in the deque.
 *
 *      The index parameter should be a non-negative integer, indicating the position of the element to be accessed.
 * 
 *      There should be no concurrent modifications to the deque by other threads or functions during the execution of this function.
 * 
 * 
 * @return int allows the function to return either the value of the element at the specified index or an error code if the index is out 
 * of bounds.
 *
 *
 * @post If the provided index is within bounds:
 *
 *       The function returns the value of the element at the specified index.
 * 
 *       No modifications are made to the deque's state.
 * 
 *       If the provided index is out of bounds:
 * 
 *       The function prints an error message indicating that the index is out of bounds.
 *
 *       The function returns -1 as an error code.
 * 
 *       No modifications are made to the deque's state.
 * 
 */
int Deque::operator[](int index) {
  if (index >= numElements) {
    cout << "Index out of bounds." << endl;
    return -1; // Error code for invalid index
  }
  return blockmap[head + index][0];
}



/**
 * This function reads integers from a file, alternately inserts them into the front and back of a deque, and closes the file stream once 
 * all the integers have been processed.
 *
 * 
 * @param string file_name acts as a placeholder for the name of the file that the function should read from, allowing the function to be 
 * reusable and adaptable to different input sources.
 *
 *
 * @pre The file specified by file_name must exist and be accessible for reading by the program.
 *
 * 
 * @post All integers from the specified file have been successfully read and inserted into the deque.
 * 
 *      The numElements member variable of the deque is updated to reflect the total number of elements in the deque after reading from 
 *      the file.
 * 
 *      The file stream infile is closed properly.
 * 
 *      The deque is in a valid state after the function completes its execution, meaning it can be further manipulated or queried by other 
 *      parts of the program without causing errors or unexpected behavior.
 * 
 */
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
