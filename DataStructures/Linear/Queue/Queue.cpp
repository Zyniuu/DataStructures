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
 * Queue.cpp
 */

#include "Queue.hpp"

template <typename T>
Queue<T>::Queue() : m_size(0), m_front(nullptr), m_back(nullptr) {}

template <typename T>
Queue<T>::~Queue()
{
    while (m_front) // Iterate through all elements
    {
        struct Node<T> *temp = m_front; // Store the pointer to the current front element
        m_front = m_front->next;        // Move the front pointer to the next element
        delete temp;                    // Delete the old front element
    }
}

template <typename T>
T Queue<T>::back() const { return m_back->data; }

template <typename T>
T Queue<T>::front() const { return m_front->data; }

template <typename T>
void Queue<T>::pop()
{
    if (m_front == nullptr)
        return; // Check if the queue is empty

    struct Node<T> *temp = m_front; // Store the pointer to the current front element
    m_front = m_front->next;        // Move the front pointer to the next element
    m_size--;                       // Decrease the size of the queue

    if (m_front == nullptr)
        m_back = nullptr; // If the queue is now empty, set m_back to nullptr

    delete temp; // Free memory for the removed element
}

template <typename T>
bool Queue<T>::isEmpty() const { return m_front == nullptr; }

template <typename T>
void Queue<T>::push(const T& data)
{
    struct Node<T> *temp = new Node<T>(data); // Create a new node with the given data

    if (m_back == nullptr)
        m_front = m_back = temp; // If the queue is empty set both m_front and m_back to the new node
    else
    {
        m_back->next = temp; // Link the new node to the end of the queue
        m_back = temp;       // Update the m_back pointer
    }

    m_size++; // Increase the size of the queue
}

template <typename T>
unsigned int Queue<T>::size() const { return m_size; }