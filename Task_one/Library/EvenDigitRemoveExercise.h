#pragma once
#include "Exercise.h"

// Класс для удаления элементов с четной первой цифрой
class EvenDigitRemoverExercise : public Exercise {
public:
    using Exercise::Exercise;

    void solve() override;
    std::string getDescription() const override;
    std::string getName() const override;

private:
    // Вспомогательный метод
    bool hasEvenFirstDigit(int number) const;
};