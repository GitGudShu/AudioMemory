#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>

class QGridLayout;
class QTimer;

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = nullptr);
signals:
    void buttonClicked(bool, QString, QPushButton*);
private slots:
    void setupBackground(int, int);
    void setupTimer();
    void playAudio(QString);
    void buttonAudio(bool, QString, QPushButton*);
    void displayCardAudios(QStringList);

private:
    QGridLayout* m_gridLayout;
	QLabel *backgroundLabel;
    QString audioPath;
    bool click;
    QMediaPlayer *player;
    QPushButton* buttonSelected;
    QString clickedButton;
    QProgressBar *timerBar;
};

#endif // GAMEBOARD_H
