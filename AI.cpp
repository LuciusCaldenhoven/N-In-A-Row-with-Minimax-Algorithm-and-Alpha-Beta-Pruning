#include "AI.h"
#include "GameLogic.h"
#include <limits>
#include <cmath>

std::pair<int, int> findBestMove(std::vector<std::vector<int>>& board, int player) {
    int bestScore = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};

    auto possibleMoves = getPossibleMoves(board);
    for (const auto& move : possibleMoves) {
        auto tempBoard = makeMove(board, move, player);
        int score = minimaxAlphaBeta(tempBoard, 5, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    return bestMove;
}

int minimaxAlphaBeta(std::vector<std::vector<int>> board, int depth, int alpha, int beta, bool isMaximizing) {
    if (depth == 0 || isGameOver(board)) {
        return evaluateBoard(board, currentPlayer);
    }

    if (isMaximizing) {
        int maxEval = std::numeric_limits<int>::min();
        for (auto& move : getPossibleMoves(board)) {
            auto newBoard = makeMove(board, move, 1);
            int eval = minimaxAlphaBeta(newBoard, depth - 1, alpha, beta, false);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) break;
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (auto& move : getPossibleMoves(board)) {
            auto newBoard = makeMove(board, move, 2);
            int eval = minimaxAlphaBeta(newBoard, depth - 1, alpha, beta, true);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}

int evaluateBoard(const std::vector<std::vector<int>>& board, int player) {
    int score = 0;
    for (int i = 0; i < boardSize; ++i) {
        std::vector<int> row(boardSize);
        std::vector<int> col(boardSize);
        for (int j = 0; j < boardSize; ++j) {
            row[j] = board[i][j];
            col[j] = board[j][i];
        }
        score += evaluateLine(row, player);
        score += evaluateLine(col, player);
    }

    return score;
}
