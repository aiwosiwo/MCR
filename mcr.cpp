#include <iostream>
using namespace std;

bool isFill(char game[3][3],int i,int j){
    if (game[i][j] == 'X' || game[i][j] == 'O') 
        return true;
    return false;
}

bool isWin(char game[3][3]){
    //先检测是否填了，如果没填，则与之相关的行、列、斜线都不用判断了，只需(0,0),(1,1),(2,2)三个位置即可覆盖所有行列和斜线。
    if (isFill(game, 0, 0)){
        if (game[0][0] == game[0][1] && game[0][1] == game[0][2]) return true;
        if (game[0][0] == game[1][0] && game[1][0] == game[2][0]) return true;
    }
    if(isFill(game, 1, 1)){
        if (game[1][0] == game[1][1] && game[1][1] == game[1][2]) return true;
        if (game[0][1] == game[1][1] && game[1][1] == game[2][1]) return true; 
        if (game[0][0] == game[1][1] && game[1][1] == game[2][2]) return true; 
        if (game[0][2] == game[1][1] && game[1][1] == game[2][0]) return true; 
    }
    if(isFill(game, 2, 2)){
        if (game[2][0] == game[2][1] && game[2][1] == game[2][2]) return true;
        if (game[0][2] == game[1][2] && game[1][2] == game[2][2]) return true; 
    }
    return false;
}

int main(){
    int i, j;
    char game[3][3] = {' '}; // Tic-tac-toe
    char player1 = 'X'; 
    char player2 = 'O'; 
    bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
    cout << "X = Player 1" << endl << "O = Player 2" << endl;
    int n;
    for (n=0; n<9; n++){
        turn = !turn; // use the not-operator to change true to false or false to true.
        if (turn == false) 
            cout << "Player 1: "; 
        else
            cout << "Player 2: "; 
        cout << "Which cell to mark? i:[0..2], j:[0..2]: "; 
        cin >> i >> j;
        while (i < 0 || i > 2 || j < 0 || j > 2){ //range judgment
            cout << "Out of range, input again: ";
            cin >> i >> j;
        }
        while (isFill(game, i, j)){ //repeat judgment
            cout << "Already filled, input again: ";
            cin >> i >> j;
        }
        if (turn == false)
            game[i][j] = 'X';
        else
            game[i][j] = 'O';
        if (isWin(game)){
            cout << "Win!" << endl;
            break;
        }
    }
    if (n==9)
        cout << "Tie!" << endl;
    for (int p=0; p<3; p++){
        for (int q=0; q<3; q++){
            cout << game[p][q] << "\t";
        }
        cout << endl << endl;
    }
    return 0;
}
