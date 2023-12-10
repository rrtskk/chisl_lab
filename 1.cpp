//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//void Gaussian_Method(int n, float** a, float* b, float* x);
//
//void Print2(float** matrix, int n);
//
//void Print1(float* array, int n);
//
//void ResidualV(float** a, float* x, float* b, float* F, int n) {
//
//	// calculation of the residual vector
//	for (int i = 0; i < n; i++) {
//		F[i] = 0;
//		for (int j = 0; j < n; j++) {
//			F[i] += (a[i][j] * x[j]);
//		}
//		F[i] -= b[i];
//	}
//	cout << "Residual vector:" << endl;
//	Print1(F, n);
//}
//
//float Norm(float* F, int n, float norm) {
//	for (int i = 1; i < n; i++) {
//		if (abs(F[i]) > norm) {
//			norm = F[i];
//		}
//	}
//	cout << "Norm of residual vector = " << norm << endl;
//	return norm;
//}
//
//int main() {
//	// enter matrix size
//	int n;
//	cout << "Enter size of array: ";
//	cin >> n;
//	cout << endl;
//
//	// init matix
//	float** a = new float* [n];
//	for (int i = 0; i < n; i++)
//		a[i] = new float[n];
//	//init copy of matrix
//	float** a1 = new float* [n];
//	for (int i = 0; i < n; i++)
//		a1[i] = new float[n];
//
//	// enter elements of matrix
//	cout << "Enter elements of matrix: \n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> a[i][j];
//		}
//	}
//	cout << endl;
//	//copy matrix
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			a1[i][j]= a[i][j];
//		}
//	}
//
//	// init vector
//	float* b = new float[n];
//
//	// enter elements of vector
//	cout << "Enter elements of vector: \n";
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//	}
//	cout << endl;
//
//	// init vector of solutions
//	float* x = new float[n];
//	for (int i = 0; i < n; i++) {
//		x[i] = 0;
//	}
//
//	// input all data into GM function
//	Gaussian_Method(n, a, b, x);
//
//	// init residual vector
//	float* F = new float[n];
//
//	//Solve norm of residual vector
//	ResidualV(a, x, b, F, n);
//	cout << endl;
//
//	// calculate norm of residual vector
//	float norm = fabs(F[0]);
//	Norm(F, n, norm);
//
//	//init 2nd vector of solutions
//	float* x1 = new float[n];
//	for (int i = 0; i < n; i++) {
//		x1[i] = 0;
//	}
//
//	//init vector Ax
//	float* Ax = new float[n];
//	for (int i = 0; i < n; i++) {
//		Ax[i] = 0;
//	}
//
//	//solve vector Ax
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			Ax[i] += a1[i][j] * x[j];
//		}
//	}
//	cout << "Vector Ax= ";
//	Print1(Ax, n);
//
//	//solve GM for Ax instead of b
//	Gaussian_Method(n, a1, Ax, x1);
//
//	//make some action to use formula
//	for (int i = 0; i < n; i++) {
//		x1[i] -= x[i];
//	}
//
//	//init norm of edited vector x1 and vector x
//	float norm_minus = x1[0];
//	float normx = x[0];
//
//	//solve norm for edited vector x1
//	norm_minus=Norm(x1, n, norm_minus);
//
//	//solve norm for vector x
//	normx=Norm(x, n, normx);
//
//	//solve error
//	float err;
//	err = norm_minus / normx;
//	cout << "Error of method= " << err;
//
//	delete[]b;
//	delete[]x;
//	delete[]F;
//	delete[]x1;
//	delete[]Ax;
//	for (int i = 0; i < n; i++) {
//		delete[] a[i];
//	}
//	delete[] a;
//
//	for (int i = 0; i < n; i++) {
//		delete[] a1[i];
//	}
//	delete[] a1;
//}
