#include <iostream>
#include <vector>
#include <cmath>

// Функция для вычисления разделенных разностей
std::vector<double> dividedDifferences(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    std::vector<double> coef(y);
    for (int j = 1; j < n; ++j) {
        for (int i = n - 1; i >= j; --i) {
            coef[i] = (coef[i] - coef[i - 1]) / (x[i] - x[i - j]);
        }
    }
    return coef;
}

// Функция для вычисления значения многочлена Ньютона
double newtonPolynomial(const std::vector<double>& x, const std::vector<double>& coef, double xi) {
    int n = coef.size();
    double result = coef[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        result = result * (xi - x[i]) + coef[i];
    }
    return result;
}

// Основная программа
int main() {
    // Заданные точки
    std::vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    std::vector<double> y;

    // Вычисление значений функции y = cos(xi) в заданных точках
    for (double xi : x) {
        y.push_back(std::cos(xi));
    }

    // Вычисление коэффициентов интерполяционного многочлена Ньютона
    std::vector<double> coef = dividedDifferences(x, y);

    // Точка, в которой нужно вычислить значение интерполированного многочлена
    double x_star = 0.25 * M_PI;
    double y_interpolated = newtonPolynomial(x, coef, x_star);

    // Вычисление истинного значения функции в точке x_star
    double y_true = std::cos(x_star);

    // Вычисление погрешности интерполяции
    double error = std::abs(y_true - y_interpolated);

    // Вывод результатов
    std::cout << "Значение интерполированного многочлена в точке x* = " << x_star << ": " << y_interpolated << std::endl;
    std::cout << "Истинное значение функции в точке x* = " << x_star << ": " << y_true << std::endl;
    std::cout << "Погрешность интерполяции: " << error << std::endl;

    return 0;
}
