//#include <iostream>
//#include <cmath>
//
//// Уравнение системы
//double equation1(double x1, double x2) {
//    return x1 - x2 - 6 * log10(x1) - 1;
//}
//
//double equation2(double x1, double x2) {
//    return x1 - 3 * x2 - 6 * log10(x2) - 2;
//}
//
//// Частные производные уравнений
//double partialDerivativeX1Equation1(double x1) {
//    return 1 - 6 / (x1 * log(10));
//}
//
//double partialDerivativeX2Equation1() {
//    return -1;
//}
//
//double partialDerivativeX1Equation2(double x1) {
//    return 1;
//}
//
//double partialDerivativeX2Equation2(double x2) {
//    return -3 - 6 / (x2 * log(10));
//}
//
//// Метод Ньютона для системы уравнений
//void newtonMethod(double x1, double x2, double epsilon) {
//    double deltaX1, deltaX2;
//    int maxIterations = 1000; // Максимальное количество итераций
//
//    for (int i = 0; i < maxIterations; ++i) {
//        double f1 = equation1(x1, x2);
//        double f2 = equation2(x1, x2);
//
//        double J11 = partialDerivativeX1Equation1(x1);
//        double J12 = partialDerivativeX2Equation1();
//        double J21 = partialDerivativeX1Equation2(x1);
//        double J22 = partialDerivativeX2Equation2(x2);
//
//        double determinant = J11 * J22 - J12 * J21;
//
//        deltaX1 = (J22 * f1 - J12 * f2) / determinant;
//        deltaX2 = (J11 * f2 - J21 * f1) / determinant;
//
//        x1 = x1 - deltaX1;
//        x2 = x2 - deltaX2;
//
//        if (std::abs(deltaX1) < epsilon && std::abs(deltaX2) < epsilon) {
//            std::cout << "Корни уравнений: x1 = " << x1 << ", x2 = " << x2 << std::endl;
//            return;
//        }
//    }
//
//    std::cout << "Достигнуто максимальное количество итераций" << std::endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    double initialGuessX1 = 0.5;
//    double initialGuessX2 = 0.2;
//    double epsilon = 0.0001;
//
//    newtonMethod(initialGuessX1, initialGuessX2, epsilon);
//
//    return 0;
//}
