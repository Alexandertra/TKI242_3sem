#pragma once
#include "Generator.h"

class ConstantsGenerator : public Generator {
private:
    int constantValue;

public:
    ConstantsGenerator(int value);
    void fill(Matrix& matrix) override;
}; 
