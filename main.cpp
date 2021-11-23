#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

// create map which will store values
char boardVals[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

// isGameOver bool (determines if the game continues or not)
bool isGameOver = false;

char turn = 'X';
char winner = 'X';

// draw the board
void drawBoard() {
    std::cout << boardVals[0][0] << " | " << boardVals[0][1] << " | " << boardVals[0][2] << "\n";
    std::cout << "- - - - -\n";
    std::cout << boardVals[1][0] << " | " << boardVals[1][1] << " | " << boardVals[1][2] << "\n";
    std::cout << "- - - - -\n";
    std::cout << boardVals[2][0] << " | " << boardVals[2][1] << " | " << boardVals[2][2] << "\n\n";
}

void getPlayerDecision() {
    // determine who goes first (50/50 radndom decision) TBD
    // for now i'll just have player X go first each time

    std::cout << "Please enter choice (1-9)\n";
    int playerChoice;
    bool validRes = false;
    int row;
    int col;

    // determine turn and who's value we're taking
    if (turn == 'X') {
        std::cout << "It's Player X's Turn\n";
    } else if (turn == 'O') {
        std::cout << "It's Player O's Turn\n";
    }
    std::cin >> playerChoice;

    
    switch (playerChoice){
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
    }

    if (playerChoice < 1 || playerChoice > 9) {
        std::cout << "Invalid entry, please enter number between 1-9... \n";
    } else if (boardVals[row][col] == 'X' || boardVals[row][col] == 'O') {
        std::cout << "Space is already filled, choose another... \n";
    }

    if (turn == 'X' && boardVals[row][col] != 'X' && boardVals[row][col] != 'O') {
        boardVals[row][col] = 'X';
        turn = 'O';
        winner = 'X';
    } else if (turn == 'O' && boardVals[row][col] != 'X' && boardVals[row][col] != 'O') {
        boardVals[row][col] = 'O';
        turn = 'X';
        winner = 'O';
    }

    // Fill space in with players choice with 'X'
}

bool checkEnd() {    
    // check if current board is a win

    // check horizontal rows
    for (int i = 0; i < 3; i++) {
        if (boardVals[i][0] == boardVals[i][1] && boardVals[i][0] == boardVals[i][2] || boardVals[0][i] == boardVals[1][i] && boardVals[0][i] == boardVals[2][i] && boardVals[1][i]) {
            return true;
        }
    }

    // check diagonal rows
    if (boardVals[0][0] == boardVals[1][1] && boardVals[0][0] == boardVals[2][2] || boardVals[0][2] == boardVals[1][1] && boardVals[0][2] == boardVals[2][0]) {
        return true;
    }
    
    return false;

}

int main() {
    std::cout << "WELCOME TO TIC TAC TOE  \n\n";

    std::string winPlayer = "";
    // draw the board
    drawBoard();
    
    // while the bool (gameover) is not true, keep playing the game
    while (isGameOver != true) {
        // in while loop, getPlayerDecision()
        getPlayerDecision();
        drawBoard();
        isGameOver = checkEnd();
    }

    std::cout << "Player : " << winner << " has won \n";

    return 0;
}
