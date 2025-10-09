#include "RandomGenerator.h"
#include <cstdlib>
#include <ctime>

RandomGenerator::RandomGenerator(int min, int max)
    : minValue(min), maxValue(max) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void RandomGenerator::fill(Matrix& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i] = minValue + std::rand() % (maxValue - minValue + 1);
    }
}