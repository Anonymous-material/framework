
Several state-of-the-art algorithms are embedded in our framework for implementing the given matrix M and the recovered matrix M', for instance, Paar1, RPaar1 (the randomised version of Paar1), BP, BFI (Banik et al.'s method), RNBP, A1, A2;
We adopt several openly available implementations for these heuristics:

1. Paar1、BP: Use the implementations from: https://github.com/rub-hgi/shorter_linear_slps_for_mds_matrices;
2. RPaar1: RPaar1 takes a candidate with equal possibility, is implemented by a slight tweaking of Paar1;
3. BFI: In order to implement BFI algorithm, we generate two permutation matrices randomly and use them as Banik et al. did;
4. RNBP、A1、A2: Adopted from Tan and Peyrin's implementation which can be found: https://github.com/thomaspeyrin/XORreduce.

It should be noted that BFI algorithm shuffles the rows and columns of the target matrix, and then applies BP algorithm (Paar’s algorithms for large matrices) to find a better solution. In fact, we can take the product matrix obtained by leftmutiplying and right-multiplying random permutation matrices with the target matrix as the input of any other heuristics. Therefore, in this paper we modify BFI algorithm, and combine their method with all the other heuristics (Paar1, RPaar1, BP, RNBP, A1 and A2).

The code can be run with a single thread or multithreading;
The variable "MULTI_THREAD_FLAG" in the file const.h indicates whether multithreading is used:
  MULTI_THREAD_FLAG = 0 : single thread;
  MULTI_THREAD_FLAG = 1 : multithreading.

To run this program, an example command will be:
        g++ *.h
        g++ *.cpp -o test.out -lpthread
        ./test.out <./test_matrix.txt    

An example of an input matrix will be:
16 16
1 0 0 0 0 0 1 0 1 1 0 0 1 1 1 0
0 1 0 0 0 0 1 1 0 0 1 0 0 0 0 1
0 0 1 0 1 0 0 1 0 0 0 1 1 0 0 0
0 0 0 1 0 1 0 0 1 0 0 0 1 1 0 0
0 0 1 0 1 0 0 0 1 1 1 0 1 1 0 0
0 0 1 1 0 1 0 0 0 0 0 1 0 0 1 0
1 0 0 1 0 0 1 0 1 0 0 0 0 0 0 1
0 1 0 0 0 0 0 1 1 1 0 0 1 0 0 0
1 1 0 0 1 1 1 0 1 0 0 0 0 0 1 0
0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 1
0 0 0 1 1 0 0 0 0 0 1 0 1 0 0 1
1 0 0 0 1 1 0 0 0 0 0 1 0 1 0 0
1 1 1 0 1 1 0 0 0 0 1 0 1 0 0 0
0 0 0 1 0 0 1 0 0 0 1 1 0 1 0 0
1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0
1 1 0 0 1 0 0 0 0 1 0 0 0 0 0 1
