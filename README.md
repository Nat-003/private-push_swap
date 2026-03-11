*This project has been created as part of the 42 curriculum by nappasam, rgliga*

## Description

Push Swap is a sorting algorithm project that implements various sorting strategies to sort a stack of integers using a limited set of stack operations and a secondary stack. The primary goal is to sort the stack with the minimum number of operations possible, making it an optimization challenge that requires careful algorithm selection and implementation.

The project consists of a C program that takes a list of integers as command-line arguments and outputs a sequence of stack operations that, when applied to the initial stack, will result in a sorted stack. The program supports multiple sorting algorithms and can automatically select the most appropriate one based on the input characteristics.

## Instructions

### Compilation
To compile the project, use the provided Makefile:
```bash
make
```

### Execution
Basic usage:
```bash
./push_swap [list of integers]
```

The program will output a sequence of operations to sort the stack. For example:
```bash
./push_swap 3 1 4 1 5
```

### Testing with Checker
The project includes a checker program (`checker_linux`) to validate the sorting:
```bash
./push_swap 3 1 4 1 5 | ./checker_linux 3 1 4 1 5
```

Expected output: "OK" if correctly sorted, "KO" if not.

### Command Line Flags
- `--simple`: Force simple sorting algorithm
- `--medium`: Force medium sorting algorithm
- `--complex`: Force complex (radix) sorting algorithm
- `--adaptative`: Use adaptive algorithm selection (default)
- `--bench`: Run in benchmark mode

## Resources

### Online Resources
- [GeeksforGeeks Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
- [GeeksforGeeks: Bucket Sort](https://www.geeksforgeeks.org/dsa/bucket-sort-2/)
- [GeeksforGeeks: Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/)

### AI Usage
- Debugging assistance and error identification
- Algorithm implementation guidance and best practices

## Algorithm Selection and Justification

The project implements four main sorting approaches, each optimized for different input characteristics:

### Simple Sort (Bubble Sort Variant)
**Algorithm**: For stacks of size ≤ 5, uses hardcoded optimal solutions. For larger stacks, implements a modified bubble sort that rotates through the stack to find and swap adjacent elements.

**Justification**: Optimal for very small stacks where the number of operations can be predetermined. Bubble sort is simple to implement and works well for nearly sorted data. The rotation-based approach ensures all elements are considered in each pass.

**Best for**: Stacks with ≤ 100 elements or low disorder levels (< 10 inversions)

### Medium Sort (Bucket Sort)
**Algorithm**: Converts all values to their indices in a sorted copy of the array, then uses a bucket-based approach to push elements to stack B and back to stack A in sorted order.

**Justification**: More efficient than bubble sort for medium-sized stacks. The index transformation allows for better element tracking and reduces comparison operations. The bucket approach provides O(n) space complexity with good performance for moderately disordered data.

**Best for**: Stacks with 100-500 elements or medium disorder levels (10-100 inversions)

### Complex Sort (Radix Sort)
**Algorithm**: Implements binary radix sort by processing numbers bit by bit. Elements are pushed to stack B based on the current bit value, then pushed back to stack A, repeating for each bit until fully sorted.

**Justification**: Highly efficient for large datasets with O(n) time complexity per bit. The bit-by-bit processing eliminates the need for comparisons, making it ideal for large stacks where comparison-based sorts become inefficient.

**Best for**: Stacks with > 500 elements or high disorder levels (> 100 inversions)

### Adaptive Sort
**Algorithm**: Automatically selects the optimal algorithm based on a disorder metric calculated as the number of inversions in the initial stack.

**Justification**: Provides the best overall performance by dynamically choosing the most appropriate sorting strategy. The disorder calculation gives insight into how "scrambled" the data is, allowing intelligent algorithm selection rather than using a one-size-fits-all approach.

**Thresholds**:
- Disorder < 10: Simple Sort
- Disorder < 100: Medium Sort
- Disorder ≥ 100: Complex Sort

This adaptive approach ensures optimal performance across various input types while maintaining code simplicity and maintainability.
