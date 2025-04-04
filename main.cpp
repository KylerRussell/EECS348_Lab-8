#include "matrix.hpp" // include the header file for the matrix class
#include <iostream> // include the standard input output library
#include <fstream> // include the file stream library
#include <sstream> // include the string stream library
#include <vector> // include the vector container
#include <stdexcept> // include the standard exceptions for error handling

using namespace std; // use standard namespace for convenience
bool load_matrices(const string &filename, Matrix &m1, Matrix &m2) { // function to load two matrices from a file
    ifstream infile(filename); // create an input file stream object and open the file
    if (!infile.is_open()) { // if the file cannot be opened
        cerr << "Error: Cannot open file " << filename << endl; // output error message
        return false; // return false
    }

    int N; // declare an integer variable to hold the size of the matrices
    infile >> N; // read the size of the matrix from the file
    if (N <= 0) { // if the size of the matrix is less than or equal to 0
        cerr << "Error: Matrix size must be a positive integer." << endl; // output an error message
        return false; // return false
    }

    vector<vector<int>> nums1(N, vector<int>(N)); // create a 2D Vector of size NxN to store the first matrix
    for (int i = 0; i < N; i++) { // loop through each row of the first matrix
        for (int j = 0; j < N; j++) { // loop through each column of the first matrix
            infile >> nums1[i][j]; // read in the integer from the file and store it in the vector
        }
    }

    vector<vector<int>> nums2(N, vector<int>(N)); // create a 2D Vector of size NxN to store the second matrix
    for (int i = 0; i < N; i++) {  // loop through each row of the second matrix
        for (int j = 0; j < N; j++) { // loop through each column of the second matrix
            infile >> nums2[i][j]; // read in the integer from the file and store it in the vector
        }
    }

    m1 = Matrix(nums1); // initialize the first matrix using the first 2D vector
    m2 = Matrix(nums2); // initialize the second matrix using the first 2D vector
    return true; // return true to indicate matrices were successfully loaded
}

int main(int argc, char *argv[]) { // declare the main function
    if (argc < 2) { // if fewer than two command line arguments are provided
        cerr << "Usage: " << argv[0] << " <input_file>" << endl; // output usage instructions
        return 1; // exit the program
    }

    string filename = argv[1]; // convert the second command line argument to a string representing the filename
    Matrix matrix1(0), matrix2(0); // declare two matrix objects with an initial size of 0

    if (!load_matrices(filename, matrix1, matrix2)) { // load matrices from the specified file
        return 1; // if it fails exit with error code
    }

    cout << "Matrix 1:" << endl; // output a header for matrix 1
    matrix1.print_matrix(); // print matrix 1 using its member function
    cout << endl; // output an empty line for spacing

    cout << "Matrix 2:" << endl; // output a header for matrix 2
    matrix2.print_matrix(); // print matrix 2 using its member function
    cout << endl; // output an empty line for spacing

    Matrix added = matrix1 + matrix2; // add the two matrices and store the result in another matrix
    cout << "Matrix 1 + Matrix 2:" << endl; // ouput a header for the addition result
    added.print_matrix(); // print the resulting matrix from addition
    cout << endl; // output an empty line for spacing

    Matrix multiplied = matrix1 * matrix2; // multiply the two matrices and store the result in another matrix
    cout << "Matrix 1 * Matrix 2:" << endl; // output a header for the multiplication result
    multiplied.print_matrix(); // print the resulting matrix from the multiplication
    cout << endl; // output an empty line for spacing

    cout << "Sum of major diagonal elements of Matrix 1: "  // output a header for the sum of the major diagonal elements
    << matrix1.sum_diagonal_major() << endl; // output the sum of the major diagonal elements of the first matrix
    cout << "Sum of minor diagonal elements of Matrix 1: " // output a header for the sum of the minor diagonal elements
    << matrix1.sum_diagonal_minor() << endl; // output the sum of the minor diagonal elements of the first matrix
    cout << endl; // output an empty line for spacing

    if (matrix1.get_size() >= 2) { // if the first matrix has at least 2 rows
        matrix1.swap_rows(0, 1); // swap row 0 with row 1
        cout << "Matrix 1 after swapping rows 0 and 1:" << endl; // output a header after swapping rows
        matrix1.print_matrix(); // print the matrix after row swap
        cout << endl; // output an empty line for spacing
    }

    if (matrix1.get_size() >= 2) { // if the matrix has at least two columns
        matrix1.swap_cols(0, matrix1.get_size()-1); // swap the first column with the last column
        cout << "Matrix 1 after swapping column 0 and column " // output a header after swapping columns
        << matrix1.get_size()-1 << ":" << endl; // output the continuation of the header
        matrix1.print_matrix(); // print the matrix after the column swap
        cout << endl; // output an empty line for spacing
    }

    if (matrix1.get_size() > 0) { // if the matrix is non empty
        matrix1.set_value(0, 0, 99); // update the position at (0,0) to 99
        cout << "Matrix 1 after updating element (0, 0) to 99:" << endl; // output a header after updating the matrix element
        matrix1.print_matrix(); // print the matrix after the update
        cout << endl; // output an empty line for spacing
    }

    return 0; // return 0 to indicate that the program executed successfully
}
