#!/bin/zsh

# Close Waterfox
pkill waterfox

# Some wait time to ensure Waterfox had time to close
sleep .5

# Kill the system manager
pkill systemd
