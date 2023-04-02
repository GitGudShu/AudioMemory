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
    dt[strlen(dt) - 1] = '\0'; 
    ofstream myfile;
    myfile.open("score.txt", ios::app);
    if (!myfile) { // Check if score.txt exists
        myfile.open("score.txt"); // Create score.txt if it doesn't exist
        myfile.close(); 
        myfile.open("score.txt", ios::app); 
    }
    myfile << dt << ", Difficulty: " << diff << ", Score: " << scr * diff<< endl;
    myfile.close();
}


QString Score::readScore() {
    vector<pair<double, string>> scores; // couples are easier to deal with trust me
    ifstream file("score.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string::size_type colon_pos = line.find(':');
            string::size_type score_pos = line.find("Score:");
            if (colon_pos != string::npos && score_pos != string::npos) {
                // extract the score from the line
                string score_str = line.substr(score_pos + 7); // add 7 to skip "Score: "
                int score = stoi(score_str);
                scores.push_back(make_pair((double)score, line));
            }
        }
        file.close();

        // sort scores in descending order
        sort(scores.rbegin(), scores.rend());
        for(int i=0;i<6;i++){
            cout << "Score: "<< scores[i].first << " line: "<< scores[i].second+"\n";
        }
        // get the top 5 scores
        int n = min(5, (int)scores.size());
        vector<pair<double, string>> top_scores(scores.begin(), scores.begin() + n);
        // sort the top 5 scores in descending order again
        sort(top_scores.rbegin(), top_scores.rend());
        // build a string with the top 5 scores
        QString tab;
        for (int i = 0; i < n; i++) {
            tab += QString::fromStdString(top_scores[i].second) + "\n";
        }
        return tab;
    } else {
        return "Unable to open score file.";
    }
}
