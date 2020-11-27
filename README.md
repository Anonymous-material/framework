
Several state-of-the-art algorithms are embedded in our framework for implementing the given matrix M and the recovered matrix M', for instance, Paar1, RPaar1 (the randomised version of Paar1), BP, BFI (Banik et al.'s method), RNBP, A1, A2;
We adopt several openly available implementations for these heuristics:

1. Paar1、BP: Use the implementations from: https://github.com/rub-hgi/shorter_linear_slps_for_mds_matrices;
2. RPaar1: RPaar1 takes a candidate with equal possibility, is implemented by a slight tweaking of Paar1;
3. BFI: In order to implement BFI algorithm, we generate two permutation matrices randomly and use them as Banik et al. did;
4. RNBP、A1、A2: Adopted from Tan and Peyrin's implementation which can be found: https://github.com/thomaspeyrin/XORreduce.
