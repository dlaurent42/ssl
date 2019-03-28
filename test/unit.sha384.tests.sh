#!/bin/bash

# Case: option S empty string

	# Set test name
	TEST_LABEL="Empty string \"\""
	TEST_NAME="sha384_option_s_empty_string"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	touch _sha384testfile
	echo -n "" | valgrind --leak-check=full ./../ft_ssl sha384 > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 _sha384testfile | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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
	TEST_LABEL="basic string \"Foo bar\""
	TEST_NAME="sha384_option_s_basic_string"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo -n "Foo bar" > _sha384testfile
	echo -n "Foo bar" | valgrind --leak-check=full ./../ft_ssl sha384 > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 _sha384testfile | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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
	TEST_LABEL="Unicode characters \"你吃饭了吗？ Nǐ chīfàn le ma? Literally: Have you eaten?\""
	TEST_NAME="sha384_option_s_unicode"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	echo -n "你吃饭了吗？ Nǐ chīfàn le ma? Literally: Have you eaten?" > _sha384testfile
	echo -n "你吃饭了吗？ Nǐ chīfàn le ma? Literally: Have you eaten?" | valgrind --leak-check=full ./../ft_ssl sha384 > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 _sha384testfile | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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
	TEST_NAME="sha384_binary_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat resources/binary_file | valgrind --leak-check=full ./../ft_ssl sha384  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 resources/binary_file  | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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
	TEST_NAME="sha384_empty_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat resources/empty_file | valgrind --leak-check=full ./../ft_ssl sha384  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 resources/empty_file  | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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
	TEST_NAME="sha384_small_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat  resources/text_file_small | valgrind --leak-check=full ./../ft_ssl sha384  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 resources/text_file_small  | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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
	TEST_NAME="sha384_medium_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat  resources/text_file_medium | valgrind --leak-check=full ./../ft_ssl sha384  > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 resources/text_file_medium  | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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
	TEST_NAME="sha384_large_file_stdin"

	# Print message to user
	echo "...... $TEST_LABEL"

	# Run program
	cat resources/text_file_large | valgrind --leak-check=full ./../ft_ssl sha384 > logs/trace_valgrind_$TEST_NAME 2>&1
	cat logs/trace_valgrind_$TEST_NAME | grep -v "==" | grep -v "\-\- run:" > logs/trace_$TEST_NAME 2>&1
	openssl sha -sha384 resources/text_file_large  | cut -d' ' -f2 > logs/trace_original_$TEST_NAME 2>&1

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

# Clean
rm _sha384testfile