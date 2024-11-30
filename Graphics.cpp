#include "Graphics.h"
#include "GameLogic.h"
#include <GLFW/glfw3.h>

void setupGraphics() {
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void drawGame() {
    float cellSize = 1.8f / boardSize;
    float margin = (2.0f - 1.8f) / 2.0f;

    glBegin(GL_LINES);
    for (int i = 1; i < boardSize; ++i) {
        float linePos = -1.0f + margin + i * cellSize;
        glVertex2f(linePos, -1.0f + margin);
        glVertex2f(linePos, 1.0f - margin);
        glVertex2f(-1.0f + margin, linePos);
        glVertex2f(1.0f - margin, linePos);
    }
    glEnd();

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            float x = -1.0f + margin + i * cellSize + cellSize / 2;
            float y = 1.0f - margin - j * cellSize - cellSize / 2;
            if (boardState[j][i] == 1) {
                drawCircle(x, y, cellSize / 4);
            } else if (boardState[j][i] == 2) {
                drawX(x, y, cellSize / 4);
            }
        }
    }
}

void drawCircle(float x, float y, float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(x + cos(degInRad) * radius, y + sin(degInRad) * radius);
    }
    glEnd();
}

void drawX(float x, float y, float size) {
    glBegin(GL_LINES);
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glVertex2f(x + size, y - size);
    glEnd();
}
