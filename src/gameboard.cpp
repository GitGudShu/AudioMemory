#include "gameboard.h"

#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QGridLayout>
#include <QRandomGenerator>
#include <algorithm>

GameBoard::GameBoard(QWidget *parent) : QWidget(parent)
{
   // Window parameters
   setWindowTitle("FGO Audio Memory");
   QRect screenGeometry = QApplication::desktop()->screenGeometry();
   int width = screenGeometry.width() * 0.75;  // 75% of screen width
   int height = screenGeometry.height() * 0.75;  // 75% of screen height
   setFixedSize(width, height);

	setupBackground(width, height);

   // Create the layout for the cards
   QGridLayout *cardLayout = new QGridLayout(this);
   cardLayout->setSpacing(20); // Add some spacing between the cards

   QString *audioPath = QCoreApplication::applicationDirPath() + "/../assets/audio/";

   for (int i = 0; i < 6; i++) {
      QLabel *cardLabel = new QLabel(this);
      cardLabel->setFixedSize(width * 0.15, height * 0.25);
      QPixmap cardImage(":/assets/image/gold.jpg");
      if (cardImage.isNull()) {
         qDebug() << "Error: failed to load card image";
      } else {
         qDebug() << "Card image loaded successfully";
      }
      cardLabel->setPixmap(cardImage);
      cardLabel->setScaledContents(true);

      int row = i / 3; 
      int col = i % 3; 
      cardLayout->addWidget(cardLabel, row, col, Qt::AlignCenter);
   }

   // Shuffle the cards randomly
   std::shuffle(cardLabels.begin(), cardLabels.end(), QRandomGenerator::global());

   // Add some spaces on the edges
   int verticalSpace = height * 0.1;
   int horizontalSpace = width * 0.2;
   cardLayout->setContentsMargins(horizontalSpace, verticalSpace, horizontalSpace, verticalSpace);

   // Set the layout for the game board
   setLayout(cardLayout);
}

void GameBoard::setupBackground(int width, int height)
{
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
}
