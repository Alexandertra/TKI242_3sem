#include "EvenDigitRemoverExercise.h"
#include <cmath>
#include <vector>

// Решение задачи
void EvenDigitRemoverExercise::solve() {
    const auto& data = inputMatrix.getData();
    std::vector<int> filteredData;

    // Фильтруем элементы
    for (int num : data) {
        if (!hasEvenFirstDigit(num)) {
            filteredData.push_back(num);
        }
    }

    // Создаем результирующую матрицу
    resultMatrix = Matrix(filteredData);
}

// Проверка, имеет ли число четную первую цифру
bool EvenDigitRemoverExercise::hasEvenFirstDigit(int number) const {
    // Берем абсолютное значение
    int n = std::abs(number);

    // Получаем первую цифру
    while (n >= 10) {
        n /= 10;
    }

    // Проверяем на четность
    return (n % 2 == 0);
}

// Описание задачи
std::string EvenDigitRemoverExercise::getDescription() const {
    return "Удаление всех элементов, первая цифра которых является четной";
}

// Имя задачи
std::string EvenDigitRemoverExercise::getName() const {
    return "Удаление элементов с четной первой цифрой";
}