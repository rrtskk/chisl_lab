#include <iostream>
#include <math.h>

using namespace std;

void Gaussian_Method(int n, float** a, float* b, float* x);

void Print2(float** matrix, int n);

void Print1(float* array, int n);

void ResidualV(float** a, float* x, float* b, float* F, int n) {

	// calculation of the residual vector
	for (int i = 0; i < n; i++) {
		F[i] = 0;
		for (int j = 0; j < n; j++) {
			F[i] += (a[i][j] * x[j]);
		}
		F[i] -= b[i];
	}
	cout << "Residual vector:" << endl;
	Print1(F, n);

	// calculate norm of residual vector
	float norm = abs(F[0]);
	for (int i = 1; i < n; i++) {
		if (abs(F[i]) > norm) {
			norm = F[i];
		}
	}
	cout << "Norm of residual vector = " << norm << endl;
}

int main() {
	// enter matrix size
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	cout << endl;

	// init matix
	float** a = new float* [n];
	for (int i = 0; i < n; i++)
		a[i] = new float[n];

	// enter elements of matrix
	cout << "Enter elements of matrix: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << endl;

	// init vector
	float* b = new float[n];

	// enter elements of vector
	cout << "Enter elements of vector: \n";
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	cout << endl;

	// init vector of solutions
	float* x = new float[n];
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}

	// input all data into GM function
	Gaussian_Method(n, a, b, x);

	// init residual vector
	float* F = new float[n];

	//Solve norm of residual vector
	ResidualV(a, x, b, F, n);

	//// init residual vector
	//float* F = new float[n];

	//// calculation of the residual vector
	//for (int i = 0; i < n; i++) {
	//	F[i] = 0;
	//	for (int j = 0; j < n; j++) {
	//		F[i] += (a[i][j] * x[j]);
	//	}
	//	F[i] -= b[i];
	//}
	//cout << "Residual vector:" << endl;
	//Print1(F, n);

	//// calculate norm of residual vector
	//float norm = abs(F[0]);
	//for (int i = 1; i < n; i++) {
	//	if (abs(F[i]) > norm) {
	//		norm = F[i];
	//	}
	//}
	//cout << "Norm of residual vector = " << norm << endl;

	delete[]b;
	delete[]x;
	delete[]F;

	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}
