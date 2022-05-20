#include <iostream>
#include <pigpiod_if2.h>
#include <unistd.h>

#define DEVICE_ID 0x08

int main (int argc, char **argv)
{
    // Setup I2C communication
    int pi = pigpio_start(NULL,NULL);
    if (pi < 0) {
        std::cout << "Failed to connect to pigpiod." << std::endl;
        return -1;
    }
        std::cout << "Pigpiod started successfully." << std::endl;
    
    int ard = i2c_open(pi, 1, DEVICE_ID, 0);
    if (ard < 0) {
        std::cout << "Failed to open I2C communication.\n";
        return -1;
    }
    std::cout << "I2C communication successfully opened.\n";
    
    while(1){
    // Send data to arduino
        i2c_write_byte(pi, ard, 0x45);
        std::cout << "Sent data: " << (int)0x45 << "\n";
        // Read data from arduino
        int received_data = i2c_read_byte(pi,ard);
        std::cout << "Data received: " << received_data << "\n";
        if (received_data == 0x45) {
            std::cout << "Success!\n";
        }
        usleep(100000);
    }
    std::cout << "Exitting main loop." << std::endl;
    pigpio_stop(pi);
    i2c_close(pi,ard);
    return 0;

}