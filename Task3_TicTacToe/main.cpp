#include<iostream>
using namespace std;
char board[3][3];
void reset_board(){
    char initial = '1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = initial++;
        }
    }
}
void display_board(){
    cout << "\n--- Tic Tac Toe ---\n";
    for(int i=0;i<3;i++){
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<board[i][j];
            if(j<2){
                cout<<" | ";
            }
        }
        cout<<"\n";
        if(i<2){
            cout << "---|---|---\n";
        }
    }
}
bool check_win(char player){
    for(int i=0;i<3;i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}
bool check_draw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}
int main(){
    char replay;
    do{
        reset_board();
        char player = 'X';
        bool gameOver = false;
        
        while(!gameOver){
            display_board();
            int choice;
            
            cout << "\nPlayer " << player << ", enter your move (1-9): ";
            cin >> choice;
            
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            
            if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            
            board[row][col] = player;
            
            if(check_win(player)){
                display_board();
                cout << "\nPlayer " << player << " wins!\n";
                gameOver = true;
            }
            else if(check_draw()){
                display_board();
                cout << "\nIt's a draw!\n";
                gameOver = true;
            }
            else{
                player = (player == 'X') ? 'O' : 'X';
            }
        }
        
        cout << "\nDo you want to play again? (y/n): ";
        cin >> replay;
    }while(replay != 'n' && replay != 'N');
    cout << "Thanks for playing!\n";
    return 0;
}
