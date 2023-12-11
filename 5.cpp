//#define M_PI 3.14159265358979323846
//#include <vector>
//#include <iostream>
//#include <cmath>
//#include <iomanip>
//#include <math.h>
//using namespace std;
//
//double KubSimpson(const double& m, const double& n, const double& a, const double& b, const double& c, const double& d, double function(const double&, const double&)) {
//    double hx = (b - a) / (2 * n);
//    double hy = (d - c) / (2 * m);
//    double sum = 0.0;
//    double I = 0.0;
//    double xi = a;
//    double yi = c;
//
//    vector<double> Xi;
//    do {
//        Xi.push_back(xi);
//        xi += hx;
//    } while (xi <= b);
//    vector<double> Yi;
//    do {
//        Yi.push_back(yi);
//        yi += hy;
//    } while (yi <= d);
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            sum += function(Xi[2 * i], Yi[2 * j]) + function(Xi[2 * i + 2], Yi[2 * j]) + function(Xi[2 * i], Yi[2 * j + 2]) + function(Xi[2 * i + 2], Yi[2 * j + 2])
//                + 4 * function(Xi[2 * i + 1], Yi[2 * j]) + 4 * function(Xi[2 * i], Yi[2 * j + 1]) + 4 * function(Xi[2 * i + 2], Yi[2 * j + 1]) + 4 * function(Xi[2 * i + 1], Yi[2 * j + 2])
//                + 16 * function(Xi[2 * i + 1], Yi[2 * j + 1]);
//        }
//    }
//    I += sum;
//    I *= ((hx * hy) / 9);
//    return I;
//}
//
//double Simpson(double a, double b, double fun(double), double e) {
//    int N = 2;
//    double sumCH = 0;
//    double sumNeCH = 0;
//    double h = (b - a) / N;
//    double I1 = fun(a) + fun(b);
//    double xi = a;
//    double I2;
//    do {
//        I2 = I1;
//        N *= 2;
//        h = (b - a) / N;
//        xi = a + h;
//        sumNeCH = 0;
//        sumCH = 0;
//        for (int i = 0; i < N; i++) {
//            if ((i % 2) == 0) { sumCH += fun(xi); }
//            else { sumNeCH += fun(xi); }
//            xi += h;
//        }
//        I1 = (h / 3) * (fun(a) + fun(b) + 4 * sumNeCH + 2 * sumCH);
//    } while (fabs(I1 - I2) > 15 * e);
//    return I1;
//}
//
//double TrapezoidMethod(double a, double b, double fun(double), double e) {
//    int N = 2;
//    double h = (b - a) / N;
//    double xi;
//    double sum = 0;
//    double I1 = fun(a) + fun(b);
//    double I2;
//    do {
//        I2 = I1;
//        N *= 2;
//        h = (b - a) / N;
//        xi = a;
//        sum = 0;
//        for (int i = 0; i < N; i++) {
//            xi += h;
//            sum += fun(xi);
//        }
//        I1 = (fun(a) + fun(b) + 2 * sum) * (h / 2);
//    } while (abs(I1 - I2) >= 3 * e);
//
//    return I1;
//}
//
//double function(double x) {
//    return pow(x * x * x - 1, -0.5);
//}
//
//double fun(const double& x, const double& y) {
//    return sin(x + y);
//}
//
//int main() {
//    double a = 1.3;
//    double b = 2.621;
//    double e1 = 1e-4;
//    double e2 = 1e-5;
//    setlocale(LC_ALL, "Rus");
//    cout << "Метод трапеций: " << endl;
//    cout << setprecision(10) << "I: " << TrapezoidMethod(a, b, function, e1) << endl;
//    cout << "Метод симпсона: " << endl;
//    cout << setprecision(10) << "I: " << Simpson(a, b, function, e2) << endl;
//
//    double ak = 0;
//    double bk = M_PI / 2;
//    double ck = 0;
//    double dk = M_PI / 4;
//    int m, n;
//    cout << "Введите уточнение m и n" << endl;
//    cin >> m >> n;
//    cout << "Кубатрный метод Симпсона: " << endl;
//    cout << setprecision(10) << "I: " << KubSimpson(m, n, ak, bk, ck, dk, fun) << endl;
//
//}