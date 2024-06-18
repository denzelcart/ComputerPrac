import numpy as np
from sympy import symbols, Eq, solve

# Уравнение однополостного гиперболоида: (x^2/a^2) + (y^2/b^2) - (z^2/c^2) = 1
class Hyperboloid:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def is_point_on_hyperboloid(self, x, y, z):
        return (x ** 2 / self.a ** 2) + (y ** 2 / self.b ** 2) - (z ** 2 / self.c ** 2) == 1

    def intersects_plane(self, A, B, C, D):
        x, y, z = symbols('x y z')
        hyperboloid_eq = Eq((x**2 / self.a**2) + (y**2 / self.b**2) - (z**2 / self.c**2), 1)
        plane_eq = Eq(A*x + B*y + C*z + D, 0)
        solutions = solve((hyperboloid_eq, plane_eq), (x, y, z))
        return bool(solutions)

    def intersects_line(self, x1, y1, z1, x2, y2, z2):
        t = symbols('t')
        x = x1 + t * (x2 - x1)
        y = y1 + t * (y2 - y1)
        z = z1 + t * (z2 - z1)
        eq = Eq((x**2 / self.a**2) + (y**2 / self.b**2) - (z**2 / self.c**2), 1)
        solutions = solve(eq, t)
        return bool(solutions)

# Параметры однополостного гиперболоида
a = 3.0
b = 4.0
c = 5.0

# Создаем объект гиперболоида
hyperboloid = Hyperboloid(a, b, c)

# Координаты точки
x = 1.0
y = 2.0
z = 3.0

# Проверяем, принадлежит ли точка гиперболоиду
if hyperboloid.is_point_on_hyperboloid(x, y, z):
    print(f"Точка ({x}, {y}, {z}) принадлежит гиперболоиду.")
else:
    print(f"Точка ({x}, {y}, {z}) не принадлежит гиперболоиду.")

# Параметры плоскости Ax + By + Cz + D = 0
A = 1.0
B = 2.0
C = 3.0
D = -4.0

# Проверяем, пересекает ли плоскость гиперболоид
if hyperboloid.intersects_plane(A, B, C, D):
    print("Плоскость пересекает гиперболоид.")
else:
    print("Плоскость не пересекает гиперболоид.")

# Координаты двух точек, определяющих прямую
x1, y1, z1 = 1.0, 2.0, 3.0
x2, y2, z2 = 4.0, 5.0, 6.0

# Проверяем, пересекает ли прямая гиперболоид
if hyperboloid.intersects_line(x1, y1, z1, x2, y2, z2):
    print("Прямая пересекает гиперболоид.")
else:
    print("Прямая не пересекает гиперболоид.")
