#include "score.h"
#include <QString>
#include <iostream>
#include <fstream>
using namespace std;

int Score::writeScore(float score) {
    ofstream myfile("score.txt"); 
    myfile << to_string(score) << "\n"; 
    myfile.close(); 
    return 0;
}

QString Score::readScore() { 
    QString tab;
    ifstream file("score.txt"); 
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            tab += QString::fromStdString(line) + "\n";
        }
        file.close(); 
    }
    return tab;
}
