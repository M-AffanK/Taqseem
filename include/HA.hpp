// Heap Allocator header file
#ifndef HEAP_ALLOCATOR_H
#define HEAP_ALLOCATOR_H

#include <iostream>
#include <cassert>

const int memory_size = 65536;
struct record { // record of memory block
	size_t size;
	void* ptr;
};

class HeapAllocator {
	// private attributes
	char memory[memory_size]{}; // memory block
	record* allocated; // records of allocated memory blocks
	record* unallocated; // records of free memory blocks
	size_t allocated_size; // number of allocated memory blocks
	size_t unallocated_size; // number of free memory blocks

	// private member functions
	void add_to_used_memory_segments(record segment); // add a memory block to allocated memory blocks
	void add_to_free_memory_segments(record segment); // add a memory block to free memory blocks
	size_t search_segment(size_t size); // search for a free memory block
	void* use_segment(size_t index, size_t size); // use a free memory block
	void merge_continous_segments(); // merge continuous free memory blocks

public:
	// constructor and destructor
	HeapAllocator();
	~HeapAllocator();

	// public member functions
	void* malloc(size_t size); // allocate memory
	void* realloc(void* ptr, size_t size); // reallocate memory
	void free(void* ptr); // deallocate memory
	size_t get_free_mem(); // get free memory
};

#endif // HEAP_ALLOCATOR_H