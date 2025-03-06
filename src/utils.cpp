#include "utils.hpp"

void insert_value(record*& array, size_t& size, size_t index, record segment) { // insert a value into an array
	record* HA = new record[size + 1];
	for (size_t i = 0; i < index; ++i) {
		HA[i] = array[i];
	}
	HA[index] = segment;
	for (size_t i = index + 1; i < size + 1; ++i) {
		HA[i] = array[i - 1];
	}
	++size;
	delete[] array;
	array = HA;
}

void delete_value(record*& array, size_t& size, size_t index) { // delete a value from an array
	record* HA = new record[size - 1];
	for (size_t i = 0; i < index; ++i) {
		HA[i] = array[i];
	}
	for (size_t i = index + 1; i < size; ++i) {
		HA[i - 1] = array[i];
	}
	--size;
	delete[] array;
	array = HA;
}