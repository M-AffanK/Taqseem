// Utility functions for the HA class
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cassert>
#include "HA.hpp"

void insert_value(record*& array, size_t& size, size_t index, record segment); // insert a value into an array
void delete_value(record*& array, size_t& size, size_t index); // delete a value from an array

#endif // UTILS_H