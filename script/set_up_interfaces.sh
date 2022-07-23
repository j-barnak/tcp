#!/bin/bash
# This scripts sets up the user space interface to send and receive
# TCP segments on

# Set up interface for receiving and sending
# Interface name: tcp0
sudo ip tuntap add dev tcp0 mod tun
# Assign tcp0 the ip "10.0.0.150"
sudo ip addr add 10.0.0.150/24 dev tcp0
# Make it so that tpc0 is up
sudo ip link set up dev tcp0
