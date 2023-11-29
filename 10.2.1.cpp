#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n; // Розмірність матриці

    cout << "Введіть розмірність квадратної матриці: ";
    cin >> n;

    cout << "Введіть елементи матриці:\n";

    // Зчитуємо елементи матриці
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Суми елементів рядків у стовпцях з парними номерами:\n";

    // Обчислюємо суму для кожного рядка у стовпцях з парними номерами
    for (int i = 0; i < n; ++i) {
        int sum = 0;

        for (int j = 0; j < n; j += 2) {
            sum += matrix[i][j]; // Додаємо до суми елементи з парними номерами стовпців
        }

        cout << "Сума елементів рядка " << i + 1 << " у стовпцях з парними номерами: " << sum << endl;
    }

    return 0;
}

