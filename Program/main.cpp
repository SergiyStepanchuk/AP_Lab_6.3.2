// Lab_6_3_2
#include <iostream>
#include <iomanip>
using namespace std;

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void draw_line(const int& size, const char& c = '-') {
	cout << c;
	if (size > 1) {
		draw_line(size - 1, c);
		return;
	}
	cout << endl;
}

void full_mass(int* mass, int size, const int* dia) {
	mass[size - 1] = myrand(dia[0], dia[1]);
	if (size > 1)
		full_mass(mass, size - 1, dia);
}

void draw_mass_recurs(const int* mass, const int& size, const int& c_space) {
	if (size > 1)
		draw_mass_recurs(mass, size - 1, c_space);

	cout << "|" << setw(c_space - 1) << mass[size - 1];
}

void draw_mass(const int* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	draw_mass_recurs(mass, size, c_space);
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

int max_(int* mass, int size) {
	if (--size > 0) {
		int b = max_(mass, size);
		return mass[size] > b ? mass[size] : b;
	}
	else return mass[0];
}

template < typename T >
T max__(T* mass, int size) {
	if (--size > 0) {
		T b = max_(mass, size);
		return mass[size] > b ? mass[size] : b;
	}
	else return mass[0];
}

void main() {
	srand(time(NULL));
	const int c_space = 4; // кількість містя яке виділяєьбся на одну комірку массиву, при виводі в консоль
	int dia[2], n; // діапазон, n

	cout << "n = "; cin >> n;
	cout << "dia start = "; cin >> dia[0];
	cout << "dia end = "; cin >> dia[1];

	int* mass = new int[n];

	full_mass(mass, n, dia);
	draw_mass(mass, n, c_space);
	cout << "max: " << max_(mass, n) << endl;
	cout << "max tmpl: " << max__<int>(mass, n) << endl;

	delete[] mass;
}