#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "ManualGenerator.h"
#include "ConstantsGenerator.h"
#include "Config.h"

int input() {
    int value;
    std::cin >> value;
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << Config::Messages::ENTER_ARRAY_SIZE;
    size_t n = input();

    Matrix matrix(n);

    std::cout << Config::Messages::CHOOSE_FILL_METHOD;
    std::cout << Config::Messages::OPTION_RANDOM;
    std::cout << Config::Messages::OPTION_MANUAL;
    std::cout << Config::Messages::OPTION_CONSTANT;

    int choice = input();
    std::unique_ptr<Generator> generator;

    switch (choice) {
    case Config::CHOICE_RANDOM:
        generator = std::make_unique<RandomGenerator>(
            Config::RANDOM_MIN_VALUE,
            Config::RANDOM_MAX_VALUE
        );
        break;
    case Config::CHOICE_MANUAL:
        generator = std::make_unique<ManualGenerator>(input);
        break;
    case Config::CHOICE_CONSTANT:
        generator = std::make_unique<ConstantsGenerator>(Config::CONSTANT_FILL_VALUE);
        break;
    default:
        std::cout << Config::Messages::INVALID_CHOICE;
        return 1;
    }

    generator->fill(matrix);

    std::cout << Config::Messages::CREATED_ARRAY
        << matrix.toString() << std::endl;

    Matrix clonedMatrix = matrix;
    clonedMatrix.replaceLastNegativeWithPenultimate();
    std::cout << Config::Messages::AFTER_REPLACEMENT
        << clonedMatrix.toString() << std::endl;

    Matrix filteredMatrix = matrix.removeEvenFirstDigitElements();
    std::cout << Config::Messages::AFTER_FILTERING
        << filteredMatrix.toString() << std::endl;

    Matrix arrayA = matrix.createArrayAFromD();
    std::cout << Config::Messages::ARRAY_A_FROM_D
        << arrayA.toString() << std::endl;

    Matrix shiftedLeft = matrix << Config::SHIFT_AMOUNT;
    Matrix shiftedRight = matrix >> Config::SHIFT_AMOUNT;

    std::cout << Config::Messages::SHIFT_LEFT
        << shiftedLeft.toString() << std::endl;
    std::cout << Config::Messages::SHIFT_RIGHT
        << shiftedRight.toString() << std::endl;

    return 0;
}