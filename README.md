**Tetris Project Readme**

### Overview
This Tetris project is a simple implementation of the classic Tetris game using C++ and SFML (Simple and Fast Multimedia Library). The game features familiar gameplay mechanics where players manipulate falling Tetrominoes (Tetris pieces) to create complete horizontal lines, which then disappear and earn points. The objective is to prevent the stack of Tetrominoes from reaching the top of the playing field.

### Features
- **Classic Tetris Gameplay**: Players can move, rotate, and drop Tetrominoes as they descend from the top of the screen.
- **Scoring System**: Points are awarded for completing lines, with additional points earned for clearing multiple lines simultaneously.
- **Level Progression**: The game features a simple level system where the difficulty increases as the player earns more points.
- **High Score Tracking**: The game records the player's high score, which persists across sessions.
- **Keyboard Controls**: Intuitive keyboard controls allow players to interact with the game seamlessly.

### File Structure
- **main.cpp**: Contains the main game loop and logic, including Tetromino movement, collision detection, and rendering.
- **pieces.h**: Defines the shapes and configurations of Tetrominoes used in the game.
- **functionality.h**: Includes various functions responsible for piece movement, rotation, line clearing, shadow generation, and level checking.
- **utils.h**: Provides utility functions and variables used throughout the game, such as grid dimensions and anomaly checks.

### Dependencies
- **SFML**: This project utilizes SFML for graphics rendering and window management. Ensure that SFML is installed and configured correctly on your system to run the game.

### How to Play
1. **Compile**: Compile the source code using a C++ compiler that supports C++11 or higher standards.
2. **Run**: Execute the compiled binary to launch the game.
3. **Controls**:
   - **Arrow Keys**: Move Tetromino left, right, or down.
   - **Up Arrow**: Rotate Tetromino clockwise.
   - **Spacebar**: Instantly drop Tetromino to the bottom.
   - **P**: Pause/unpause the game.
   - **S**: Go back to the start screen.
   - **E**: Exit the game.

### Development Environment
- **Language**: C++
- **Graphics Library**: SFML
- **IDE/Text Editor**: G++ terminal , Visual Tudio
- **Operating System**: Windows/Ubuntu
### Credits
- **SFML**: Simple and Fast Multimedia Library - [SFML Website](https://www.sfml-dev.org/)

### Contributors
- [Muhammad Zain]: [https://github.com/zainkhalid10]

### Feedback and Contributions
Feedback, bug reports, and contributions are welcome! Feel free to submit issues or pull requests to improve the game. Let's make Tetris even better together!

### Enjoy the Game!
Thank you for playing our Tetris project. Have fun stacking those blocks and chasing high scores! If you encounter any issues or have suggestions for improvements, don't hesitate to reach out. Happy gaming!
