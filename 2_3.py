import math

class Ellipse:
    def __init__(self, a, b, h, k):
        self.a = a  # Большая полуось
        self.b = b  # Малая полуось
        self.h = h  # Центр эллипса по x
        self.k = k  # Центр эллипса по y

    def is_point_on_ellipse(self, x, y):
        return ((x - self.h) ** 2 / self.a ** 2) + ((y - self.k) ** 2 / self.b ** 2) == 1

    def foci(self):
        c = math.sqrt(abs(self.a ** 2 - self.b ** 2))
        return (self.h + c, self.k), (self.h - c, self.k)

    def eccentricity(self):
        return math.sqrt(1 - (self.b ** 2 / self.a ** 2))

    def directrices(self):
        e = self.eccentricity()
        return (self.h + self.a / e, self.k), (self.h - self.a / e, self.k)

# Параметры эллипса: большая полуось a, малая полуось b, центр (h, k)
a = 5.0
b = 3.0
h = 1.0
k = 2.0

# Создаем объект эллипса
ellipse = Ellipse(a, b, h, k)

# Координаты точки
x = 4.0
y = 5.0

# Проверяем, принадлежит ли точка эллипсу
if ellipse.is_point_on_ellipse(x, y):
    print(f"Точка ({x}, {y}) принадлежит эллипсу.")
else:
    print(f"Точка ({x}, {y}) не принадлежит эллипсу.")

# Находим координаты фокусов
focus1, focus2 = ellipse.foci()
print(f"Координаты фокусов эллипса: {focus1} и {focus2}")

# Находим эксцентриситет
e = ellipse.eccentricity()
print(f"Эксцентриситет эллипса: {e}")

# Находим директрисы
directrix1, directrix2 = ellipse.directrices()
print(f"Координаты директрис эллипса: {directrix1} и {directrix2}")

# Длины полуосей
print(f"Длина большой полуоси: {ellipse.a}")
print(f"Длина малой полуоси: {ellipse.b}")


