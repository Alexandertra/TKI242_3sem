#pragma once
#ifndef CONFIG_H
#define CONFIG_H

namespace Config {
    // Параметры для RandomGenerator
    constexpr int RANDOM_MIN_VALUE = -10;
    constexpr int RANDOM_MAX_VALUE = 20;

    // Параметр для ConstantsGenerator
    constexpr int CONSTANT_FILL_VALUE = 0;

    // Параметр для операций сдвига
    constexpr int SHIFT_AMOUNT = 1;

    // Коды выбора в меню
    constexpr int CHOICE_RANDOM = 1;
    constexpr int CHOICE_MANUAL = 2;
    constexpr int CHOICE_CONSTANT = 3;

    // Сообщения пользователю
    namespace Messages {
        const char* ENTER_ARRAY_SIZE = "Введите размер массива: ";
        const char* CHOOSE_FILL_METHOD = "Выберите способ заполнения:\n";
        const char* OPTION_RANDOM = "1 - Случайные числа [-10;20]\n";
        const char* OPTION_MANUAL = "2 - Ввод с клавиатуры\n";
        const char* OPTION_CONSTANT = "3 - Заполнение нулями\n";
        const char* INVALID_CHOICE = "Неверный выбор!\n";

        const char* CREATED_ARRAY = "Созданный массив:\n";
        const char* AFTER_REPLACEMENT = "После замены последнего отрицательного элемента:\n";
        const char* AFTER_FILTERING = "После удаления элементов с четной первой цифрой:\n";
        const char* ARRAY_A_FROM_D = "Массив A созданный из D:\n";
        const char* SHIFT_LEFT = "Массив после сдвига влево на 1:\n";
        const char* SHIFT_RIGHT = "Массив после сдвига вправо на 1:\n";
    }
}

#endif // CONFIG_H
