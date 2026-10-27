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
