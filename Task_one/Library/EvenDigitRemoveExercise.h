#pragma once
#include "Exercise.h"

class EvenDigitRemoverExercise : public Exercise {
public:
    using Exercise::Exercise;

    void execute() override;  // Было: void solve() override;
    void replaceLastNegativeWithPenultimate() override;
    Matrix removeEvenFirstDigitElements() const override;
    Matrix createArrayAFromD() const override;

    std::string getDescription() const override;
    std::string getName() const override;

private:
    bool hasEvenFirstDigit(int number) const;
};

// Реализация EvenDigitRemoverMatrix
void EvenDigitRemoverExercise::process() {
    *this = removeEvenFirstDigitElements();
}

Matrix EvenDigitRemoverExercise::removeEvenFirstDigitElements() const {
    std::vector<int> result;
    for (const auto& element : *data) {
        int firstDigit = getFirstDigit(element);
        if (firstDigit % 2 != 0) {
            result.push_back(element);
        }
    }

    EvenDigitRemoverExercise newMatrix;
    *newMatrix.data = result;
    return newMatrix;
}