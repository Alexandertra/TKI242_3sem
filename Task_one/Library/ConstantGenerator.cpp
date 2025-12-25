#include "ConstantGenerator.h"

ConstantGenerator::ConstantGenerator(int value)
    : constantValue(value) {
}

void ConstantGenerator::fill(Matrix& matrix) {
    // Получаем доступ к данным матрицы
    auto& data = matrix.getData();

    // Заполняем весь вектор константным значением
    std::fill(data.begin(), data.end(), constantValue);
}
   