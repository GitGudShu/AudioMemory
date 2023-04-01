
#include <QtWidgets>
#include <QString>
#include <QMediaPlayer>

#include "score.h"
#include "menu.h"

QMediaPlayer *player = new QMediaPlayer();

Menu::Menu(QWidget *parent) :
 QWidget(parent)
 {
  setupScreen();
 }

 void Menu::setupScreen()
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
   
   // Styles
   buttonStyle = "font-size: 30px; font-family: Verdana; padding: 10px; border:4px solid #ffd700; border-radius:10px; background-color:#234e98; color:white; font-weight:bold;";
   comboBStyle = "QComboBox { font-size: 30px; padding: 10px; border: 4px solid #ffd700; border-radius: 10px; background-color: #234e98; color: white; font-weight: bold; }"
                     "QComboBox QAbstractItemView { font-size: 30px; border:4px solid #ffd700; background-color: #234e98; color: white; selection-background-color: #ffd700; }";
   scoreStyle = "font-size: 25px; font-family: Verdana; padding: 2px; border:6px solid #ffd700; border-radius:10px; background-color:#234e98; color:white; font-weight:bold;";
    
   // Buttons
   startButton = new QPushButton(tr("START"), this);
   startButton->setMinimumHeight(40);
   startButton->setStyleSheet(buttonStyle);
   startButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   connect(startButton, &QPushButton::clicked, this, &Menu::startGame);

   exitButton = new QPushButton(tr("EXIT"), this);
   exitButton->setMinimumHeight(40);
   exitButton->setStyleSheet(buttonStyle);
   exitButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   connect(exitButton, &QPushButton::clicked, this, &Menu::exit);

   // Create and set the score box
   scores = new QLabel(this);
   QString tab = "Le score sera ici granted Aurélien make it work ;)";
   score = new Score();
   //score->readScore(tab);
   scores->setText(tab);
   scores->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

   // Set the button size
  int buttonWidth = width * 0.2;  // 20% of window width
  int buttonHeight = height * 0.1;  // 10% of window height
  startButton->setFixedSize(buttonWidth, buttonHeight);
  exitButton->setFixedSize(buttonWidth, buttonHeight);

  // Create the level selection combo box
  QComboBox *levelComboBox = new QComboBox(this);
  levelComboBox->setFixedSize(buttonWidth, buttonHeight);
  levelComboBox->setStyleSheet(comboBStyle);
  levelComboBox->addItem("Level 1");
  levelComboBox->addItem("Level 2");
  levelComboBox->addItem("Level 3");
  connect(levelComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Menu::changeDifficulty);
  
  layout = new QGridLayout(this);
  layout->addWidget(scores, 1, 0, 2, 1, Qt::AlignHCenter | Qt::AlignVCenter);
  layout->addWidget(startButton, 1, 1, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
  layout->addWidget(levelComboBox, 2, 1, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
  layout->addWidget(exitButton, 3, 1, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
  layout->setContentsMargins(1, 1, 1, 1);

  layout->setAlignment(Qt::AlignCenter);
  layout->setHorizontalSpacing(width * 0.25); // 5% of window width
  layout->setVerticalSpacing(width * 0.025); // 5% of window height
 }

 void Menu::changeDifficulty(int selected){
   difficultyLevel = selected+1;
 }

  void Menu::startGame()
 {
    gameBoard = new GameBoard(nullptr,difficultyLevel);
    gameBoard->show();
    this->hide();
    connect(gameBoard, &GameBoard::backToMenu, this, &Menu::showMenu);
 }

 void Menu::exit()
 {
   // exit the game
   qApp->quit();
 }

 void Menu::showMenu()
{
    this->show();
    gameBoard->hide();
}