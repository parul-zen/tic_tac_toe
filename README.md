# Tic-Tac-Toe in Pure C

A command-line Tic-Tac-Toe game built in standard C (`stdio.h` only) while practicing core programming logic, arrays, and state evaluation.

## What I Learned Building This

- **Managing Game State:** Using a 1D character array to track board positions (1–9), validate user moves, and check win/draw conditions after every turn.
- **Writing a Rule-Based Bot:** Instead of using random moves, I built a priority check so the computer looks for a winning move first,
                                 blocks my immediate threats second, and then falls back to taking the center or corners.
- **Keeping it Standard:** Writing everything using only `stdio.h` so it compiles cleanly on any system without relying on Windows-only headers.
- **Known Limitation (Next Fix):** Because the bot evaluates single-move threats rather than looking two steps ahead,
                                    a human player can still beat it using a two-way "fork" trap—something I plan to patch next.

## How to Run It

1. **Compile the code:**
   ```
   gcc tic_tac_toe.c -o tic_tac_toe
   ```
2. Run in terminal:
                     Windows: .\tic_tac_toe.exe
                     Linux/macOS: ./tic_tac_toe

## Board layout:
```
1 | 2 | 3 
---+---+---
4 | X | 6 
---+---+---
7 | 8 | O
```
