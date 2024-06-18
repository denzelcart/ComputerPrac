import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline

# Данные из таблицы
xi = np.array([0.0, 1.0, 2.0, 3.0, 4.0])
yi = np.array([0.0, 0.5, 0.86603, 1.0, 0.86603])

# Построение кубического сплайна с нулевой кривизной на концах
cs = CubicSpline(xi, yi, bc_type='natural')

# Вычисление значения функции в точке x* = 1.5
x_star = 1.5
y_star = cs(x_star)

print(f"Значение функции в точке x* = {x_star}: y* = {y_star}")

# Построение графика
x_vals = np.linspace(0, 4, 100)
y_vals = cs(x_vals)

plt.plot(xi, yi, 'o', label='Узлы интерполяции')
plt.plot(x_vals, y_vals, label='Кубический сплайн')
plt.plot(x_star, y_star, 'ro', label=f'Точка x*={x_star}')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Кубический сплайн')
plt.grid(True)
plt.show()

