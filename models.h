#ifndef MODELS_H
#define MODELS_H
#include <string>

// Shared data structures used across the whole GameBox project
struct GameRecord {
    std::string gameName;
    std::string playerName;
    int score;
    std::string result; // e.g., "Win", "Loss", "Draw"
};

struct Player {
    std::string name;
    int totalScore;
};

#endif
