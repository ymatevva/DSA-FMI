# HW_2 - k-ary Heap Project 

This project implements a k-ary heap, a generalization of the binary heap where each node has up to `k` children. The heap supports standard heap operations with customizable arity.

## Features

- **k-ary Heap**:
  - Each node can have up to `k` children.
  - `k` is specified in the constructor.
  - Supports both min-heap and max-heap behavior if desired.

- **Supported Operations**:
  - `insert(element)` – Add a new element to the heap.
  - `extract()` – Remove and return the root element (minimum or maximum depending on heap type).
  - `peek()` – Return the root element without removing it.
  - `size()` – Returns the number of elements in the heap.
  - `empty()` – Checks if the heap is empty.
  - `heapify()` – Rearranges the elements to maintain heap property after bulk insertions.
