#include "ConstantsGenerator.h"

ConstantsGenerator::ConstantsGenerator(int value)
    : constantValue(value) {
}

void ConstantsGenerator::fill(Matrix& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i] = constantValue;
    }
}