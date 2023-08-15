#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string filename;

    cout << "Word Count Program\n";
    cout << "Enter the name of the text file: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error opening the file. Make sure the file exists and the name is correct.\n";
        return 1; // Exit with an error code
    }

    stringstream ss;
    ss << inputFile.rdbuf(); // Read the entire file into the stringstream
    string fileContents = ss.str();

    stringstream wordStream(fileContents);
    string word;
    int wordCount = 0;

    while (wordStream >> word) {
        wordCount++;
    }

    cout << "Number of words in the file: " << wordCount << endl;

    inputFile.close();

    return 0;
}
