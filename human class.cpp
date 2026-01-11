#include<iostream>

using namespace std;

class Human {
    private:
        string id;
        string name;
        string skinTone;
        double height;
        double weight;

    public:
        Human(string i, string n, string st, double h, double w) {
            id = i;
            name = n;
            skinTone = st;
            height = h;
            weight = w;
        }

        Human(string i, string n, string st) {
            id = i;
            name = n;
            skinTone = st;
        }

        Human() {
            id = "";
            name = "";
            skinTone = "";
            height = 0.0;
            weight = 0.0;
        }

        string getId() {
            return id;
        }

        string getName() {
            return name;
        }

        string getSkinTone() {
            return skinTone;
        }

        double getHeight() {
            return height;
        }

        double getWeight() {
            return weight;
        }

        void setId(string i) {
            id = i;
        }

        void setName(string n) {
            name = n;
        }

        void setSkinTone(string st) {
            skinTone = st;
        }

        void setHeight(double h) {
            height = h;
        }

        void setWeight(double w) {
            weight = w;
        }

        void display() {
            cout << "Human Info: " << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "SkinTone: " << skinTone << endl;
            cout << "Height: " << height << endl;
            cout << "Weight: " << weight << endl << endl;
        }

        void walk() {
            cout << name << " is walking..." << endl << endl;
        }
};

int main() {
    int total;

    cout << "Enter total number of humen you want to create: " << endl;
    cin >> total;

    Human humanList[total];

    for (int i = 0; i < total; i++) {
        string id, name, skintone, garbage;
        double height, weight;

        cout << "For human-" << i+1 << ":" << endl;
        cout << "Enter human ID: " << endl;
        getline(cin, garbage);
        getline(cin, id);

        cout << "Enter human name: " << endl;
        getline(cin, name);
        
        cout << "Enter human SkinTone: " << endl;
        getline(cin, skintone);
        
        cout << "Enter human Height: " << endl;
        cin >> height;
        
        cout << "Enter human Weight: " << endl;
        cin >> weight;

        if (id != "" && name != "" && skintone != "" && height > 0 && weight > 0)
            humanList[i] = Human(id, name, skintone, height, weight);
        else if (id != "" && name != "" && skintone != "" && height <= 0 && weight <= 0)
            humanList[i] = Human(id, name, skintone);
        else
            humanList[i] = Human();
    }

    for (int i = 0; i < total; i++) {
        humanList[i].display();
        humanList[i].walk();
    }

    return 0;
}