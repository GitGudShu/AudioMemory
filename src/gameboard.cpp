#include "gameboard.h"
#include <array>
#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QGridLayout>
#include <QRandomGenerator>
#include <algorithm>


GameBoard::GameBoard(QWidget *parent) : QWidget(parent)
{
   // Setup audio player
   player = new QMediaPlayer(this);
   clickedButton = nullptr;

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

   QString audioPath = QCoreApplication::applicationDirPath() + "/../assets/audio/";

   QStringList cardAudios = { audioPath + "artoria.mp3",
                              audioPath + "artoria.mp3",
                              audioPath + "voyager.mp3",
                              audioPath + "voyager.mp3",
                              audioPath + "jalter.mp3",
                              audioPath + "jalter.mp3"};

   displayCardAudios(cardAudios);

   // Shuffle the cards randomly
   QRandomGenerator generator(QTime::currentTime().msec());
   std::shuffle(cardAudios.begin(), cardAudios.end(), generator);

   displayCardAudios(cardAudios);

   QList<QPushButton*> cardButtons;

   for (int i = 0; i < 6; i++) {
      QPushButton *cardButton = new QPushButton(this);
      cardButton->setFixedSize(width * 0.15, height * 0.25);
      QPixmap cardImage(":/assets/image/gold.jpg");
      if (cardImage.isNull()) {
         qDebug() << "Error: failed to load card image";
      } else {
         qDebug() << "Card image loaded successfully";
      }
      cardButton->setIcon(QIcon(cardImage));
      cardButton->setIconSize(cardButton->size());
      cardButton->setFlat(true);

      cardButtons.append(cardButton);
      
      // Connect the card's clicked signal to the slot that checks for matches
      connect(cardButton, &QPushButton::clicked, this, [this, audio = cardAudios[i], buttonSelected = cardButton](){
         emit buttonClicked(true, audio, buttonSelected);
      });
   }

   std::shuffle(cardButtons.begin(), cardButtons.end(), generator);

   // Play the correct audio when clicked
   connect(this, SIGNAL(buttonClicked(bool, QString)),this,SLOT(buttonAudio(bool,QString)));

   // Add the shuffled cards to the layout
   for (int i = 0; i < 6; i++) {
      int row = i / 3; 
      int col = i % 3; 
      cardLayout->addWidget(cardButtons[i], row, col, Qt::AlignCenter);
      
      // TODO
      // Connect the card's clicked signal to the slot that checks for matches
      //checkForMatch(cardButtons[i], i););
   }

   timerBar = new QProgressBar(this);
   timerBar->setRange(0, 100); // Set the range of the progress bar to 0-100
   timerBar->setValue(0); // Set the initial value of the progress bar to 0
   cardLayout->addWidget(timerBar, 3, 0, 1, 3); // Add the progress bar to the layout

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

void GameBoard::playAudio(QString audioPath)
{
    // Load and play the audio file
  QString audioFilePath = audioPath;
  QUrl audioFileUrl = QUrl::fromLocalFile(audioFilePath);
  if (QFile::exists(audioFilePath)) {
      qDebug() << "Audio file found at:" << audioFilePath;
      player->setMedia(audioFileUrl);
      player->setVolume(5); // set initial volume
      player->play();
      if (player->error() != QMediaPlayer::NoError) {
          qDebug() << "Error: " << player->errorString();
      }
  } else {
      qDebug() << "Error: audio file not found at:" << audioFilePath;
  }
}

QList<QPushButton*> selectedButton;
QList<QPushButton*> winnedButton;

void GameBoard::buttonAudio(bool click, QString audioPath, QPushButton *button){
   selectedButton.append(button);
   button->setEnabled(false);
    if(click){
      playAudio(audioPath);
      if(clickedButton == nullptr){
         clickedButton = audioPath;
      }
      else{
         if(clickedButton == audioPath){
            qDebug() << "GG WELL PLAYED";
            for(int i=0;i<2;i++){
               winnedButton.append(selectedButton[i]);
            }
            if(sizeof(winnedButton)/sizeof(winnedButton[0]) == 6){
               qDebug() << "YOU WIN GG BROOOOO";
            }
         }
         else{
            qDebug() << "yorokobe shonen";
            for(int i=0;i<2;i++){
               selectedButton[i]->setEnabled(true);
            }
            // for button in list : setEnable(true)
         }
         clickedButton = nullptr;
      }
    }
}

void GameBoard::displayCardAudios(QStringList cardAudios) {
    qDebug() << "Card Audios:";
    for (const auto& audio : cardAudios) {
        qDebug() << audio;
    }
}