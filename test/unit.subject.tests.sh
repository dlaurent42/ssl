#!/bin/bash

# Case: test 01

	# Set test name
	TEST_LABEL="echo \"pickle rick\" | ./ft_ssl md5"
	TEST_NAME="subject_test_01"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "pickle rick" | valgrind --leak-check=full ./../ft_ssl md5 > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if [[ $(< logs/trace_$TEST_NAME) != "c5e433c1dbd7ba01e3763a9483e74b04" ]]; then
		echo ".......... Unexpected output"
	fi

# Case: test 02

	# Set test name
	TEST_LABEL="echo \"Do not pity the dead, Harry.\" | ./ft_ssl md5 -p"
	TEST_NAME="subject_test_02"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "Do not pity the dead, Harry." | valgrind --leak-check=full ./../ft_ssl md5 -p > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if ! grep -q "Do not pity the dead, Harry." "logs/trace_$TEST_NAME" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "2d95365bc44bf0a298e09a3ab7b34d2f" "logs/trace_$TEST_NAME" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: test 03

	# Set test name
	TEST_LABEL="echo \"Pity the living.\" | ./ft_ssl md5 -q -r"
	TEST_NAME="subject_test_03"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "Pity the living." | valgrind --leak-check=full ./../ft_ssl md5 -q -r > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if [[ $(< logs/trace_$TEST_NAME) != "e20c3b973f63482a778f3fd1869b7f25" ]]; then
		echo ".......... Unexpected output"
	fi


# Case: test 04

	echo "And above all," > file

	# Set test name
	TEST_LABEL="./ft_ssl md5 file"
	TEST_NAME="subject_test_04"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 file > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if [[ $(< logs/trace_$TEST_NAME) != "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" ]]; then
		echo ".......... Unexpected output"
	fi

# Case: test 05

	# Set test name
	TEST_LABEL="./ft_ssl md5 -r file"
	TEST_NAME="subject_test_05"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 -r file > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if [[ $(< logs/trace_$TEST_NAME) != "53d53ea94217b259c11a5a2d104ec58a file" ]]; then
		echo ".......... Unexpected output"
	fi

# Case: test 06

	# Set test name
	TEST_LABEL="./ft_ssl md5 -s \"pity those that aren't following baerista on spotify.\""
	TEST_NAME="subject_test_06"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 -s "pity those that aren't following baerista on spotify." > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if [[ $(< logs/trace_$TEST_NAME) != "MD5 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f" ]]; then
		echo ".......... Unexpected output"
	fi

# Case: test 07

	# Set test name
	TEST_LABEL="echo \"be sure to handle edge cases carefully\" | ./ft_ssl md5 -p file"
	TEST_NAME="subject_test_07"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "be sure to handle edge cases carefully" | valgrind --leak-check=full ./../ft_ssl md5 -p file > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if ! grep -q "be sure to handle edge cases carefully" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "3553dc7dc5963b583c056d1b9fa3349c" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: test 08

	# Set test name
	TEST_LABEL="echo \"some of this will not make sense at first\" | ./ft_ssl md5 file"
	TEST_NAME="subject_test_08"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "some of this will not make sense at first" | valgrind --leak-check=full ./../ft_ssl md5 file > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if [[ $(< logs/trace_$TEST_NAME) != "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" ]]; then
		echo ".......... Unexpected output"
	fi

# Case: test 08

	# Set test name
	TEST_LABEL="echo \"but eventually you will understand\" | ./ft_ssl md5 -p -r file"
	TEST_NAME="subject_test_08"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "but eventually you will understand" | valgrind --leak-check=full ./../ft_ssl md5 -p -r file > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if ! grep -q "but eventually you will understand" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "dcdd84e0f635694d2a943fa8d3905281" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "53d53ea94217b259c11a5a2d104ec58a file" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: test 09

	# Set test name
	TEST_LABEL="echo \"GL HF let's go\" | ./ft_ssl md5 -p -s \"foo\" file"
	TEST_NAME="subject_test_09"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "GL HF let's go" | valgrind --leak-check=full ./../ft_ssl md5 -p -s "foo" file > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if ! grep -q "GL HF let's go" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "d1e3cc342b6da09480b27ec57ff243e2" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "MD5 (\"foo\") = acbd18db4cc2f85cedef654fccc4a4d8" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: test 10

	# Set test name
	TEST_LABEL="echo \"one more thing\" | ./ft_ssl md5 -r -p -s \"foo\" file -s \"bar\""
	TEST_NAME="subject_test_10"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "one more thing" | valgrind --leak-check=full ./../ft_ssl md5 -r -p -s "foo" file -s "bar" > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if ! grep -q "one more thing" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "a0bd1876c6f011dd50fae52827f445f5" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "acbd18db4cc2f85cedef654fccc4a4d8 \"foo\"" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "53d53ea94217b259c11a5a2d104ec58a file" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "ft_ssl: MD5: -s: No such file or directory." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "ft_ssl: MD5: bar: No such file or directory." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: test 11

	# Set test name
	TEST_LABEL="echo \"just to be extra clear\" | ./ft_ssl md5 -r -q -p -s \"foo\" file"
	TEST_NAME="subject_test_11"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "just to be extra clear" | valgrind --leak-check=full ./../ft_ssl md5 -r -q -p -s "foo" file > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1

	# Check leaks
	if ! grep -q "definitely lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (definitely lost)"
	fi
	if ! grep -q "indirectly lost: 0 bytes in 0 blocks" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Leaks (indirectly lost)"
	fi

	# Check double free / segfaults
	if grep -q "Process terminating with default action" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Fatal error"
	fi

	# Check invalid read / write
	if grep -q "Invalid read" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid read"
	fi
	if grep -q "Invalid write" "logs/trace_valgrind_$TEST_NAME"; then
		echo ".......... Invalid write"
	fi

	# Check ouput
	if ! grep -q "just to be extra clear" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "3ba35f1ea0d170cb3b9a752e3360286c" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "acbd18db4cc2f85cedef654fccc4a4d8" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi
	if ! grep -q "53d53ea94217b259c11a5a2d104ec58a" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Cleaning
rm file > /dev/null
