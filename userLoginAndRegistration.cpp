#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

void login();
void registerUser();
void forgotPassword();

int main() {
    int choice;

    while (true) {
        cout << "\t_____________User Login And Registration_____________\n ";
        cout << "\t Select 1: To Login.\n";
        cout << "\t Select 2: To Register.\n";
        cout << "\t Select 3 if Password forgotten!\n";
        cout << "\t Select 4: To exit\n";
        cout << "\t\t\t Select choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                forgotPassword();
                break;
            case 4:
                cout << "Thank you!\n" << endl;
                return 0;  // Exit the program
            default:
                system("cls");
                cout << "Invalid option. Try Again!" << endl;
        }
    }

    return 0;
}

void login() {
    int count = 0;
    string userName, password, rUserName, uPassword;

    system("cls");
    cout << "Enter your Username & Password:\n";
    cout << "Enter your USERNAME: ";
    cin >> userName;
    cout << endl;
    cout << "Enter your PASSWORD: ";
    cin >> password;
    cout << endl;

    ifstream input("records.txt");

    while (input >> rUserName >> uPassword) {
        if (userName == rUserName && password == uPassword) {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1) {
        system("cls");
        cout << "Login Successful! " << endl;
    } else {
        system("cls");
        cout << "Login Failed! Wrong credentials" << endl;
    }
}

void registerUser() {
    int count = 0;
    string userName, password, rUserName, rPassword;
    cout << "Register your New Username and Password: \n";
    cout << "Enter your New Username: ";
    cin >> userName;
    cout << endl;
    cout << "Enter your New Password: ";
    cin >> password;
    cout << endl;

    ifstream input("records.txt");
    while (input >> rUserName >> rPassword) {
        if (rUserName == userName) {
            count = 1;
            break;
        }
    }

    input.close();
    if (count == 1) {
        system("cls");
        cout << "Already Registered with that userName! Try Again\n";
    } else {
        system("cls");
        ofstream output("records.txt", ios::app);
        output << userName << ' ' << password << '\n';
        output.close();
        cout << "Registered new User!" << endl;
    }
}

void forgotPassword() {
    int count = 0;
    string userName, rUserName, rPassword;
    cout << "Enter the userName you remembered: \n";
    cin >> userName;
    cout << endl;

    ifstream input("records.txt");

    while (input >> rUserName >> rPassword) {
        if (userName == rUserName) {
            count = 1;
            break;
        }
    }

    input.close();

    if (count == 1) {
        system("cls");
        cout << "User found! Password is: " << rPassword << endl;
    } else {
        system("cls");
        cout << "User not found!\n";
    }
}
