import numpy as np

def kramer_method(A, B):
    det_A = np.linalg.det(A)
    n = len(B)
    X = []

    for i in range(n):
       
        Ai = A.copy()
        Ai[:, i] = B
        det_Ai = np.linalg.det(Ai)
        X.append(det_Ai / det_A)

    return X


def jacobi_method(A, B, eps=1e-10, max_iterations=1000):
    n = len(B)
    X = np.zeros(n)
    X_prev = np.zeros(n)
    iteration = 0

    while iteration < max_iterations:
        for i in range(n):
            sum_ = sum(A[i][j] * X_prev[j] for j in range(n) if j != i)
            X[i] = (B[i] - sum_) / A[i][i]

        if np.linalg.norm(X - X_prev) < eps:
            break

        X_prev = X.copy()
        iteration += 1

    return X


A = np.array([[2, -2, 5],
              [-2, 3, 6],
              [-10, 12, -4]], dtype=float)


B = np.array([2, -1, 2], dtype=float)


X_kramer = kramer_method(A, B)
print("Решение методом Крамера:")
print(X_kramer)


X_jacobi = jacobi_method(A, B)
print("\nРешение методом Якоби:")
print(X_jacobi)