#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)

echo "The maximum process ID value for this system is: $pid_max"

