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

# This is so that the packets actually get forwarded to the
# tun interface.
ip route add 10.0.0.150 dev tcp0 table 1234
ip rule add from 10.0.0.150 lookup 1234 pref 10
ip rule add from all lookup local pref 20
ip rule del from all lookup local pref 0


