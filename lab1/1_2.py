import math

# Заданное уравнение
def f(x):
    return math.log(x) + (x + 1) ** 3

# Производная функции для метода Ньютона
def f_derivative(x):
    return 1 / x + 3 * (x + 1) ** 2

# Метод дихотомии (бисекции)
def bisection_method(a, b, epsilon=1e-6):
    if f(a) * f(b) >= 0:
        raise ValueError("Invalid interval for the bisection method.")
    
    while (b - a) / 2.0 > epsilon:
        midpoint = (a + b) / 2.0
        if f(midpoint) == 0:
            return midpoint
        elif f(a) * f(midpoint) < 0:
            b = midpoint
        else:
            a = midpoint
    
    return (a + b) / 2.0

# Функция для метода простых итераций
def g(x):
    return -math.log(x) / ((x + 1) ** 3)

# Метод простых итераций
def fixed_point_iteration(x0, epsilon=1e-6):
    while True:
        x1 = g(x0)
        if abs(x1 - x0) < epsilon:
            break
        x0 = x1
    return x1

# Метод хорд (секущих)
def secant_method(a, b, epsilon=1e-6):
    while abs(b - a) >= epsilon:
        c = b - (f(b) * (b - a)) / (f(b) - f(a))
        a, b = b, c
    return c

# Метод Ньютона
def newton_method(x0, epsilon=1e-6):
    while True:
        x1 = x0 - f(x0) / f_derivative(x0)
        if abs(x1 - x0) < epsilon:
            break
        x0 = x1
    return x1

if __name__ == "__main__":
    # Интервал для метода дихотомии и хорд
    a, b = 0.1, 1.0
    # Начальное приближение для метода простых итераций и Ньютона
    initial_guess = 0.5

    # Метод дихотомии
    root_bisection = bisection_method(a, b)
    print(f"Корень, найденный методом дихотомии: {root_bisection}")

    # Метод простых итераций
    root_fixed_point = fixed_point_iteration(initial_guess)
    print(f"Корень, найденный методом простых итераций: {root_fixed_point}")

    # Метод хорд
    root_secant = secant_method(a, b)
    print(f"Корень, найденный методом хорд: {root_secant}")

    # Метод Ньютона
    root_newton = newton_method(initial_guess)
    print(f"Корень, найденный методом Ньютона: {root_newton}")
