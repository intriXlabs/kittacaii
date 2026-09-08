#include "../kittacaii.cpp"


int main() {
    Kittacaii kitty;
    // demonstration of animateBetweenKittiesBulk

    kitty.animateKittiesBulk({

        // older - 2
        {5, 10, {"staticKitty", "staticKittyHappy"}, {"#ff4d6d", "#ff4d6d"}, 500, 300},
        {5, 30, {"staticKitty", "staticKittySad"}, {"#ff4d6d", "#ff4d6d"}, 500, 300},
        {5, 50, {"staticKitty", "staticKittySurprised"}, {"#ff922b", "#ff922b"}, 500, 300},
        {5, 70, {"staticKitty", "angry"}, {"#ff922b", "#ff922b"}, 500, 300}, 
        {5, 90, {"staticKitty", "excited"}, {"#ffd43b", "#ffd43b"}, 500, 300},

        {5, 110, {"staticKitty", "staticKittyConfused"}, {"#ffd43b", "#ffd43b"}, 500, 300},
        {5, 130, {"staticKitty", "sleepy"}, {"#a9e34b", "#a9e34b"}, 500, 300},
        {5, 150, {"staticKitty", "staticKittyLoveLevelOne"}, {"#a9e34b", "#a9e34b"}, 500, 300},
        {10, 10, {"staticKitty", "staticKittyLoveLevelTwo"}, {"#69db7c", "#69db7c"}, 500, 300},
        {10, 30, {"staticKitty", "staticKittyLoveLevelThree"}, {"#69db7c", "#69db7c"}, 500, 300},

        {10, 50, {"staticKitty", "staticKittyEarTurnLeft"}, {"#38d9a9", "#38d9a9"}, 500, 300},
        {10, 70, {"staticKitty", "staticKittyEarTurnRight"}, {"#38d9a9", "#38d9a9"}, 500, 300},
        {10, 90, {"staticKitty", "money"}, {"#3bc9db", "#3bc9db"}, 500, 300},
        {10, 110, {"staticKitty", "awkward"}, {"#3bc9db", "#3bc9db"}, 500, 300},
        {10, 130, {"staticKitty", "traumatized"}, {"#4dabf7", "#4dabf7"}, 500, 300},

        {10, 150, {"staticKitty", "starred"}, {"#4dabf7", "#4dabf7"}, 500, 300},
        {15, 10, {"staticKitty", "crying"}, {"#5c7cfa", "#5c7cfa"}, 500, 300},
        {15, 30, {"staticKitty", "yenyan"}, {"#5c7cfa", "#5c7cfa"}, 500, 300},
        {15, 50, {"staticKitty", "traumatized2"}, {"#845ef7", "#845ef7"}, 500, 300},
        {15, 70, {"staticKitty", "possesed"}, {"#845ef7", "#845ef7"}, 500, 300},
        
        {15, 90, {"staticKitty", "flashbanged"}, {"#be4bdb", "#be4bdb"}, 500, 300},
        {15, 110, {"staticKitty", "nya"}, {"#be4bdb", "#be4bdb"}, 500, 300},

        // 8 sep added - 11

        {15, 130, {"staticKitty", "worried"}, {"#f783ac", "#f783ac"}, 500, 300},
        {15, 150, {"staticKitty", "scared"}, {"#f783ac", "#f783ac"}, 500, 300},
        {20, 10, {"staticKitty", "bored"}, {"#ff8787", "#ff8787"}, 500, 300},
        {20, 30, {"staticKitty", "dead"}, {"#ff8787", "#ff8787"}, 500, 300},
        {20, 50, {"staticKitty", "dizzy"}, {"#ffa94d", "#ffa94d"}, 500, 300},
        {20, 70, {"staticKitty", "suspecious"}, {"#ffa94d", "#ffa94d"}, 500, 300},
        {20, 90, {"staticKitty", "relieved"}, {"#94d82d", "#94d82d"}, 500, 300},
        {20, 110, {"staticKitty", "smug"}, {"#94d82d", "#94d82d"}, 500, 300},
        {20, 130, {"staticKitty", "winkRight"}, {"#20c997", "#20c997"}, 500, 300},
        {20, 150, {"staticKitty", "winkLeft"}, {"#20c997", "#20c997"}, 500, 300},
        {25, 10, {"staticKitty", "blank"}, {"#ff6b6b", "#ff6b6b"}, 500, 300}
        
        
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
    
    return 0;
}