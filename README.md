# 🎮 Tic Tac Toe Game (C Language)

A simple **Tic Tac Toe** (3x3 grid) game written in **C**, where two players take turns marking spaces with **X** and **O**.  
The game includes:
- A **menu-driven interface**
- **Rule explanation**
- Automatic **draw detection** (even before the board is full)
- **Input validation** and clean grid display

---

## 🧠 Features

- ✅ Two-player mode (Player 1: X, Player 2: O)
- ✅ Interactive menu: Play / Rules / Exit
- ✅ Detects invalid moves and prompts retry
- ✅ Declares **winner** automatically when a player gets 3 in a row
- ✅ Declares **draw early** when no winning combination is possible (even before board fills)
- ✅ Simple and clean **ASCII-based grid display**

---

## 🕹️ Game Rules

1. The game is played on a **3x3 grid**.  
2. **Player 1 uses 'X'** and **Player 2 uses 'O'**.  
3. Players take turns placing their marks in empty spaces.  
4. The **first player to get 3 of their marks in a row** (horizontally, vertically, or diagonally) wins.  
5. If **no possible winning line remains** for either player, or if all 9 cells are filled, the game ends in a **draw**.

---

## 🧩 How It Works

- The program initializes an empty 3×3 matrix.  
- It prompts for player names (ensuring they are different).  
- The board updates after every move and checks:
  - If a player has won (`check_grid()`).
  - If no more winning combinations are possible (`check_no_possible_win()`).
- Once a win or draw condition is met, the game stops and displays the result.

---


## 👨‍💻 Author

**👤 Nikhil Nataraj Malashetti**  

⭐ *If you liked this project, consider giving it a star on GitHub!*
