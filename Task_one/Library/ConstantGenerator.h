#pragma once
#include "Generator.h"

class ConstantGenerator : public Generator {
private:
    int constantValue;

public:
    explicit ConstantGenerator(int value);
    void fill(Matrix& matrix) override;
};
