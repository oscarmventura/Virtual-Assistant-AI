#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

// Define a function to get the current time
string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string time(dt);
    return time;
}

// Define a function to open a file
void openFile(string filename) {
    string command = "notepad.exe " + filename;
    system(command.c_str());
}

int main() {
    string input;
    cout << "Hello, I am your AI assistant. How can I assist you today?" << endl;
    while (true) {
        cout << "You: ";
        getline(cin, input);

        if (input.find("open") != string::npos) {
            size_t pos = input.find("open") + 5;
            string filename = input.substr(pos);
            openFile(filename);
            cout << "Opening file " << filename << "..." << endl;
        }
        else if (input.find("time") != string::npos) {
            string time = getCurrentTime();
            cout << "Current time is " << time << endl;
        }
        else if (input == "exit") {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "I'm sorry, I don't understand. Can you please repeat?" << endl;
        }
    }
    return 0;
}
