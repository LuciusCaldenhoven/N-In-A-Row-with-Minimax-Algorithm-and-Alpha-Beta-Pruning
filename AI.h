#ifndef AI_H
#define AI_H

#include <vector>
#include <utility>

std::pair<int, int> findBestMove(std::vector<std::vector<int>>& board, int player);
int minimaxAlphaBeta(std::vector<std::vector<int>> board, int depth, int alpha, int beta, bool isMaximizing);
int evaluateBoard(const std::vector<std::vector<int>>& board, int player);

#endif
