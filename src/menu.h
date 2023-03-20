#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QMediaPlayer>

class Menu : public QWidget
{
   Q_OBJECT

 public:
    Menu(QWidget *parent = nullptr);

 private slots:
    void startGame();
    void exit();

 private:
    QPushButton *startButton;
    QPushButton *exitButton;
    QLabel *score;
    QGridLayout *layout;
    QLabel *backgroundLabel;
    QMediaPlayer *player;
};

#endif // WINDOW_H