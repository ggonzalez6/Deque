
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
  
  /*  
  Deque dq;
  dq.push_front(1);
  dq.push_back(2);
  dq.push_back(3);
  dq.push_front(4);
  dq.push_back(5);
  dq.push_back(6);
  dq.push_back(7);
  dq.push_back(8);
  dq.push_back(9);
  dq.push_front(10);
  dq.push_front(11);



  cout << "Front: " << dq.front() << endl;
  cout << "Back: " << dq.back() << endl;

  cout << "Size: " << dq.size() << endl;


  dq.pop_front();
  dq.pop_back();

  cout << "Removed front and back" << endl;
  cout << "Front: " << dq.front() << endl;
  cout << "Back: " << dq.back() << endl;

  cout << "Size: " << dq.size() << endl;
  */
  return 0;
}


