#include <iostream>
#include <vector>
#include <cmath>


std::vector<double> seidel(std::vector<std::vector<double>>& A, std::vector<double>& b, std::vector<double>& x0, double epsilon, int max_iter) {
    int n = A.size();
    std::vector<double> x(n, 0.0); 
    int iter = 0;
    double error = epsilon + 1;

    while (iter < max_iter && error > epsilon) {
        for (int i = 0; i < n; ++i) {
            double sum1 = 0.0;
            double sum2 = 0.0;
            for (int j = 0; j < i; ++j) {
                sum1 += A[i][j] * x[j];
            }
            for (int j = i + 1; j < n; ++j) {
                sum2 += A[i][j] * x0[j];
            }
            x[i] = (b[i] - sum1 - sum2) / A[i][i];
        }

  
        error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += std::abs(x[i] - x0[i]);
        }

        x0 = x;
        iter++;
    }

    return x;
}

int main() {
    std::vector<std::vector<double>> A = {{23, -6, -5, 9},
                                           {8, 22, -2, 5},
                                           {7, -6, 18, -1},
                                           {3, 5, 5, -19}};
    std::vector<double> b = {232, -82, 202, -57};
    std::vector<double> x0 = {0, 0, 0, 0}; 
    double epsilon = 1e-6; 
    int max_iter = 1000; 

    std::vector<double> solution = seidel(A, b, x0, epsilon, max_iter);


    std::cout << "Solution:\n";
    for (int i = 0; i < solution.size(); ++i) {
        std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;
    }

    return 0;
}