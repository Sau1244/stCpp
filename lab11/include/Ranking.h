#pragma once

#include <iostream>
#include <vector>
#include <memory>

using ScoreEntry = std::pair<std::string, std::vector<int>>;
using ScoreList = std::vector<ScoreEntry>;

void addPlayer(ScoreList& scores, const ScoreEntry& newScore);

void printSingle(const ScoreEntry& score);

void printAll(const ScoreList& scores);

const ScoreEntry* findPlayer(const ScoreList& scores, const std::string& name);