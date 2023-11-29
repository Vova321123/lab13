//
// Created by demyk on 29.11.2023.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;

// Функція для заповнення матриці випадковими числами
void fillRandomMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    srand(time(0)); // Ініціалізуємо генератор випадкових чисел

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100; // Заповнюємо елементи матриці випадковими числами в діапазоні [0, 99]
        }
    }
}

// Функція для знаходження мінімального елемента в рядку
int findMinElementInRow(int matrix[MAX_SIZE][MAX_SIZE], int row, int n) {
    int minElement = matrix[row][0];

    for (int i = 1; i < n; ++i) {
        if (matrix[row][i] < minElement) {
            minElement = matrix[row][i];
        }
    }

    return minElement;
}

// Функція для зміщення елементів рядка вліво на вказану кількість позицій
void shiftRowLeft(int matrix[MAX_SIZE][MAX_SIZE], int row, int shiftAmount, int n) {
    shiftAmount = shiftAmount % n; // Здійснюємо зсув за модулем n

    while (shiftAmount > 0) {
        int temp = matrix[row][0]; // Зберігаємо перший елемент

        for (int i = 0; i < n - 1; ++i) {
            matrix[row][i] = matrix[row][i + 1]; // Зсуваємо елементи вліво
        }

        matrix[row][n - 1] = temp; // Поміщаємо збережений елемент в кінці рядка
        shiftAmount--;
    }
}

// Функція для виведення матриці на екран
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n; // Розмірність квадратної матриці

    cout << "Введіть розмірність квадратної матриці: ";
    cin >> n;

    fillRandomMatrix(matrix, n); // Заповнюємо матрицю випадковими числами
    cout << "\nВихідна матриця:\n";
    printMatrix(matrix, n); // Виводимо початкову матрицю

    int rowToShift;
    cout << "\nВведіть номер рядка для зсуву: ";
    cin >> rowToShift;

    int minElement = findMinElementInRow(matrix, rowToShift, n); // Знаходимо мінімальний елемент у вказаному рядку
    shiftRowLeft(matrix, rowToShift, minElement, n); // Зсуваємо рядок на кількість позицій, рівну мінімальному елементу
    cout << "\nОтримана матриця після зсуву рядка " << rowToShift << " вліво на " << minElement << " позицій:\n";
    printMatrix(matrix, n); // Виводимо отриману матрицю

    return 0;
}
