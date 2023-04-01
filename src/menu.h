#ifndef MENU_H
#define MENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <gameboard.h>
#include <score.h>

class Menu : public QWidget
{
   Q_OBJECT

 public:
    Menu(QWidget *parent = nullptr);

 private slots:
    void startGame();
    void exit();
    void setupScreen();
    void changeDifficulty(int);
    void showMenu();

 private:
    QPushButton *startButton;
    QPushButton *exitButton;
    QLabel *scores;
    QGridLayout *layout;
    QLabel *backgroundLabel;

   GameBoard *gameBoard; 
   Score *score;

   // Styles
   QString buttonStyle;
   QString comboBStyle;
   QString scoreStyle;
   int difficultyLevel = 1;
};

#endif // WINDOW_H