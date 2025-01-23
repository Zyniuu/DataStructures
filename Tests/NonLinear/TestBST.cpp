#include <gtest/gtest.h>
#include "../../DataStructures/NonLinear/BST/BST.hpp"

// Helper function to populate the tree with a set of values.
void populateTree(BST<int> &tree, const std::vector<int> &values)
{
    for (const int &value : values)
        tree.insert(value);
}

// Test case: inserting elements into the BST and checking basic structure.
TEST(BSTTests, InsertElements)
{
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    // Verify the tree contains the inserted elements
    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
    EXPECT_FALSE(tree.search(20)); // Element not present
}

// Test case: searching for elements in the BST.
TEST(BSTTests, SearchElements) {
    BST<int> tree;
    populateTree(tree, {30, 20, 40, 10, 25, 35, 50});

    // Verify the tree contains the correct elements
    EXPECT_TRUE(tree.search(30));
    EXPECT_TRUE(tree.search(25));
    EXPECT_TRUE(tree.search(50));

    // Verify the tree does not contain these elements
    EXPECT_FALSE(tree.search(5));
    EXPECT_FALSE(tree.search(100));
}

// Test case: removing elements from the BST.
TEST(BSTTests, RemoveElements) {
    BST<int> tree;
    populateTree(tree, {15, 10, 20, 8, 12, 17, 25});

    // Remove a leaf node
    tree.remove(8);
    EXPECT_FALSE(tree.search(8));

    // Remove a node with one child
    tree.remove(25);
    EXPECT_FALSE(tree.search(25));

    // Remove a node with two children
    tree.remove(15);
    EXPECT_FALSE(tree.search(15));

    // Ensure the other elements are still present
    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(12));
    EXPECT_TRUE(tree.search(20));
    EXPECT_TRUE(tree.search(17));
}

// Test case: converting the BST to a string representation.
TEST(BSTTests, TreeToString) {
    BST<int> tree;
    populateTree(tree, {10, 5, 15, 3, 7, 12, 18});

    // Expected structure: [10, [5, [3, [], []], [7, [], []]], [15, [12, [], []], [18, [], []]]]
    EXPECT_EQ(tree.treeToString(),
              "[10, [5, [3, [], []], [7, [], []]], [15, [12, [], []], [18, [], []]]]");

    // Test with an empty tree
    BST<int> emptyTree;
    EXPECT_EQ(emptyTree.treeToString(), "[]");
}

// Test case: removing all elements from the BST.
TEST(BSTTests, RemoveAllElements) {
    BST<int> tree;
    populateTree(tree, {50, 30, 70, 20, 40, 60, 80});

    // Remove all elements
    for (int value : {50, 30, 70, 20, 40, 60, 80}) {
        tree.remove(value);
    }

    // Ensure the tree is empty
    EXPECT_EQ(tree.treeToString(), "[]");
    EXPECT_FALSE(tree.search(50));
    EXPECT_FALSE(tree.search(30));
}

// Test case: handling duplicate elements in the BST.
TEST(BSTTests, HandleDuplicates) {
    BST<int> tree;
    tree.insert(10);
    tree.insert(10); // Attempt to insert duplicate

    // Ensure the tree contains the element only once
    EXPECT_TRUE(tree.search(10));
    EXPECT_EQ(tree.treeToString(), "[10, [], []]");
}