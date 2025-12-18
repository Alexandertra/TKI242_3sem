#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "ManualGenerator.h"
#include "ConstantGenerator.h"

int input() {
    int value;
    std::cin >> value;
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");

    size_t n = input();

    Matrix matrix(n);

    int choice = input();
    std::unique_ptr<Generator> generator;

    switch (choice) {
    case Config::CHOICE_RANDOM:
        generator = std::make_unique<RandomGenerator>(
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

    std::vector<int> testData = { 12, -5, 7, -3, 24, -8, 45 };
    Matrix matrix(testData);

    std::cout << "Исходная матрица: " << matrix.toString() << std::endl;
    std::cout << std::endl;

    // Создаем и выполняем все упражнения
    std::vector<ExerciseType> exerciseTypes = {
        ExerciseType::NEGATIVE_REPLACER,
        ExerciseType::EVEN_DIGIT_REMOVER,
        ExerciseType::ARRAY_CREATOR
    };

    for (auto type : exerciseTypes) {
        try {
            // Создаем упражнение
            auto exercise = ExerciseFactory::createExercise(type, matrix);

            // Выполняем
            exercise->solve();

            // Выводим результаты
            exercise->printResults();

        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }

    return 0;
}