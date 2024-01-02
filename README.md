# so_long
The `so_long` project is part of the 42 school curriculum, challenging students to create a simple 2D game using the MinilibX library. The repository includes `map` and `texture` folders, with the map containing .ber files and the `texture` containing xpm image files.

## Overview
The project consists of a game where a player (identified by `P`) navigates through a map with various elements such as walls (`1`), empty spaces (`0`), exits (`E`), and collectibles (`C`). The player must collect all collectibles and reach the exit to win the game.

## File Structure
The repository is structured as follows:

- `map`: Contains .ber files, each defining a map with identifiers `1`, `0`, `P`, `E`, and `C`.
- `texture`: Contains xpm image files for the visual representation of different game elements.

## Gameplay
- **Controls**: The player can move using the keys `W` (up), `A` (left), `S` (down), and `D` (right).
- **Objective**: Collect all collectibles (`C`) and reach the exit (`E`) to win the game.
- **Exit**: The player can exit the game by pressing `ESC` or the window close button.

## Game Completion
The game ends when the player has collected all collectibles and reaches the exit.

## Usage
1. Clone the repository:
```bash
git clone https://github.com/seungwonme/so_long
```

2. Navigate to the project directory:
```bash
cd so_long
```

3. Compile the so_long executable:
```bash
make
```

4. Run the game with a .ber file:
```bash
./so_long maps/map.ber
```

- To clean up object files:
```bash
make clean
```

- To delete all build files:
```bash
make fclean
```

- To clean and rebuild the executable:
```bash
make re
```
