## 7th Marathon of Parallel Programming
### WSCAD-SSC/SBAC-PAD-2012
### October 17th, 2012

## Problem A
# Bucket Sort
Bucket Sort is another divide and conquer algorithm. It works by partitioning an array
into a number of buckets. Each bucket is then sorted individually, either using a
different sorting algorithm, or by recursively applying the bucket sorting algorithm

Write a parallel program that uses a Bucket Sort algorithm to sort keys.

# Input
The input file contains only one test case. The first line contains the total number of
keys (N) to be sorted (94 ≤ N ≤ 1010). The following lines contain N keys, each key in a
separate line. A key is a seven-character string made up of printable characters (0x21 to
0x7E – ASCII) not including the space character (0x20 ASCII). The input keys are
uniformly distributed.

The input must be read from a file named bucketsort.in

# Output
The output file contains the sorted keys. Each key must be in a separate line.
The output must be written to a file named bucketsort.out

# Example

Input
```
11
SINAPAD
SbacPad
Wscad12
Sinapad
1234567
LADGRID
WEAC-12
CTDeWIC
sinaPAD
MPP2012
SINApad
```

Output for the input
```
1234567
CTDeWIC
LADGRID
MPP2012
SINAPAD
SINApad
SbacPad
Sinapad
WEAC-12
Wscad12
sinaPAD
```
