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
 * Node.hpp
 */

#ifndef NODE_HPP
#define NODE_HPP

/**
 * @brief Template structure representing a single node.
 *
 * @tparam T type of the data stored in the node.
 */
template <typename T>
struct Node
{
    T data;            // Stored value of type T
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node

    /**
     * @brief Constructor that initializes the node with a set value and sets the next pointer to nullptr.
     *
     * @param value The value to initialize the node with.
     */
    Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
};

#endif