#pragma once
#include "Exercise.h"

class NegativeReplacerExercise : public Exercise {
public:
    using Exercise::Exercise;

    // Реализация чисто виртуальных методов
    void execute() override;  // Было: void solve() override;
    void replaceLastNegativeWithPenultimate() override;
    Matrix removeEvenFirstDigitElements() const override;
    Matrix createArrayAFromD() const override;

    std::string getDescription() const override;
    std::string getName() const override;

private:
    int findLastNegativeIndex() const;
};

// Реализация NegativeReplacerMatrix
void NegativeReplacerExercise::process() {
    if (data->size() < 2) return;

    int lastNegativeIndex = -1;
    for (int i = data->size() - 1; i >= 0; --i) {
        if ((*data)[i] < 0) {
            lastNegativeIndex = i;
            break;
        }
    }

    if (lastNegativeIndex != -1) {
        (*data)[lastNegativeIndex] = (*data)[data->size() - 2];
    }
}

std::string NegativeReplacerExercise::getTaskDescription() const {
    return "Replace last negative element with penultimate element";
}