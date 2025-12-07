#pragma once
#include <vector>
#include <string>
#include <memory>

// Абстрактный базовый класс Matrix
class Matrix {
protected:
    std::vector<int> data;
    size_t size;

public:
    Matrix(size_t size);
    Matrix(const std::vector<int>& data);
    Matrix(const Matrix& other);
    virtual ~Matrix() = default;

    virtual void replaceLastNegativeWithPenultimate() = 0;
    virtual Matrix removeEvenFirstDigitElements() const = 0;
    virtual Matrix createArrayAFromD() const = 0;

    virtual std::string toString() const = 0;
    virtual void fillFromGenerator(class Generator& generator) = 0;

    virtual Matrix& operator=(const Matrix& other) = 0;
    virtual Matrix operator<<(size_t shift) const = 0;
    virtual Matrix operator>>(size_t shift) const = 0;

    virtual int& operator[](size_t index) = 0;
    virtual const int& operator[](size_t index) const = 0;
    virtual int& at(size_t index) = 0;
    virtual const int& at(size_t index) const = 0;

    virtual size_t getSize() const;
    virtual const std::vector<int>& getData() const;
    virtual bool isEmpty() const;

    virtual std::string getType() const = 0;

    virtual std::string getOperationsDescription() const = 0;
};