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
 * LinkedList.hpp
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "../../Common/Node.hpp"

/**
 * @brief A singly linked list implementation.
 *
 * @tparam T The type of data stored in the linked list.
 */
template <typename T>
class LinkedList
{
private:
    unsigned int m_length;  // The number of elements in the linked list.
    struct Node<T> *m_head; // Pointer to the first node of the linked list.

public:
    /**
     * @brief Constructs an empty linked list.
     */
    LinkedList();

    /**
     * @brief Destroys the linked list and frees all allocated memory.
     */
    ~LinkedList();

    /**
     * @brief Inserts a new element at the specified index.
     *
     * @param data The data to insert.
     * @param index The position where the data should be inserted.
     */
    void insert(const T &data, const int &index);

    /**
     * @brief Removes the element at the specified index.
     *
     * @param index The position of the element to remove.
     */
    void remove(const int &index);

    /**
     * @brief Returns the number of elements in the linked list.
     *
     * @return The length of the linked list.
     */
    unsigned int length() const;

    /**
     * @brief Retrieves the data at the specified index.
     *
     * @param index The position of the data to retrieve.
     * @return The data at the specified index.
     */
    T get(const int &index) const;

private:
    /**
     * @brief Travels to the node at the specified index.
     *
     * @param index The index of the node to retrieve.
     * @return Pointer to the node at the specified index.
     */
    struct Node<T> *travel(const int &index) const;
};

#include "LinkedList.cpp"

#endif