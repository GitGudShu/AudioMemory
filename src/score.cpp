#include "score.h"
#include <QString>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void Score::writeScore(QString difficulty, QString score) {
    time_t now = time(0);
    char* dt = ctime(&now);

    ofstream myfile;
    myfile.open("score.txt", ios::app);

    myfile << dt << "Difficulty: " << difficulty.toStdString() << ", Score: " << score.toStdString() << endl;

    myfile.close();
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
