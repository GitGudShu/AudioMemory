#include <QApplication>
#include <QVBoxLayout>
#include <QtWidgets>
#include "menu.h"

Menu::Menu(QWidget *parent) :
 QWidget(parent)
 {
   // Window parameters
   setFixedSize(400, 200);
   //setStyleSheet("background-color:black;");
   setWindowTitle("FGO Audio Memory");

   // run some tests
   QFile file(":/assets/image/home.png");
   if (file.exists()) {
      qDebug() << "Image file loaded successfully from .qrc file";
   } else {
      qDebug() << "Error: image file not found in .qrc file";
   }

   // Background image
   QPixmap bkgnd(":/assets/image/home.png");
   if (bkgnd.isNull()) {
      qDebug() << "Error: failed to load background image";
   } else {
      qDebug() << "Background image loaded successfully";
      bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);
      setPalette(palette);
   }
   
    
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