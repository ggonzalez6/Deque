
#include <iostream>
#include <string>
#include "deque.h"

using namespace std;

int main() {
  Deque dq;
  dq.push_front(1);
  dq.push_back(2);
  dq.push_back(3);
  dq.push_front(124);
  dq.push_back(24);
  dq.push_back(5642);
  dq.push_back(7);
  dq.push_back(45);
  dq.push_back(204);
  dq.push_front(24);
  dq.push_front(56);



  cout << "Front: " << dq.front() << endl;
  cout << "Back: " << dq.back() << endl;

  cout << "Size: " << dq.size() << endl;


  dq.pop_front();
  dq.pop_back();

  cout << "Removed front and back" << endl;
  cout << "Front: " << dq.front() << endl;
  cout << "Back: " << dq.back() << endl;

  cout << "Size: " << dq.size() << endl;

  return 0;
}
