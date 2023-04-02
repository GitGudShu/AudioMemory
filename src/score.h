#ifndef SCORE_H
#define SCORE_H

#include <QString>

class Score {
public:
    static void writeScore(QString difficulty, QString score);
    static QString readScore();
};

#endif // SCORE_H
