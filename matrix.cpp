#include "matrix.hpp" // include the header file for the matrix class
#include <iostream> // include the standard input output library
#include <iomanip> // include the input output manipulation library
#include <stdexcept> // include the standard exception library
#include <algorithm> // include the algorithm library

using namespace std; // use standard namespace for convenience
Matrix::Matrix(size_t N) : size(N) { // constructor that initializes a matrix with a given size of NxN filled with 0s
    data.resize(N, vector<int>(N, 0)); // resize the 2D vector to be NxN and fill with 0s
}

Matrix::Matrix(vector<vector<int>> nums) : data(nums) { // constructor that initializes a matrix using a provided 2D vector
    if (!nums.empty()) // if the provided vector is not empty
        size = nums.size(); // set the matrix size to the number of rows
    else // if it is empty
        size = 0; // set the size to 0
}

Matrix Matrix::operator+(const Matrix &rhs) const { // overloaded +operator that adds two matrices of the same size
    if (size != rhs.size) // if the sizes of the matrices differ
        throw invalid_argument("Matrices must be of the same size for addition"); // throw an exception

    Matrix result(size); // create a result matrix of the same size
    for (size_t i = 0; i < size; i++) { // loop through each row
        for (size_t j = 0; j < size; j++) { // loop through each column
            result.data[i][j] = data[i][j] + rhs.data[i][j]; // add corresponding elements from both matrices
        }
    }
    return result; // return the resulting matrix
}

Matrix Matrix::operator*(const Matrix &rhs) const { // overloaded *operator that multiplies two matrices
    if (size != rhs.size) // if the size of the matrices differ
        throw invalid_argument("Matrices must be of the same size for multiplication"); // throw an exception

    Matrix result(size); // create a result matrix of the same size
    for (size_t i = 0; i < size; i++) { // loop through each row of the first matrix
        for (size_t j = 0; j < size; j++) { // loop through each column of the second matrix
            int sum = 0; // initialize the sum for the dot product
            for (size_t k = 0; k < size; k++) { // loop through each element for the dot product calculation
                sum += data[i][k] * rhs.data[k][j]; // multiply and accumulate the product
            }
            result.data[i][j] = sum; // set the calculated sum in the result matrix
        }
    }
    return result; // return the resulting matrix
}

void Matrix::set_value(size_t i, size_t j, int n) { // set the value at a given row i and column j to a new value n
    if (i >= size || j >= size) // check if the indices are within the bounds of the matrix
        throw out_of_range("Index out of bounds"); // if not throw an exception
    data[i][j] = n; // update the value at the specified indices
}

int Matrix::get_value(size_t i, size_t j) const { // gets the value at a given row i and column j
    if (i >= size || j >= size) // check if the indices are within the bounds of the matrix
        throw out_of_range("Index out of bounds"); // if not throw an exception
    return data[i][j]; // return the value at the specified indices
}

int Matrix::get_size() const { // returns the size of the matrix
    return size; // return the stored matrix size
}

int Matrix::sum_diagonal_major() const { // calculates and returns the sum of the major diagonal elements
    int sum = 0; // initialize the sum
    for (size_t i = 0; i < size; i++) { // loop through each element on the main diagonal
        sum += data[i][i]; // add the diagonal element to the sum
    }
    return sum; // return the computed sum
}

int Matrix::sum_diagonal_minor() const { // calculates and returns the sum of the minor diagonal elements
    int sum = 0; // initialize the sum
    for (size_t i = 0; i < size; i++) { // loop through each element on the secondary diagonal
        sum += data[i][size - i - 1]; // add the element from the secondary diagonal to the sum
    }
    return sum; // return the computed sum
}

void Matrix::swap_rows(size_t r1, size_t r2) { // swaps two rows of the matrix given their indices
    if (r1 >= size || r2 >= size) // check if the row indices are within bounds
        throw out_of_range("Row index out of bounds"); // if not throw exception
    swap(data[r1], data[r2]); // swap the two rows using the standard library swap function
}

void Matrix::swap_cols(size_t c1, size_t c2) { // swaps two columns of the matrix given their indices
    if (c1 >= size || c2 >= size) // check if the column indices are within bounds
        throw out_of_range("Column index out of bounds"); // if not throw exception
    for (size_t i = 0; i < size; i++) { // loop through each row to swap the elements in the two specified columns
        swap(data[i][c1], data[i][c2]); // swap the column elements
    }
}

void Matrix::print_matrix() const { // prints the matrix to the console
    for (size_t i = 0; i < size; i++) { // loop through each row of the matrix
        for (size_t j = 0; j < size; j++) { // loop through each column of the matrix
            cout << setw(4) << data[i][j]; // output each element in a field width of 4 for alignmnet
        }
        cout << endl; // end the current line after finishing a row
    }
}
