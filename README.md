# Page Replacement Algorithm Simulator

## Brief Description

This C++ program provides as a versatile tool for simulating and comparing different page replacement algorithms: Least Recently Used (LRU), Optimal, and First-In-First-Out (FIFO). It adopts an object-oriented and data structure approach, using the algorithms within a 'PageReplacer' class.

## Layout

At its base, the program revolves around the 'PageReplacer' class, a storage to simulate each algorithm. The 'main' function navigates the simulation process, creating an instance of 'PageReplacer' and implementing its methods.

## Functions

- 'simulateLRU()': Implements the LRU algorithm, maintaining a page table and tracking page faults.
- 'simulateOptimal()': Executes the Optimal algorithm, predicting future page accesses to optimize page replacement decisions.
- 'simulateFIFO()': Enacts the FIFO algorithm, replacing pages based on their arrival order.

## Usage Instructions

1. **Compilation**: Compile the source code using a compatible C++ compiler.
2. **Execution**: Run the compiled program.
3. **Interaction**: The program outputs each algorithm simulation results. Each algorithm simulation presents detailed insights into page faults and the changing page tables.

## Error Handling

The program consists of error handling mechanisms, managing conditions like page faults or unexpected behavior. If issues occur during execution, informative error messages is displayed.
