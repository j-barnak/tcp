#include <iostream>
#include <IPv4Layer.h>
#include <Packet.h>
#include <PcapFileDevice.h>
#include "stdlib.h"
#include "PcapLiveDeviceList.h"
#include "SystemUtils.h"

int main() {
	// We are capturing on the interface with the specified IP
	std::string ipv4_address { "10.0.0.150" };

	// Find the interface itself
	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(ipv4_address);
	if (dev == NULL) {
		std::cerr << "Cannot find interface with the IPv4 of " << ipv4_address << "\n";
		return 1;
	}

	// Esnures the device is open
	if (!dev->open()) {
		std::cerr << "Cannot open device\n";
		std::cerr << "Be sure to run the binary with sudo\n";
		return 1;
	}
}
