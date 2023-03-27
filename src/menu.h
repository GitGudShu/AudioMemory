#ifndef MENU_H
#define MENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <gameboard.h>

class Menu : public QWidget
{
   Q_OBJECT

 public:
    Menu(QWidget *parent = nullptr);

 private slots:
    void startGame();
    void exit();
    void setupScreen();

 private:
    QPushButton *startButton;
    QPushButton *exitButton;
    QLabel *score;
    QGridLayout *layout;
    QLabel *backgroundLabel;

   GameBoard *gameBoard; 

   // Styles
   QString buttonStyle;
   QString comboBStyle;
   QString scoreStyle;
};

#endif // WINDOW_H