#pragma once
#include "Exercise.h"

//  ласс дл¤ создани¤ массива A из D по специальному правилу
class ArrayCreatorExercise : public Exercise {
public:
    using Exercise::Exercise;

    void solve() override;
    std::string getDescription() const override;
    std::string getName() const override;

private:
    // ѕравило преобразовани¤ D -> A
    int transformElement(int dElement) const;
};