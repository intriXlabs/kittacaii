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
    
    const int MAX_ROW = 50;
    const int MAX_COL = 210;
    
    // ============================================
    // THE ADVENTURES OF WHISKERS & FRIENDS
    // A Kitty Love Story
    // ============================================
    
    // Helper function to clear and pause
    auto clearScreen = []() {
        std::cout << "\033[2J\033[H";
    };
    
    auto pauseForEffect = [](int ms = 1500) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    };
    
    auto drawText = [](int row, int col, std::string text, std::string color = "#FFFFFF") {
        // Simple hex to ANSI conversion for text
        if (color == "#FF69B4") {
            std::cout << "\033[38;2;255;105;180m";
        } else if (color == "#87CEEB") {
            std::cout << "\033[38;2;135;206;235m";
        } else if (color == "#FFD700") {
            std::cout << "\033[38;2;255;215;0m";
        } else if (color == "#FFA500") {
            std::cout << "\033[38;2;255;165;0m";
        } else if (color == "#98FB98") {
            std::cout << "\033[38;2;152;251;152m";
        } else if (color == "#FFB6C1") {
            std::cout << "\033[38;2;255;182;193m";
        } else {
            std::cout << "\033[38;2;255;255;255m";
        }
        
        std::cout << "\033[" << row << ";" << col << "H";
        std::cout << text;
        std::cout << "\033[0m";
    };
    
    // ============================================
    // SCENE 1: THE MEETING
    // ============================================
    
    clearScreen();
    
    // Title
    drawText(2, 50, "✨ THE ADVENTURES OF WHISKERS & FRIENDS ✨", "#FFD700");
    drawText(4, 60, "Chapter 1: The Meeting", "#FF69B4");
    drawText(6, 45, "Once upon a time, in a cozy little terminal...", "#FFFFFF");
    pauseForEffect(2000);
    
    clearScreen();
    
    // Whiskers the cat appears
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 50, "happy");
    drawText(15, 40, "This is Whiskers. He's a happy little cat.", "#87CEEB");
    drawText(17, 40, "But today, Whiskers is feeling a bit lonely...", "#FFFFFF");
    pauseForEffect(2500);
    
    // Whiskers looks sad
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 50, "sad");
    drawText(15, 40, "He wishes he had a friend to play with.", "#FFFFFF");
    drawText(17, 40, "*sigh*", "#87CEEB");
    pauseForEffect(2000);
    
    // Suddenly, another cat appears!
    clearScreen();
    
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 110, "surprised");
    drawText(15, 80, "Suddenly, a new cat appears!", "#FFD700");
    drawText(17, 80, "Her name is Mittens!", "#FF69B4");
    pauseForEffect(2000);
    
    // They see each other
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 50, "shocked");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 110, "shocked");
    drawText(10, 65, "Their eyes meet across the terminal...", "#FFFFFF");
    pauseForEffect(2500);
    
    // They slowly approach each other
    for (int i = 0; i < 20; i++) {
        clearScreen();
        
        int whiskersX = 50 + i * 2;
        int mittensX = 110 - i * 2;
        
        kitty.setKittyColor("#87CEEB");
        kitty.printKitty(20, whiskersX, "confused");
        kitty.setKittyColor("#FF69B4");
        kitty.printKitty(20, mittensX, "confused");
        
        drawText(15, 60, "They slowly approach each other...", "#FFFFFF");
        
        std::cout.flush();
        pauseForEffect(200);
    }
    
    // They meet in the middle
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 75, "loveLevelOne");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 95, "loveLevelOne");
    drawText(12, 55, "And then... something magical happens!", "#FFD700");
    drawText(14, 55, "They both feel a special connection!", "#FF69B4");
    pauseForEffect(2500);
    
    // ============================================
    // SCENE 2: THE FIRST DATE
    // ============================================
    
    clearScreen();
    
    drawText(2, 60, "Chapter 2: The First Date", "#FF69B4");
    drawText(4, 50, "Whiskers asks Mittens on a date to the fish market!", "#FFFFFF");
    pauseForEffect(2000);
    
    clearScreen();
    
    // At the fish market
    for (int i = 0; i < 10; i++) {
        clearScreen();
        
        kitty.setKittyColor("#87CEEB");
        kitty.printKitty(15, 40, "excited");
        kitty.setKittyColor("#FF69B4");
        kitty.printKitty(15, 140, "excited");
        
        drawText(10, 70, "🐟 FRESH FISH MARKET 🐟", "#FFD700");
        drawText(25, 30, "Whiskers: Look at all this fish!", "#87CEEB");
        drawText(27, 110, "Mittens: It's wonderful!", "#FF69B4");
        
        // Add some fish decorations
        for (int j = 0; j < 5; j++) {
            drawText(20 + j * 2, 60 + j * 15, "🐟", "#FFA500");
        }
        
        std::cout.flush();
        pauseForEffect(500);
    }
    
    // They share a fish
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(18, 70, "loveLevelTwo");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(18, 100, "loveLevelTwo");
    drawText(12, 75, "They share a fish together.", "#FFFFFF");
    drawText(14, 75, "It's the most romantic fish ever!", "#FF69B4");
    pauseForEffect(2500);
    
    // ============================================
    // SCENE 3: THE ADVENTURE
    // ============================================
    
    clearScreen();
    
    drawText(2, 60, "Chapter 3: The Great Adventure", "#FFD700");
    drawText(4, 45, "One day, a big scary dog appears in the terminal!", "#FF0000");
    pauseForEffect(2000);
    
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 50, "shocked");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 80, "shocked");
    
    // Dog appears (using angry cat as substitute)
    kitty.setKittyColor("#8B0000");
    kitty.printKitty(20, 140, "angry");
    drawText(12, 140, "WOOF! WOOF!", "#FF0000");
    pauseForEffect(2000);
    
    // Whiskers protects Mittens
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 100, "angry");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 70, "surprised");
    kitty.setKittyColor("#8B0000");
    kitty.printKitty(20, 140, "surprised");
    
    drawText(12, 50, "Whiskers: Don't worry Mittens, I'll protect you!", "#87CEEB");
    drawText(14, 130, "*The dog is surprised by Whiskers' bravery*", "#FF0000");
    pauseForEffect(2500);
    
    // The dog runs away
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 100, "excited");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 70, "loveLevelThree");
    
    drawText(12, 50, "The dog runs away! Whiskers is a hero!", "#FFD700");
    drawText(14, 60, "Mittens: My hero!", "#FF69B4");
    pauseForEffect(2500);
    
    // ============================================
    // SCENE 4: THE PROPOSAL
    // ============================================
    
    clearScreen();
    
    drawText(2, 60, "Chapter 4: The Proposal", "#FFD700");
    drawText(4, 45, "Whiskers knows Mittens is the one...", "#FFFFFF");
    pauseForEffect(2000);
    
    clearScreen();
    
    // Romantic sunset scene
    for (int i = 0; i < 5; i++) {
        clearScreen();
        
        // Sunset colors
        for (int row = 10; row < 40; row++) {
            for (int col = 10; col < 190; col += 10) {
                if ((row + col + i) % 5 == 0) {
                    drawText(row, col, "❤️", "#FF69B4");
                } else if ((row + col + i) % 5 == 1) {
                    drawText(row, col, "💕", "#FFB6C1");
                } else if ((row + col + i) % 5 == 2) {
                    drawText(row, col, "💖", "#FF1493");
                } else if ((row + col + i) % 5 == 3) {
                    drawText(row, col, "✨", "#FFD700");
                } else {
                    drawText(row, col, "⭐", "#FFD700");
                }
            }
        }
        
        kitty.setKittyColor("#87CEEB");
        kitty.printKitty(20, 60, "loveLevelThree");
        kitty.setKittyColor("#FF69B4");
        kitty.printKitty(20, 110, "loveLevelThree");
        
        drawText(15, 75, "The terminal is filled with love...", "#FF69B4");
        
        std::cout.flush();
        pauseForEffect(1000);
    }
    
    // The proposal
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 60, "loveLevelThree");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 110, "surprised");
    
    drawText(12, 50, "Whiskers: Mittens, will you be my forever coding buddy?", "#87CEEB");
    drawText(14, 50, "*Whiskers presents a diamond ring*", "#FFD700");
    pauseForEffect(2000);
    
    // Mittens says yes!
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 110, "loveLevelThree");
    drawText(14, 90, "Mittens: YES! YES! A thousand times YES!", "#FF69B4");
    pauseForEffect(2500);
    
    // ============================================
    // SCENE 5: THE WEDDING
    // ============================================
    
    clearScreen();
    
    drawText(2, 60, "Chapter 5: The Wedding", "#FFD700");
    drawText(4, 55, "The whole terminal came to celebrate!", "#FFFFFF");
    pauseForEffect(2000);
    
    clearScreen();
    
    // Wedding scene with guests
    std::vector<std::pair<int, int>> guestPositions = {
        {15, 30}, {15, 170}, {25, 30}, {25, 170},
        {20, 20}, {20, 180}, {10, 40}, {10, 160},
        {30, 40}, {30, 160}, {35, 50}, {35, 150}
    };
    
    // Draw guests
    for (auto& pos : guestPositions) {
        kitty.setKittyColor("#98FB98");
        kitty.printKitty(pos.first, pos.second, "happy");
    }
    
    // Bride and groom
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(25, 80, "loveLevelThree");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(25, 110, "loveLevelThree");
    
    // Wedding decorations
    drawText(12, 90, "💒 WEDDING 💒", "#FFD700");
    drawText(35, 85, "💍", "#FFD700");
    drawText(20, 95, "❤️", "#FF0000");
    
    drawText(15, 60, "Dearly beloved, we are gathered here today...", "#FFFFFF");
    pauseForEffect(3000);
    
    // Vows
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 50, "loveLevelTwo");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 120, "loveLevelTwo");
    
    drawText(12, 40, "Whiskers: I promise to always debug with you,", "#87CEEB");
    drawText(14, 40, "to share my fish, and to never push to production on Fridays.", "#87CEEB");
    pauseForEffect(2000);
    
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 50, "loveLevelTwo");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 120, "loveLevelTwo");
    
    drawText(12, 40, "Mittens: I promise to always compile with you,", "#FF69B4");
    drawText(14, 40, "to share my treats, and to never merge without review.", "#FF69B4");
    pauseForEffect(2000);
    
    // You may kiss the bride
    clearScreen();
    
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(20, 70, "loveLevelThree");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(20, 100, "loveLevelThree");
    
    drawText(12, 65, "You may now kiss the bride!", "#FFD700");
    pauseForEffect(1500);
    
    // Kiss animation - they get closer
    for (int i = 0; i < 5; i++) {
        clearScreen();
        
        int whiskersX = 70 + i * 3;
        int mittensX = 100 - i * 3;
        
        kitty.setKittyColor("#87CEEB");
        kitty.printKitty(20, whiskersX, "loveLevelThree");
        kitty.setKittyColor("#FF69B4");
        kitty.printKitty(20, mittensX, "loveLevelThree");
        
        if (i < 4) {
            drawText(12, 70, "*They lean in for a kiss*", "#FF69B4");
        } else {
            drawText(12, 75, "💋", "#FF0000");
        }
        
        std::cout.flush();
        pauseForEffect(500);
    }
    
    pauseForEffect(2000);
    
    // ============================================
    // SCENE 6: HAPPILY EVER AFTER
    // ============================================
    
    clearScreen();
    
    drawText(2, 55, "And they lived happily ever after...", "#FFD700");
    pauseForEffect(2000);
    
    clearScreen();
    
    // Final scene - happy family
    kitty.setKittyColor("#87CEEB");
    kitty.printKitty(25, 60, "loveLevelOne");
    kitty.setKittyColor("#FF69B4");
    kitty.printKitty(25, 90, "loveLevelOne");
    
    // Baby kitten!
    kitty.setKittyColor("#FFB6C1");
    kitty.printKitty(25, 75, "happy");
    
    drawText(15, 55, "And they had a beautiful baby kitten...", "#FFFFFF");
    drawText(17, 55, "Little Pixel was the happiest kitten in the terminal!", "#FFB6C1");
    pauseForEffect(2500);
    
    // Family animation
    for (int i = 0; i < 3; i++) {
        clearScreen();
        
        kitty.setKittyColor("#87CEEB");
        kitty.printKitty(25, 60, "loveLevelThree");
        kitty.setKittyColor("#FF69B4");
        kitty.printKitty(25, 90, "loveLevelThree");
        kitty.setKittyColor("#FFB6C1");
        kitty.printKitty(25, 75, "excited");
        
        drawText(15, 65, "The happiest family in the whole terminal!", "#FFD700");
        
        // Add floating hearts
        for (int j = 0; j < 10; j++) {
            int heartRow = 10 + j * 2;
            int heartCol = 30 + (j * 15) % 120;
            drawText(heartRow, heartCol, "❤️", "#FF69B4");
        }
        
        std::cout.flush();
        pauseForEffect(1000);
    }
    
    // The End
    clearScreen();
    
    drawText(20, 60, "THE END", "#FFD700");
    drawText(22, 50, "Thank you for reading this kitty love story!", "#FFFFFF");
    drawText(24, 55, "Made with ❤️ and lots of 🐱", "#FF69B4");
    drawText(26, 60, "Press Enter to exit...", "#FFFFFF");
    
    // Show cursor and reset
    std::cout << "\033[?25h\033[0m";
    std::cin.get();
    
    // Final cleanup
    std::cout << "\033[2J\033[H";
    
    return 0;
}