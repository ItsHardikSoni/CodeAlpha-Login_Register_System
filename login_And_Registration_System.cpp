#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void registerUser(){
    string userName, password;
    cout << "Enter your name: ";
    cin >> userName;

    cout << "Create Password: ";
    cin >> password;

    // Store Username and password 
    ofstream file;
    file.open("user_database.txt", ios::app);
    
    file << userName << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
}

bool loginUser(){
    string username, password, u, p;
    
    // Getting user input for login
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Opening file to check credentials
    ifstream file("user_database.txt");
    
    // Checking each line in the file for matching username and password
    while (file >> u >> p) {
        if (u == username && p == password) {
            file.close();
            cout << "Login successful!" << endl;
            return true;
        }
    }

    file.close();
    cout << "Login failed! Incorrect username or password." << endl;
    return false;
}

int main() {
    int choice;

    // Menu for user
    cout << "1. Register\n2. Login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Handle registration or login based on user input
    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}