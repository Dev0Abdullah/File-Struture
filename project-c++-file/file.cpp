#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Check if a file exists
void checkFile() {
    string fileName;
    cout << "Enter the file name to check: ";
    cin >> fileName;

    fstream file(fileName);
    if (!file.is_open()) {
        cout << "The file \"" << fileName << "\" does not exist." << endl;
    } else {
        cout << "The file \"" << fileName << "\" exists." << endl;
    }
    file.close();
}

// Write data to a file
void writeInFile() {
    string fileName;
    cout << "Enter the file name to write to: ";
    cin >> fileName;

    ofstream file(fileName, ios::out);
    if (!file.is_open()) {
        cout << "Failed to open the file \"" << fileName << "\" for writing." << endl;
        return;
    }

    cout << "Enter the text to write to the file: ";
    cin.ignore();
    string text;
    getline(cin, text);

    file << text << endl;
    cout << "Successfully wrote to the file \"" << fileName << "\"." << endl;
    file.close();
}

// Append data to a file
void appendToFile() {
    string fileName;
    cout << "Enter the file name to append to: ";
    cin >> fileName;

    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cout << "Failed to open the file \"" << fileName << "\" for appending." << endl;
        return;
    }

    cout << "Enter the text to append to the file: ";
    cin.ignore();
    string text;
    getline(cin, text);

    file << text << endl;
    cout << "Successfully appended to the file \"" << fileName << "\"." << endl;
    file.close();
}

// Read a file word by word
void readWordByWord() {
    string fileName;
    cout << "Enter the file name to read: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open the file \"" << fileName << "\" for reading." << endl;
        return;
    }

    string word;
    cout << "Reading file word by word:" << endl;
    while (file >> word) {
        cout << word << endl;
    }
    file.close();
}

// Read a file character by character
void readCharacterByCharacter() {
    string fileName;
    cout << "Enter the file name to read: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open the file \"" << fileName << "\" for reading." << endl;
        return;
    }

    char ch;
    cout << "Reading file character by character:" << endl;
    while (file.get(ch)) {
        cout << ch;
    }
    cout << endl;
    file.close();
}

// Read a file line by line
void readLineByLine() {
    string fileName;
    cout << "Enter the file name to read: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open the file \"" << fileName << "\" for reading." << endl;
        return;
    }

    string line;
    cout << "Reading file line by line:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Copy a text file
void copyTextFile() {
    string sourceFile, destinationFile;
    cout << "Enter the source file name: ";
    cin >> sourceFile;
    cout << "Enter the destination file name: ";
    cin >> destinationFile;

    ifstream src(sourceFile, ios::in);
    if (!src.is_open()) {
        cout << "Failed to open the source file \"" << sourceFile << "\"." << endl;
        return;
    }

    ofstream dest(destinationFile, ios::out);
    if (!dest.is_open()) {
        cout << "Failed to open the destination file \"" << destinationFile << "\"." << endl;
        return;
    }

    string line;
    while (getline(src, line)) {
        dest << line << endl;
    }

    cout << "Successfully copied content from \"" << sourceFile << "\" to \"" << destinationFile << "\"." << endl;
    src.close();
    dest.close();
}

// Count words in a file
void countFileWords() {
    string fileName;
    cout << "Enter the file name to count words: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open the file \"" << fileName << "\" for counting." << endl;
        return;
    }

    int wordCount = 0;
    string word;
    while (file >> word) {
        ++wordCount;
    }

    cout << "The file \"" << fileName << "\" contains " << wordCount << " words." << endl;
    file.close();
}
// Wrie Int Main Function
int main() {
    int choice;

    do {
        cout << "\nFile Management Application\n";
        cout << "1. Check if a file exists\n";
        cout << "2. Write to a file\n";
        cout << "3. Append to a file\n";
        cout << "4. Read a file word by word\n";
        cout << "5. Read a file character by character\n";
        cout << "6. Read a file line by line\n";
        cout << "7. Copy a text file\n";
        cout << "8. Count words in a file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkFile();
                break;
            case 2:
                writeInFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                readWordByWord();
                break;
            case 5:
                readCharacterByCharacter();
                break;
            case 6:
                readLineByLine();
                break;
            case 7:
                copyTextFile();
                break;
            case 8:
                countFileWords();
                break;
            case 0:
                cout << "Exiting the application...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
