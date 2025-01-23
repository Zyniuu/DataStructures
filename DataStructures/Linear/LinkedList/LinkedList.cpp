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
 * LinkedList.cpp
 */

#include "LinkedList.hpp"

#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : m_length(0), m_head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (m_head)
    {
        struct Node<T> *temp = m_head;
        m_head = m_head->next;
        delete temp; // Free each node
    }
}

template <typename T>
void LinkedList<T>::insert(const T &data, const int &index)
{
    struct Node<T> *newNode = new Node<T>(data); // Allocate new node

    if (index == 0)
    {
        // Insert at the head of the list
        newNode->next = m_head;
        m_head = newNode;
    }
    else
    {
        // Insert at a specific position
        struct Node<T> *prevElem = travel(index - 1);
        newNode->next = prevElem->next;
        prevElem->next = newNode;
    }

    m_length++; // Increment the length
}

template <typename T>
void LinkedList<T>::remove(const int &index)
{
    if (m_length <= 0)
    {
        std::cout << "Error: Linked List is empty." << std::endl;
        exit(1);
    }

    if (index == 0)
    {
        // Remove the head node
        struct Node<T> *nodeToRemove = m_head;
        m_head = nodeToRemove->next;
        delete nodeToRemove;
    }
    else
    {
        // Remove a node at a specific position
        struct Node<T> *prevElem = travel(index - 1);
        struct Node<T> *nodeToRemove = prevElem->next;
        prevElem->next = nodeToRemove->next;
        delete nodeToRemove;
    }

    m_length--; // Decrement the length
}

template <typename T>
unsigned int LinkedList<T>::length() const { return m_length; }

template <typename T>
T LinkedList<T>::get(const int &index) const
{
    struct Node<T> *temp = travel(index); // Travel to the specified node
    return temp->data;
}

template <typename T>
struct Node<T> *LinkedList<T>::travel(const int &index) const
{
    if (index < 0 || index >= m_length)
    {
        std::cout << "Error: Linked List index out of range." << std::endl;
        exit(1);
    }

    struct Node<T> *current = m_head; // Start from the head

    for (int i = 0; i < index; i++) // Traverse the list
        current = current->next;

    return current;
}