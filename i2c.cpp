
#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <wiringPiI2C.h>

using namespace std;

#define DEVICE_ADDR		0X04
#define MICROSECOND 	1000000
 

int main(int argc, char **argv) {
	
	cout << "Device address is : " << DEVICE_ADDR << endl;
	
	int fd = wiringPiI2CSetup(DEVICE_ADDR);
	cout << "FD: "<< fd << endl;
	
	//* Write 0x00, 0x01, 0x02, ... 0x07
	//* delay 4 seconds each data
	
	for(int i = 0; i<7; i++) {
		cout << i << " will be written."  << endl;
		wiringPiI2CWrite(fd, i);
		usleep(4 * MICROSECOND);
	}
	
	return 0;
}
