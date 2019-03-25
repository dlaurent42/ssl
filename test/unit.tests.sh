#!/bin/bash

# Check if program is compiled and compile it if not
if [ -f "../ft_ssl" ]; then
	echo "Program is already compiled."
else
	echo "Program is not compiled."
	echo "Compiling..."
	make -C ../ > /dev/null
fi

# PREPARING ENVIRONMENT
echo "Preparing environment
"
rm -rf logs > /dev/null 2>&1
mkdir -p logs
if [ ! -f "resources/permissions" ]; then
	touch "resources/permissions"
	chmod 0 "resources/permissions"
fi

# RUNNING BASIC TESTS
echo "Running basic tests..."
./unit.basic.tests.sh
echo ""

# RUNNING SUBJECT TESTS
echo "Running subject tests..."
./unit.subject.tests.sh
echo ""

exit

# RUNNING ERRORS TESTS
echo "Running tests on md5..."
./unit.md5.tests.sh
echo ""

# RUNNING ERRORS TESTS
echo "Running tests on sha256..."
./unit.sha256.tests.sh

# Cleaning env
chmod 777 "resources/permissions" > /dev/null
rm "resources/permissions" > /dev/null