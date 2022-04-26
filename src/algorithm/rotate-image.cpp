#include <algorithm>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) { rotateWithMath(matrix); }

    void rotateWithMath(vector<vector<int>> &matrix) {
        for (vector<int> &row : matrix) {
            reverse(row.begin(), row.end());
        }

        const int dimension = matrix.size();
        for (int minIndex = 0, maxIndex = dimension - 1; minIndex < maxIndex; ++minIndex, --maxIndex) {
            const int maxOffset = maxIndex - minIndex;

            swap(matrix[minIndex][minIndex], matrix[maxIndex][maxIndex]);
            for (int offset = 1; offset < maxOffset; ++offset) {
                swap(matrix[minIndex][minIndex + offset], matrix[maxIndex - offset][maxIndex]);
                swap(matrix[minIndex + offset][minIndex], matrix[maxIndex][maxIndex - offset]);
            }
        }
    }

    void rotateWithBuffer(vector<vector<int>> &matrix) {
        const size_t dimension = matrix.size();
        vector<int> swapBuffer(dimension, 0);

        for (int minIndex = 0, maxIndex = dimension - 1; minIndex < maxIndex; ++minIndex, --maxIndex) {
            const int maxOffset = maxIndex - minIndex;

            // first row becomes last col
            for (int offset = 0; offset < maxOffset; ++offset) {
                const int srcRowIndex = minIndex, srcColIndex = minIndex + offset;
                const int destRowIndex = minIndex + offset, destColIndex = maxIndex;

                swapBuffer[offset] = matrix[destRowIndex][destColIndex];
                matrix[destRowIndex][destColIndex] = matrix[srcRowIndex][srcColIndex];
            }

            // last col becomes last row
            for (int offset = 0; offset < maxOffset; ++offset) {
                const int destRowIndex = maxIndex, destColIndex = maxIndex - offset;
                const int swappee = swapBuffer[offset];
                swapBuffer[offset] = matrix[destRowIndex][destColIndex];
                matrix[destRowIndex][destColIndex] = swappee;
            }

            // last row becomes first col
            for (int offset = 0; offset < maxOffset; ++offset) {
                const int destRowIndex = maxIndex - offset, destColIndex = minIndex;
                const int swappee = swapBuffer[offset];
                swapBuffer[offset] = matrix[destRowIndex][destColIndex];
                matrix[destRowIndex][destColIndex] = swappee;
            }

            // first col becomes first row
            for (int offset = 0; offset < maxOffset; ++offset) {
                const int destRowIndex = minIndex, destColIndex = minIndex + offset;
                const int swappee = swapBuffer[offset];
                swapBuffer[offset] = matrix[destRowIndex][destColIndex];
                matrix[destRowIndex][destColIndex] = swappee;
            }
        }
    }
};

TEST(RotateImage, Empty) {
    vector<vector<int>> matrix1, matrix2;
    vector<vector<int>> matrixRotated;

    Solution().rotateWithBuffer(matrix1);
    EXPECT_EQ(matrix1, matrixRotated);

    Solution().rotateWithMath(matrix2);
    EXPECT_EQ(matrix2, matrixRotated);
}

TEST(RotateImage, TwoByTwo) {
    vector<vector<int>> matrix1 {
        {1, 2},
        {3, 4},
    };
    vector<vector<int>> matrix2 = matrix1;
    vector<vector<int>> matrixRotated {
        {3, 1},
        {4, 2},
    };
    Solution().rotateWithBuffer(matrix1);
    EXPECT_EQ(matrix1, matrixRotated);
}

TEST(RotateImage, ThreeByThree) {
    vector<vector<int>> matrix1 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    vector<vector<int>> matrix2 = matrix1;
    vector<vector<int>> matrixRotated {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3},
    };

    Solution().rotate(matrix1);
    EXPECT_EQ(matrix1, matrixRotated);

    Solution().rotateWithMath(matrix2);
    EXPECT_EQ(matrix2, matrixRotated);
}

TEST(RotateImage, FourByFour) {
    vector<vector<int>> matrix1 {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
    };
    vector<vector<int>> matrix2 = matrix1;
    vector<vector<int>> matrixRotated {
        {13,  9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4},
    };

    Solution().rotateWithBuffer(matrix1);
    EXPECT_EQ(matrix1, matrixRotated);

    Solution().rotateWithMath(matrix2);
    EXPECT_EQ(matrix2, matrixRotated);
}

TEST(RotateImage, FiveByFive) {
    vector<vector<int>> matrix1 {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };
    vector<vector<int>> matrix2 = matrix1;
    vector<vector<int>> matrixRotated {
        {21, 16, 11,  6, 1},
        {22, 17, 12,  7, 2},
        {23, 18, 13,  8, 3},
        {24, 19, 14,  9, 4},
        {25, 20, 15, 10, 5},
    };

    Solution().rotateWithBuffer(matrix1);
    EXPECT_EQ(matrix1, matrixRotated);

    Solution().rotateWithMath(matrix2);
    EXPECT_EQ(matrix2, matrixRotated);
}
