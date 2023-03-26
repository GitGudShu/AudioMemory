#include "level.h"
#include <QApplication>
#include <QtWidgets>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaMetaData>

Level::Level(QWidget *parent, int numCards) : QWidget(parent), m_numCards(numCards)
{
    // Set up user interface
    m_mainLayout = new QVBoxLayout(this);
    m_gridLayout = new QGridLayout();
    m_mainLayout->addLayout(m_gridLayout);

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
}
