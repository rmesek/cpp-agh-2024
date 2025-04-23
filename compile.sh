#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Define the output directory
BUILD_DIR="build"
# Define the compiler and flags
CXX="g++-14"
# CXXFLAGS="-std=c++23 -Wall -fanalyzer -fsanitize=address"
CXXFLAGS="-std=c++23 -Wall -fsanitize=address"

# Check if at least one argument is provided
if [ $# -eq 0 ]; then
  echo "Usage: $0 <file1.cpp | directory> [file2.cpp ...]"
  exit 1
fi

# Create the build directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Determine the executable name based on the first argument
if [ -d "$1" ]; then
  # If the first argument is a directory, use its name
  EXECUTABLE_NAME=$(basename "$1")
elif [[ "$1" == *.cpp ]]; then
  # If the first argument is a .cpp file, use its name without extension
  EXECUTABLE_NAME=$(basename "$1" .cpp)
else
  # Otherwise, use a default name or error out
  echo "Error: First argument must be a directory or a .cpp file."
  exit 1
fi
OUTPUT_PATH="$BUILD_DIR/$EXECUTABLE_NAME"

# Collect all .cpp files from arguments (files or directories)
SOURCE_FILES=()
for arg in "$@"; do
  if [ -d "$arg" ]; then
    # If argument is a directory, find all .cpp files in it (non-recursively)
    while IFS= read -r -d $'\0' file; do
      SOURCE_FILES+=("$file")
    done < <(find "$arg" -maxdepth 1 -name '*.cpp' -print0)
  elif [[ "$arg" == *.cpp ]] && [ -f "$arg" ]; then
    # If argument is a .cpp file, add it
    SOURCE_FILES+=("$arg")
  # Optionally handle non-directory, non-.cpp file arguments here
  # else
  #   echo "Warning: Ignoring argument '$arg' as it is not a directory or a .cpp file."
  fi
done

# Check if any .cpp files were found
if [ ${#SOURCE_FILES[@]} -eq 0 ]; then
  echo "Error: No .cpp files found in the provided arguments."
  exit 1
fi

# Compile and link the source files
# echo "Compiling and linking ${SOURCE_FILES[*]}..."
"$CXX" $CXXFLAGS -o "$OUTPUT_PATH" "${SOURCE_FILES[@]}"

# echo "Build successful! Executable created at: $OUTPUT_PATH"

# Run the compiled program
# echo "Running $EXECUTABLE_NAME..."
"$OUTPUT_PATH"