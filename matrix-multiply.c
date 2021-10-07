/*
Naive code for multiplying two matrices together.

There must be a better way!
*/

#include <stdio.h>
#include <stdlib.h>

/*
  A naive implementation of matrix multiplication.

  DO NOT MODIFY THIS FUNCTION, the tests assume it works correctly, which it
  currently does
*/
void matrix_multiply(double **C, double **A, double **B, int a_rows, int a_cols,
                     int b_cols) {
  for (int i = 0; i < a_rows; i++) {
    for (int j = 0; j < b_cols; j++) {
      C[i][j] = 0;
      for (int k = 0; k < a_cols; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
  }
}

void kij_matrix_multiply(double **C, double **A, double **B, int a_rows, int a_cols,
                     int b_cols) {
  double r;
  for (int k = 0; k < a_rows; k++) {
    for (int i = 0; i < b_cols; i++) {
      r = A[i][k];
      for (int j = 0; j < a_cols; j++)
        C[i][j] += r*B[k][j];
    }
  }
}

void ikj_matrix_multiply(double **C, double **A, double **B, int a_rows, int a_cols,
                     int b_cols) {
  double r;
  for (int i = 0; i < a_rows; i++) {
    for (int k = 0; k < b_cols; k++) {
      r = A[i][k];
      for (int j = 0; j < a_cols; j++)
        C[i][j] += r*B[k][j];
    }
  }
}

void fast_matrix_multiply(double **c, double **a, double **b, int a_rows,
                          int a_cols, int b_cols) {
  return ikj_matrix_multiply(c, a, b, a_rows, a_cols, b_cols);
}
