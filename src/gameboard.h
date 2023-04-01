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
signals:
    void buttonClicked(bool, QString);
private slots:
    void setupBackground(int, int);
    void setupTimer();
    void handleClick(){
        emit buttonClicked(click,audioPath);
    }
    void playAudio(QString);
    void buttonAudio(bool, QString);
    void displayCardAudios(QStringList);

private:
    QGridLayout* m_gridLayout;
	QLabel *backgroundLabel;
    QString audioPath;
    bool click;
    QMediaPlayer *player;
    QString clickedButton;
    QProgressBar *timerBar;
};

#endif // GAMEBOARD_H
