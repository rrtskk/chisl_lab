#include<iostream>
using namespace std;

void Print2(float** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j]<<' ';
		}
		cout << endl;
	}
	cout << endl;
}

void Print1(float* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i]<<' ';
	}
	cout << endl<<endl;
}

int main() {
	int n, strmax;
	float max = 0, times = 0, norma = 0;
	cout << "Enter size of array: ";
	cin >> n;
	cout << endl;
	float* temp = new float[n - 1];
	float** a = new float*[n];
	for (int i = 0; i < n; i++)
		a[i] = new float[n];
	float** as = new float* [n];
	for (int i = 0; i < n; i++)
		as[i] = new float[n];
	float* b = new float [n];
	float* x = new float[n];
	float* F = new float[n];
	cout << "Enter elements of matrix: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << endl;
	cout << "Enter elements of vector: \n";
	for (int i = 0; i < n; i++) {
			cin >> b[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		F[i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = k; i < k+1; i++) {
			for (int j = k; j < n; j++) {
				if (max < a[j][i]&&a[j][i]!=0) {
					max = a[j][i];
					strmax = j;
				}
			}
		}
		for (int i = k; i < n; i++) {
			swap(a[0][i], a[strmax][i]);
		}
		for (int i = k; i < n; i++) {
			for (int j = k; j < 1; j++) {
				a[i][j] /= max;
			}
		}
		for (int i = k; i < 1; i++) {
			b[i] /= max;
		}
		for (int i = k; i < n - 1; i++) {
			temp[i] = a[i + 1][k];
		}
		for (int i = k; i < n; i++) {
			for (int j = k+1; j < n; j++) {
				a[j][i] -= (temp[j - 1] * a[0][i]);
			}
		}
		for (int i = k + 1; i < n; i++) {
			b[i] -= (temp[i - 1] * b[0]);
		}
		Print2(a, n);
	}		
	Print2(a, n);
	float m = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1)
			for (int j = n - 1; j >= 0; j--) {
				m += (a[i][j] * x[j]);
			}
		x[i] = (b[i]-m) / a[i][i];
		m = 0;
	}
	Print1(x, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			times +=( a[i][j] * x[j]);
		}
		F[i] += b[i] - times;
		times = 0;
	}
	Print1(F, n);
	cout << endl<<endl;
	for (int i = 0; i < n; i++) {
		if (F[i] > norma) {
			norma = F[i];
		}
	}
	cout << "Norma vectora nevyazki= " << norma;
	delete[]F;
	delete[]b;
	delete[]a;
	delete[]x;
	delete[]temp;
	delete[]as;
}
