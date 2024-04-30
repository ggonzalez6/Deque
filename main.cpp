/**
 * @file main.cpp
 * @author Gerardo Gonzalez & Daniel Way
 * @date 2024-04-29
 * @brief a menu with 4 file options for the user to choose from in-order to test our Deque
 * 
 * This is the main.cpp file where my partner and I created a easy to choose from menu that has 5 options. 4 of them are differnt files that carry a certin amount of numbers in order to test the capabilites of our Deque, and the 5th one is an option to exit the menu.
 */


#include <iostream>
#include <string>
#include "deque.h"

using namespace std;

int main() {
  
  Deque dq;
  string option, file_name;
  cout << "Welcome to Daniel's and Gerardo's Deque!" << endl;
  cout << "There are 3 files to choose from in order to test all our main functions of the Deque, please choose wisely." << endl;
  cout << "(1) 10000 numbers, (2) 5000 random numbers, (3) 1000 numbers, (4) 0 numbers, (5) Exit" << endl;
  cout << endl;
  cout << "Enter choice now...";

  while(option != "5") {
    if(option == "1") {
      file_name = "10000_numbers.txt";
      dq.read_from_file(file_name);
      cout << "Here is the front number of the Deque: " << dq.front() << endl;
      cout << "Here is the back number of the Deque: " << dq.back() << endl;
      cout << "Here is the size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Now it will be removing the front and back numbers..." << endl;
	
      cout << endl;
      dq.pop_front();
      dq.pop_back();
      cout << "Here is the new front number of the Deque: " << dq.front() << endl;
      cout << "Here is the new back number of the Deque: " << dq.back() << endl;
      cout << "Here is the new size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Please enter your next choice now...";
    }
    else if(option == "2") {
      file_name = "5000_random_numbers.txt";
      dq.read_from_file(file_name);
      cout << "Here is the front number of the Deque: " << dq.front() << endl;
      cout << "Here is the back number of the Deque: " << dq.back() << endl;
      cout << "Here is the size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Now it will be removing the front and back numbers..." << endl;
	
      cout << endl;
      dq.pop_front();
      dq.pop_back();
      cout << "Here is the new front number of the Deque: " << dq.front() << endl;
      cout << "Here is the new back number of the Deque: " << dq.back() << endl;
      cout << "Here is the new size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Please enter your next choice now...";
    }
    else if(option == "3") {
      file_name = "1000_numbers.txt";
      dq.read_from_file(file_name);
      cout << "Here is the front number of the Deque: " << dq.front() << endl;
      cout << "Here is the back number of the Deque: " << dq.back() << endl;
      cout << "Here is the size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Now it will be removing the front and back numbers..." << endl;
	
      cout << endl;
      dq.pop_front();
      dq.pop_back();
      cout << "Here is the new front number of the Deque: " << dq.front() << endl;
      cout << "Here is the new back number of the Deque: " << dq.back() << endl;
      cout << "Here is the new size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Please enter your next choice now...";
    }
    else if(option == "4") {
      file_name = "0_numbers.txt";
      dq.read_from_file(file_name);
      cout << "Here is the front number of the Deque: " << dq.front() << endl;
      cout << "Here is the back number of the Deque: " << dq.back() << endl;
      cout << "Here is the size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Now it will be removing the front and back numbers..." << endl;
	
      cout << endl;
      dq.pop_front();
      dq.pop_back();
      cout << "Here is the new front number of the Deque: " << dq.front() << endl;
      cout << "Here is the new back number of the Deque: " << dq.back() << endl;
      cout << "Here is the new size of the Deque: " << dq.size() << endl;

      cout << endl;
      cout << "Please enter your next choice now...";
    }
    else{
      
    }
    cin >> option;
    cout << endl;
  }
  return 0;
}


