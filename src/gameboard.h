#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QTimer>
#include "score.h"

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = nullptr, int difficultyLevel = 1);
signals:
    void buttonClicked(bool, QString, QPushButton*);
    void backToMenu();
    void retryGame();
    void winScore(QString, QString);
private slots:
    void setupBackground(int, int);
    void playAudio(QString);
    void buttonAudio(bool, QString, QPushButton*);
    void checkForWin(QString, QPushButton*);
    void displayWinMessageBox();
    void displayTimeUpMessageBox();
    void updateTimerBar()
   {
      int currentValue = timerBar->value();
      if (currentValue == 100) {
         // Time is up!
         timer->stop();
         win = false;
         displayTimeUpMessageBox();
      }
      else if(win){
        // you won
         timer->stop();
         timeScore = QString::number(100 - currentValue);
         qDebug() << "Time score:" << timeScore;
         win = false;
         score = new Score();
         score->writeScore(difficulty,timeScore);
      } 
      else {
         timerBar->setValue(currentValue + 1);
      }
   }

private:
    QMediaPlayer *player;
    QPushButton* buttonSelected;
    QGridLayout* m_gridLayout;
	QLabel *backgroundLabel;
    QString audioPath;
    QString timeScore;
    QString clickedButton;
    QString difficulty;
    QProgressBar *timerBar;
    QTimer *timer;
    QList<QPushButton*> selectedButton;
    QList<QPushButton*> winnedButton;
    Score *score;
    bool click;
    bool win = false;
    int count;
    int cardNumber;
};

#endif // GAMEBOARD_H
