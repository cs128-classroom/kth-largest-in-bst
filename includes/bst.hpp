#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "node.hpp"

namespace cs128 {

  class BST {
  private:
    Node* root_;

    /* TODO
     * @Param Node* root is root of the BST to traverse
     * @Param int k is the kth largest int to find
     * Return the kth largest number in the BST
     * If k is invalid, return -1
     * If the tree is empty, return -1
     */
    int KthLargest_(Node* root, int k) { return 0; }

  public:
    BST(): root_(nullptr) {}

    int KthLargest(int k) { return KthLargest_(root_, k); }

    Node* GetRoot() { return root_; }

    void SetRoot(Node* root) { root_ = root; }
  };

}  // namespace cs128

#endif