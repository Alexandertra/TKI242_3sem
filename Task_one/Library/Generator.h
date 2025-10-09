#pragma once
#include "Matrix.h"

class Generator {
public:
    virtual ~Generator() = default;
    virtual void fill(Matrix& matrix) = 0; 
};