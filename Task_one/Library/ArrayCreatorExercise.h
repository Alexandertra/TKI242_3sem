#pragma once
#include "Exercise.h"

class ArrayCreatorExercise : public Exercise {
public:
    using Exercise::Exercise;

    void execute() override;  // Было: void solve() override;
    void replaceLastNegativeWithPenultimate() override;
    Matrix removeEvenFirstDigitElements() const override;
    Matrix createArrayAFromD() const override;

    std::string getDescription() const override;
    std::string getName() const override;

private:
    int transformElement(int dElement) const;
};

// Реализация ArrayCreatorMatrix
void ArrayCreatorExercise::process() {
    *this = createArrayAFromD();
}

Matrix ArrayCreatorExercise::createArrayAFromD() const {
    ArrayCreatorExercise result(data->size());
    for (size_t i = 0; i < data->size(); ++i) {
        if (i % 2 == 0) {
            (*result.data)[i] = (*data)[i] * (*data)[i];
        }
        else {
            (*result.data)[i] = (*data)[i] * 2;
        }
    }
    return result;
}

std::string ArrayCreatorExercise::getTaskDescription() const {
    return "Create array A from D (even index: square, odd index: double)";
}