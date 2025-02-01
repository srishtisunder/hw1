/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "cstddef"
#include "split.h"
using namespace std;
#include <iostream>

int main(int argc, char* argv[])
{
  Node* head = NULL;
  Node* tail = NULL;

  for (int i = 0; i < 10; i++) {
    Node* newnode = new Node(i, NULL);
    if (head == NULL) {
      head = newnode;
      tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
  }

  Node* odds = NULL;
  Node* evens = NULL;
  split(head, odds, evens);

  cout << "Odds: ";
  Node* oddPtr = odds;
  while (oddPtr != NULL) {
    cout << oddPtr->value << " ";
    oddPtr = oddPtr->next;
  }
  cout << endl;
  
  cout << "Evens: ";
  Node* evenPtr = evens;
  while (evenPtr != NULL) {
      cout << evenPtr->value << " ";
      evenPtr = evenPtr->next;
  }
  cout << endl;

  Node* current;
    
  while (odds) {
    current = odds;
    odds = odds->next;
    delete current;
  }

  while (evens) {
    current = evens;
    evens = evens->next;
    delete current;
  }

  return 0;
}