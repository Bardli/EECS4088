#include <iostream>
#include <cstdlib>  // For system()
#include <unistd.h> // For sleep()

int main() {
    const char* writeAddress = "0x4a300000";
    const char* readAddress = "0x4a300004";
    const char* valueToWrite = "1";
    const char* resetValue = "0";
    char command[256]; // Buffer for command strings

    //init the timer
    snprintf(command, sizeof(command), "devmem2 %s w %s", readAddress, resetValue);
    system(command);
    
    // Set the value at address 0x4a300000 to 1
    snprintf(command, sizeof(command), "devmem2 %s w %s", writeAddress, valueToWrite);
    system(command);

    // Wait for 1 second
    sleep(1);

    // Set the value at address 0x4a300000 back to 0
    snprintf(command, sizeof(command), "devmem2 %s w %s", writeAddress, resetValue);
    system(command);

    // Read and print the value at address 0x4a300004
    snprintf(command, sizeof(command), "devmem2 %s", readAddress);
    system(command); // This will print the value to standard output

    return 0;
}
