// Description: Implementation of the HeapAllocator class.
#include "utils.hpp"

// constructor and destructor
HeapAllocator::HeapAllocator() : allocated(nullptr), unallocated(new record[1]{ {memory_size, memory} }),
allocated_size(0), unallocated_size(1) { // initialize memory block
}

HeapAllocator::~HeapAllocator() { // deallocate memory blocks
	delete[] allocated;
	delete[] unallocated;
}

// private member functions
void HeapAllocator::add_to_used_memory_segments(record segment) { // add a memory block to allocated memory blocks
	// inserting a value into an array at the end
	insert_value(allocated, allocated_size, allocated_size, segment);
}

void HeapAllocator::add_to_free_memory_segments(record segment) { // add a memory block to free memory blocks
	// inserting a value into an array at the end
	insert_value(unallocated, unallocated_size, unallocated_size, segment);
}

size_t HeapAllocator::search_segment(size_t size) { // search for a free memory block
	size_t index = -1;
	for (size_t i = 0; i < unallocated_size; ++i) {
		if (size <= unallocated[i].size) {
			index = i;
			break;
		}
	}
	return index;
}

void* HeapAllocator::use_segment(size_t index, size_t size) { // use a free memory block
	record segment = unallocated[index];
	segment.size = size;
	add_to_used_memory_segments(segment);
	unallocated[index].size -= size;
	if (unallocated[index].size == 0) {
		delete_value(unallocated, unallocated_size, index);
	}
	else {
		unallocated[index].ptr = static_cast<char*>(unallocated[index].ptr) + size;
	}
	return allocated[allocated_size - 1].ptr;
}

void HeapAllocator::merge_continous_segments() { // merge continuous free memory blocks
	for (size_t i = 0; i < unallocated_size - 1; ++i) {
		char* ptr = static_cast<char*>(unallocated[i].ptr);
		if (ptr + unallocated[i].size == unallocated[i + 1].ptr) {
			unallocated[i].size += unallocated[i + 1].size;
			record* HA = new record[unallocated_size - 1];
			for (size_t j = 0; j < i + 1; ++j) {
				HA[j] = unallocated[j];
			}
			for (size_t j = i + 2; j < unallocated_size; ++j) {
				HA[j - 1] = unallocated[j];
			}
			delete[] unallocated;
			unallocated = HA;
			--unallocated_size;
		}
	}
}

// public member functions
void* HeapAllocator::malloc(size_t size) { // allocate memory	
	size_t index = search_segment(size);
	if (index == -1) {
		return nullptr;
	}
	return use_segment(index, size);
}

void HeapAllocator::free(void* ptr) { // deallocate memory
	size_t index = -1;
	for (size_t i = 0; i < allocated_size; ++i) {
		if (ptr == allocated[i].ptr) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		return;
	}
	record segment = allocated[index];
	delete_value(allocated, allocated_size, index);
	add_to_free_memory_segments(segment);
	merge_continous_segments();
}

size_t HeapAllocator::get_free_mem() { // get free memory
	size_t free_mem = 0;
	for (size_t i = 0; i < unallocated_size; ++i) {
		free_mem += unallocated[i].size;
	}
	return free_mem;
}