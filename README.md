# **Audio Memory Game**

This is a simple audio memory game written in C++ using the Qt framework. The game presents a grid of cards with audio on one side. The player must click on two cards at a time to reveal their audios. If the audios match, the cards are removed from the board. The game ends when all pairs have been found.

## **Getting started**

To build and run the game, follow these steps:

1. Install the Qt framework on your system, if it is not already installed. You can download the latest version of Qt from the official website: https://www.qt.io/download.

2. Clone the repository to your local machine:

```bash
git clone https://github.com/GitGudShu/AudioMemory.git
```

3. Open a terminal or command prompt and navigate to the project directory.

4. If you don't have the qt mutlimedia module:

```bash
sudo apt update
sudo apt-get install qtmultimedia5-dev
```

5. Run the following commands to build the project

```bash
qmake
make
```

6. Once the project has been built, you can launch the game by running the following command:

```bash
./memoryaudio
```

This will start the game and display the main menu.

## **Features**

Our goal for this game are the following features:

- Multiple difficulty levels (easy, medium, hard)
- Audio effects when cards are flipped and matched
- Score tracking and display
- Timer to track game duration
- Main menu with options to start a new game or exit

## **Credits**

This game was developed by [Aurélien Guillou](https://github.com/aurelienGUILLOU) and [Thomas Chu](https://github.com/GitGudShu) as a project for our S4C1 C++/QT class.
