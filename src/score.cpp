#include "score.h"
#include <QString>
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

void Score::writeScore(QString difficulty, QString score) {
    int diff = difficulty.toInt();
    int scr = score.toInt();

    time_t now = time(0);
    char* dt = ctime(&now);
    ofstream myfile;
    myfile.open("score.txt", ios::app);
    if (!myfile) { // Check if score.txt exists
        myfile.open("score.txt"); // Create score.txt if it doesn't exist
        myfile.close(); 
        myfile.open("score.txt", ios::app); 
    }
    myfile << dt << "Difficulty: " << diff << ", Score: " << scr << endl;
    myfile.close();
}

QString Score::readScore() { 
    vector<pair<double, string>> scores; // couples are easier to deal with trust me
    ifstream file("score.txt"); 
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string::size_type colon_pos = line.find(':');
            string::size_type comma_pos = line.find(',');
            if (colon_pos != string::npos && comma_pos != string::npos) {
                // extract the difficulty and score from the line
                string diff_str = line.substr(colon_pos + 2, comma_pos - colon_pos - 2);
                string score_str = line.substr(line.find(':', comma_pos) + 2);
                int diff = stoi(diff_str);
                int score = stoi(score_str);
                if (diff != 0) {
                    double ratio = (double)score / diff;
                    scores.push_back(make_pair(ratio, line));
                }
            }
        }
        file.close(); 
    }
    sort(scores.rbegin(), scores.rend()); 
    int n = min(5, (int)scores.size()); // only display the top 5 scores
    QString tab;
    for (int i = 0; i < n; i++) {
        tab += QString::fromStdString(scores[i].second) + "\n";
    }
    return tab;
}
