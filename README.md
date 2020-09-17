# Data Structures And Algorithms
This repo is created to help me and other students learn more about different types of Data Structures and Algorithms. When programming the different types of data structures and algorithms, I will be using two different programming languages: C++ and Python.

The following algorithms have been completed:


# Sorting Algorithms

| Algorithms     | C++                | Python               | Time Complexity | Space Complexity |
|----------------|--------------------|----------------------|-----------------|------------------|
| Bubble Sort    | :heavy_check_mark: |  :heavy_check_mark:  | O(n<sup>2</sup>)|     O(1)         |
| Merge Sort     | :heavy_check_mark: |  :heavy_check_mark:  | O(n log n)      |     O(n)         |
| Insertion Sort | :heavy_check_mark: |  :heavy_check_mark:  | O(n<sup>2</sup>)|   O(1)           |
| Selection Sort | :heavy_check_mark: |  :heavy_check_mark:  | O(n<sup>2</sup>)|   O(1)           |
| Quick Sort     | :heavy_check_mark: |  :heavy_check_mark:  | O(n<sup>2</sup>)<sup>*</sup>      |  O(log n)          |

\* Although the time complexity for Quick Sort is  O(n<sup>2</sup>), if the pivots are chosen properly, the time complexity can become O(n log n).

# Sorting Algorithms Explanations (Pros, Cons, Potential uses)

1. Bubble Sort
    * Easy to understand and implement.
    * Very little use of memory as sorting takes place within array or list.
    * Extremely inefficient. O(n<sup>2</sup>) Time Complexity.
    * Performs more comparisons and swaps compared to other sorting algorithms.
2. Merge Sort
      * Complex compared to other algorithms and utilizes recursion
      * Extremely efficient in terms of time complexity
      * However, O(n) space complexity due to creating a new array that is sorted with length n which means additional memory is required.
3. Insertion Sort
4. Selection Sort
5. Quick Sort


# Search Algorithms

| Algorithms     | C++                | Python               | Time Complexity | Space Complexity |
|----------------|--------------------|----------------------|-----------------|------------------|
| Binary Search  | :heavy_check_mark: |  :heavy_check_mark:  | O(log n)        |     O(1)         |

# Data Structures

| Data Structures    | C++                | Python           | Access | Search | Insertion | Deletion|
|----------------|--------------------|----------------------|--------|--------|-----------|---------|
| Linked List  | :heavy_check_mark: | :heavy_check_mark:  | O(n) | O(n) | O(1) | O(1) |
| Hash Table  |   |   | N/A | O(n) | O(n) | O(n) |
| Binary Tree  |   |   |  |  |  |  |

1. Linked List
      * Although Insertion and Deletion are O(1), if desired to put a node at the end of the list for insertion or delete a specific item in the list, this would require O(n) because traversal of the list would be necessary.
2. Hash Table
      * Worst cases for Search, Insertion, and Deletion is O(n). However, this is only true if we have a bad hash function. Assuming that we have a good hash function and collisions occur less often, Search, Insertion, and Deletion can be considered O(1).
      * Hash Tables are one of the most useful data structures and most problems asked in coding interviews can be solved using a hash table.

When time permits, more algorithms and data structures will be discussed.
