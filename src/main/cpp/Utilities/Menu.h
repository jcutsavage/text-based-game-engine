#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <termios.h>
#include <unistd.h>

class Menu {
public:

    Menu(const std::vector<std::vector<std::string>>& options)
    : options(options), selectedRow(0), selectedCol(0) 
    {
        tcgetattr(STDIN_FILENO, &originalTerm);
    }

    ~Menu() 
    {
        disableRawMode();
    }

    // Launches the menu and returns the index of the selected option
    int run() 
    {
        enableRawMode();

        std::cout << "\033[?25l"; // Hide cursor

        display();

        while (true) {
            KeyPress key = getKeyPress();

            switch (key) {
                case UP:
                    selectedRow = (selectedRow - 1 + options.size()) % options.size();
                    break;
                case DOWN:
                    selectedRow = (selectedRow + 1) % options.size();
                    break;
                case LEFT:
                    selectedCol = (selectedCol - 1 + options[selectedRow].size()) % options[selectedRow].size();
                    break;
                case RIGHT:
                    selectedCol = (selectedCol + 1) % options[selectedRow].size();
                    break;
                case ENTER:
                case SPACE:
                    std::cout << "\033[?25h"; // Show cursor
                    disableRawMode();
                    return selectedRow * 100 + selectedCol; // Composite index (or refactor return type)
            }

            display();
        }
    }

private:
    std::vector<std::vector<std::string>> options;
    int selectedIndex;
    termios originalTerm;
    int linesDrawn = 0;
    int selectedRow = 0;
    int selectedCol = 0;

    enum KeyPress { UP, DOWN, LEFT, RIGHT, ENTER, SPACE, UNKNOWN };

    void enableRawMode() 
    {
        termios raw = originalTerm;
        raw.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    void disableRawMode() 
    {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTerm);
    }

    char readKey() 
    {
        char c;
        int read_successful = read(STDIN_FILENO, &c, 1);
        return c;
    }

    KeyPress getKeyPress() 
    {
        char c = readKey();

        if (c == '\033') { // Escape sequence
            readKey(); // skip '['
            char dir = readKey();
            switch (dir) {
                case 'A': return UP;
                case 'B': return DOWN;
                case 'C': return RIGHT;
                case 'D': return LEFT;
            }
        } 
        else if (c == 'w' || c == 'W') return UP;
        else if (c == 's' || c == 'S') return DOWN;
        else if (c == 'a' || c == 'A') return LEFT;
        else if (c == 'd' || c == 'D') return RIGHT;
        else if (c == '\n') return ENTER;
        else if (c == ' ') return SPACE;

        return UNKNOWN;
    }

    void display() {
        if (linesDrawn > 0)
            std::cout << "\033[" << linesDrawn << "A";
    
        linesDrawn = 0;
    
        for (size_t row = 0; row < options.size(); ++row) {
            for (size_t col = 0; col < options[row].size(); ++col) {
                if ((int)row == selectedRow && (int)col == selectedCol)
                    std::cout << "\033[1;32m[" << options[row][col] << "]\033[0m ";
                else
                    std::cout << " " << options[row][col] << "  ";
            }
            std::cout << "\n";
            ++linesDrawn;
        }
    
        std::cout.flush();
    }
};