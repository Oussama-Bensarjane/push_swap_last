#!/bin/bash

# Check if Python is installed
if ! command -v python3 &> /dev/null; then
  echo "Python3 is required but not installed. Please install Python3."
  exit 1
fi

# Function to generate random numbers
generate_random_numbers() {
  local count=$1
  python3 -c "import random; print(' '.join(map(str, random.sample(range(-2147483648, 2147483648), $count))))"
}

# Function to test sorting
test_sorting() {
  local num_count=$1
  local max_operations=$2
  local max_found=0
  local iteration=0
  local max_iterations=300 # Limit the number of tests

  echo "Testing with $num_count random numbers..."

  while [ "$iteration" -lt "$max_iterations" ]; do
    iteration=$((iteration + 1))

    # Generate random numbers
    ARG=$(generate_random_numbers "$num_count")

    # Run push_swap and count operations
    RESULT=$(./push_swap $ARG | wc -l)
    CHECKER_RESULT=$(./push_swap $ARG | ./checker_linux $ARG)

    # Update maximum operations found
    if [ "$RESULT" -gt "$max_found" ]; then
      max_found=$RESULT
    fi

    # Display results
    echo "Test $iteration:"
    echo "Arguments: $ARG"
    echo "Instructions: $RESULT (Max so far: $max_found)"
    echo "Checker result: $CHECKER_RESULT"
    echo "---------------------------------"

    # Check if instructions exceed the limit
    if [ "$RESULT" -gt "$max_operations" ]; then
      echo "Test stopped: Found a result with instructions greater than $max_operations."
      break
    fi

    # Check if the stack is not sorted
    if [ "$CHECKER_RESULT" == "KO" ]; then
      echo "Test stopped: The stack is not sorted."
      break
    fi
  done

  # Final summary
  echo "Summary for $num_count numbers:"
  echo "Maximum instructions found: $max_found"
  if [ "$max_found" -le "$max_operations" ]; then
    echo "SUCCESS: All tests passed within the operation limit ($max_operations)."
  else
    echo "FAILURE: Exceeded the operation limit ($max_operations)."
  fi
}

# Test for 100 numbers
#test_sorting 100 700

# Test for 500 numbers
test_sorting 500 5500