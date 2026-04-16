#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val): data(val), left(nullptr), right(nullptr) {}
};

#endif  // SOLUTION_HPP
