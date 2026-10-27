#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<char> letters;
    
    // Англійське слово для перевірки
    string text = "education"; 
    
    // Записуємо кожну літеру слова в чергу
    for (int i = 0; i < text.length(); i++) {
        letters.push(text[i]);
    }
    
    int vowelCount = 0;
    
    // Витягуємо літери з черги та перевіряємо, чи є вони голосними
    while (!letters.empty()) {
        char c = letters.front();
        letters.pop();
        
        // Перевірка на голосні літери англійського алфавіту (включаючи великі та малі)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
            vowelCount++;
        }
    }
    
    cout << "Слово: '" << text << "'" << endl;
    cout << "Кількість голосних літер у слові: " << vowelCount << endl;
    
    return 0;
}