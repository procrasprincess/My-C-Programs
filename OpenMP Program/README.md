## Objectives

Write a program using OpenMP to hire 8 threads to accomplish the following:
- Declare a shared array: a of type integer of size 800.
- Declare a shared array: b of type integer of size 8.
- Generates 800 random numbers in the range 0 to 50,000 inclusive and stores them in array: a.
- The 8 threads with the ranks 0, 1, 2, 3, 4, 5, 6, 7 find the biggest number of array: a, from indices 0 to 99, 100 to 199, 200, 299, 300 to 399, 400 to 499, 500 to 599, 600 to 699,  700 to 799 and store them in b[0], b[1], b[2], b[3], b[4], b[5], b[6], and b[7] respectively.
- The function: main displays the biggest number of array: b.
