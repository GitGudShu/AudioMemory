#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class Menu : public QWidget
{
 public:
    Menu(QWidget *parent = nullptr);

 private slots:
    void startGame();
    void exit();

 private:
    QPushButton *startButton;
    QPushButton *exitButton;
    QLabel *background;
};

#endif // WINDOW_H