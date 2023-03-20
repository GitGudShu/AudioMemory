#include <QApplication>
#include <QtWidgets>
#include <QSoundEffect>
#include "menu.h"

Menu::Menu(QWidget *parent) :
 QWidget(parent)
 {
   // Window parameters
   setWindowTitle("FGO Audio Memory");
   QRect screenGeometry = QApplication::desktop()->screenGeometry();
   int width = screenGeometry.width() * 0.75;  // 75% of screen width
   int height = screenGeometry.height() * 0.75;  // 75% of screen height
   setFixedSize(width, height);

   // Background image
   QPixmap bkgnd(":/assets/image/home.jpeg");
   if (bkgnd.isNull()) {
      qDebug() << "Error: failed to load background image";
   } else {
      qDebug() << "Background image loaded successfully";
      bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
      backgroundLabel = new QLabel(this);
      backgroundLabel->setPixmap(bkgnd);
      backgroundLabel->setAlignment(Qt::AlignCenter);
      backgroundLabel->setGeometry(0, 0, width, height);
   }
   
    
   // Buttons
   startButton = new QPushButton(tr("START"), this);
   startButton->setMinimumHeight(40);
   startButton->setStyleSheet("font-size: 30px; font-family: Arial; padding: 10px; border:4px solid blue; border-radius:10px; background-color:#F2F3F4; color:blue; font-weight:bold;");
   startButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   connect(startButton, &QPushButton::clicked, this, &Menu::startGame);

   exitButton = new QPushButton(tr("EXIT"), this);
   exitButton->setMinimumHeight(40);
   exitButton->setStyleSheet("font-size: 30px; font-family: Arial; padding: 10px; border:4px solid blue; border-radius:10px; background-color:#F2F3F4; color:blue; font-weight:bold;");
   exitButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   connect(exitButton, &QPushButton::clicked, this, &Menu::exit);

   // Set the button size
   int buttonWidth = width * 0.2;  // 20% of window width
   int buttonHeight = height * 0.1;  // 10% of window height
   startButton->setFixedSize(buttonWidth, buttonHeight);
   exitButton->setFixedSize(buttonWidth, buttonHeight);

   score = new QLabel(this);

   layout = new QGridLayout(this);
   layout->addWidget(score, 0, 0, 0, 1, Qt::AlignHCenter | Qt::AlignVCenter);
   layout->addWidget(startButton, 0, 1, Qt::AlignHCenter | Qt::AlignVCenter);
   layout->addWidget(exitButton, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
   layout->setContentsMargins(0, 0, 0, 0);
 }

 void Menu::startGame()
 {
   // levels here
   QMediaPlayer *player = new QMediaPlayer;   
   player->setMedia(QUrl::fromLocalFile("../assets/audio/artoria.mp3"));
   player->play();
 }

 void Menu::exit()
 {
   // exit the game
   qApp->quit();
 }