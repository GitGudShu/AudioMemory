#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>

class Level : public QWidget
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr, int numCards = 0);

private:
    int m_numCards;
    QLabel *backgroundLabel;
};

#endif // LEVEL_H
