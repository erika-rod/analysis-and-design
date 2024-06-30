# analysis-and-design

## Project One: Analysis of Run-Time and Memory for Data Structures

### Analysis of Run-Time and Memory

In Project One, I evaluated the run-time and memory usage of three data structures: vectors, hash tables, and binary search trees. Here's a summary of my analysis:

- **Vector**: 
  - **Insertion**: O(1) average, O(n) worst-case (due to resizing)
  - **Search**: O(n)
  - **Memory**: Contiguous memory allocation
- **Hash Table**: 
  - **Insertion and Search**: O(1) average, O(n) worst-case (due to collisions)
  - **Memory**: Depends on load factor and resizing
- **Binary Search Tree (BST)**: 
  - **Insertion and Search**: O(log n) average, O(n) worst-case (unbalanced)
  - **Memory**: Node-based, non-contiguous memory allocation

Based on the analysis, I recommended using hash tables due to their average-case performance benefits for insertion and search operations.

## Project Two: Working Code for Sorting and Printing Courses

### Sorting and Printing Courses

(Include the working code for sorting and printing courses here.)

## Reflection

### What was the problem you were solving in the projects for this course?
The problem I was solving involved creating an advising assistance program for academic advisors in the Computer Science department at ABCU. The program needed to read course data from a file, store it in an appropriate data structure, and provide various functionalities such as printing an alphanumeric list of courses and displaying specific course information.

### How did you approach the problem? Consider why data structures are important to understand.
I approached the problem by first analyzing different data structures to determine which would be most efficient for the given requirements. Understanding data structures is crucial because they directly impact the performance and efficiency of an application. By analyzing vectors, hash tables, and binary search trees, I was able to choose the most suitable data structure based on their run-time and memory usage characteristics.

### How did you overcome any roadblocks you encountered while going through the activities or project?
I encountered roadblocks related to handling file input and ensuring the correct parsing and storage of course data. I overcame these by thoroughly testing different scenarios, implementing error handling for file operations, and using debugging techniques to track down and fix issues.

### How has your work on this project expanded your approach to designing software and developing programs?
Working on this project expanded my approach to designing software by emphasizing the importance of choosing the right data structures for specific tasks. It highlighted how critical it is to balance efficiency and functionality when developing programs, leading to better performance and maintainability.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
This project has significantly influenced my coding practices. I now place a stronger emphasis on writing clear, maintainable code with appropriate naming conventions and in-line comments. Additionally, I prioritize error handling and user feedback to create robust and user-friendly programs. These practices ensure that my code is not only functional but also easier to maintain and adapt in the future.
