#ifndef SCORE_H
#define SCORE_H

#include <QString>

class Score {
public:
    static int writeScore(float score);
    static QString readScore();
};

#endif // SCORE_H
