#include "HA.hpp"

/**
 * @breif allocates memory for four blocks of different sizes, then frees them 
 * @prints the amount of free memory
 */
int main() {
	HeapAllocator HA;
	void* p1 = HA.malloc(100);
	void* p2 = HA.malloc(200);
	void* p3 = HA.malloc(300);
	HA.free(p2);
	void* p4 = HA.malloc(400);
	HA.free(p1);
	HA.free(p3);
	HA.free(p4);
	std::cout << "Free memory: " << HA.get_free_mem() << std::endl;
	return 0;
}

// Output:
// Free memory: 65536