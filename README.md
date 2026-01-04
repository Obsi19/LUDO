# 🎲 LUDO - Console-Based Board Game

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg" alt="C++">
  <img src="https://img.shields.io/badge/Platform-Windows-lightgrey.svg" alt="Windows">
  <img src="https://img.shields.io/badge/Status-Working-brightgreen.svg" alt="Status">
  <img src="https://img.shields.io/badge/Players-2%20to%204-orange.svg" alt="Players">
</p>

A fully functional console-based LUDO game implemented in C++ using Object-Oriented Programming principles. This classic board game supports multiplayer gameplay for 2 to 4 players with colorful console output and interactive gameplay.

---

## 📸 Game Screenshots

### Game Board
```
    ┌─────────────────────────────────────────┐
    │     BLUE HOME          GREEN HOME       │
    │      B B                  G G           │
    │      B B                  G G           │
    │                                         │
    │         .  . . O . . . . .  . .            │
    │         . . . O .  . . . . .  .           │
    │         . . .  O . . . .  . . .           │
    │         .  . . O . .  . . . . .            │
    │    O O O O O O $ O O O O O O O O        │
    │         . . . O . . . . .  . .           │
    │         . .  . O . . .  . . . .           │
    │         . . . O .  . . . . .  .           │
    │                                         │
    │      R R                  Y Y           │
    │      R R                  Y Y           │
    │     RED HOME           YELLOW HOME      │
    └─────────────────────────────────────────┘
```

### Dice Roll Display
```
                 You rolled: 
                 | *   * |
                 |   *   |
                 | *   * |
```

---

## ✨ Features

### Current Features
- ✅ **Fully Working Game** - Complete LUDO gameplay experience
- ✅ **4-Player Mode** - Blue, Green, Red, and Yellow players
- ✅ **2-Player Mode** - Play with 2 players (Red vs Green)
- ✅ **Colorful Console UI** - ANSI color-coded pieces for each player
- ✅ **Animated Dice** - Visual ASCII art dice display
- ✅ **Token Management** - Track and manage 4 tokens per player
- ✅ **Safe Zones & Stars** - Special positions marked on the board
- ✅ **Kill Mechanism** - Capture opponent's tokens
- ✅ **Home Run** - Tokens reaching the center win
- ✅ **Turn-Based System** - Proper turn management
- ✅ **Win Detection** - Automatic winner announcement

---

## 🏗️ Object-Oriented Programming Implementation

This project demonstrates core OOP concepts in C++:

### Classes Structure

| Class | Description | OOP Concept |
|-------|-------------|-------------|
| `Ludo` | Main game logic, board management, player turns | **Encapsulation** - Private data members with public interface |
| `Dice` | Random dice rolling and display | **Encapsulation** & **Abstraction** |
| `Board` | Board visualization and rendering | **Composition** - Uses Ludo class |

### OOP Concepts Implemented

#### 1. **Encapsulation**
```cpp
class Ludo {
private: 
    char Board[22][22];           // Game board matrix
    int Bpositions[4][2];         // Blue token positions
    int Gpositions[4][2];         // Green token positions
    int Rpositions[4][2];         // Red token positions
    int Ypositions[4][2];         // Yellow token positions
    int turn;                     // Current player turn
public:
    void DisplayBoard();          // Public interface methods
    void Taketurn();
    bool checkwin();
};
```

#### 2. **Abstraction**
```cpp
class Dice {
public: 
    int roll();                   // Abstract dice rolling
    void displayResult(int);      // Abstract result display
};
```

#### 3. **Composition**
- `Ludo` class composes `Dice` class for dice functionality
- `Board` class uses `Ludo` class for game state

#### 4. **Constructor Initialization**
```cpp
Ludo() {
    // Initialize board, positions, and game state
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 22; j++) {
            Board[i][j] = ' ';
        }
    }
    // Setup player starting positions... 
}
```

---

## 🎮 How to Play

### Controls
1. **Roll Dice** - Press Enter to roll the dice
2. **Select Token** - Enter token number (1-4) to move
3. **View Tokens** - Press 0 to see token positions
4. **Free Token** - Roll 6 to release a token from home

### Rules
- Roll a **6** to bring a token out of home
- Move tokens clockwise around the board
- Land on an opponent's token to send it back home
- Safe zones (marked with ★) protect your tokens
- First player to get all 4 tokens to the center wins! 

---

## 🛠️ Installation & Compilation

### Prerequisites
- C++ Compiler (g++, MSVC, or MinGW)
- Windows OS (for console color support)

### Compile & Run

```bash
# Using g++
g++ -o ludo "Bscs23107&BSCS23202_new console.cpp" -std=c++11

# Run the game
./ludo
```

### Visual Studio
1. Open the project in Visual Studio
2. Build the solution (Ctrl + Shift + B)
3. Run (F5)

---

## 📁 Project Structure

```
LUDO/
├── Bscs23107&BSCS23202_new console.cpp   # Main entry point
├── Bscs23107&BSCS23202_Ludo.h            # Ludo game class
├── Bscs23107&BSCS23202_Dice.h            # Dice class
├── Bscs23107&BSCS23202_Board.h           # Board visualization
└── README.md                              # Documentation
```

---

## 🎨 Color Coding

| Color | Player | Console Code |
|-------|--------|--------------|
| 🔵 Blue | Player 1 | `\u001B[34m` |
| 🟢 Green | Player 2 | `\u001B[32m` |
| 🔴 Red | Player 3 | `\u001B[31m` |
| 🟡 Yellow | Player 4 | `\u001B[33m` |

---

## 🚀 Future Improvements

### Planned Features

| Feature | Status | Priority |
|---------|--------|----------|
| 🤖 AI Integration | 🔄 Planned | High |
| 👥 3-Player Mode | 🔄 Planned | Medium |
| 🎨 GUI with SFML/Qt | 🔄 Planned | High |
| 🌐 Online Multiplayer | 💭 Considering | Low |
| 💾 Save/Load Game | 💭 Considering | Medium |
| 🔊 Sound Effects | 💭 Considering | Low |

### GUI Enhancement (Coming Soon)

We plan to upgrade the console-based interface to a modern graphical interface using: 

- **SFML (Simple and Fast Multimedia Library)**
  - Cross-platform graphics
  - Smooth animations
  - Mouse input support
  
- **Qt Framework**
  - Professional UI components
  - Cross-platform compatibility
  - Rich widget library

### AI Integration (Coming Soon)

Planned AI features: 
- **Easy Mode** - Random valid moves
- **Medium Mode** - Basic strategy (prioritize killing, safe zones)
- **Hard Mode** - Advanced decision making with minimax algorithm

---

## 👥 Contributors

- **BSCS23107** - Developer
- **BSCS23202** - Developer

---

## 📄 License

This project is open source and available for educational purposes.

---

## 🙏 Acknowledgments

- Classic LUDO board game rules
- C++ OOP course project
- Console color implementation references

---

<p align="center">
  Made with ❤️ using C++
</p>

<p align="center">
  ⭐ Star this repository if you found it helpful!
</p>
