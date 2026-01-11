#include <iostream>
using namespace std;

class Car; // forward declaration

class Truck {
private:
    string name;
    double speed;

public:
    Truck() {
        speed = 0.0;
    }

    Truck(string n, double s) {
        name = n;
        speed = s;
    }

    ~Truck() {}

    string getName() {
        return name;
    }

    double getSpeed() {
        return speed;
    }

    void setName(string n) {
        name = n;
    }

    void setSpeed(double s) {
        speed = s;
    }

    // ✅ Proper member declaration
    void race(Car c);
};

class Car {
private:
    string name;
    double speed;

public:
    Car() {
        speed = 0.0;
    }

    Car(string n, double s) {
        name = n;
        speed = s;
    }

    ~Car() {}

    string getName() {
        return name;
    }

    double getSpeed() {
        return speed;
    }

    void setName(string n) {
        name = n;
    }

    void setSpeed(double s) {
        speed = s;
    }

    friend void move(Car c);

    // ✅ Allow Truck’s race() to access Car’s private members
    friend void Truck::race(Car c);
};

// ✅ Truck member function definition
void Truck::race(Car c) {
    if (speed > c.speed) {
        cout << "Truck beats Car" << endl;
    } else if (c.speed > speed) {
        cout << "Car beats Truck" << endl;
    } else {
        cout << "Race drawn" << endl;
    }
}

// free function
void move(Car c) {
    cout << c.speed << endl;
}

int main() {
    Car c("Toyota", 80);
    Truck t("Eicher", 40);

    t.race(c); // ✅ works fine

    return 0;
}
