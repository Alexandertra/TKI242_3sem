#pragma once
#include <memory>
#include <vector>
#include <string>

class Matrix {
private:
    std::unique_ptr<std::vector<int>> data;

public:
    // Конструкторы по умолчанию
    Matrix();
    Matrix(size_t size);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;

    // Деструктор
    ~Matrix();

    // Операторы
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    Matrix operator<<(int shift) const;
    Matrix operator>>(int shift) const;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& operator*();

    // Методы
    size_t size() const;
    std::string toString() const;
    void resize(size_t newSize);
    void clear();

    // Алгоритмы обработки
    void replaceLastNegativeWithPenultimate();
    Matrix removeEvenFirstDigitElements() const;
    Matrix createArrayAFromD() const;

private:
    int getFirstDigit(int number) const;
};