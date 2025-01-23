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
 * Queue.hpp
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../../Common/Node.hpp"

/**
 * @brief Template class Queue implementing a FIFO (First In, First Out) queue.
 *
 * @tparam T Type of the elements stored in the queue.
 */
template <typename T>
class Queue
{
private:
    unsigned int m_size;     // Number of elements in the queue.
    struct Node<T> *m_front; // Pointer to the first element in the queue.
    struct Node<T> *m_back;  // Pointer to the last element in the queue.

public:
    /**
     * @brief Default constructor that initializes an empty queue.
     */
    Queue();

    /**
     * @brief Default destructor that deletes all elements in the queue.
     */
    ~Queue();

    /**
     * @brief Retrieves the last element in the queue.
     *
     * @return Value of the last element.
     */
    T back() const;

    /**
     * @brief Retrieves the first element in the queue.
     *
     * @return Value of the first element.
     */
    T front() const;

    /**
     * @brief Removes the first element from the queue.
     */
    void pop();

    /**
     * @brief Checks if the queue is empty.
     *
     * @return True if the queue is empty, otherwise false.
     */
    bool isEmpty() const;

    /**
     * @brief Adds a new element to the back of the queue.
     *
     * @param data The value to add to the queue.
     */
    void push(const T& data);

    /**
     * @brief Retrieves the number of elements in the queue.
     *
     * @return The size of the queue.
     */
    unsigned int size() const;
};

#include "Queue.cpp"

#endif