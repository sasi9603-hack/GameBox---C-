#include "scores.h"
#include <iostream>
#include <vector>

using namespace std;

// Store all game records across the session
vector<GameRecord> gameHistory;

void recordGame(const GameRecord& record) {
    gameHistory.push_back(record);
}

void viewLeaderboard() {
    cout << "\n--- Leaderboard ---\n";
    cout << "(Leaderboard implementation pending by Member 5)\n";
}

void viewGameHistory() {
    cout << "\n--- Game History ---\n";
    if (gameHistory.empty()) {
        cout << "No games have been played yet.\n";
        return;
    }
    
    for (size_t i = 0; i < gameHistory.size(); ++i) {
        cout << i + 1 << ". " << gameHistory[i].playerName 
             << " played " << gameHistory[i].gameName 
             << " | Result: " << gameHistory[i].result 
             << " | Score: " << gameHistory[i].score << "\n";
    }
}
