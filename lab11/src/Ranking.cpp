#include "Ranking.h"
#include <algorithm>

void addPlayer(ScoreList& scores, const ScoreEntry& newScore){
    scores.push_back(newScore);
}

void printSingle(const ScoreEntry& score){
    std::cout << "Gracz: " << std::get<0>(score) << ", Wyniki: [";
    for(auto it = std::get<1>(score).begin(); it != std::get<1>(score).end(); ++it){
        if(it != std::get<1>(score).begin()) std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]\n";
}

void printAll(const ScoreList& scores){
    for(auto it = scores.begin(); it != scores.end(); ++it){
        printSingle(*it);
    }
}

const ScoreEntry* findPlayer(const ScoreList& scores, const std::string& name){
    auto found = std::find_if(scores.begin(),scores.end(),[&name](const ScoreEntry& score){
        return score.first == name;
    });
    if (found == scores.end()) return nullptr;
    return &(*found);
}

