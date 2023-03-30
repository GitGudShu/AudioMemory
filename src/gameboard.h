#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
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
    void playAudio(QString);

private:
    QGridLayout* m_gridLayout;
	QLabel *backgroundLabel;
    QMediaPlayer *player;
};

#endif // GAMEBOARD_H
