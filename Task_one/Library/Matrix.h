#pragma once
#include <vector>
#include <string>
#include <memory>

// Абстрактный базовый класс Matrix
class Matrix 
{
protected:
    std::vector<int> data;
    size_t size;

public:
    Matrix(const size_t size);
    Matrix(const std::vector<int>& data);
    Matrix(const Matrix& other);
    ~Matrix() = default;

    std::string toString() const;
    void fillFromGenerator(class Generator& generator);

    Matrix& operator=(const Matrix& other);
    Matrix operator<<(size_t shift);
    Matrix operator>>(size_t shift);

    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& at(size_t index);
    const int& at(size_t index) const;

    size_t getSize() const;
    const std::vector<int>& getData() const;
    bool isEmpty() const;

    std::string getType() const;

    std::string getOperationsDescription() const;
};