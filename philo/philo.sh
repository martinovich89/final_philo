#!/bin/bash

echo "=====>ERRORS<=====" >> output.log

./philo > output.log
./philo 2 >> output.log
./philo 2 1000 >> output.log
./philo 2 1000 200 >> output.log
./philo 2 1000 200 200 200 200 >> output.log

echo "----->0 philo<-----" >> output.log
./philo 0 1000 200 200 >> output.log
echo "----->0 tte<-----" >> output.log
./philo 2 0 200 200 >> output.log
#./philo 2 1000 0 200 >> output.log
#./philo 2 1000 200 0 >> output.log
echo "----->0 max meal<-----" >> output.log
./philo 2 1000 200 200 0 >> output.log

echo "----->negative args<-----" >> output.log
./philo -1 1000 200 200 2 >> output.log
./philo 2 -1 200 200 2 >> output.log
./philo 2 1000 -1 200 2 >> output.log
./philo 2 1000 200 -1 2 >> output.log
./philo 2 1000 200 200 -1 >> output.log

echo "=====>REGULAR TESTS<=====" >> output.log
echo "----->1 410 200 200 10<-----" >> output.log
./philo 1 410 200 200 10 >> output.log
echo "----->2 401 200 200 10<-----" >> output.log
./philo 2 401 200 200 10 >> output.log
echo "----->4 410 200 200 10<-----" >> output.log
./philo 4 410 200 200 10 >> output.log
echo "----->5 610 200 200 10<-----" >> output.log
./philo 5 610 200 200 10 >> output.log
echo "----->200 450 200 200 10<-----" >> output.log
./philo 200 450 200 200 10 >> output.log
echo "----->4 399 200 200 10<-----" >> output.log
./philo 4 399 200 200 10 >> output.log
echo "----->5 599 200 200 10<-----" >> output.log
./philo 5 599 200 200 10 >> output.log
