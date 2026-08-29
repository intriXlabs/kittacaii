---
this md is consideration to keep the framework as updated as possible, and to provide a clear and concise documentation for the API. It is important to ensure that all endpoints are well-documented, including request parameters, response formats, and any relevant examples. Additionally, any changes or updates to the API should be reflected in this documentation to maintain accuracy and usability for developers.
---



# API Documentation

## Initialization
To initialize the API, you need to import the necessary modules and set up the configuration. Below is an example of how to initialize the API:

```cpp
#include "kittacaii.cpp"
kittacaii FW_API;
```
includes is direct cpp based due to two reasons
- direct compilation of cpp file is faster than header file
- no need to write commands each time to compile the header file, just include the cpp file and compile it directly



# kittacaii main API's

## basic API:

### setKittyColor(color)
it uses to set the color of the kitty. The color parameter should be a string representing the desired color.
the "color" parameter is a string that represents the desired color of the kitty. which is hexcadecimal color code. For example, to set the kitty color to red, you would call the function like this:

```cpp
FW_API.setKittyColor("#FF0000");
```

### resetKittyColor()
This function resets the kitty color to its default value. It does not require any parameters. You can call this function like this:

```cpp
FW_API.resetKittyColor();
```

## Mid level API:

### renderKittyFrame() [not recomended to use]
This function is used to render a frame of the kitty. It requires two parameters: `animateKitties` and `frameIndex`. You can call this function like this:

```cpp
FW_API.renderKittyFrame(animateKitties, frameIndex);
```

# Main FW API's
- printKitty() - prints the kitty to the console
- animateBetweenKitties() - animates the kitty between frames
- animteKittiesBulk() - animates multiple kitties in bulk

## printKitty()
This function prints the kitty to the console. It does not require any parameters. You can call this function like this:

```cpp
FW_API.printKitty(row, col, kitttName);
```
**what it does**: Prints the kitty to the console at the specified row and column with the given name.

each name is an expression of the kitty, this method is used to print static kitty means no animation, just a single frame of the kitty is printed to the console. The `row` and `col` parameters specify the position where the kitty will be printed, and the `kitttName` parameter specifies the name of the kitty expression to be printed.

- you can see names in expressions.md or directly see the code.

## aniomateBetweenKitties(animationData)
This function animates the kitties by treating the kitty as a single frame and animating between different frames. It requires an `animationData` parameter, which is an struct containing the necessary information for the animation.

struct name is: "animateKitties" which is exactly this
```
    struct animateKitties{
        int row;
        int col;
        std::vector<std::string> kittyNames;
        std::vector<std::string> hexColors;
        int delay;
        int repeatCount;
    };
```

## animteKittiesBulk(animationData)
This function animates multiple kitties in bulk. It requires an `animationData` parameter, which is a vector of structs containing the necessary information for each kitty animation.

bassicaly it makes use of the animateBetweenKitties() function to animate multiple kitties at once. The `animationData` parameter is a vector of structs, where each struct contains the necessary information for animating a single kitty.