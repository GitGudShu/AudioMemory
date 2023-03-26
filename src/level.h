#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QLabel>
#include <QDebug>

class Level : public QWidget
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr, int numCards = 6);

private:
    QVBoxLayout *m_mainLayout;
    QGridLayout *m_gridLayout;
    QLabel *backgroundLabel;
    QTimer m_timer;
    int m_numCards;
};

#endif // LEVEL_H
