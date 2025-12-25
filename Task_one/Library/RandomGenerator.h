#pragma once
#include "Generator.h"

class RandomGenerator : public Generator {
private:
    int minValue;
    int maxValue;

public:
    RandomGenerator(int min, int max);
    void fill(Matrix& matrix) override;
}; 
