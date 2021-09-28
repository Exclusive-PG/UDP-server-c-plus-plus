//#define _CRT_SECURE_NO_WARNINGS
//#include <string.h>
//#include <string>
//#include <iostream>
//
//
//using namespace std;
//
//
//class parserCommands {
//
//
//public:
//    string* parser(char buff[]) {
//        string* arrayWord = new string[100];
//        int counter = 0;
//
//        //Разбор слов
//        char separators[] = ", ()";
//        char* tok;
//        tok = strtok(buff, separators);
//        while (tok) {
//            cout << tok << endl;
//
//            arrayWord[counter] = tok;
//            arrayWord[counter].erase(remove_if(arrayWord[counter].begin(), arrayWord[counter].end(), isspace), arrayWord[counter].end());
//            tok = strtok(NULL, separators);
//            counter++;
//        }
//
//        return arrayWord;
//    }
//};
