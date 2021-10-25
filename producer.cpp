#include <iostream>
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
    const int MAX_TABLE_SIZE = 2;
    sem_t *fill, *available, *mutex;
    int shared_memory_file_descriptor;
    int *table;
    int loop_count = 5;

    // Make shared process between prod and cons
    shared_memory_file_descriptor = shm_open(name, O_CREAT | O_RDWR, 0666);

    // Set the size of the mem space
    ftruncate(shared_memory_file_descriptor,sizeof(int));

    table = (int *)mmap(0,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shared_memory_file_descriptor, 0);

    fill = sem_open(fill_semaphore, O_CREAT,0666,0);
    
    available = sem_open(avail_sempahore, O_CREAT, 0666, 3);

    mutex = sem_open(mutex_semaphore,O_CREAT,0666,1);

    std::cout << "\n" << std::endl;
    while(loop_count--){
        //std::cout << "P Loop Count: " << loop_count << std::endl;
        sem_wait(available);
        sleep(rand()%2+1);
        sem_wait(mutex);
        //limit table size
        if(*table < MAX_TABLE_SIZE){
            (* table)++;
            std::cout << "Producer: Produce an item. There are " << *table << " item(s).\n";
        } else {
            std::cout << "Producer: Table Full. There are " << *table << " item(s).\n";
        }
        
        sem_post(mutex);
        
        sem_post(fill);
    }
    
    std::cout << "Producer: Cycle limit. " << *table << " product(s) are left.\n";
    
    /* 
        Close and unlink semaphores
        Remove Shared memory
    */
    sem_close(fill);
    sem_close(available);
    sem_close(mutex);
    sem_unlink(fill_semaphore);
    sem_unlink(avail_sempahore);
    sem_unlink(mutex_semaphore);

    /* close and unlink shared memory*/
    munmap(table, sizeof(int));
    close(shared_memory_file_descriptor);
    shm_unlink(name);

    return 0;
}