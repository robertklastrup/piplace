# piplace

ENGLISH VERSION BELOW!!

### Ide
Et 128×64 tegnelærred på nettet, der lyser live op på en OLED-skærm på en Raspberry Pi. Bygget fra bunden i C++: egen I2C-driver til skærmen, epoll-server, WebSocket og threads. Lavet for at lære om systemarkitektur og systemprogrammering.


#### Step 1: CMake
Projektet bygges med CMake, CMakeLists.txt. Så kan det bygges på alle maskiner, jeg behøver ikke holde styr på alle filer og flag ved hver compile, og kun de filer, der er ændret, bliver bygget igen.

## English version

### Idea
A shared 128×64 pixel canvas on the web that lights up live on an OLED screen on a Raspberry Pi. Built from scratch in C++: custom I2C display driver, epoll server, WebSocket and threads. Made to learn about system architecture and programming.

#### Step 1: CMake
The project is built with CMake CMakeLists.txt. This makes it buildable on any machine, saves me from keeping track of every file and flag when compiling, and only rebuilds the files that changed.