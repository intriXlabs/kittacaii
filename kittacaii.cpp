#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cstdint>
#include <chrono>


/*

main kitty architecture: each public and private section is divided to keep as organized as possible. each section has a specific purpose and is clearly labeled for easy navigation and understanding of the code structure.
meanwhile many code sections can be at different places but the're organised in such manner to provide need-use functionality type architecture organizations which means if we found need then we make it's code at time - not early or at end.

- private: kitty expressions (staticKitty, staticKittyAngry, etc.)
- public: static kitty ecpression list (kittyList)
- private: color struct for RGB values
- private: isKittyColorful flag and kittyColor variable
- public: setKittyColor and resetKittyColor methods
- public: printKitty method to display kitty at specified position with optional color
- public: animateKitties struct for animation data
- public: renderKittyFrame method to render a single frame of animation
- public: animateBetweenKitties method to animate between multiple kitties

*/

/*

To add new kitty expressions, follow these steps:

1. Define a new private string array for the kitty expression, similar to the existing ones (e.g., staticKittyNewExpression).
2. Add the new kitty expression to the kittyList array in the public section, ensuring it has a unique name.
3. Update the printKitty method to include a condition for the new kitty expression, allowing it to be displayed when specified.

NOTE: animatuon methods does use printKitty method to render kitty expressiions so once kitty is defined inside above three places then animation directly can use it without any further changes.
NOTE: string is used due to same reason - fast and easy way to update
NOTE: architecture is designed to handle 1000s of kitty expressions without any serious performance issues, as the expressions are stored in memory and accessed directly when needed. This allows for quick rendering and animation of kitties without the need for complex data structures or algorithms.

*/

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

    std::string staticKittyMoney[3] ={
        "  /\\_/\\  ",
        " ( $.$ ) ",
        "  >   <  "
    };

    std::string staticKittyAwkward[3] ={
        "  /\\_/\\  ",
        " ( ס.ס ) ",
        "  >   <  "
    };

    std::string staticKittyTraumatized[3] ={
        "  /\\_/\\  ",
        " ( ة.ة ) ",
        "  >   <  "
    };

    std::string staticKittyStarred[3] ={
        "  /\\_/\\  ",
        " ( ٭.٭ ) ",
        "  >   <  "
    };

    std::string staticKittyCrying[3] ={
        "  /\\_/\\  ",
        " ( ܊.܊ ) ",
        "  >   <  "
    };

    std::string staticKittyYenYan[3] ={
        "  /\\_/\\  ",
        " ( ࿊.࿊ ) ",
        "  >   <  "
    };

    std::string staticKittyTraumatized2[3] ={
        "  /\\_/\\  ",
        " ( ⊙.⊙ ) ",
        "  >   <  "
    };

    std::string staticKittyPossesed[3] ={
        "  /\\_/\\  ",
        " ( ◉.◉ ) ",
        "  >   <  "
    };

    std::string staticKittyFlashBanged[3] ={
        "  /\\_/\\  ",
        " ( ⬤.⬤ ) ",
        "  >   <  "
    };

    std::string staticKittyNya[3] ={
        "  /\\_/\\  ",
        " ( ~.~ ) ",
        "  >   <  "
    };
    
public:
    std::string kittyList[25] = {
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
        "staticKittyEarTurnRight",
        "staticKittyMoney",
        "staticKittyAwkward",
        "staticKittyTraumatized",
        "staticKittyStarred",
        "staticKittyCrying",
        "staticKittyYenYan",
        "staticKittyTraumatized2",
        "staticKittyPossesed",
        "staticKittyFlashBanged",
        "staticKittyNya"
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
    void setKittyColor(std::string colorCode) {
        // Implementation for converting hex color to RGB
        if(colorCode.length() == 7 && colorCode[0] == '#') {
            //hexcode format #RRGGBB
            kittyColor.r = static_cast<uint8_t>(std::stoi(colorCode.substr(1, 2), nullptr, 16));
            kittyColor.g = static_cast<uint8_t>(std::stoi(colorCode.substr(3, 2), nullptr, 16));
            kittyColor.b = static_cast<uint8_t>(std::stoi(colorCode.substr(5, 2), nullptr, 16));
            isKittyColorful = true;
        }
        else if(colorCode[0] == 'r' && colorCode[1] == 'g' && colorCode[2] == 'b' && colorCode[3] == '(' && colorCode.back() == ')') {
            // Parse rgb(r, g, b) format
            size_t firstComma = colorCode.find(',');
            size_t secondComma = colorCode.find(',', firstComma + 1);
            if(firstComma != std::string::npos && secondComma != std::string::npos) {
                kittyColor.r = static_cast<uint8_t>(std::stoi(colorCode.substr(4, firstComma - 4)));
                kittyColor.g = static_cast<uint8_t>(std::stoi(colorCode.substr(firstComma + 1, secondComma - firstComma - 1)));
                kittyColor.b = static_cast<uint8_t>(std::stoi(colorCode.substr(secondComma + 1, colorCode.length() - secondComma - 2)));
                isKittyColorful = true;
            } else {
                std::cerr << "Error: Invalid RGB format." << std::endl;
            }
        } else {
            std::cerr << "Error: Invalid color code format." << std::endl;
        }

    }

    void resetKittyColor() {
        kittyColor = {255, 255, 255}; // Reset to white
        isKittyColorful = false;
    }

public:

    void printKitty(int row, int col, std::string kittyName = "staticKitty") {

        if(row < 0 || col < 0) {
            std::cerr << "Error: Row and column must be non-negative." << std::endl;
            return;
        }

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
        } else if(kittyName == "staticKittyMoney" || kittyName == "money"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyMoney[i];
            }
        } else if(kittyName == "staticKittyAwkward" || kittyName == "awkward"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyAwkward[i];
            }
        } else if(kittyName == "staticKittyTraumatized" || kittyName == "traumatized"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyTraumatized[i];
            }
        } else if(kittyName == "staticKittyStarred" || kittyName == "starred"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyStarred[i];
            }
        } else if(kittyName == "staticKittyCrying" || kittyName == "crying"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyCrying[i];
            }
        } else if(kittyName == "staticKittyYenYan" || kittyName == "yenyan"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyYenYan[i];
            }
        } else if(kittyName == "staticKittyTraumatized2" || kittyName == "traumatized2"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyTraumatized2[i];
            }
        } else if(kittyName == "staticKittyPossesed" || kittyName == "possesed"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyPossesed[i];
            }
        } else if(kittyName == "staticKittyFlashBanged" || kittyName == "flashbanged"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyFlashBanged[i];
            }
        } else if(kittyName == "staticKittyNya" || kittyName == "nya"){
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKittyNya[i];
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


int main() {
    Kittacaii kittyAnimator;

    kittyAnimator.setKittyColor("#FF69B4"); // Set kitty color to pink
    kittyAnimator.printKitty(5, 10, "staticKittyHappy"); //
    kittyAnimator.resetKittyColor(); // Reset color to default
    kittyAnimator.setKittyColor("rgb(0, 255, 0)"); // Set kitty color to green
    kittyAnimator.printKitty(10, 10, "staticKittyAngry");
    kittyAnimator.resetKittyColor(); // Reset color to default

    return 0;
}