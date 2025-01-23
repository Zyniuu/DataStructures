/**
 * Data Structures in C++
 * Copyright (C) 2025 Mateusz Zynek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * BST.hpp
 */

#ifndef BST_HPP
#define BST_HPP

#include "../../Common/Node.hpp"

#include <string>

/**
 * @brief A class representing a Binary Search Tree (BST).
 *
 * @tparam T The type of elements stored in the BST. Must support comparison operators.
 */
template <typename T>
class BST
{
private:
    struct Node<T> *m_root; // Pointer to the root node of the BST

public:
    /**
     * @brief Constructs an empty Binary Search Tree.
     */
    BST();

    /**
     * @brief Destroys the Binary Search Tree and frees all allocated memory.
     */
    ~BST();

    /**
     * @brief Inserts a value into the Binary Search Tree.
     *
     * @param data The value to be inserted.
     */
    void insert(const T &data);

    /**
     * @brief Searches for a value in the Binary Search Tree.
     *
     * @param data The value to search for.
     * @return true If the value is found.
     * @return false If the value is not found.
     */
    bool search(const T &data);

    /**
     * @brief Removes a value from the Binary Search Tree.
     *
     * @param data The value to be removed.
     */
    void remove(const T &data);

    /**
     * @brief Converts the tree structure into a string representation.
     *
     * @return A string representation of the tree in the format `[root, leftSubtree, rightSubtree]`.
     */
    std::string treeToString();

private:
    /**
     * @brief Helper method that recursively inserts a value into the tree starting from a given node.
     *
     * @param data The value to be inserted.
     * @param node The current node being checked.
     */
    void insert(const T &data, struct Node<T> *&node);

    /**
     * @brief Helper method that recursively searches for a value starting from a given node.
     *
     * @param data The value to search for.
     * @param node The current node being checked.
     * @return true If the value is found.
     * @return false If the value is not found.
     */
    bool search(const T &data, struct Node<T> *node);

    /**
     * @brief Helper method that recursively removes a value starting from a given node.
     *
     * @param data The value to be removed.
     * @param node The current node being checked.
     */
    void remove(const T &data, struct Node<T> *&node);

    /**
     * @brief Finds the node with the minimum value in a subtree.
     *
     * @param node The root node of the subtree.
     * @return struct Node<T>* The node with the minimum value.
     */
    struct Node<T> *findMinValueNode(struct Node<T> *node);

    /**
     * @brief Helper method that recursively converts a subtree into a string representation.
     *
     * @param node The root node of the subtree.
     * @return A string representation of the subtree.
     */
    std::string subTreeToString(struct Node<T> *node);

    /**
     * @brief Deletes all nodes in a subtree using post-order traversal.
     *
     * @param node The root node of the subtree to delete.
     */
    void deletePostOrder(struct Node<T> *&node);
};

#include "BST.cpp"

#endif