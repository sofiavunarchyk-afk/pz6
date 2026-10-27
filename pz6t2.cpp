#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> source;
    queue<int> result;

    // Записуємо в чергу цілі числа від 1 до 100
    for (int i = 1; i <= 100; i++) {
        source.push(i);
    }

    // Витягуємо по одному і записуємо в нову чергу числа, що діляться на 4
    while (!source.empty()) {
        int x = source.front();
        source.pop();

        if (x % 4 == 0) {
            result.push(x);
        }
    }

    cout << "Числа, що діляться на 4: ";

    // Виводимо нову чергу
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }

    cout << endl;

    return 0;
}