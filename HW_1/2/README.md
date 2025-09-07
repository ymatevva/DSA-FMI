# HW_1 - Specialized Vector<bool>

This project implements a specialization of the `Vector` class template for storing boolean (`bool`) values efficiently. Each boolean value is stored using **only one bit**, minimizing memory usage.

## Features

### Element Manipulation

- `void push_back(bool value)`  
  Adds an element to the end of the vector.

- `void pop_back()`  
  Removes the last element in the vector.

- `void insert(iterator pos, bool value)`  
  Inserts an element at the position indicated by the iterator.

- `void remove(iterator pos)`  
  Removes an element at the position indicated by the iterator.

- `void pop_front()`  
  Removes the first element in the vector.

### Indexing

- `operator[]`  
  Access or modify elements by index.
  - Supports both **constant** and **non-constant** versions.

### Iterators

- The class provides **iterators** for traversing the vector:
  - `iterator`
  - `const_iterator`
  - `reverse_iterator`

- Supported iterator operations:
  - Increment `++`
  - Decrement `--`
  - Dereference `*`
  - Equality/Inequality `==`, `!=`

