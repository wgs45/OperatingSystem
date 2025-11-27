#!/bin/bash

echo "Starting fork server..."
./login_server_fork &
FORK_PID=$!
sleep 1

echo "Running stress test on fork server..."
./login_stress 127.0.0.1 200 50 alice

echo "Collecting fork server stats..."
/usr/bin/time -v ./login_client 127.0.0.1 alice 1234
ps -L -p $FORK_PID
pmap -x $FORK_PID

kill $FORK_PID
sleep 1

echo "Starting thread server..."
./login_server_thread &
THREAD_PID=$!
sleep 1

echo "Running stress test on thread server..."
./login_stress 127.0.0.1 200 50 alice

echo "Collecting thread server stats..."
/usr/bin/time -v ./login_client 127.0.0.1 alice 1234
ps -L -p $THREAD_PID
pmap -x $THREAD_PID

kill $THREAD_PID
