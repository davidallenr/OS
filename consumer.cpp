#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>


/* Information taken from 
    https://man7.org/linux/man-pages/man3/shm_open.3.html
*/
int main () {
    const char *name = "Shared Memory";
    const char *fill_semaphore = "Full";
    const char *avail_sempahore = "Available";
    const char *mutex_semaphore = "Mutex";
    const char *end_semaphore = "End";
    sem_t *fill, *available, *mutex, *end;
    int shared_memory_file_descriptor;
    int *table;
    int loop_count = 20;

    // Make shared process between prod and cons
    shared_memory_file_descriptor = shm_open(name, O_CREAT | O_RDWR, 0666);

    // Set the size of the mem space
    ftruncate(shared_memory_file_descriptor,sizeof(int));

    table = (int *)mmap(0,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shared_memory_file_descriptor, 0);

    fill = sem_open(fill_semaphore, O_CREAT,0666,0);
    
    available = sem_open(avail_sempahore, O_CREAT, 0666, 3);

    mutex = sem_open(mutex_semaphore,O_CREAT,0666,1);

    end = sem_open(end_semaphore,O_CREAT,0666,2);

    // Loop through production
        // wait (available)
        // wait on mutex
        // increase size
        // post mutex
        // post (full)
        int value = 2;
    while(loop_count--){
        sem_wait(fill);
        sleep(rand()%2+1);
        sem_wait(mutex);
        (* table)--;
        sem_post(mutex);
        
        std::cout << "END VALUE: " << sem_getvalue(end, &value) << std::endl;
        if (sem_getvalue(end, &value)) {
            
            std::cout << "Consumer: Consume an item. There are " << *table << " item(s).\n";

        }

        sem_post(available);
    }
 
    // Close/unlink connections
    // Remove shared memory
    /* close and unlink semaphores*/
    sem_close(fill);
    sem_close(available);
    sem_close(mutex);
    sem_close(end);
    sem_unlink(fill_semaphore);
    sem_unlink(avail_sempahore);
    sem_unlink(mutex_semaphore);
    sem_unlink(end_semaphore);
    /* close and unlink shared memory*/
    munmap(table, sizeof(int));
    close(shared_memory_file_descriptor);
    shm_unlink(name);

    return 0;
}