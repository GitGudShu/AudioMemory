//
// Created by aurel on 18/03/2023.
//

#include "score.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int writeScore(float score){
    ofstream myfile;
    myfile.open("score.txt");
    myfile << to_string(score)+"\n";
    myfile.close();
    return 0;
}

list<string> readScore() {
    ofstream file;
    file.open("score.txt");
    list<string> tab;
    string s;
    while(!EOF){
        tab.push_back(s);
    }
    file.close();
    return tab;
}
