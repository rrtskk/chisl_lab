#include<iostream>
#include<math.h>
using namespace std;

void Print2(float** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void Print1(float* array, int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << ' ';
	}
	cout << endl << endl;
}

void Gaussian_Method(int n, float** a, float* b, float* x) {
	// forward stroke of the Gaussian method
	for (int k = 0; k < n; k++) {

		cout << "=======================================" << endl;
		cout << "matrix step " << k + 1 << endl;
		Print2(a, n);
		Print1(b, n);

		float maxColumnElement = abs(a[k][k]);
		int maxElementIndex = k;

		// find max element in column
		for (int i = k; i < n; i++) {
			if (abs(a[k][i]) > maxColumnElement) {
				maxColumnElement = abs(a[k][i]);
				maxElementIndex = i;
			}
		}

		// swap row i and row with max element
		if (k != maxElementIndex) {
			swap(a[k], a[maxElementIndex]);
			swap(b[k], b[maxElementIndex]);
		}

		cout << "matrix after swap rows " << k << " " << maxElementIndex << endl;
		Print2(a, n);
		Print1(b, n);

		// variable exclusion
		// make first element of row k equal 1
		float coefficient = a[k][k];
		for (int i = k; i < n; i++) {
			a[k][i] /= coefficient;
		}
		b[k] /= coefficient;

		cout << "matrix after make first element of row k equal 1" << endl;
		Print2(a, n);
		Print1(b, n);

		// nulling an element in a column
		for (int i = k + 1; i < n; i++) {
			float nullingCoefficient = a[i][k];
			for (int j = k; j < n; j++) {
				a[i][j] -= nullingCoefficient * a[k][j];
			}
			b[i] -= nullingCoefficient * b[k];
		}

		cout << "matrix after variable exlusion " << endl;
		Print2(a, n);
		Print1(b, n);
	}

	// backward stroke of th Gaussian method
	for (int i = n - 1; i >= 0; --i) {
		x[i] = b[i];
		for (int j = n - 1; j > i; --j) {
			x[i] -= x[j] * a[i][j];
		}
		x[i] /= a[i][i];
	}

	// print solution
	cout << "Solution is :" << endl;
	Print1(x, n);
}