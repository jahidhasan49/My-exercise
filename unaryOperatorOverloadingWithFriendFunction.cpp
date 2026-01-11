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

        friend Student operator++(Student& s1) {
            s1.age++;
            return s1;
        }

        friend Student operator++(Student& s1, int notUsed) {
            Student temp = s1;
            s1.age++;
            return temp;
        }

        friend Student operator--(Student& s1) {
            s1.age--;
            return s1;
        }

        friend Student operator--(Student& s1, int notUsed) {
            Student temp = s1;
            s1.age--;
            return temp;
        }
};

int main() {
    Student s1("John", 20);
    s1.display();

    cout << "Case #11: ++s1 ---> (Student)Y" << endl;
    cout << "------------------------------------------" << endl;
    Student s2 = ++s1;
    s1.display();
    s2.display();

    cout << "Case #12: s1++ ---> (Student)Y" << endl;
    cout << "------------------------------------------" << endl;
    Student s3 = s1++;
    s1.display();
    s3.display();

    cout << "Case #13: --s1 ---> (Student)Y" << endl;
    cout << "------------------------------------------" << endl;
    Student s4 = --s1;
    s1.display();
    s4.display();

    cout << "Case #14: s1-- ---> (Student)Y" << endl;
    cout << "------------------------------------------" << endl;
    Student s5 = s1--;
    s1.display();
    s5.display();

    return 0;
}