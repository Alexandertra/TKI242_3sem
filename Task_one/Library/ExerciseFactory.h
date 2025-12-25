#pragma once
#include "Exercise.h"
#include "NegativeReplacerExercise.h"
#include "EvenDigitRemoverExercise.h"
#include "ArrayCreatorExercise.h"
#include <memory>

// Типы упражнений
enum class ExerciseType {
    NEGATIVE_REPLACER,
    EVEN_DIGIT_REMOVER,
    ARRAY_CREATOR
};

// Фабрика для создания упражнений
class ExerciseFactory {
public:
    static std::unique_ptr<Exercise> createExercise(
        ExerciseType type,
        const Matrix& matrix
    ) {
        switch (type) {
        case ExerciseType::NEGATIVE_REPLACER:
            return std::make_unique<NegativeReplacerExercise>(matrix);
        case ExerciseType::EVEN_DIGIT_REMOVER:
            return std::make_unique<EvenDigitRemoverExercise>(matrix);
        case ExerciseType::ARRAY_CREATOR:
            return std::make_unique<ArrayCreatorExercise>(matrix);
        default:
            throw std::invalid_argument("Неизвестный тип упражнения");
        }
    }
};