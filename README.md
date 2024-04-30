# Deque
In this assignment you will be building one of the most universal structures available in the standard library, a deque.

## Design Decisions
* The deque only uses ints.  
* We decided to start the capacity at 4 blocks in the blockmap and the size of the blockmap being 10.
* Every part of the blockmap is initalized to NULL.  
* For the tests, when we read in the code, we are alternating between push front and push back.  


## Functions and uses
* resizeBlockmap(int newCapacity): Allows resizing of the blockmap's capacity.
* push_front(int value): Adds value to front of the deque  
* push_back(int value): Adds value to back of the deque  
* pop_front(): Removes newest added front element.
* pop_back(): Removes newest added back element.
* front(): Finds and gives item at the front of the deque
* back(): Finds and gives item at the back of the deque
* empty(): Checks if the deque is empty
* size(): Returns how many elements are in the deque

## How to run
1. run `make` to create the program
2. run `./deque` to run the program
3. pick a file to open  
4. 

## Challenges 
For some reason our biggest issue was we front() giving a segmentation fault after popping the front off, but we eventually got that working. 

## How the work was split up  
The 'skeleton' was set up by Gerardo.  
The class and its code were worked on by us both, either directly on the same computer, or both in a call discord talking it over.  
Test cases created by Daniel (taken from old homework).  
Implementation of test cases / menu created by Gerardo.  
