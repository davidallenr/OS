

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple example steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
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
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

This project shows the producer consumer problem using mutex/semaphores sharing memory.

<p align="right">(<a href="#top">back to top</a>)</p>

