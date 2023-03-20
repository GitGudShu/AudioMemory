//
// Created by aurel on 18/03/2023.
//

#ifndef AUDIOMEMORY_SCORE_H
#define AUDIOMEMORY_SCORE_H
#include <string>
#include <QString>
#include <iostream>
#include <fstream>

class score {
    public:
        int writeScore(float score);
        void readScore(QString tab);
};


#endif //AUDIOMEMORY_SCORE_H
