#include <iostream>
#include <fstream>
#include <direct.h>

using namespace std;

string reverseString(){
    string str;
    string reversed;
    string path = getenv("USERPROFILE");
    path += "\\Downloads\\CSC450_CT5_mod5.txt"; //file must be in downloads folder to work
    ifstream file(path);

        if (file.is_open()){
            while (std::getline(file, str)){
                reversed += str;
                reversed.push_back(' ');
            }
            file.close();
        }
        else {
            cout << "File failed to open." << endl;
    }
//If these first three lines are deleted, then your program is not functioning as expected.
    int length = reversed.length();
    for (int i = 0; i < length / 2; i++){
        swap(reversed[i], reversed[length - i - 1]);
    }
    cout << reversed;
    //clear strings
    str.clear();
    path.clear();
    return reversed;

    //clear reversed to ensure it gets passed
    reversed.clear();
}

void toFile(string reversedText){

    string path = getenv("USERPROFILE");
    path += "\\Downloads\\CSC450_CT5_mod5.txt";
    ofstream file(path);

    if(file.is_open()){
        file << reversedText; //resorts text
    }
    file.close();
    path.clear();
    reversedText.clear();
}

int main()
{
    //makes file
    string path = getenv("USERPROFILE");
    path += "\\Downloads\\CSC450_CT5_mod5.txt";
    ofstream newFile(path);
            newFile << "Please be sure to append your data to this text file." << endl; //avoided \n
            newFile << "If these first three lines are deleted, then your program is not" << endl;
            newFile << "functioning as expected." << endl;
            newFile.close();

    //prints to console to ensure that it works properly (it changes the file directly)
    ifstream file(path);
        string printToConsole;
        string str;
        if (file.is_open()){
            while (std::getline(file, str)){
                printToConsole += str;
                printToConsole.push_back(' ');
            }
        }
        cout << printToConsole << endl;
        file.close();
        printToConsole.clear();
        str.clear();
        path.clear();

    //gets reversed string
    string reversedText = reverseString();
    //overwrites file
    toFile(reversedText);
    reversedText.clear(); //NOTE: Windows ransomware protection prevented my program from running as intended
}
