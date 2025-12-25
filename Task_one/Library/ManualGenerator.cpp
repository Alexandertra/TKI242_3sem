#include "ManualGenerator.h"

using namespace std;

ManualGenerator::ManualGenerator(std::function<int()> inputFunc)
    : inputFunction(inputFunc) {
}

void ManualGenerator::fill(Matrix& matrix) {
    // Проверяем, что функция ввода установлена
    if (!inputFunction) {
        throw std::runtime_error("Функция ввода не установлена для ManualGenerator");
    }

    // Проходим по всем элементам матрицы
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        // Выводим подсказку для пользователя
        std::cout << "Введите элемент [" << i << "]: ";

        // Получаем ввод от пользователя через переданную функцию
        int value = inputFunction();

        // Записываем значение в матрицу
        matrix[i] = value;
    }
}