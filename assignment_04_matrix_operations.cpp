// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

void readDimensions(int &rows, int &cols, const string &which = "") {
    while (true) {
        cout << "Enter number of rows: ";
        if (!(cin >> rows)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        cout << "Enter number of columns: ";
        if (!(cin >> cols)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        if (rows >= 1 && rows <= MAX && cols >= 1 && cols <= MAX) break;
        cout << "Rows and columns must be between 1 and " << MAX << ". Try again.\n";
    }
}

void readMatrix(int mat[MAX][MAX], int rows, int cols, const string &label = "") {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            while (!(cin >> mat[i][j])) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter element [" << i << "][" << j << "]: ";
            }
        }
    }
}

void printMatrix(const int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << mat[i][j];
        }
        cout << '\n';
    }
}

void transposeMatrix(const int in[MAX][MAX], int out[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            out[j][i] = in[i][j];
}

void addMatrices(const int a[MAX][MAX], const int b[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            res[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(const int a[MAX][MAX], const int b[MAX][MAX], int res[MAX][MAX], int m, int n, int p) {
    // result is m x p, with inner dimension n
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    // PART A — Transpose a Matrix
    cout << "PART A — Transpose a Matrix\n";
    int rowsA, colsA;
    readDimensions(rowsA, colsA);
    int A[MAX][MAX] = {0};
    readMatrix(A, rowsA, colsA);
    cout << "\nOriginal Matrix:\n";
    printMatrix(A, rowsA, colsA);

    int T[MAX][MAX] = {0};
    transposeMatrix(A, T, rowsA, colsA);
    cout << "\nTransposed Matrix:\n";
    printMatrix(T, colsA, rowsA); // transposed dims: colsA x rowsA

    // PART B — Add Two Matrices
    cout << "\nPART B — Add Two Matrices\n";
    int rowsB1, colsB1;
    readDimensions(rowsB1, colsB1);
    int B1[MAX][MAX] = {0};
    readMatrix(B1, rowsB1, colsB1);

    int rowsB2, colsB2;
    // For addition, sizes must match. We'll prompt for the second matrix dims and check.
    cout << "Now enter dimensions for second matrix (must match first):\n";
    while (true) {
        readDimensions(rowsB2, colsB2);
        if (rowsB1 == rowsB2 && colsB1 == colsB2) break;
        cout << "Dimensions do not match the first matrix. They must be " << rowsB1 << " x " << colsB1 << ". Try again.\n";
    }
    int B2[MAX][MAX] = {0};
    readMatrix(B2, rowsB2, colsB2);

    int Sum[MAX][MAX] = {0};
    addMatrices(B1, B2, Sum, rowsB1, colsB1);
    cout << "\nSum Matrix:\n";
    printMatrix(Sum, rowsB1, colsB1);

    // PART C — Multiply Two Matrices
    cout << "\nPART C — Multiply Two Matrices\n";
    int m, n, p;
    cout << "Enter dimensions for matrix A (M x N):\n";
    readDimensions(m, n);
    int M1[MAX][MAX] = {0};
    readMatrix(M1, m, n);

    cout << "Enter dimensions for matrix B (N x P):\n";
    // For multiplication, rows of B must equal n
    int rowsB, colsB;
    while (true) {
        readDimensions(rowsB, colsB);
        if (rowsB == n) {
            p = colsB;
            break;
        }
        cout << "Number of rows of B must equal number of columns of A (" << n << "). Try again.\n";
    }
    int M2[MAX][MAX] = {0};
    readMatrix(M2, n, p);

    int Product[MAX][MAX] = {0};
    multiplyMatrices(M1, M2, Product, m, n, p);
    cout << "\nProduct Matrix (A x B):\n";
    printMatrix(Product, m, p);

    return 0;
}

