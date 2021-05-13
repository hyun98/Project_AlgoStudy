#include <iostream>

using namespace std;

int R, C, result = 0, cnt = 0;
char board[21][21];
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};
bool visited[21][21];
bool alpha[30];

void DFS(int r, int c){
    
    char now = board[r][c];
    
    if(alpha[now - 'A']) return;
    
    alpha[now-'A'] = true;
    cnt+=1;
    visited[r][c] = true;
    
    result = max(result, cnt);
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]){
            DFS(nr, nc);
        }
    }
    
    alpha[now-'A'] = false;
    cnt-=1;
    visited[r][c] = false;
}

int main(){
    string in;
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> in;
        for(int j = 0; j < C; j++){
            board[i][j] = in[j];
        }
    }
    
    DFS(0, 0);
    
    cout << result;
    
    return 0;
}
