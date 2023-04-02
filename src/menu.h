#ifndef MENU_H
#define MENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
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
    void retryGame();

 private:
    QPushButton *startButton;
    QPushButton *exitButton;
    QComboBox *levelComboBox;
    QLabel *scores;
    QLabel *title;
    QGridLayout *layout;
    QLabel *backgroundLabel;
    int difficultyLevel = 1;

   GameBoard *gameBoard; 
   Score *score;

   // Styles
   QString buttonStyle;
   QString comboBStyle;
   QString scoreStyle;
   QString titleStyle;
};

#endif // WINDOW_H