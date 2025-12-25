#include <gtest/gtest.h>
#include "Matrix.h"
#include "ConstantsGenerator.h"

TEST(MatrixTest, BasicOperations) {
    Matrix matrix(5);
    ConstantsGenerator generator(5);
    generator.fill(matrix);

    EXPECT_EQ(matrix.size(), 5);
    EXPECT_EQ(matrix[0], 5);
}

TEST(MatrixTest, ReplaceLastNegative) {
    Matrix matrix(3);
    matrix[0] = 1;
    matrix[1] = -2;
    matrix[2] = 3;

    matrix.replaceLastNegativeWithPenultimate();
    EXPECT_EQ(matrix[1], 3);
}

TEST(MatrixTest, RemoveEvenFirstDigit) {
    Matrix matrix(3);
    matrix[0] = 21;  // Первая цифра 2 - четная
    matrix[1] = 35;  // Первая цифра 3 - нечетная
    matrix[2] = 48;  // Первая цифра 4 - четная

    Matrix result = matrix.removeEvenFirstDigitElements();
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 35);
}
