# CPPND: Capstone Snake Game Example

This is a Bong game built as the Capstone project for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`

## Game instructions
This is a two player Pong game. The player on the right side move up and down through the "up" and "down" buttons, and the player on the left moves up and down using "w" and "s" respectively. The winner is the one who scores more.

## Classes files strucutre
movingobject.cpp - the base class representing the game moving objects basic position attributes.

ball.cpp - the class representing the ball in the game, it's derived from the base class MovingObject.

player.cpp - the class representing the player's paddle, it's derived from the based class MovingObject.

controller.cpp - the controller class handles the user input and connects it to the movement of the player paddles.

renderer.cpp - the renderer class takes the position of the ball and the players paddles and render them to the game window.

game.cpp - the game class contains the game loop and use all the previous classes to control and visualize the game.

main.cpp - the main file initializes the renderer, controller, game objects and runs the game.


## Project rubric requirements
### README (All Rubric Points REQUIRED)
1. A README with instructions is included with the project
2. The README describes the project you have built.
3. The README also indicates the file and class structure, along with the expected behavior or output of the program.

### Compiling and Testing (All Rubric Points REQUIRED)
1. The project code must compile and run without errors.
2. The project uses cmake and make.

### Loops, Functions, I/O
1. A variety of control structures are used in the project. The project code is clearly organized into functions.
2. The project accepts input from a user as part of the necessary operation of the program.
   
### Object Oriented Programming
1. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
2. All class data members are explicitly specified as public, protected, or private.
3. All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
4. Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
5. Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.
6. One member function in an inherited class overrides a virtual base class member function.

### Memory Management
1. At least two variables are defined as references, or two functions use pass-by-reference in the project code.
2. At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.
3. The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.
4. For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object.

