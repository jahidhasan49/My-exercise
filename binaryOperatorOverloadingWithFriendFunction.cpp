#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int age;

    public:
        Student() {
            age = 18;
        }

        Student(string name, int age) {
            this->name = name;
            this->age = age;
        }

        string getName() {
            return this->name;
        }

        void setName(string name) {
            this->name = name;
        }

        int getAge() {
            return this->age;
        }

        void setAge(int age) {
            this->age = age;
        }

        void display() {
            cout << "Student Information: " << endl;
            cout << "------------------------------------------" << endl;
            cout << "Name: " << this->name << endl;
            cout << "Age: " << this->age << endl << endl;
        }

        friend int operator+(Student s1, int x) {
            return s1.age + x;
        }

        friend Student operator+(Student s1, Student s2) {
            //Student newStudent(this->name + " " +s2.getName(), this->age + s2.getAge());

            string newName = s1.name + " " + s2.getName();
            int newAge = s1.age + s2.getAge();
            Student newStudent(newName, newAge);

            return newStudent;
        }

        friend int operator+(int x, Student s1) {
            return x + s1.age;
        }
};

int main() {
    Student s1("John", 20);
    s1.display();

    Student s2("Doe", 30);
    s2.display();

    cout << "Case #4: s1 + (int)X ---> (int)Y" << endl;
    cout << "------------------------------------------" << endl;
    int result = s1 + 7;
    cout << result << endl;

    cout << "Case #5: s1 + s2 ---> (Student)Y" << endl;
    cout << "------------------------------------------" << endl;
    Student superStudent = s1 + s2;
    superStudent.display();

    cout << "Case #6: (int)7 + s1 ---> (int)Y" << endl;
    cout << "------------------------------------------" << endl;
    result = 7 + s1;
    cout << result << endl;

    return 0;
}