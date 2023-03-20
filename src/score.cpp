//
// Created by aurel on 18/03/2023.
//

#include "score.h"
#include <string>
#include <iostream>
#include <fstream>
#include <QtWidgets>
using namespace std;
QLabel score = new QLabel();

int writeScore(float score){
    ofstream myfile;
    myfile.open("score.txt");
    myfile << to_string(score)+"\n";
    myfile.close();
    return 0;
}

int readScore() {
    ofstream file;
    file.open("score.txt");
    while(!EOF){
        score << line << '\n'
    }
    file.close();
    return 0;
}
