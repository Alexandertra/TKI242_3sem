#include "NegativeReplacerExercise.h"
#include <algorithm>
#include <stdexcept>

// Решение задачи
void NegativeReplacerExercise::solve() {
    const auto& data = inputMatrix.getData();
    int lastNegativeIndex = findLastNegativeIndex();

    if (lastNegativeIndex >= 0 && data.size() >= 2) {
        // Копируем входную матрицу
        resultMatrix = inputMatrix;

        // Получаем предпоследний элемент
        int penultimateValue = data[data.size() - 2];

        // Заменяем последний отрицательный элемент
        resultMatrix[lastNegativeIndex] = penultimateValue;
    }
    else {
        // Если нет отрицательных или матрица слишком мала
        resultMatrix = inputMatrix;
    }
}

// Поиск индекса последнего отрицательного элемента
int NegativeReplacerExercise::findLastNegativeIndex() const {
    const auto& data = inputMatrix.getData();
    int lastIndex = -1;

    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] < 0) {
            lastIndex = static_cast<int>(i);
        }
    }

    return lastIndex;
}

// Описание задачи
std::string NegativeReplacerExercise::getDescription() const {
    return "Замена последнего отрицательного элемента предпоследним элементом матрицы";
}

// Имя задачи
std::string NegativeReplacerExercise::getName() const {
    return "Замена отрицательного элемента";
}