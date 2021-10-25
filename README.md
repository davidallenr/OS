

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple example steps.

### Prerequisites

g++ and pthread library.
* Compiled on Ubuntu 20.04 
* g++
  ```sh
  sudo apt-get install g++
  ```

### Installation
1. Clone the repo
   ```sh
   git clone https://github.com/davidallenr/OS.git
   ```
2. Compile the program
   ```sh
   g++ producer.cpp -pthread -lrt -o producer
   g++ consumer.cpp -pthread -lrt -o consumer
   ./consumer & ./producer &
   ```
3. Exit program run
   ```sh
   ctrl+c
   ```
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

This project shows the producer consumer problem using mutex/semaphores sharing memory.

# OUTPUT
1. Expected Sample Output
   ```sh
   test@test:~/test/project/$ g++ producer.cpp -pthread -lrt -o producer
   test@test:~/test/project/$ g++ consumer.cpp -pthread -lrt -o consumer
   test@test:~/test/project/$ ./consumer & ./producer &
   [1] 3605
   [2] 3606
   test@test:~/test/project/$ 

   PRODUCER: Produce an item. There are 1 item(s).
   PRODUCER: Produce an item. There are 2 item(s).
   ***   PRODUCER TABLE FULL   ***
   CONSUMER: Consume an item. There are 1 item(s).
   CONSUMER: Consume an item. There are 0 item(s).
   PRODUCER: Produce an item. There are 1 item(s).
   CONSUMER: Consume an item. There are 0 item(s).
   PRODUCER: Produce an item. There are 1 item(s).
   PRODUCER: Produce an item. There are 2 item(s).
   ***   PRODUCER TABLE FULL   ***
   ----------------------------------------------
   PRODUCER: Cycle limit. 2 product(s) are left.
   ----------------------------------------------
   CONSUMER: Consume an item. There are 1 item(s).
   CONSUMER: Consume an item. There are 0 item(s).
   ----------------------------------------------
   CONSUMER: Cycle limit. 0 product(s) are left.
   ----------------------------------------------
   ^C
   [1]-  Done                    ./producer
   [2]+  Done                    ./consumer
   ```

<p align="right">(<a href="#top">back to top</a>)</p>

