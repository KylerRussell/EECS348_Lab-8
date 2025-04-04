#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

using namespace std; // use standard namespace for convenience
class Matrix {
public:
    Matrix(size_t N);
    Matrix(vector<vector<int>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(size_t i, size_t j, int n);
    int get_value(size_t i, size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(size_t r1, size_t r2);
    void swap_cols(size_t c1, size_t c2);
    void print_matrix() const;

private:
    size_t size; // the size N of the matrix
    vector<vector<int>> data; // 2D vector to store the matrix data
};

#endif // __MATRIX_HPP__
