#include <iostream>
#include <IPv4Layer.h>
#include <Packet.h>
#include <PcapFileDevice.h>
#include "stdlib.h"
#include "PcapLiveDeviceList.h"
#include "SystemUtils.h"

// Sets up the interfaces needed from PcapPlusPlus
// Makes it so that the the program can read/write bytes from and to interfaces
// If the set up of these devices are successful, set_up() returns true
bool set_up();

int main() {
	// Will exit will error code -1 if the set up fails
	if(!set_up()) {
		exit(-1);
	}
}

bool set_up() {

	// We are capturing on the interface with the specified IP
	std::string ipv4_address { "127.0.0.1" };

	// Find the interface itself
	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(ipv4_address);
	if (dev == NULL) {
		std::cerr << "Cannot find interface with the IPv4 of " << ipv4_address << "\n";
		return false;
	}

	// Esnures the device is open
	if (!dev->open()) {
		std::cerr << "Cannot open device\n";
		std::cerr << "Be sure to run the binary with sudo\n";
		return false;
	}

	return true;
}