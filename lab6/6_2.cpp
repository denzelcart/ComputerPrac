#include <iostream>
#include <cmath>

using namespace std;


double f(double x1, double x2) {
    return x[0]**2 + np.exp(x[0]**2 + x[1]**2 2*x2)+4*x[0]+3*[1];
}


void gradient(double x1, double x2, double& grad_x1, double& grad_x2) {
    double denom = sqrt(1 + x1*x1 + x2*x2);
    grad_x1 = 1 + 4*x1/denom;
    grad_x2 = 2 + 4*x2/denom;
}

pair<double, double> steepest_descent(double initial_x1, double initial_x2, double alpha, int max_iterations, double tolerance) {
    double x1 = initial_x1;
    double x2 = initial_x2;

    for (int i = 0; i < max_iterations; ++i) {
        double grad_x1, grad_x2;
        gradient(x1, x2, grad_x1, grad_x2);
        
        // Update x1 and x2
        x1 -= alpha * grad_x1;
        x2 -= alpha * grad_x2;

        // Check convergence
        if (sqrt(grad_x1*grad_x1 + grad_x2*grad_x2) < tolerance) {
            break;
        }
    }

    return {x1, x2};
}

int main() {
    double initial_x1 = 0.0;
    double initial_x2 = 0.0;
    double alpha = 0.01;
    int max_iterations = 1000;
    double tolerance = 1e-6;

    pair<double, double> optimum = steepest_descent(initial_x1, initial_x2, alpha, max_iterations, tolerance);

    cout << "Optimal point: (" << optimum.first << ", " << optimum.second << ")" << endl;
    cout << "Minimum value: " << f(optimum.first, optimum.second) << endl;

    return 0;
}