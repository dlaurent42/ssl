#!/bin/bash

# Case: no argument 01

	# Set test name
	TEST_LABEL="No argument 01"
	TEST_NAME="no_argument_01"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if [[ $(< logs/trace_$TEST_NAME) != "usage: ft_ssl command [command opts] [command args]" ]]; then
		echo ".......... Unexpected output"
	fi

# Case: no argument 02 (same as no argument 01 but with stdin input)

	# Set test name
	TEST_LABEL="No argument 02"
	TEST_NAME="no_argument_02"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "$TEST_LABEL" | valgrind --leak-check=full ./../ft_ssl > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if [[ $(< logs/trace_$TEST_NAME) != "usage: ft_ssl command [command opts] [command args]" ]]; then
		echo ".......... Unexpected output"
	fi

# Case: invalid command 01

	# Set test name
	TEST_LABEL="Invalid command 01"
	TEST_NAME="Invalid_command_01"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl x > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: Error: 'x' is an invalid command." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: invalid command 02 (same as invalid command 01 but with stdin input)

	# Set test name
	TEST_LABEL="Invalid command 02"
	TEST_NAME="Invalid_command_02"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "$TEST_LABEL" | valgrind --leak-check=full ./../ft_ssl x > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: Error: 'x' is an invalid command." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: invalid command 03 (same as invalid command 01 but with arg input)

	# Set test name
	TEST_LABEL="Invalid command 03"
	TEST_NAME="Invalid_command_03"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl x $TEST_LABEL > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: Error: 'x' is an invalid command." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: invalid command 04 (same as invalid command 01 but with bot stdin and arg input)

	# Set test name
	TEST_LABEL="Invalid command 04"
	TEST_NAME="Invalid_command_04"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "$TEST_LABEL" | valgrind --leak-check=full ./../ft_ssl x $TEST_LABEL > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: Error: 'x' is an invalid command." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: invalid command 05 (same as invalid command 04 but with options)

	# Set test name
	TEST_LABEL="Invalid command 05"
	TEST_NAME="Invalid_command_05"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo "$TEST_LABEL" | valgrind --leak-check=full ./../ft_ssl x -s $TEST_LABEL > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: Error: 'x' is an invalid command." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: File not found

	# Set test name
	TEST_LABEL="File not found"
	TEST_NAME="file_not_found"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/testing_everything > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: MD5: resources/testing_everything: No such file or directory." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: Permission denied

	# Set test name
	TEST_LABEL="Permission denied"
	TEST_NAME="permission_denied"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/permissions > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: MD5: resources/permissions: Permission denied." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: Permission denied

	# Set test name
	TEST_LABEL="Directory"
	TEST_NAME="directory"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/folder > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: MD5: resources/folder: Is a directory." "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi

# Case: Option s without argument

	# Set test name
	TEST_LABEL="Option -s without argument"
	TEST_NAME="option_s_without_arg"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 -s > logs/trace_valgrind_$TEST_NAME 2>&1
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
	if ! grep -q "ft_ssl: MD5: option requires an argument -- s" "logs/trace_$TEST_NAME"; then
		echo ".......... Unexpected output"
	fi