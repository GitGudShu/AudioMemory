//
// Created by aurel on 18/03/2023.
//

#include "score.h"
#include <QString>
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

void readScore(QString tab) {

    ofstream file;
    file.open("score.txt");
    tab << file;
    file.close();
}
