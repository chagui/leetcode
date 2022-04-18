#include "spiral-matrix.h"

using namespace std;

std::vector<int>
leetcode::Solution::spiralOrder(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return {};
    }
    if (matrix.size() == 1) {
        return matrix.front();
    }
    const size_t nb_of_rows = matrix.size();
    const size_t nb_of_cols = matrix.front().size();
    const size_t nb_of_elements = nb_of_rows * nb_of_cols;
    std::vector<int> results;
    results.reserve(nb_of_elements);

    int first_row = 0, first_col = 0, last_row = nb_of_rows - 1,
        last_col = nb_of_cols - 1;
    while (results.size() < nb_of_elements) {
        // copy elements from first row
        for (int index = first_col;
             results.size() < nb_of_elements && index <= last_col; ++index) {
            results.push_back(matrix[first_row][index]);
        }

        // copy elements from last column excluding the first row element
        for (int index = first_row + 1;
             results.size() < nb_of_elements && index <= last_row; ++index) {
            results.push_back(matrix[index][last_col]);
        }

        // reverse copy elements from last row excluding the last column element
        for (int index = last_col - 1;
             results.size() < nb_of_elements && index >= first_col; --index) {
            results.push_back(matrix[last_row][index]);
        }

        // reverse copy elements from first column excluding the last row
        // element
        for (int index = last_row - 1;
             results.size() < nb_of_elements && index > first_row; --index) {
            results.push_back(matrix[index][first_col]);
        }
        ++first_row, ++first_col, --last_row, --last_col;
    }

    return results;
}
