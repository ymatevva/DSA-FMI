# HW_2 -  UnorderedSet 

This project implements a templated unordered set using **separate chaining hash** for internal storage. The class supports custom element types and hash functions and provides full iterator support.

## Features

### Template Parameters

- `T`: Type of elements stored in the set.
- `Hash`: Hash function type (defaults to a standard hash if not provided).

### Internal Representation

- The set uses **separate chaining** for collision resolution.
- Iterators traverse elements in a way that all elements with the same hash code are consecutive.

### Supported Operations

- **Insertion**
  - `insert(element)` – Adds an element to the set. Duplicate elements are ignored.

- **Removal**
  - `remove(element)` – Removes the element with the given key, if it exists.
  - `remove(iterator)` – Removes the element pointed to by the iterator. Iterator becomes invalid after removal.

- **Search**
  - `find(element)` – Returns an iterator to the element if found, otherwise `end()`.

- **Clear**
  - `clear()` – Removes all elements from the set. The set becomes empty.

- **Check Empty**
  - `empty()` – Returns `true` if the set is empty, otherwise `false`.

- **Conditional Erasure**
  - `erase_if(predicate)` – Removes all elements for which the predicate returns `true`.  
    The predicate is a callable object or function that accepts an element and returns a boolean.

### Iterators

- Supports full iterator functionality:
  - `begin()`, `end()`
  - Increment `++`, decrement `--`
  - Dereference `*`
  - Equality/Inequality `==`, `!=`
- Iterators ensure that elements with the same hash code are consecutive during traversal.
