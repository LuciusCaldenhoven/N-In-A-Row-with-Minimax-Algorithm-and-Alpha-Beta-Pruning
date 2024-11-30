
#include "GameLogic.h"

int boardSize;
std::vector<std::vector<int>> boardState;
int currentPlayer = 1;

void initializeBoard(int size) {
    boardSize = size;
    boardState = std::vector<std::vector<int>>(boardSize, std::vector<int>(boardSize, 0));
}

bool checkVictory(int player) {
    for (int i = 0; i < boardSize; ++i) {
        bool rowComplete = true;
        bool colComplete = true;
        for (int j = 0; j < boardSize; ++j) {
            if (boardState[i][j] != player) rowComplete = false;
            if (boardState[j][i] != player) colComplete = false;
        }
        if (rowComplete || colComplete) return true;
    }

    bool mainDiagonalComplete = true;
    bool secondaryDiagonalComplete = true;
    for (int i = 0; i < boardSize; ++i) {
        if (boardState[i][i] != player) mainDiagonalComplete = false;
        if (boardState[i][boardSize - 1 - i] != player) secondaryDiagonalComplete = false;
    }

    return mainDiagonalComplete || secondaryDiagonalComplete;
}

bool isGameOver(const std::vector<std::vector<int>>& board) {
    if (checkVictory(1) || checkVictory(2)) return true;

    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 0) return false;
        }
    }
    return true;
}

std::vector<std::pair<int, int>> getPossibleMoves(const std::vector<std::vector<int>>& board) {
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 0) moves.emplace_back(i, j);
        }
    }
    return moves;
}

std::vector<std::vector<int>> makeMove(std::vector<std::vector<int>> board, const std::pair<int, int>& move, int player) {
    if (board[move.first][move.second] == 0) {
        board[move.first][move.second] = player;
    }
    return board;
}
