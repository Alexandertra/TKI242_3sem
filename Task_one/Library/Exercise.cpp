#include "Exercise.h"
#include <iostream>

// Конструктор
Exercise::Exercise(const Matrix& matrix)
    : inputMatrix(matrix), resultMatrix(matrix) {
}

// Получение входной матрицы
const Matrix& Exercise::getInputMatrix() const {
    return inputMatrix;
}

// Получение результирующей матрицы
const Matrix& Exercise::getResultMatrix() const {
    return resultMatrix;
}

// Вывод результатов
void Exercise::printResults() const {
    std::cout << "=== " << getName() << " ===" << std::endl;
    std::cout << "Описание: " << getDescription() << std::endl;
    std::cout << "Входная матрица: " << inputMatrix.toString() << std::endl;
    std::cout << "Результат: " << resultMatrix.toString() << std::endl;
    std::cout << std::endl;
}

// Информация о доступных операциях
std::string Exercise::getAvailableOperations() const {
    return "Доступные операции:\n"
        "1. replaceLastNegativeWithPenultimate() - замена последнего отрицательного элемента\n"
        "2. removeEvenFirstDigitElements() - удаление элементов с четной первой цифрой\n"
        "3. createArrayAFromD() - создание массива A из D";
}