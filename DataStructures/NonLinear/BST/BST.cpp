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
 * BST.cpp
 */

#include "BST.hpp"

template <typename T>
BST<T>::BST() : m_root(nullptr) {}

template <typename T>
BST<T>::~BST() { deletePostOrder(m_root); }

template <typename T>
void BST<T>::insert(const T &data) { insert(data, m_root); }

template <typename T>
bool BST<T>::search(const T &data) { return search(data, m_root); }

template <typename T>
void BST<T>::remove(const T &data) { remove(data, m_root); }

template <typename T>
std::string BST<T>::treeToString()
{
    if (m_root == nullptr)
        return "[]";
    return subTreeToString(m_root);
}

template <typename T>
void BST<T>::insert(const T &data, struct Node<T> *&node)
{
    if (node == nullptr)
    {
        node = new Node<T>(data); // Create a new node if the current one is null
        return;
    }

    if (data < node->data)
        insert(data, node->prev); // Insert in the left subtree
    else if (data > node->data)
        insert(data, node->next); // Insert in the right subtree
}

template <typename T>
bool BST<T>::search(const T &data, struct Node<T> *node)
{
    if (node == nullptr)
        return false; // Value not found
    if (data == node->data)
        return true; // Value found
    if (data < node->data)
        return search(data, node->prev); // Search in the left subtree
    return search(data, node->next);     // Search in the right subtree
}

template <typename T>
void BST<T>::remove(const T &data, struct Node<T> *&node)
{
    if (node == nullptr)
        return;

    if (data < node->data)
        remove(data, node->prev); // Remove from the left subtree
    else if (data > node->data)
        remove(data, node->next); // Remove from the right subtree
    else
    {
        struct Node<T> *nodeToRemove = nullptr;

        // Case: Node has no children
        if (node->prev == nullptr && node->next == nullptr)
        {
            nodeToRemove = node;
            node = nullptr;
        }
        // Case: Node has one child (left)
        else if (node->prev != nullptr && node->next == nullptr)
        {
            nodeToRemove = node;
            node = node->prev;
        }
        // Case: Node has one child (right)
        else if (node->prev == nullptr && node->next != nullptr)
        {
            nodeToRemove = node;
            node = node->next;
        }
        // Case: Node has two children
        else
        {
            struct Node<T> *minNode = findMinValueNode(node->next);
            node->data = minNode->data; // Replace with the smallest value in the right subtree
            remove(minNode->data, node->next);
        }

        if (nodeToRemove != nullptr)
            delete nodeToRemove; // Free memory
    }
}

template <typename T>
struct Node<T> *BST<T>::findMinValueNode(struct Node<T> *node)
{
    if (node->prev == nullptr)
        return node; // Leftmost node is the smallest
    return findMinValueNode(node->prev);
}

template <typename T>
std::string BST<T>::subTreeToString(struct Node<T> *node)
{
    std::string leftChildStr = node->prev == nullptr ? "[]" : subTreeToString(node->prev);
    std::string rightChildStr = node->next == nullptr ? "[]" : subTreeToString(node->next);
    return "[" + std::to_string(node->data) + ", " + leftChildStr + ", " + rightChildStr + "]";
}

template <typename T>
void BST<T>::deletePostOrder(struct Node<T> *&node)
{
    if (node != nullptr)
    {
        deletePostOrder(node->prev);
        deletePostOrder(node->next);
        delete node;
        node = nullptr;
    }
}