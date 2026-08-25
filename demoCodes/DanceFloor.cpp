#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cstdint>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../kittacaii.cpp"

// [Kittacaii class code goes here - already included]

int main() {
    Kittacaii kitty;
    srand(time(nullptr));
    
    // Hide cursor
    std::cout << "\033[?25l";
    
    const int FLOOR_WIDTH = 80;   // Dance floor width
    const int FLOOR_HEIGHT = 30;  // Dance floor height
    const int FLOOR_START_ROW = 5;
    const int FLOOR_START_COL = 20;
    
    // Dance floor characters
    const char FLOOR_CHAR = '.';
    const char DISCO_LIGHT = 'O';
    
    // Cat positions and velocities
    struct DancingCat {
        int row, col;
        int velRow, velCol;
        int dancePhase;
        std::vector<std::string> danceMoves;
        std::vector<std::string> colors;
        bool isJumping;
        int jumpHeight;
        int currentJump;
    };
    
    std::vector<DancingCat> cats;
    
    // Initialize 15 dancing cats with random positions and dance styles
    for (int i = 0; i < 15; i++) {
        DancingCat cat;
        cat.row = FLOOR_START_ROW + rand() % (FLOOR_HEIGHT - 4);
        cat.col = FLOOR_START_COL + rand() % (FLOOR_WIDTH - 10);
        cat.velRow = (rand() % 5) - 2;  // -2 to 2
        cat.velCol = (rand() % 5) - 2;  // -2 to 2
        cat.dancePhase = rand() % 4;
        cat.isJumping = false;
        cat.jumpHeight = 0;
        cat.currentJump = 0;
        
        // Different dance moves for each cat
        if (i % 4 == 0) {
            cat.danceMoves = {"happy", "excited", "happy", "loveLevelOne"};
            cat.colors = {"#FF0000", "#00FF00", "#0000FF", "#FFFF00"};
        } else if (i % 4 == 1) {
            cat.danceMoves = {"loveLevelTwo", "loveLevelThree", "loveLevelTwo", "excited"};
            cat.colors = {"#FF69B4", "#FF1493", "#FF69B4", "#FFD700"};
        } else if (i % 4 == 2) {
            cat.danceMoves = {"surprised", "shocked", "surprised", "confused"};
            cat.colors = {"#FF4500", "#FF0000", "#FF4500", "#FFA500"};
        } else {
            cat.danceMoves = {"earTurnLeft", "earTurnRight", "happy", "excited"};
            cat.colors = {"#00FFFF", "#FF00FF", "#00FFFF", "#FF00FF"};
        }
        
        cats.push_back(cat);
    }
    
    // Add a DJ cat in the corner
    DancingCat djCat;
    djCat.row = FLOOR_START_ROW + 2;
    djCat.col = FLOOR_START_COL + FLOOR_WIDTH - 12;
    djCat.velRow = 0;
    djCat.velCol = 0;
    djCat.dancePhase = 0;
    djCat.isJumping = false;
    djCat.jumpHeight = 0;
    djCat.currentJump = 0;
    djCat.danceMoves = {"loveLevelThree", "excited", "loveLevelThree", "loveLevelThree"};
    djCat.colors = {"#FFD700", "#FFD700", "#FFD700", "#FFD700"};
    cats.push_back(djCat);
    
    int frame = 0;
    int maxFrames = 150;  // ~15 seconds of dancing
    
    while (frame < maxFrames) {
        // Clear screen using \033[J
        std::cout << "\033[2J\033[H";
        
        // Draw dance floor border
        for (int col = FLOOR_START_COL - 2; col <= FLOOR_START_COL + FLOOR_WIDTH + 2; col++) {
            std::cout << "\033[" << (FLOOR_START_ROW - 2) << ";" << col << "H";
            std::cout << "\033[38;2;255;0;255m";
            std::cout << "═";
            
            std::cout << "\033[" << (FLOOR_START_ROW + FLOOR_HEIGHT + 2) << ";" << col << "H";
            std::cout << "\033[38;2;255;0;255m";
            std::cout << "═";
        }
        
        for (int row = FLOOR_START_ROW - 2; row <= FLOOR_START_ROW + FLOOR_HEIGHT + 2; row++) {
            std::cout << "\033[" << row << ";" << (FLOOR_START_COL - 2) << "H";
            std::cout << "\033[38;2;255;0;255m";
            std::cout << "║";
            
            std::cout << "\033[" << row << ";" << (FLOOR_START_COL + FLOOR_WIDTH + 2) << "H";
            std::cout << "\033[38;2;255;0;255m";
            std::cout << "║";
        }
        
        // Draw dance floor tiles with disco pattern
        for (int row = 0; row < FLOOR_HEIGHT; row++) {
            for (int col = 0; col < FLOOR_WIDTH; col++) {
                std::cout << "\033[" << (FLOOR_START_ROW + row) << ";" << (FLOOR_START_COL + col) << "H";
                
                // Disco floor pattern
                if ((row + col + frame / 2) % 4 == 0) {
                    std::cout << "\033[38;2;100;100;100m";
                    std::cout << FLOOR_CHAR;
                } else if ((row + col + frame / 2) % 4 == 1) {
                    std::cout << "\033[38;2;150;150;150m";
                    std::cout << FLOOR_CHAR;
                } else if ((row + col + frame / 2) % 4 == 2) {
                    std::cout << "\033[38;2;200;200;200m";
                    std::cout << FLOOR_CHAR;
                } else {
                    std::cout << "\033[38;2;255;255;255m";
                    std::cout << FLOOR_CHAR;
                }
            }
        }
        
        // Draw disco lights on the edges
        for (int i = 0; i < 10; i++) {
            int lightRow = FLOOR_START_ROW - 1;
            int lightCol = FLOOR_START_COL - 1 + (i * (FLOOR_WIDTH / 10));
            
            std::cout << "\033[" << lightRow << ";" << lightCol << "H";
            
            // Cycling disco light colors
            int colorIndex = (frame / 2 + i) % 7;
            switch (colorIndex) {
                case 0: std::cout << "\033[38;2;255;0;0m"; break;
                case 1: std::cout << "\033[38;2;0;255;0m"; break;
                case 2: std::cout << "\033[38;2;0;0;255m"; break;
                case 3: std::cout << "\033[38;2;255;255;0m"; break;
                case 4: std::cout << "\033[38;2;255;0;255m"; break;
                case 5: std::cout << "\033[38;2;0;255;255m"; break;
                case 6: std::cout << "\033[38;2;255;255;255m"; break;
            }
            std::cout << DISCO_LIGHT;
            
            // Bottom disco lights
            std::cout << "\033[" << (FLOOR_START_ROW + FLOOR_HEIGHT + 1) << ";" << lightCol << "H";
            std::cout << DISCO_LIGHT;
        }
        
        // Update and draw cats
        for (auto& cat : cats) {
            // Random jumping behavior
            if (!cat.isJumping && rand() % 50 == 0) {
                cat.isJumping = true;
                cat.jumpHeight = 2 + rand() % 3;  // Jump 2-4 units up
                cat.currentJump = 0;
            }
            
            // Handle jumping
            int drawRow = cat.row;
            if (cat.isJumping) {
                cat.currentJump++;
                if (cat.currentJump < cat.jumpHeight) {
                    drawRow = cat.row - cat.currentJump;
                } else if (cat.currentJump < cat.jumpHeight * 2) {
                    drawRow = cat.row - (cat.jumpHeight * 2 - cat.currentJump);
                } else {
                    cat.isJumping = false;
                    drawRow = cat.row;
                }
            }
            
            // Move cats (if not DJ)
            if (cat.velRow != 0 || cat.velCol != 0) {
                cat.row += cat.velRow;
                cat.col += cat.velCol;
                
                // Bounce off walls
                if (cat.row < FLOOR_START_ROW) {
                    cat.row = FLOOR_START_ROW;
                    cat.velRow = abs(cat.velRow);
                }
                if (cat.row > FLOOR_START_ROW + FLOOR_HEIGHT - 4) {
                    cat.row = FLOOR_START_ROW + FLOOR_HEIGHT - 4;
                    cat.velRow = -abs(cat.velRow);
                }
                if (cat.col < FLOOR_START_COL) {
                    cat.col = FLOOR_START_COL;
                    cat.velCol = abs(cat.velCol);
                }
                if (cat.col > FLOOR_START_COL + FLOOR_WIDTH - 10) {
                    cat.col = FLOOR_START_COL + FLOOR_WIDTH - 10;
                    cat.velCol = -abs(cat.velCol);
                }
                
                // Random direction changes
                if (rand() % 20 == 0) {
                    cat.velRow = (rand() % 5) - 2;
                    cat.velCol = (rand() % 5) - 2;
                }
            }
            
            // Draw the cat
            cat.dancePhase = (cat.dancePhase + 1) % cat.danceMoves.size();
            kitty.setKittyColor(cat.colors[cat.dancePhase]);
            kitty.printKitty(drawRow, cat.col, cat.danceMoves[cat.dancePhase]);
            
            // Add jump shadow/effect
            if (cat.isJumping && cat.currentJump < cat.jumpHeight) {
                std::cout << "\033[" << (cat.row + 2) << ";" << (cat.col + 4) << "H";
                std::cout << "\033[38;2;255;255;0m";
                std::cout << "▲";
            }
        }
        
        // Draw title
        std::cout << "\033[1;" << (FLOOR_START_COL + FLOOR_WIDTH / 2 - 15) << "H";
        std::cout << "\033[38;2;255;255;255m";
        std::cout << "🎵 CAT DISCO FEVER 🎵";
        
        // Draw instructions
        std::cout << "\033[" << (FLOOR_START_ROW + FLOOR_HEIGHT + 4) << ";1H";
        std::cout << "\033[38;2;255;255;255m";
        std::cout << "Watching cats dance... they're having the time of their lives!";
        
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        frame++;
    }
    
    // Clean up
    std::cout << "\033[2J\033[H";
    std::cout << "\033[?25h\033[0m";
    std::cout << "\033[25;60H";
    std::cout << "Disco party complete! Press Enter to exit...";
    std::cin.get();
    
    return 0;
}