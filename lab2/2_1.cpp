#include <iostream>
#include <cmath>

// Структура для представления вектора
struct Vector2D {
    double x;
    double y;
};

// Функция для вычисления длины вектора
double vectorLength(const Vector2D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

// Функция для вычисления скалярного произведения двух векторов
double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

// Функция для вычисления угла между двумя векторами
double angleBetweenVectors(const Vector2D& v1, const Vector2D& v2) {
    double dot = dotProduct(v1, v2);
    double len1 = vectorLength(v1);
    double len2 = vectorLength(v2);
    return std::acos(dot / (len1 * len2));
}

// Функция для сложения двух векторов
Vector2D addVectors(const Vector2D& v1, const Vector2D& v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

// Функция для вычитания двух векторов
Vector2D subtractVectors(const Vector2D& v1, const Vector2D& v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

// Функция для проверки параллельности двух векторов
bool areParallel(const Vector2D& v1, const Vector2D& v2) {
    return (v1.x * v2.y - v1.y * v2.x) == 0;
}

int main() {
    // Определим три вектора случайным образом
    Vector2D v1 = {3.0, 4.0};
    Vector2D v2 = {6.0, 8.0};
    Vector2D v3 = {5.0, -2.0};

    // Вычислим длины векторов
    double len1 = vectorLength(v1);
    double len2 = vectorLength(v2);
    double len3 = vectorLength(v3);

    std::cout << "Длины векторов:" << std::endl;
    std::cout << "v1: " << len1 << std::endl;
    std::cout << "v2: " << len2 << std::endl;
    std::cout << "v3: " << len3 << std::endl;

    // Вычислим углы между векторами
    double angle12 = angleBetweenVectors(v1, v2);
    double angle13 = angleBetweenVectors(v1, v3);
    double angle23 = angleBetweenVectors(v2, v3);

    std::cout << "\nУглы между векторами (в радианах):" << std::endl;
    std::cout << "v1 и v2: " << angle12 << std::endl;
    std::cout << "v1 и v3: " << angle13 << std::endl;
    std::cout << "v2 и v3: " << angle23 << std::endl;

    // Вычислим суммы и разности векторов
    Vector2D sum12 = addVectors(v1, v2);
    Vector2D diff12 = subtractVectors(v1, v2);

    Vector2D sum13 = addVectors(v1, v3);
    Vector2D diff13 = subtractVectors(v1, v3);

    Vector2D sum23 = addVectors(v2, v3);
    Vector2D diff23 = subtractVectors(v2, v3);

    std::cout << "\nСумма и разность векторов:" << std::endl;
    std::cout << "v1 + v2: (" << sum12.x << ", " << sum12.y << ")" << std::endl;
    std::cout << "v1 - v2: (" << diff12.x << ", " << diff12.y << ")" << std::endl;

    std::cout << "v1 + v3: (" << sum13.x << ", " << sum13.y << ")" << std::endl;
    std::cout << "v1 - v3: (" << diff13.x << ", " << diff13.y << ")" << std::endl;

    std::cout << "v2 + v3: (" << sum23.x << ", " << sum23.y << ")" << std::endl;
    std::cout << "v2 - v3: (" << diff23.x << ", " << diff23.y << ")" << std::endl;

    // Проверим параллельность векторов
    bool parallel12 = areParallel(v1, v2);
    bool parallel13 = areParallel(v1, v3);
    bool parallel23 = areParallel(v2, v3);

    std::cout << "\nПараллельные векторы:" << std::endl;
    std::cout << "v1 и v2: " << (parallel12 ? "Да" : "Нет") << std::endl;
    std::cout << "v1 и v3: " << (parallel13 ? "Да" : "Нет") << std::endl;
    std::cout << "v2 и v3: " << (parallel23 ? "Да" : "Нет") << std::endl;

    return 0;
}
