/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens){
  if(in == NULL){ //base case
    return;
  }
  
  split(in->next, odds, evens); //recursive call
  if(in->value % 2 == 0){ // checks to see if even
      in->next = evens;
      evens = in;
  }

  else{ // otherwise odd
    in->next = odds;
    odds = in;
  }

  in = nullptr; // guarantees that in is set to null when program terminates
}

/* If you needed a helper function, write it here */
