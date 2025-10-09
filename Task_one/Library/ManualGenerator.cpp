#include "ManualGenerator.h"

ManualGenerator::ManualGenerator(std::function<int()> inputFunc)
    : inputFunction(inputFunc) {
}

void ManualGenerator::fill(Matrix& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i] = inputFunction();
    }
}