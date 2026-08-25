#include <iostream>
#include <string>
#include <vector>

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
        " ( 💖.💖 ) ",
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
    

public:
    void printKitty(std::string kittyName = "staticKitty") {

        std::string temporaryKitty[3];
        if(kittyName == "staticKitty"){
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
        } else {
            std::cout << "Kitty type not found. Displaying default static kitty." << std::endl;
            for(int i = 0; i < 3; i++){
                temporaryKitty[i] = staticKitty[i];
            }
        }

        for(int i = 0; i < 3; i++){
            std::cout << temporaryKitty[i] << std::endl;
        }
        // Add conditions for other kitty types if needed
    }
};

int main(){
    Kittacaii kitty;
    kitty.printKitty("");
    kitty.printKitty("angry");
    kitty.printKitty("happy");
    kitty.printKitty("sad");
    kitty.printKitty("surprised");
    kitty.printKitty("sleepy");
    kitty.printKitty("excited");
    kitty.printKitty("confused");
    kitty.printKitty("loveLevelOne");
    kitty.printKitty("loveLevelTwo");
    kitty.printKitty("loveLevelThree");
    kitty.printKitty("question");
    kitty.printKitty("shocked");

    return 0;
}