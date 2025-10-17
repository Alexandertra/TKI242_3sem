#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <vector>
#include <string>

class Matrix {
protected:
    std::unique_ptr<std::vector<int>> data;

public:
    Matrix();
    Matrix(size_t size);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    virtual ~Matrix() = default;

    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    Matrix operator<<(int shift) const;
    Matrix operator>>(int shift) const;

    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& operator*();

    size_t size() const;
    std::string toString() const;
    void resize(size_t newSize);
    void clear();

    // Абстрактные методы для решения конкретных задач
    virtual void process() = 0;
    virtual std::string getTaskDescription() const = 0;

protected:
    int getFirstDigit(int number) const;
};

// Класс для замены последнего отрицательного элемента предпоследним
class NegativeReplacerMatrix : public Matrix {
public:
    using Matrix::Matrix;

    void process() override;
    std::string getTaskDescription() const override;
};

// Класс для удаления элементов с четной первой цифрой
class EvenDigitRemoverMatrix : public Matrix {
public:
    using Matrix::Matrix;

    void process() override;
    std::string getTaskDescription() const override;

    // Специфичный метод для этого класса
    Matrix removeEvenFirstDigitElements() const;
};

// Класс для создания массива A из D по специальному правилу
class ArrayCreatorMatrix : public Matrix {
public:
    using Matrix::Matrix;

    void process() override;
    std::string getTaskDescription() const override;

    // Специфичный метод для этого класса
    Matrix createArrayAFromD() const;
};

#endif