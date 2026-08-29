#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cstdint>
#include <chrono>

class Kittacaii{

private:
    std::string staticKitty[3] ={
        "  /\\_/\\  ",
        " ( o.o ) ",
        "  >   <  "
    };

    std::string staticKittyAngry[3] ={
        "  /\\_/\\  ",
        " ( >.< ) ",
        "  >   <  "
    };
    
    std::string staticKittyHappy[3] ={
        "  /\\_/\\  ",
        " ( ^.^ ) ",
        "  >   <  "
    };

    std::string staticKittySad[3] ={
        "  /\\_/\\  ",
        " ( T.T ) ",
        "  >   <  "
    };

    std::string staticKittySurprised[3] ={
        "  /\\_/\\  ",
        " ( O.O ) ",
        "  >   <  "
    };

    std::string staticKittySleepy[3] ={
        "  /\\_/\\  ",
        " ( -.- ) ",
        "  >   <  "
    };

    std::string staticKittyExcited[3] ={
        "  /\\_/\\  ",
        " ( ^o^ ) ",
        "  >   <  "
    };

    std::string staticKittyConfused[3] ={
        "  /\\_/\\  ",
        " ( o.O ) ",
        "  >   <  "
    };

    std::string staticKittyLoveLevelOne[3] ={
        "  /\\_/\\  ",
        " ( ♥.♥ ) ",
        "  >   <  "
    };

    std::string staticKittyLoveLevelTwo[3] ={
        "  /\\_/\\  ",
        " ( ❤️.❤️ ) ",
        "  >   <  "
    };

    std::string staticKittyLoveLevelThree[3] ={
        "  /\\_/\\  ",
        " ( 🩷.🩷 ) ",
        "  >   <  "
    };

    std::string staticKittyquestion[3] ={
        "  /\\_/\\  ",
        " ( o.o ) ",
        "  > ? <  "
    };

    std::string staticKittyShocked[3] ={
        "  /\\_/\\  ",
        " ( O.O ) ",
        "  > ! <  "
    };

    std::string staticKittyEarTurnLeft[3] ={
        "  |\\_|\\  ",
        " ( o.o ) ",
        "  >   <  "
    };

    std::string staticKittyEarTurnRight[3] ={
        "  /|_/|  ",
        " ( -.- ) ",
        "  >   <  "
    };

    
public:
    std::string kittyList[15] = {
        "staticKitty",
        "staticKittyAngry",
        "staticKittyHappy",
        "staticKittySad",
        "staticKittySurprised",
        "staticKittySleepy",
        "staticKittyExcited",
        "staticKittyConfused",
        "staticKittyLoveLevelOne",
        "staticKittyLoveLevelTwo",
        "staticKittyLoveLevelThree",
        "staticKittyquestion",
        "staticKittyShocked",
        "staticKittyEarTurnLeft",
        "staticKittyEarTurnRight"
    };

private:
    struct color{
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

private:
    bool isKittyColorful = false;
    color kittyColor = {255, 255, 255}; // Default color is white

public:
    void setKittyColor(std::string hexColor) {
        // Implementation for converting hex color to RGB
        if(hexColor.length() != 7 || hexColor[0] != '#') {
            std::cerr << "Invalid hex color format. Use #RRGGBB." << std::endl;
            return;
        }
        uint32_t hexValue = std::stoul(hexColor.substr(1), nullptr, 16);
        uint8_t r = (hexValue >> 16) & 0xFF;
        uint8_t g = (hexValue >> 8) & 0xFF;
        uint8_t b = hexValue & 0xFF;
        kittyColor.r = r;
        kittyColor.g = g;
        kittyColor.b = b;
        isKittyColorful = true;
    }

    void resetKittyColor() {
        kittyColor = {255, 255, 255}; // Reset to white
        isKittyColorful = false;
    }

public:

    void printKitty(int row, int col, std::string kittyName = "staticKitty") {

        std::string temporaryKitty[3];
        if(kittyName == "staticKitty" || kittyName == "normal"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKitty[i];
            }
        } else if(kittyName == "staticKittyAngry" || kittyName == "angry"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyAngry[i];
            }
        } else if(kittyName == "staticKittyHappy" || kittyName == "happy"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyHappy[i];
            }
        } else if(kittyName == "staticKittySad" || kittyName == "sad"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittySad[i];
            }
        } else if(kittyName == "staticKittySurprised" || kittyName == "surprised"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittySurprised[i];
            }
        } else if(kittyName == "staticKittySleepy" || kittyName == "sleepy"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittySleepy[i];
            }
        } else if(kittyName == "staticKittyExcited" || kittyName == "excited"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyExcited[i];
            }
        } else if(kittyName == "staticKittyConfused" || kittyName == "confused"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyConfused[i];
            }
        } else if(kittyName == "staticKittyLoveLevelOne" || kittyName == "loveLevelOne"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyLoveLevelOne[i];
            }
        } else if(kittyName == "staticKittyLoveLevelTwo" || kittyName == "loveLevelTwo"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyLoveLevelTwo[i];
            }
        } else if(kittyName == "staticKittyLoveLevelThree" || kittyName == "loveLevelThree"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyLoveLevelThree[i];
            }
        } else if(kittyName == "staticKittyquestion" || kittyName == "question"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyquestion[i];
            }
        } else if(kittyName == "staticKittyShocked" || kittyName == "shocked"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyShocked[i];
            }
        } else if(kittyName == "staticKittyEarTurnLeft" || kittyName == "earTurnLeft"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyEarTurnLeft[i];
            }
        } else if(kittyName == "staticKittyEarTurnRight" || kittyName == "earTurnRight"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyEarTurnRight[i];
            }
        }
         else {
            std::cout << "Kitty type not found. Displaying default static kitty." << std::endl;
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKitty[i];
            }
        }

        if(isKittyColorful){
            std::cout << "\033[38;2;" << (int)kittyColor.r << ";" << (int)kittyColor.g << ";" << (int)kittyColor.b << "m";
        }

        for(int i = 0; i < 3; i++){
            std::cout << "\033[" << (row + i) << ";" << col << "H"; // Move cursor to the specified row and column for each line of the kitty
            std::cout << temporaryKitty[i] << std::endl;
        }

        if(isKittyColorful){
            std::cout << "\033[0m"; // Reset color
        }
        // Add conditions for other kitty types if needed
    }
public:
    struct animateKitties{
        int row;
        int col;
        std::vector<std::string> kittyNames;
        std::vector<std::string> hexColors;
        int delay;
        int repeatCount;
    };

    void renderKittyFrame(const animateKitties& animationData, size_t frameIndex) {
        setKittyColor(animationData.hexColors[frameIndex]);
        printKitty(animationData.row, animationData.col, animationData.kittyNames[frameIndex]);
    }

public:

    int animateBetweenKitties(animateKitties animationData) {
        if(animationData.kittyNames.size() != animationData.hexColors.size() || animationData.row < 0 || animationData.delay < 0 || animationData.repeatCount < 1) {
            std::cerr << "Error: The number of kitty names and colors must be the same." << std::endl;
            return -1;
        }

        // mouse hide
        std::cout << "\033[?25l"; // Hide cursor

        for(int i = 0; i < animationData.repeatCount; i++) {
            for(size_t j = 0; j < animationData.kittyNames.size(); j++) {
                renderKittyFrame(animationData, j);
                std::this_thread::sleep_for(std::chrono::milliseconds(animationData.delay));
            }
        }

        //mouse show
        std::cout << "\033[?25h"; // Show cursor

        return 0;
    }

    int animateKittiesBulk(const std::vector<animateKitties>& animations) {
        if(animations.empty()) {
            std::cerr << "Error: No animations provided." << std::endl;
            return -1;
        }
        for(const auto& animation : animations) {
            if(animation.kittyNames.size() != animation.hexColors.size() || animation.row < 0 || animation.delay < 0 || animation.repeatCount < 1) {
                std::cerr << "Error: The number of kitty names and colors must be the same." << std::endl;
                return -1;
            }
        }

        struct activeAnimation {
            const animateKitties* animation;
            size_t frameIndex;
            int repeatsLeft;
            std::chrono::steady_clock::time_point nextFrameTime;
        };

        //hide cursor
        std::cout << "\033[?25l"; // Hide cursor

        std::vector<activeAnimation> activeAnimations;
        activeAnimations.reserve(animations.size());

        const auto startTime = std::chrono::steady_clock::now();
        for(const auto& animation : animations) {
            activeAnimations.push_back({&animation, 0, animation.repeatCount, startTime});
        }

        while(!activeAnimations.empty()) {
            const auto now = std::chrono::steady_clock::now();
            bool renderedFrame = false;

            for(size_t i = 0; i < activeAnimations.size();) {
                auto& active = activeAnimations[i];

                if(active.repeatsLeft <= 0) {
                    activeAnimations.erase(activeAnimations.begin() + static_cast<std::vector<activeAnimation>::difference_type>(i));
                    continue;
                }

                if(now < active.nextFrameTime) {
                    ++i;
                    continue;
                }

                if(active.frameIndex >= active.animation->kittyNames.size()) {
                    active.frameIndex = 0;
                    --active.repeatsLeft;
                    if(active.repeatsLeft <= 0) {
                        activeAnimations.erase(activeAnimations.begin() + static_cast<std::vector<activeAnimation>::difference_type>(i));
                        continue;
                    }
                }

                renderKittyFrame(*active.animation, active.frameIndex);
                active.frameIndex++;
                active.nextFrameTime = now + std::chrono::milliseconds(active.animation->delay);
                renderedFrame = true;
                ++i;
            }

            if(activeAnimations.empty()) {
                break;
            }

            if(!renderedFrame) {
                auto nextWakeTime = activeAnimations.front().nextFrameTime;
                for(const auto& active : activeAnimations) {
                    if(active.nextFrameTime < nextWakeTime) {
                        nextWakeTime = active.nextFrameTime;
                    }
                }

                if(nextWakeTime > now) {
                    std::this_thread::sleep_until(nextWakeTime);
                }
            }
        }
        //show cursor
        std::cout << "\033[?25h"; // Show cursor

        return 0;
    }
};