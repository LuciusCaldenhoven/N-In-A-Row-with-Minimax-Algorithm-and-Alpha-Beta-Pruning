# N-In-A-Row-with-Minimax-Algorithm-and-Alpha-Beta-Pruning

## Overview
**N-In-A-Row** is an advanced AI-driven board game implementation, extending traditional Tic-Tac-Toe to a customizable board size. The game incorporates the **Minimax algorithm** with **Alpha-Beta Pruning** for optimal decision-making, enabling competitive gameplay against a computer opponent.

This project explores:
- **Heuristic evaluation functions** to determine the board state.
- **Game tree traversal** using the Minimax algorithm.
- **Alpha-Beta Pruning** to improve computational efficiency.
- A **graphical interface** built with OpenGL and GLFW for user interaction.

---

## Features
- **Customizable Board Size**: Play with a board of any NxN size.
- **AI Implementation**: The AI player uses the Minimax algorithm with Alpha-Beta Pruning.
- **Heuristic Evaluation**: Calculates the board's fitness to make strategic moves.
- **Human vs AI Gameplay**: Interact with the game via mouse clicks.
- **Graphical Rendering**: The game board, moves (circle and X), and results are visually displayed using OpenGL.
- **Draw Detection**: Handles tie cases when no further moves are possible.

---

## Algorithmic Highlights

### Minimax Algorithm
- Explores all possible moves recursively to evaluate the best possible outcome for the AI.
- Supports both maximizing and minimizing strategies:
  - **Maximizing Player**: AI's turn to maximize its advantage.
  - **Minimizing Player**: Opponent's turn to minimize the AI's score.

### Alpha-Beta Pruning
- Enhances the Minimax algorithm by pruning branches that do not affect the outcome.
- Reduces computational complexity significantly, enabling larger board sizes.

### Heuristic Evaluation Function
The heuristic evaluates the current board state using:
- **Row and Column Analysis**: Counts consecutive pieces for both players in rows and columns.
- **Diagonal Analysis**: Evaluates the primary and secondary diagonals.
- **Exponential Weighting**: Rewards longer chains of the player's pieces while penalizing opponent chains.
