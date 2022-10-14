#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string s;
    //User I/O (i.e. from the terminal)
    //Note, this only works with certain types
    cout << "Enter string (space indicates the end of the string) to process:\n";
    cin >> s;
    cout << "The user entered the following string: " << s << std::endl;
    //File I/O - write to a text file
    ofstream aFileForWrting;
    aFileForWrting.open ("test.txt");
    aFileForWrting << "This is a test write to a text file.\n";
    aFileForWrting << "The user entered the following string: " << s << endl;
    aFileForWrting.close();
    //File I/O - read from a text file
    ifstream aFileForReading ("test.txt");
    if (aFileForReading.is_open())
    {
        while ( getline (aFileForReading,s) )
        {
            cout << "The following string was read from the file:" << s << '\n';
        }
        aFileForReading.close();
    }
    else
    {
        cout << "Could not open file.\n";
    }

    return 0;
}
