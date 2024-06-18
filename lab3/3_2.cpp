#include <iostream>
#include <cmath>

double f2(double x) {
    return std::exp(-2 * x) * std::sin(5 * x);
}

double rectangle_method(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += f(a + i * h);
    }
    return result * h;
}

double trapezoidal_method(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        result += f(a + i * h);
    }
    return result * h;
}

double simpson_method(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        ++n; // n должен быть четным
    }
    double h = (b - a) / n;
    double result = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        result += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return result * h / 3;
}

int main() {
    double a = 0.0, b = 10.0; // Верхняя граница достаточно большая
    int n = 1000; // Количество разбиений

    double result_rectangle = rectangle_method(f2, a, b, n);
    double result_trapezoidal = trapezoidal_method(f2, a, b, n);
    double result_simpson = simpson_method(f2, a, b, n);

    std::cout << "Method of Rectangles: " << result_rectangle << std::endl;
    std::cout << "Method of Trapezoids: " << result_trapezoidal << std::endl;
    std::cout << "Simpson's Method: " << result_simpson << std::endl;

    return 0;
}