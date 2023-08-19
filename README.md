# Shark Frenzy Game Documentation

Shark Frenzy is a short, simple, and entertaining game that demonstrates basic game mechanics, collision detection, user input handling, and graphics rendering using OpenGL. The game's straightforward design makes it suitable for beginners and a starting point for more complex game development projects.

## Game Elements

### Shark

- The player controls a shark using the 'a' and 'd' keys on the keyboard.
- The shark is initially positioned at the center of the screen.
- The shark's size increases when it successfully catches a fish.
- The shark's body is represented by a gray-colored rhombus, and it has a triangular tail.

### Fish

- Fish swim from left to right across the screen.
- The player's goal is to catch the fish by colliding with them.
- Each caught fish increases the player's score.
- Fish come in different colors.
- When a fish is caught, it disappears, and a new fish appears.

### Score

- The player's score is displayed on the screen.
- The game ends when the player catches a certain number of fish (e.g., 5).

## Controls

- 'a' key: Move the shark to the left.
- 'd' key: Move the shark to the right.

## Game Logic

1. Initialize the game window and rendering context using OpenGL.
2. Set up the game environment, including the shark and initial fish position.
3. Enter the game loop:
   - Update the fish's position as it moves across the screen.
   - Check for collisions between the shark and fish:
     - If a collision occurs, increase the player's score, make the fish disappear, and update the shark's size and position.
     - If the player's score reaches the goal, end the game.
   - Update the shark's position based on user input.
   - Render the game elements (shark, fish, score) on the screen.
4. Repeat the game loop until the game is won or closed by the player.

## Compilation and Execution

1. Ensure you have the required libraries (OpenGL and GLUT) installed.
2. Compile the game's source code using a C/C++ compiler with the necessary flags.
3. Run the compiled executable.
4. Use the 'a' and 'd' keys to control the shark and catch fish.
5. The game ends when the player catches the required number of fish or closes the game window.

## Notes
This game was developed as part of the "Computer Graphics" course project at the University of EELU, Egypt.


