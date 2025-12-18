#pragma once
#include "Exercise.h"

// Класс для замены последнего отрицательного элемента предпоследним
class NegativeReplacerExercise : public Exercise {
public:
    using Exercise::Exercise;  // Наследуем конструктор

    // Реализация чисто виртуальных методов
    void solve() override;
    std::string getDescription() const override;
    std::string getName() const override;

private:
    // Вспомогательные методы
    int findLastNegativeIndex() const;
};