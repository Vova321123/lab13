#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n; // Розмірність матриці
    int negativeCount = 0; // Лічильник від'ємних елементів

    cout << "Введіть розмірність квадратної матриці: ";
    cin >> n;

    cout << "Введіть елементи матриці:\n";

    // Зчитуємо елементи матриці
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            // Перевіряємо, чи є елемент від'ємним
            if (matrix[i][j] < 0) {
                negativeCount++; // Збільшуємо лічильник
            }
        }
    }

    cout << "Кількість від'ємних елементів у матриці: " << negativeCount << endl;

    return 0;
}
