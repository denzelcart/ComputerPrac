#include <iostream>
#include <cmath>
#include <vector>

int main() {
    std::pair<int, int> z1 = std::make_pair(-1, 1);
    std::pair<int, int> z2 = std::make_pair(-2, -2);

    std::pair<int, int> sum_z = std::make_pair(z1.first + z2.first, z1.second + z2.second);
    std::pair<int, int> diff_z = std::make_pair(z1.first - z2.first, z1.second - z2.second);
    std::pair<int, int> prod_z = std::make_pair(z1.first * z2.first - z1.second * z2.second, z1.first * z2.second + z1.second * z2.first);
    std::pair<int, int> numerator = std::make_pair(z1.first * z2.first + z1.second * z2.second, z1.second * z2.first - z1.first * z2.second);
    int denominator = z2.first * z2.first + z2.second * z2.second;
    std::pair<double, double> quot_z = std::make_pair(static_cast<double>(numerator.first) / denominator, static_cast<double>(numerator.second) / denominator);
    std::pair<int, int> z3 = std::make_pair(-1, 1);
    double r = std::sqrt(z3.first * z3.first + z3.second * z3.second);
    double theta = std::atan2(z3.second, z3.first);
    double r4 = std::pow(r, 4);
    double theta4 = 4 * theta;
    std::pair<double, double> z3_fourth_power = std::make_pair(r4 * std::cos(theta4), r4 * std::sin(theta4));
    double r3 = std::pow(r, 1.0/3.0);
    std::vector<std::pair<double, double>> z3_cube_roots;
    for (int k = 0; k < 3; k++) {
        double theta3 = (theta + 2 * M_PI * k) / 3;
        z3_cube_roots.push_back(std::make_pair(r3 * std::cos(theta3), r3 * std::sin(theta3)));
    }

    std::cout << "Сумма: " << sum_z.first << " + " << sum_z.second << "i" << std::endl;
    std::cout << "Разность: " << diff_z.first << " + " << diff_z.second << "i" << std::endl;
    std::cout << "Произведение: " << prod_z.first << " + " << prod_z.second << "i" << std::endl;
    std::cout << "Частное: " << quot_z.first << " + " << quot_z.second << "i" << std::endl;
    std::cout << "Четвертая степень: " << z3_fourth_power.first << " + " << z3_fourth_power.second << "i" << std::endl;
    std::cout << "Корни третьей степени:" << std::endl;
    for (const auto& root : z3_cube_roots) {
        std::cout << root.first << " + " << root.second << "i" << std::endl;
    }

    return 0;
}