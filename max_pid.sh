#!/bin/bash

max_value_pid=$(cat /proc/sys/kernel/pid_max)
echo "$max_value_pid"
