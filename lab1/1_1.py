import math

z1 = (-1, 1) 
z2 = (-2, -2)  

sum_z = (z1[0] + z2[0], z1[1] + z2[1])
diff_z = (z1[0] - z2[0], z1[1] - z2[1])
prod_z = (z1[0] * z2[0] - z1[1] * z2[1], z1[0] * z2[1] + z1[1] * z2[0])
numerator = (z1[0] * z2[0] + z1[1] * z2[1], z1[1] * z2[0] - z1[0] * z2[1])
denominator = z2[0]**2 + z2[1]**2
quot_z = (numerator[0] / denominator, numerator[1] / denominator)
z3 = (-1, 1)
r = math.sqrt(z3[0]**2 + z3[1]**2)
theta = math.atan2(z3[1], z3[0])
r4 = r**4
theta4 = 4 * theta
z3_fourth_power = (r4 * math.cos(theta4), r4 * math.sin(theta4))
r3 = r**(1/3)
z3_cube_roots = []
for k in range(3):
    theta3 = (theta + 2 * math.pi * k) / 3
    z3_cube_roots.append((r3 * math.cos(theta3), r3 * math.sin(theta3)))

print(f"Сумма: {sum_z[0]} + {sum_z[1]}i")
print(f"Разность: {diff_z[0]} + {diff_z[1]}i")
print(f"Произведение: {prod_z[0]} + {prod_z[1]}i")
print(f"Частное: {quot_z[0]} + {quot_z[1]}i")
print(f"Четвертая степень: {z3_fourth_power[0]} + {z3_fourth_power[1]}i")
print(f"Корни третьей степени:")
for root in z3_cube_roots:
    print(f"{root[0]} + {root[1]}i")