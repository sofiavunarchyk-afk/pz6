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