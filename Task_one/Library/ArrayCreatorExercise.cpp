#include "ArrayCreatorExercise.h"
#include <vector>
#include <cmath>

// Решение задачи
void ArrayCreatorExercise::solve() {
    const auto& data = inputMatrix.getData();
    std::vector<int> resultData(data.size());

    // Применяем правило преобразования к каждому элементу
    for (size_t i = 0; i < data.size(); ++i) {
        resultData[i] = transformElement(data[i]);
    }

    // Создаем результирующую матрицу
    resultMatrix = Matrix(resultData);
}

// Правило преобразования (можно изменить)
int ArrayCreatorExercise::transformElement(int dElement) const {
    // Пример правила: A[i] = D[i]^2 - 2*D[i] + 1
    // Или просто: A[i] = D[i] * 2
    return dElement * 2;
}

// Описание задачи
std::string ArrayCreatorExercise::getDescription() const {
    return "Создание массива A из массива D по правилу: A[i] = D[i] * 2";
}

// Имя задачи
std::string ArrayCreatorExercise::getName() const {
    return "Создание массива A из D";
}