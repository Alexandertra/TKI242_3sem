#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "ManualGenerator.h"
#include "ConstantsGenerator.h"

int input() {
    int value;
    std::cin >> value;
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите размер массива: ";
    size_t n = input();

    Matrix matrix(n);

    std::cout << "Выберите способ заполнения:\n";
    std::cout << "1 - Случайные числа [-10;20]\n";
    std::cout << "2 - Ввод с клавиатуры\n";
    std::cout << "3 - Заполнение нулями\n";

    int choice = input();
    std::unique_ptr<Generator> generator;

    switch (choice) {
    case 1:
        generator = std::make_unique<RandomGenerator>(-10, 20);
        break;
    case 2:
        generator = std::make_unique<ManualGenerator>(input);
        break;
    case 3:
        generator = std::make_unique<ConstantsGenerator>(0);
        break;
    default:
        std::cout << "Неверный выбор!\n";
        return 1;
    }

    generator->fill(matrix);

    std::cout << "Созданный массив:\n" << matrix.toString() << std::endl;

    // Замена последнего отрицательного элемента
    Matrix clonedMatrix = matrix;
    clonedMatrix.replaceLastNegativeWithPenultimate();
    std::cout << "После замены последнего отрицательного элемента:\n"
        << clonedMatrix.toString() << std::endl;

    // Удаление элементов с четной первой цифрой
    Matrix filteredMatrix = matrix.removeEvenFirstDigitElements();
    std::cout << "После удаления элементов с четной первой цифрой:\n"
        << filteredMatrix.toString() << std::endl;

    // Создание массива A из D
    Matrix arrayA = matrix.createArrayAFromD();
    std::cout << "Массив A созданный из D:\n"
        << arrayA.toString() << std::endl;

    // Демонстрация операторов
    Matrix shiftedLeft = matrix << 1;
    Matrix shiftedRight = matrix >> 1;

    std::cout << "Массив после сдвига влево на 1:\n"
        << shiftedLeft.toString() << std::endl;
    std::cout << "Массив после сдвига вправо на 1:\n"
        << shiftedRight.toString() << std::endl;

    return 0;
}