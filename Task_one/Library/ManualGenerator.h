#pragma once
#include "Generator.h"
#include <functional>

class ManualGenerator : public Generator {
private:
    std::function<int()> inputFunction;

public:
    ManualGenerator(std::function<int()> inputFunc);
    void fill(Matrix& matrix) override;
}; 
