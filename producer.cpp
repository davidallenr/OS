#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/mman.h>   //Used for memory manamgent
#include <semaphore.h>  //Used for Semaphores

void* create_shared_memory(size_t size) {
    //Fill with memory creations
}

int main () {
    const char* name = "Shared Memory";
    const char* fillSemaphore = "Full";
    const char* availSempahore = "Available";
    const char* mutexSemaphore = "Mutex";
    sem_t *fill, *available, *mutex;
    int sharedMemDescriptor;
    int* table;
    int loopCount = 20;

    
    // Make shared process between prod and cons
    void* shmem = create_shared_memory(1024);
    // Set the size of the mem space

    // Loop through production
        // wait (available)
        // wait on mutex
        // increase size
        // post mutex
        // post (full)

    // Close/unlink connections
    // Remove shared memory
}