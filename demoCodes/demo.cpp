#include "../kittacaii.cpp"


int main() {
    Kittacaii kitty;
    // demonstration of animateBetweenKittiesBulk

    kitty.animateKittiesBulk({
        {5, 10, {"staticKitty", "staticKittyHappy"}, {"#ffffff", "#ffffff"}, 500, 300},
        {5, 30, {"staticKitty", "staticKittySad"}, {"#ff9f9f", "#ff9f9f"}, 500, 300},
        {5, 50, {"staticKitty", "staticKittySurprised"}, {"#ffd498", "#ffd498"}, 500, 300},
        {5, 70, {"staticKitty", "angry"}, {"#fffd91", "#fffd91"}, 500, 300}, 
        {5, 90, {"staticKitty", "excited"}, {"#c3ffa9", "#c3ffa9"}, 500, 300},
        {5, 110, {"staticKitty", "staticKittyConfused"}, {"#a5ffbd", "#a5ffbd"}, 500, 300},
        {5, 130, {"staticKitty", "sleepy"}, {"#a8ffd8", "#a8ffd8"}, 500, 300},
        {5, 150, {"staticKitty", "staticKittyLoveLevelOne"}, {"#a1f4ff", "#a1f4ff"}, 500, 300},
        {10, 10, {"staticKitty", "staticKittyLoveLevelTwo"}, {"#afe3ff", "#afe3ff"}, 500, 300},
        {10, 30, {"staticKitty", "staticKittyLoveLevelThree"}, {"#afc3ff", "#afc3ff"}, 500, 300},
        {10, 50, {"staticKitty", "staticKittyEarTurnLeft"}, {"#c6a1ff", "#c6a1ff"}, 500, 300},
        {10, 70, {"staticKitty", "staticKittyEarTurnRight"}, {"#ff96ee", "#ff96ee"}, 500, 300},
        {10, 90, {"staticKitty", "staticKittyHappy"}, {"#ff9bc3", "#ff9bc3"}, 500, 300},
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
    
    return 0;
}