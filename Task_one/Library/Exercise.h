#pragma once
#include "Matrix.h"
#include <string>
#include <memory>

// Абстрактный базовый класс для упражнений
class Exercise {
protected:
    Matrix inputMatrix;  // Входная матрица для обработки
    Matrix resultMatrix; // Результат выполнения упражнения

public:
    // Конструктор принимает матрицу для обработки
    explicit Exercise(const Matrix& matrix);
    virtual ~Exercise() = default;

    // Чисто виртуальный метод execute() - каждая задача реализует свою логику выполнения
    virtual void execute() = 0;

    // Три основные задачи как чисто виртуальные функции
    virtual void replaceLastNegativeWithPenultimate() = 0;
    virtual Matrix removeEvenFirstDigitElements() const = 0;
    virtual Matrix createArrayAFromD() const = 0;

    // Виртуальный метод для получения описания задачи
    virtual std::string getDescription() const = 0;

    // Виртуальный метод для получения имени задачи
    virtual std::string getName() const = 0;

    // Методы для доступа к результатам
    const Matrix& getInputMatrix() const;
    const Matrix& getResultMatrix() const;

    // Метод для вывода результатов
    virtual void printResults() const;

    // Метод для получения информации о доступных операциях
    virtual std::string getAvailableOperations() const;
};