#include <iostream>
#include <cmath>

// Структура для представления точки в пространстве
struct Point3D {
    double x, y, z;
};

// Структура для представления вектора в пространстве
struct Vector3D {
    double x, y, z;
};

// Функция для вычисления длины вектора
double vectorLength(const Vector3D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Функция для вычисления скалярного произведения двух векторов
double dotProduct(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Функция для вычисления векторного произведения двух векторов
Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2) {
    return {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

// Структура для представления прямой в пространстве (точка и направляющий вектор)
struct Line {
    Point3D point;
    Vector3D direction;
};

// Структура для представления плоскости в пространстве (коэффициенты уравнения Ax + By + Cz + D = 0)
struct Plane {
    double A, B, C, D;
};

// Функция для вычисления угла между прямой и плоскостью
double angleBetweenLineAndPlane(const Line& line, const Plane& plane) {
    Vector3D normal = {plane.A, plane.B, plane.C};
    double dot = dotProduct(line.direction, normal);
    double lenDir = vectorLength(line.direction);
    double lenNorm = vectorLength(normal);
    return std::asin(dot / (lenDir * lenNorm));
}

// Функция для проверки параллельности прямой и плоскости
bool areParallel(const Line& line, const Plane& plane) {
    Vector3D normal = {plane.A, plane.B, plane.C};
    return dotProduct(line.direction, normal) == 0;
}

// Функция для нахождения расстояния между параллельной прямой и плоскостью
double distanceBetweenParallelLineAndPlane(const Line& line, const Plane& plane) {
    return std::abs(plane.A * line.point.x + plane.B * line.point.y + plane.C * line.point.z + plane.D) / vectorLength({plane.A, plane.B, plane.C});
}

// Функция для нахождения точки пересечения прямой и плоскости
Point3D intersectionPoint(const Line& line, const Plane& plane) {
    Vector3D normal = {plane.A, plane.B, plane.C};
    double t = -(plane.A * line.point.x + plane.B * line.point.y + plane.C * line.point.z + plane.D) / dotProduct(normal, line.direction);
    return {
        line.point.x + t * line.direction.x,
        line.point.y + t * line.direction.y,
        line.point.z + t * line.direction.z
    };
}

int main() {
    // Определим прямую и плоскость случайным образом
    Line line = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    Plane plane = {1.0, -1.0, 2.0, -3.0};

    // Вычислим угол между прямой и плоскостью
    double angle = angleBetweenLineAndPlane(line, plane);
    std::cout << "Угол между прямой и плоскостью (в радианах) " << angle << std::endl;

    // Проверим параллельность прямой и плоскости
    if (areParallel(line, plane)) {
        std::cout << "Прямая и плоскость не параллельны" << std::endl;
        // Найдем расстояние между ними
        double distance = distanceBetweenParallelLineAndPlane(line, plane);
        std::cout << "Расстояние между параллельной линией и плоскостью " << distance << std::endl;
    } else {
        std::cout << "Прямая и плоскость не параллельны." << std::endl;
        // Найдем точку пересечения
        Point3D intersection = intersectionPoint(line, plane);
        std::cout << "точка пересечения: (" << intersection.x << ", " << intersection.y << ", " << intersection.z << ")" << std::endl;
    }

    return 0;
}

