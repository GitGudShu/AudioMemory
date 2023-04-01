#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QTimer>

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = nullptr);
signals:
    void buttonClicked(bool, QString, QPushButton*);
private slots:
    void setupBackground(int, int);
    void playAudio(QString);
    void buttonAudio(bool, QString, QPushButton*);
    void displayCardAudios(QStringList);
    void checkForWin(QString, QPushButton*);
    void updateTimerBar()
   {
      int currentValue = timerBar->value();
      if (currentValue == 100 || win) {
         // Time is up!
         timer->stop();
         timeScore = QString::number(currentValue);
         qDebug() << timeScore;
         // TODO: Handle the end of the game
      } else {
         timerBar->setValue(currentValue + 1);
      }
   }

private:
    QGridLayout* m_gridLayout;
	QLabel *backgroundLabel;
    QString audioPath;
    bool click;
    bool win;
    QString timeScore;
    QMediaPlayer *player;
    QPushButton* buttonSelected;
    QString clickedButton;
    QProgressBar *timerBar;
    QTimer *timer;
};

#endif // GAMEBOARD_H
