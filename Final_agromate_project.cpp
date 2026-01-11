#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool displayFile(string agromateFile) {
    ifstream in(agromateFile);
    if (!in) {
        cout << "File not found!" << endl;
        return false;
    }

    string line;
    while (getline(in, line)) {
        cout << line << endl;   
    }
    in.close();
    return true;
}

// class for user authentication
class User {
private:

    string username;     // User এর username store করার জন্য
    string password;    // User এর password store করার জন্য

public:
    User () {
        username = " ";
        password = " ";
    }  // Default constructor

    // Parameterized constructor, যখন object তৈরি হবে তখন username/password set করে
    User (string U , string P){
        username = U;
        password = P;
    }

    void registerUser() {

        string newUser, newPass;        // local variable, new username/password store করার জন্য
        cout << "Register a new user." << endl;
        cout << "Enter new username: ";
        cin >> newUser ;
        cout << "Enter new password: ";
        cin >> newPass ;

        username = newUser;             // class variable set করা
        password = newPass;        // class variable set করা

        cout << "Registration successful! You can now log in with your new credentials." << endl;
        ofstream out ("AgroMate.txt", ios::app);      // user data store করার জন্য
        out << username << " " << password << endl;         // file এ username/password write করা
        out.close();        // file close করা


    }

   bool loginUser() {

    string inputUser, inputPass;    // local variable, input store করার জন্য
        cout << "Enter username: ";
        cin >> inputUser ;
        cout << "Enter password: ";
        cin >> inputPass ;

        ifstream in ("AgroMate.txt"); // user data read করার জন্য
        string fileUser, filePass;          // file থেকে username/password read করার জন্য
        while (in >> fileUser >> filePass)  // file থেকে username/password read করে
             {

                if (fileUser == inputUser && filePass == inputPass) {
                    in.close();                     // file close করে
                    cout << "Login successful!" << endl;
                    return true;
                }
            }
        in.close();
        cout << "Invalid username or password. Please try again." << endl;
        return false;
    }


// Harvest menu function: user কে crop/disease select করার option দেয়
    void harvestMenu(){
        int choice1, choice2;           // user choice store করার জন্য

        cout << "Harvest Menu: " << endl;
        cout << "\n1. Rice\n2. Wheat\n3. Sugarcane\n4. Corn\n5. Jute\n6. Potato\n7. Tomato\n8. Watermelon" << endl;
        cout << "Enter your choice: ";
        cin >> choice1;      // user crop choice input নেয়া
        switch(choice1) {
            case 1:
                cout << "You selected Rice :" << endl;
                cout << "Rice Dieseases : " << endl;
                cout << "\n1. Bacterial Leaf Blight\n2. Blast" << endl;
                cin >> choice2;

                if (choice2 == 1) {
                    displayFile("Crop_files/Rice Bacterial Leaf Blight.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Rice Blast.txt");
                }
                else {
                    cout << "Invalid choice." << endl;
                }
                break;


            case 2:
                cout << "You selected Wheat :" << endl;
                cout << "Wheat Dieseases : " << endl;
                cout << "\n1. Rust\n2. Powdery Mildew" << endl;
                cin >> choice2;
                if (choice2 == 1) {
                    displayFile("Crop_files/Wheat Rust.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Wheat Powdery Mildew.txt");
                }
                else{
                    cout << "Invalid choice." << endl;
                }
                break;

            case 3:
                cout << "You selected Sugarcane :" << endl;
                cout << "Sugarcane Dieseases : " << endl;
                cout << "1. Red Rot\n2. Smut" << endl;
                cin >> choice2;
                if (choice2 == 1) {
                    displayFile("Crop_files/Sugarcane Red Rot.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Sugarcane Smut.txt");
                }
                else{
                    cout << "Invalid choice." << endl;
                }
                break;

            case 4:
                cout << "You selected Corn :" << endl;
                cout << "Corn diseases : " << endl;
                cout << "\n1. Northern Leaf Blight\n2. Anthracnose" << endl;
                cin >>  choice2;
                if (choice2 == 1) {
                    displayFile("Crop_files/Corn Northern Leaf Blight.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Corn Anthracnose.txt");
                }
                else{
                    cout << "Invalid choice." << endl;
                }
                break;

            case 5:
                cout << "You selected jute :" << endl;
                cout << "Jute diseases : " << endl;
                cout << "\n1. Jute mosaic\n2. root-Knot" << endl;
                cin >> choice2;
                if (choice2 == 1) {
                    displayFile("Crop_files/Jute mosaic.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Jute root knot.txt");
                }
                else{
                    cout << "Invalid choice." << endl;
                }
                break;

            case 6:
                cout << "You selected Potato :" << endl;
                cout << "Potato diseases : " << endl;
                cout << "\n1. Black Scurf\n2. Bacterial Wilt" << endl;
                cin >> choice2;
                if (choice2 == 1) {
                    displayFile("Crop_files/Potato Black Scurf.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Potato Bacterial Wilt.txt");
                }
                else{
                    cout << "Invalid choice." << endl;
                }
                break;

            case 7:
                cout << "You selected Tomato :" << endl;
                cout << "Tomato diseases : " << endl;
                cout << "\n1. Leaf Curl Virus\n2. Damping Off" << endl;
                cin >> choice2;
                if (choice2 == 1) {
                    displayFile("Crop_files/Tomato Leaf Curl Virus.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Tomato Damping Off.txt");
                }
                else {
                    cout << "Invalid choice." << endl;
                }
                break;

            case 8:
                cout << "You selected Watermelon :" << endl;
                cout << "Watermelon diseases : " << endl;
                cout << "\n1. Fusarium Wilt\n2. Gummy Stem Blight" << endl;
                cin >>  choice2;
                if (choice2 == 1) {
                    displayFile("Crop_files/Watermelon Fusarium Wilt.txt");
                }
                else if (choice2 == 2) {
                    displayFile("Crop_files/Watermelon Gummy Stem Blight.txt");
                }
                else {
                        cout << "Invalid choice." << endl;
                }
                break;
        }


         cout << "\nThank you for using AgroMate!" << endl;

    }


        void feedback(){
            int feedback; // user feedback store করার জন্য
            cout << "Please provide your feedback about AgroMate: ";    // feedback request
            cout << "\n1. Excellent \n2. Good\n3. Average\n4. Poor" << endl;     // feedback options
            cin >> feedback;        // user feedback input নেয়া
            switch(feedback) {          // feedback অনুযায়ী message দেয়
                case 1:
                    cout <<"Thank you for your excellent feedback!" << endl;
                    break;
                case 2:
                    cout << "Thank you for your good feedback!" << endl;
                    break;
                case 3:
                    cout << "Thank you for your average feedback!" << endl;
                    break;
                case 4:
                    cout << "Thank you for your feedback! We will strive to improve." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;

            }
        }
    };


int main() {

    cout << "Welcome to AgroMate!" << endl;
    cout << "Please log in to continue." << endl;
    User farmer;  // farmer user create

    int choice;
    cout << "1. Register\n2. Log in" << endl;
    cin >> choice;

    switch (choice) {
        case 1:

            farmer.registerUser();
            cout << "Please log in to continue." << endl;

            if (farmer.loginUser()){
                farmer.harvestMenu();
                farmer.feedback();
            }
            break;

        case 2:

            if (farmer.loginUser()){
                farmer.harvestMenu();
                farmer.feedback();
            }
            break;
        default:
            cout << "Invalid choice." << endl;
            return 0;
    }
    return 0;
}



