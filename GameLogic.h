#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include <utility>

extern int boardSize;
extern std::vector<std::vector<int>> boardState;
extern int currentPlayer;

void initializeBoard(int size);
bool checkVictory(int player);
bool isGameOver(const std::vector<std::vector<int>>& board);
std::vector<std::pair<int, int>> getPossibleMoves(const std::vector<std::vector<int>>& board);
std::vector<std::vector<int>> makeMove(std::vector<std::vector<int>> board, const std::pair<int, int>& move, int player);

#endif
