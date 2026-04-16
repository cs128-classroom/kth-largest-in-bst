// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : <Your Name>                  Environment : ubuntu:bionic               //
//  Date ......: <00/00/00>                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "bst.hpp"
#include "node.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Balanced BST basic cases") {
  cs128::BST tree;

  Node* root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(8);
  root->left->left = new Node(2);
  root->left->right = new Node(4);
  root->right->right = new Node(10);

  tree.SetRoot(root);

  REQUIRE(tree.KthLargest(1) == 10);
  REQUIRE(tree.KthLargest(3) == 5);
}

TEST_CASE("Right-skewed BST") {
  cs128::BST tree;

  Node* root = new Node(2);
  root->right = new Node(3);
  root->right->right = new Node(4);
  root->right->right->right = new Node(5);
  root->right->right->right->right = new Node(6);

  tree.SetRoot(root);

  REQUIRE(tree.KthLargest(1) == 6);
  REQUIRE(tree.KthLargest(3) == 4);
  REQUIRE(tree.KthLargest(5) == 2);
}

TEST_CASE("BST with duplicate values") {
  cs128::BST tree;

  Node* root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(7);

  root->right->left = new Node(5);
  root->right->right = new Node(7);

  tree.SetRoot(root);

  // Reverse inorder: 7, 7, 5, 5, 3
  REQUIRE(tree.KthLargest(1) == 7);
  REQUIRE(tree.KthLargest(2) == 7);
  REQUIRE(tree.KthLargest(3) == 5);
  REQUIRE(tree.KthLargest(4) == 5);
}

TEST_CASE("k equals number of nodes") {
  cs128::BST tree;

  Node* root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(15);
  root->left->left = new Node(2);
  root->left->right = new Node(7);

  tree.SetRoot(root);

  REQUIRE(tree.KthLargest(5) == 2);
}

TEST_CASE("Empty tree") {
  cs128::BST tree;

  REQUIRE(tree.KthLargest(1) == -1);
}

TEST_CASE("Invalid k values") {
  cs128::BST tree;

  Node* root = new Node(5);
  tree.SetRoot(root);

  REQUIRE(tree.KthLargest(0) == -1);
  REQUIRE(tree.KthLargest(2) == -1);
}

// TEST_CASE("First Case", "1") {
//   cs128::BST tree;

//   Node* root = new Node(5);
//   root->left = new Node(3);
//   root->right = new Node(8);
//   root->left->left = new Node(2);
//   root->left->right = new Node(4);
//   root->right->right = new Node(10);

//   tree.SetRoot(root);

//   std::cout << tree.KthLargest(1) << std::endl;  // 10
//   std::cout << tree.KthLargest(3) << std::endl;  // 5
// }

// TEST_CASE("Single Node", "2") {
//   cs128::BST tree;

//   Node* root = new Node(7);
//   tree.SetRoot(root);

//   std::cout << tree.KthLargest(1) << std::endl; // 7
// }

// TEST_CASE("Left Skewed", "3") {
//   cs128::BST tree;

//   Node* root = new Node(5);
//   root->left = new Node(4);
//   root->left->left = new Node(3);
//   root->left->left->left = new Node(2);

//   tree.SetRoot(root);

//   std::cout << tree.KthLargest(2) << std::endl; // 4

// }

// TEST_CASE("Right Skewed", "4") {
//   cs128::BST tree;

//   Node* root = new Node(2);
//   root->right = new Node(3);
//   root->right->right = new Node(4);
//   root->right->right->right = new Node(5);
//   root->right->right->right->right = new Node(6);

//   tree.SetRoot(root);

//   std::cout << tree.KthLargest(1) << std::endl; // 6
//   std::cout << tree.KthLargest(3) << std::endl; // 4
//   std::cout << tree.KthLargest(5) << std::endl; // 2

// }

// TEST_CASE("Tie case", "5") {
//   cs128::BST tree;

//   Node* root = new Node(5);
//   root->left = new Node(3);
//   root->right = new Node(7);

//   // duplicates
//   root->right->left = new Node(5);
//   root->right->right = new Node(7);

//   tree.SetRoot(root);

//   // Reverse inorder: 7, 7, 5, 5, 3
//   std::cout << tree.KthLargest(1) << std::endl; // 7
//   std::cout << tree.KthLargest(2) << std::endl; // 7
//   std::cout << tree.KthLargest(3) << std::endl; // 5
//   std::cout << tree.KthLargest(4) << std::endl; // 5

// }

// TEST_CASE("k equals num nodes", "6") {
//   cs128::BST tree;

//   Node* root = new Node(10);
//   root->left = new Node(5);
//   root->right = new Node(15);
//   root->left->left = new Node(2);
//   root->left->right = new Node(7);

//   tree.SetRoot(root);

//   std::cout << tree.KthLargest(5) << std::endl; // 2

// }

// TEST_CASE("Empty Tree", "7") {
//   cs128::BST tree;

//   std::cout << tree.KthLargest(1) << std::endl;
//   // expected: -1 (or whatever behavior you define)

// }

// TEST_CASE("Invalid Input", "8") {
//   cs128::BST tree;

//   Node* root = new Node(5);
//   tree.SetRoot(root);

//   std::cout << tree.KthLargest(0) << std::endl;
//   // expected: -1

// }

/////////////////////////////////////////////////////////////////////////////////////////////