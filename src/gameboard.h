#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class QGridLayout;
class QTimer;

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = nullptr);

private slots:
    void setupBackground(int, int);

private:
    QGridLayout* m_gridLayout;
	QLabel *backgroundLabel;
};

#endif // GAMEBOARD_H
