#include "gameboard.h"
#include <array>
#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QGridLayout>
#include <QRandomGenerator>
#include <algorithm>


GameBoard::GameBoard(QWidget *parent, int difficultyLevel) : QWidget(parent)
{
   // Setup audio player
   player = new QMediaPlayer(this);
   clickedButton = nullptr;
   cardNumber = 6*difficultyLevel;
   difficulty = QString::number(difficultyLevel);
   count = 0;

   // Window parameters
   setWindowTitle("FGO Audio Memory");
   QRect screenGeometry = QApplication::desktop()->screenGeometry();
   int width = screenGeometry.width() * 0.75;  // 75% of screen width
   int height = screenGeometry.height() * 0.75;  // 75% of screen height
   setFixedSize(width, height);

	setupBackground(width, height);

   // Create the layout for the cards
   QGridLayout *cardLayout = new QGridLayout(this);

   // Add some spacing between the cards
   if (difficultyLevel == 1){
      cardLayout->setSpacing(20); 
   }else if (difficultyLevel == 2){
      cardLayout->setSpacing(5);
      cardLayout->setVerticalSpacing(5);
   }else{ 
      cardLayout->setSpacing(3);
      cardLayout->setVerticalSpacing(5);
   }

   QString audioPath = QCoreApplication::applicationDirPath() + "/../assets/audio/";

   QStringList audioFiles;
   QDir audioDir(audioPath); // assuming audioPath is the path to your audio directory
   audioDir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
   audioFiles = audioDir.entryList();

   QStringList cardAudios;
   for (const QString& audioFile : audioFiles) {
      QString filePath = audioPath + audioFile;
      cardAudios << filePath ;
   }

   // Shuffle the cards randomly
   QRandomGenerator generator(QTime::currentTime().msec());
   std::shuffle(cardAudios.begin(), cardAudios.end(), generator);

   QList<QPushButton*> cardButtons;

   for (int i = 0; i < cardNumber/2; i++) {
      for (int j = 0; j < 2; j++) {
         QPushButton *cardButton = new QPushButton(this);
         QPixmap cardImage;

         if (difficultyLevel == 1){
            cardButton->setFixedSize(width * 0.15, height * 0.25);
            cardImage = QPixmap(":/assets/image/bronze.jpeg");
         }else if (difficultyLevel == 2){
            cardButton->setFixedSize(width * 0.1, height * 0.2);
            cardImage = QPixmap(":/assets/image/silver.jpeg");
         }else{ 
            cardButton->setFixedSize(width * 0.1, height * 0.18);
            cardImage = QPixmap(":/assets/image/gold.jpg");
         }

         if (cardImage.isNull()) 
            qDebug() << "Error: failed to load card image";
         else 
            qDebug() << "Card image loaded successfully";

         cardButton->setIcon(QIcon(cardImage));
         cardButton->setIconSize(cardButton->size());
         cardButton->setFlat(true);

         cardButtons.append(cardButton);
         
         // Connect the card's clicked signal to the slot that checks for matches
         connect(cardButton, &QPushButton::clicked, this, [this, audio = cardAudios[i], buttonSelected = cardButton](){
            emit buttonClicked(true, audio, buttonSelected);
         });
      }
   }

   std::shuffle(cardButtons.begin(), cardButtons.end(), generator);

   // Play the correct audio when clicked
   connect(this, SIGNAL(buttonClicked(bool, QString, QPushButton*)),this,SLOT(buttonAudio(bool,QString, QPushButton*)));

   // Add the shuffled cards to the layout
   if (difficultyLevel == 1) {
      for (int i = 0; i < cardNumber; i++) {
         int row = i / 3;
         int col = i % 3;
         cardLayout->addWidget(cardButtons[i], row, col, Qt::AlignCenter);
      }
   } else if (difficultyLevel == 2) {
      for (int i = 0; i < cardNumber; i++) {
         int row = i / 4;
         int col = i % 4;
         cardLayout->addWidget(cardButtons[i], row, col, Qt::AlignCenter);
      }
   } else {
      for (int i = 0; i < cardNumber; i++) {
         int row = i / 6;
         int col = i % 6;
         cardLayout->addWidget(cardButtons[i], row, col, Qt::AlignCenter);
      }
   }

   // Setup a timer
   timer = new QTimer(this);
   connect(timer, &QTimer::timeout, this, &GameBoard::updateTimerBar);
   timer->start(1000); 

   timerBar = new QProgressBar(this);
   timerBar->setRange(0, 100); // Set the range of the progress bar to 0-100
   timerBar->setValue(0); // Set the initial value of the progress bar to 0
   // Add the progress bar to the layout
   if(difficultyLevel == 1){
      cardLayout->addWidget(timerBar, 3, 0, 1, 3);
   }
   else if(difficultyLevel == 2){
      cardLayout->addWidget(timerBar, 3, 0, 1, 4);
   }
   else{
      cardLayout->addWidget(timerBar, 3, 0, 1, 6);
   }

   // Add some spaces on the edges
   int verticalSpace;
   int horizontalSpace;
   if(difficultyLevel == 1){
      verticalSpace = height * 0.1;
      horizontalSpace = width * 0.2;
   }
   else if(difficultyLevel == 2){
      verticalSpace = height * 0.15;
      horizontalSpace = width * 0.2;
   }
   else{
      verticalSpace = height * 0.15;
      horizontalSpace = width * 0.2;
   }
   
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

void GameBoard::checkForWin(QString audioPath, QPushButton *button){
   button->setEnabled(false);
   if(clickedButton == nullptr){
      clickedButton = audioPath;
   }
   else{
      if(clickedButton == audioPath){
         for(int i=0;i<2;i++){
            winnedButton.append(selectedButton[i]);
            count++;
         }
         if(count == cardNumber){
            win = true;
            displayWinMessageBox();
         }
      }
      else{
         for(int i=0;i<2;i++){
            selectedButton[i]->setEnabled(true);
            QPixmap cardImage;
            if(difficulty == "1"){
               cardImage = QPixmap(":/assets/image/bronze.jpeg");
            }
            else if(difficulty == "2"){
               cardImage = QPixmap(":/assets/image/silver.jpeg");
            }
            else{
               cardImage = QPixmap(":/assets/image/gold.jpg");
            }
            selectedButton[i]->setIcon(QIcon(cardImage));
         }
      }
      clickedButton = nullptr;
      selectedButton.clear();
   }
}

void GameBoard::buttonAudio(bool click, QString audioPath, QPushButton *button){
   selectedButton.append(button);
   QPixmap cardImage(":/assets/image/front.jpeg");
   button->setIcon(QIcon(cardImage));
    if(click){
      playAudio(audioPath);
      checkForWin(audioPath, button);
    }
}

void GameBoard::displayBox(QString mess){
   // create a message box
   QMessageBox messageBox;
    messageBox.setText(mess);
    messageBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
    messageBox.setDefaultButton(QMessageBox::Retry);
    int ret = messageBox.exec();
    if (ret == QMessageBox::Retry) {
        emit retryGame();
    } else {
        emit backToMenu();
    }
}

void GameBoard::displayWinMessageBox(){
   // create a message box when win is achieved
   QString mess = "Congratulations! You have won the game!";
   displayBox(mess);
}

void GameBoard::displayTimeUpMessageBox(){
   // create a message if the time is up
   QString mess = "You have run out of time";
   displayBox(mess);
}