#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> numbers;

    // Додаємо 15 цілих чисел до черги
    numbers.push(4);
    numbers.push(7);
    numbers.push(10);
    numbers.push(3);
    numbers.push(8);
    numbers.push(15);
    numbers.push(22);
    numbers.push(33);
    numbers.push(40);
    numbers.push(55);
    numbers.push(60);
    numbers.push(77);
    numbers.push(80);
    numbers.push(91);
    numbers.push(100);

    int countEven = 0;
    int sumEven = 0;

    cout << "Початкова черга: ";

    // Витягуємо елементи, виводимо їх та робимо обчислення
    while (!numbers.empty()) {
        int x = numbers.front();
        cout << x << " "; // Виводимо елемент черги
        numbers.pop();

        // Перевірка на парність
        if (x % 2 == 0) {
            countEven++;
            sumEven += x;
        }
    }
    cout << endl; // Перехід на новий рядок після виведення черги

    // Виведення результатів
    cout << "Кількість парних чисел: " << countEven << endl;
    cout << "Сума парних чисел: " << sumEven << endl;

    return 0;
}