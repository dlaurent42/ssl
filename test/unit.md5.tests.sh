#!/bin/bash

# Case: option S empty string

	# Set test name
	TEST_LABEL="Empty string using option -s \"\""
	TEST_NAME="md5_option_s_empty_string"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 -s "" > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 -s "" > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: option S basic string

	# Set test name
	TEST_LABEL="basic string using option -s \"Foo bar\""
	TEST_NAME="md5_option_s_basic_string"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 -s "Foo bar" > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 -s "Foo bar" > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: option S edge case 448 bits

	# Set test name
	TEST_LABEL="Edge case (448 bits input) using option -s \"A very long text with 448 chars, but i need to add more!\""
	TEST_NAME="md5_option_s_448_chars_edge_case"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 -s "A very long text with 448 chars, but i need to add more!" > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 -s "A very long text with 448 chars, but i need to add more!" > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi


# Case: option S unicode

	# Set test name
	TEST_LABEL="Unicode characters using option -s \"你吃饭了吗？ Nǐ chīfàn le ma? Literally: Have you eaten?\""
	TEST_NAME="md5_option_s_unicode"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 -s "你吃饭了吗？ Nǐ chīfàn le ma? Literally: Have you eaten?" > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 -s "你吃饭了吗？ Nǐ chīfàn le ma? Literally: Have you eaten?" > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: binary file

	# Set test name
	TEST_LABEL="Binary file as argument"
	TEST_NAME="md5_binary_file_arg"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/binary_file  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 resources/binary_file  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: binary file

	# Set test name
	TEST_LABEL="Binary file through stdin"
	TEST_NAME="md5_binary_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat  resources/binary_file | valgrind --leak-check=full ./../ft_ssl md5  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	cat  resources/binary_file | md5  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: empty file

	# Set test name
	TEST_LABEL="Empty file as argument"
	TEST_NAME="md5_empty_file_arg"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/empty_file  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 resources/empty_file  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: empty file

	# Set test name
	TEST_LABEL="Empty file through stdin"
	TEST_NAME="md5_empty_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat  resources/empty_file | valgrind --leak-check=full ./../ft_ssl md5  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	cat  resources/empty_file | md5  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: small text file

	# Set test name
	TEST_LABEL="Small text file as argument"
	TEST_NAME="md5_small_file_arg"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/text_file_small  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 resources/text_file_small  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: small text file

	# Set test name
	TEST_LABEL="Small text file through stdin"
	TEST_NAME="md5_small_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat  resources/text_file_small | valgrind --leak-check=full ./../ft_ssl md5  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	cat  resources/text_file_small | md5  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: medium text file

	# Set test name
	TEST_LABEL="Medium text file as argument"
	TEST_NAME="md5_medium_file_arg"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/text_file_medium  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 resources/text_file_medium  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: medium text file

	# Set test name
	TEST_LABEL="Medium text file through stdin"
	TEST_NAME="md5_medium_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat  resources/text_file_medium | valgrind --leak-check=full ./../ft_ssl md5  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	cat  resources/text_file_medium | md5  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: large text file

	# Set test name
	TEST_LABEL="Large text file as argument"
	TEST_NAME="md5_large_file_arg"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	valgrind --leak-check=full ./../ft_ssl md5 resources/text_file_large  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	md5 resources/text_file_large  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi

# Case: large text file

	# Set test name
	TEST_LABEL="Large text file through stdin"
	TEST_NAME="md5_large_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat  resources/text_file_large | valgrind --leak-check=full ./../ft_ssl md5  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	cat  resources/text_file_large | md5  > logs/trace_original_$TEST_NAME 2>&1

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
	if ! cmp -s logs/trace_$TEST_NAME logs/trace_original_$TEST_NAME; then
		echo ".......... Unexpected output"
	fi