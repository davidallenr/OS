#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/mman.h>   //Used for memory manamgent
#include <semaphore.h>  //Used for Semaphores

int main () {
    //Create variable
    //Create semaphores
    
    // Make shared process between prod and cons
    // Set the size of the mem space

    // Loop through consumer
        // wait (full)
        // wait on mutex
        // decrease size
        // post mutex
        // post (available)

    // Close/unlink connections
    // Remove shared memory

}