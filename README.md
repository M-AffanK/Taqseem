# Taqseem

A custom C++ heap allocator that replicates `malloc`, `free`, and `realloc` for efficient dynamic memory management.

### Description
This program demonstrates the implementation of the HeapAllocator class. The HeapAllocator class is a simple memory allocator that allocates memory from a fixed-size memory block. The memory block is divided into two types of memory segments: allocated memory segments and free memory segments. The allocated memory segments store the memory blocks that have been allocated, while the free memory segments store the memory blocks that are available for allocation.

The HeapAllocator class provides the following public member functions:
- malloc(size_t size): Allocates a memory block of the specified size and returns a pointer to the allocated memory block. If there is not enough free memory available, the function prints an error message and returns nullptr.
- free(void* ptr): Deallocates the memory block pointed to by the specified pointer. If the pointer is invalid, the function prints an error message.
- get_free_mem(): Returns the total amount of free memory available in the memory block.

### main
In the main function, the program demonstrates the use of the HeapAllocator class by allocating and deallocating memory blocks of different sizes. After deallocating all memory blocks, the program prints the total amount of free memory available in the memory block.
