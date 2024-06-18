import numpy as np

def inverse_matrix(A, B):
    A_inv = np.linalg.inv(A)
    X = np.dot(A_inv, B)
    return X

def gaussian_elimination(A, B):
    n = len(B)
    
     for i in range(n):
        for j in range(i+1, n):
            factor = A[j][i] / A[i][i]
            for k in range(n):
                A[j][k] -= factor * A[i][k]
            B[j] -= factor * B[i]
    
    X = [0] * n
    for i in range(n-1, -1, -1):
        X[i] = (B[i] - sum(A[i][j] * X[j] for j in range(i+1, n))) / A[i][i]
    
    return X

A = np.array([[1, 2, -1, -7],
              [8, -9, 0, -3],
              [2, -3, 7, 1],
              [1, -5, -6, 8]], dtype=float)

B = np.array([-23, 39, -7, 30], dtype=float)

X_inv = inverse_matrix(A, B)
print("Решение методом обратной матрицы:")
print(X_inv)

X_gauss = gaussian_elimination(A.tolist(), B.tolist())
print("\nРешение методом Гаусса:")
print(X_gauss)