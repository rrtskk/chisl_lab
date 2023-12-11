#include <iostream>
#include <vector>
#include <cmath>

// Функция для решения СЛАУ методом Гаусса
void gaussElimination(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(A[j][i]) > std::abs(A[maxRow][i])) {
                maxRow = j;
            }
        }
        std::swap(A[i], A[maxRow]);
        std::swap(b[i], b[maxRow]);

        for (int j = i + 1; j < n; ++j) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; ++k) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            b[i] -= A[i][j] * b[j];
        }
        b[i] /= A[i][i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<double> x = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    std::vector<double> y;
    for (double xi : x) {
        y.push_back(1 / (1 + xi));
    }

    int n = 5; // степень многочлена (4-ой степени: 0, 1, 2, 3, 4)
    std::vector<std::vector<double>> A(n + 1, std::vector<double>(n + 1, 0));
    std::vector<double> b(n + 1, 0);

    // Построение матрицы A и вектора b для метода наименьших квадратов
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (double xi : x) {
                A[i][j] += std::pow(xi, i + j);
            }
        }
        for (int k = 0; k < x.size(); ++k) {
            b[i] += std::pow(x[k], i) * y[k];
        }
    }

    // Решение системы методом Гаусса
    gaussElimination(A, b);

    // Вывод коэффициентов найденного многочлена
    std::cout << "Коэффициенты многочлена:\n";
    for (int i = 0; i <= n; ++i) {
        std::cout << "a" << i << " = " << b[i] << std::endl;
    }

    return 0;
}
