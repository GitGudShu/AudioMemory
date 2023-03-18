#include <QApplication>
#include <QVBoxLayout>
#include "menu.h"

Menu::Menu(QWidget *parent) :
 QWidget(parent)
 {
    // Window parameters
    setFixedSize(400, 200);
    setStyleSheet("background-color:white;");

    // Background
    background = new QLabel(this);
    background->setPixmap(QPixmap(":home.png"));
    background->setGeometry(0, 0, width(), height());
    background->setScaledContents(true);
    background->lower();
    
    // Buttons
    startButton = new QPushButton(tr("Start"), this);
    connect(startButton, &QPushButton::clicked, this, &Menu::startGame);

    exitButton = new QPushButton(tr("Exit"), this);
    connect(exitButton, &QPushButton::clicked, this, &Menu::exit);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(startButton);
    layout->addWidget(exitButton);
 }

 void Menu::startGame()
 {
    // levels here
 }

 void Menu::exit()
 {
    // exit the game
    qApp->quit();
 }