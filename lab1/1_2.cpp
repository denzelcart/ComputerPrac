#include <iostream>
#include <cmath>
#include <functional>

const double EPSILON = 1e-6;

// Функция
double f(double x) {
    return std::log(x) + std::pow((x + 1), 3);
}

// Производная функции для метода Ньютона
double f_derivative(double x) {
    return 1/x + 3*std::pow((x + 1), 2);
}

// Метод дихотомии (бисекции)
double bisectionMethod(double a, double b) {
    if (f(a) * f(b) >= 0) {
        std::cerr << "Invalid interval for the bisection method." << std::endl;
        return -1;
    }

    double c;
    while ((b - a) >= EPSILON) {
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

// Функция для метода простых итераций
double g(double x) {
    return -std::log(x) / std::pow((x + 1), 3);
}

// Метод простых итераций
double fixedPointIteration(double x0) {
    double x1;
    do {
        x1 = g(x0);
        if (std::abs(x1 - x0) < EPSILON) {
            break;
        }
        x0 = x1;
    } while (true);
    return x1;
}

// Метод хорд (секущих)
double secantMethod(double a, double b) {
    double c;
    while (std::abs(b - a) >= EPSILON) {
        c = b - (f(b) * (b - a)) / (f(b) - f(a));
        a = b;
        b = c;
    }
    return c;
}

// Метод Ньютона
double newtonMethod(double x0) {
    double x1;
    while (true) {
        x1 = x0 - f(x0) / f_derivative(x0);
        if (std::abs(x1 - x0) < EPSILON) {
            break;
        }
        x0 = x1;
    }
    return x1;
}

int main() {
    double a = 0.1, b = 1.0; // Интервал для метода дихотомии и хорд
    double initial_guess = 0.5; // Начальное приближение для метода простых итераций и Ньютона

    // Метод дихотомии
    double root_bisection = bisectionMethod(a, b);
    std::cout << "Корень, найденный методом дихотомии: " << root_bisection << std::endl;

    // Метод простых итераций
    double root_fixed_point = fixedPointIteration(initial_guess);
    std::cout << "Корень, найденный методом простых итераций: " << root_fixed_point << std::endl;

    // Метод хорд
    double root_secant = secantMethod(a, b);
    std::cout << "Корень, найденный методом хорд: " << root_secant << std::endl;

    // Метод Ньютона
    double root_newton = newtonMethod(initial_guess);
    std::cout << "Корень, найденный методом Ньютона: " << root_newton << std::endl;

    return 0;
}


