#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

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
    QLabel *scores;
    QVBoxLayout *layout;
    QLabel *backgroundLabel;
};

#endif // WINDOW_H