#include "Matrix.h"
#include <algorithm>
#include <sstream>
#include <cmath>

Matrix::Matrix() : data(std::make_unique<std::vector<int>>()) {}

Matrix::Matrix(size_t size) : data(std::make_unique<std::vector<int>>(size)) {}

Matrix::Matrix(const Matrix& other)
    : data(std::make_unique<std::vector<int>>(*other.data)) {
}

Matrix::Matrix(Matrix&& other) noexcept
    : data(std::move(other.data)) {
}

Matrix::~Matrix() = default;

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        *data = *other.data;
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
    }
    return *this;
}

Matrix Matrix::operator<<(int shift) const {
    Matrix result(*this);
    for (auto& element : *result.data) {
        element <<= shift;
    }
    return result;
}

Matrix Matrix::operator>>(int shift) const {
    Matrix result(*this);
    for (auto& element : *result.data) {
        element >>= shift;
    }
    return result;
}

int& Matrix::operator[](size_t index) {
    return (*data)[index];
}

const int& Matrix::operator[](size_t index) const {
    return (*data)[index];
}

int& Matrix::operator*() {
    return data->front();
}

size_t Matrix::size() const {
    return data->size();
}

std::string Matrix::toString() const {
    std::ostringstream oss;
    oss << "{ ";
    for (size_t i = 0; i < data->size(); ++i) {
        oss << (*data)[i];
        if (i < data->size() - 1) {
            oss << ", ";
        }
    }
    oss << " }";
    return oss.str();
}

void Matrix::resize(size_t newSize) {
    data->resize(newSize);
}

void Matrix::clear() {
    data->clear();
}

int Matrix::getFirstDigit(int number) const {
    number = std::abs(number);
    while (number >= 10) {
        number /= 10;
    }
    return number;
}

void Matrix::replaceLastNegativeWithPenultimate() {
    if (data->size() < 2) return;

    int lastNegativeIndex = -1;
    for (int i = data->size() - 1; i >= 0; --i) {
        if ((*data)[i] < 0) {
            lastNegativeIndex = i;
            break;
        }
    }

    if (lastNegativeIndex != -1) {
        (*data)[lastNegativeIndex] = (*data)[data->size() - 2];
    }
}

Matrix Matrix::removeEvenFirstDigitElements() const {
    std::vector<int> result;
    for (const auto& element : *data) {
        int firstDigit = getFirstDigit(element);
        if (firstDigit % 2 != 0) {
            result.push_back(element);
        }
    }

    Matrix newMatrix;
    *newMatrix.data = result;
    return newMatrix;
}

Matrix Matrix::createArrayAFromD() const {
    Matrix result(data->size());
    for (size_t i = 0; i < data->size(); ++i) {
        if (i % 2 == 0) {
            (*result.data)[i] = (*data)[i] * (*data)[i];
        }
        else {
            (*result.data)[i] = (*data)[i] * 2;
        }
    }
    return result;
}