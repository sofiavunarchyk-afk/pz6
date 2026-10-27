# Звіт про виконання практичної роботи (Черга / std::queue)

**Виконала:** студентка 4СОМ, Винарчик Софія Степанівна  
**Варіант:** 1  

---

## Тема роботи
Опрацювання структури даних Черга (Queue) у мові програмування C++ за допомогою стандартного контейнера `std::queue`.

## Мета роботи
Набути практичних навичок роботи з контейнером `std::queue`, навчитися додавати елементи до черги (`push`), вилучати їх за принципом FIFO (First In, First Out — «перший прийшов — перший вийшов»), отримувати доступ до першого та останнього елементів (`front`, `back`), а також перевіряти чергу на порожнечу (`empty`).

---

## Виконання завдань

### Завдання 1. Створення черги цілих чисел та обчислення кількості парних елементів
**Умова:** Створити чергу з 15 цілих чисел. Підрахувати кількість парних елементів черги та знайти їхню суму. Вивести початкову чергу та результати.

**Програмний код:**
```cpp
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
```
**Результат виконання:**
```text
Початкова черга: 4 7 10 3 8 15 22 33 40 55 60 77 80 91 100 
Кількість парних чисел: 8
Сума парних чисел: 324
```
> *<img width="1522" height="760" alt="image" src="https://github.com/user-attachments/assets/1fe03630-5b22-4133-aa40-66026293baa1" />
*

---

### Завдання 2. Фільтрація черги (числа, що діляться на 4)
**Умова:** Додайте до черги цілі числа від 1 до 100. Створіть нову чергу, що містить лише числа, які діляться на 4 без остачі. Виведіть нову чергу.

**Програмний код:**
```cpp
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
```
**Результат виконання:**
```text
Числа, що діляться на 4: 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 
```
> *<img width="1640" height="922" alt="image" src="https://github.com/user-attachments/assets/8b6e3a80-f6d1-4a12-9f3a-82675b3dcc2a" />
*

---

### Завдання 3. Черга символів (підрахунок голосних)
**Умова:** Створіть чергу символів, що містить літери англійського слова. Підрахуйте кількість голосних літер у слові.

**Програмний код:**
```cpp
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
```
**Результат виконання:**
```text
Слово: 'education'
Кількість голосних літер у слові: 5
```
> *(Скріншот роботи програми)*

---

### Завдання 4. Черга структур (Прізвище та бал)
**Умова:** Створити чергу, інформаційними полями якої є: прізвище та середній бал студента. Додати у чергу відомості про студентів. Вивести список студентів, середній бал яких >= 80.

**Програмний код:**
```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Student {
    string surname;
    int mark;
};

int main() {
    queue<Student> students;

    students.push({"Ivanenko", 85});
    students.push({"Petrenko", 74});
    students.push({"Kovalenko", 92});
    students.push({"Melnyk", 78});

    cout << "Студенти з балом не менше 80:\n";

    while (!students.empty()) {
        Student s = students.front();
        students.pop();

        if (s.mark >= 80) {
            cout << s.surname
                 << " - " << s.mark << endl;
        }
    }

    return 0;
}
```
**Результат виконання:**
```text
Студенти з балом не менше 80:
Ivanenko - 85
Kovalenko - 92
```
> *<img width="1706" height="861" alt="image" src="https://github.com/user-attachments/assets/85f3e064-c2dd-4b50-98b5-d7365c9e5e56" />
*

---

### Завдання 5. Моделювання черги документів для друку
**Умова:** Реалізуйте програму, яка моделює чергу документів для друку. Працівники або студенти можуть відправляти свої документи на друк, і вони повинні друкуватися в порядку їх надходження (перший надісланий — перший надрукований). Програма повинна дозволяти додавати нові документи до черги після завершення поточного друку. За умовою варіанта — додати щонайменше 4 документи до черги перед початком друку.

**Програмний код:**
```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Document {
    string name;
    int pages;
};

int main() {
    queue<Document> q;

    // Додаємо щонайменше 4 документи за умовою Варіанта 1
    q.push({"Doc1.docx", 3});
    q.push({"Homework.pdf", 5});
    q.push({"Project.pptx", 10});
    q.push({"Report.xlsx", 2}); // Доданий 4-й документ

    // Друк документів
    while (!q.empty()) {
        cout << "Друк: " << q.front().name
             << " (" << q.front().pages
             << " сторінок)" << endl;
        q.pop();
    }

    char choice;

    do {
        cout << "\nДодати новий документ? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            Document d;

            cout << "Назва документа: ";
            // ws дозволяє ігнорувати зайві пробіли перед введенням рядка
            getline(cin >> ws, d.name);

            cout << "Кількість сторінок: ";
            cin >> d.pages;

            if (d.pages > 0) {
                q.push(d);
                cout << "Документ додано до черги.\n";
            }

            // Друк нового документа
            while (!q.empty()) {
                cout << "Друк: " << q.front().name
                     << " (" << q.front().pages
                     << " сторінок)" << endl;
                q.pop();
            }
        }
    } while (choice == 'y' || choice == 'Y');

    cout << "Роботу завершено." << endl;

    return 0;
}
```
**Результат виконання:**
```text
Друк: Doc1.docx (3 сторінок)
Друк: Homework.pdf (5 сторінок)
Друк: Project.pptx (10 сторінок)
Друк: Report.xlsx (2 сторінок)

Додати новий документ? (y/n): n
Роботу завершено.
```
> *<img width="1668" height="893" alt="image" src="https://github.com/user-attachments/assets/3a98071c-9f3b-4d5a-800b-4c7857440360" />
*

---

## Висновок
Під час виконання практичної роботи було детально опрацьовано принципи функціонування черги (FIFO) у мові програмування C++. Було практично застосовано основні методи класу `std::queue`: додавання елементів у кінець (`push`), читання першого елемента (`front`) та його подальше видалення (`pop`). Використання циклів із перевіркою `!empty()` дозволило ефективно реалізувати алгоритми послідовного вилучення елементів для підрахунку парних чисел, фільтрації даних, роботи зі структурами та симуляції процесу друку документів у порядку їх надходження.
