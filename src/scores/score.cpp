//
// Created by aurel on 18/03/2023.
//

#include "score.h"*
#include <iostream>
#include <fstream>
using namespace std

int write(float score){
    ofstream myfile;
    myfile.open("score.txt");
    myfile << score+"\n";
    myfile.close();
    return 0;
}

int read() {
    ofstream file;
    file.open("score.txt");
    while( getline(file, line)){
        count << line << '\n'
    }
    file.close();
    return 0;
}
