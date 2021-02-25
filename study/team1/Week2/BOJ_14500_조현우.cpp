#include <iostream>
#include <vector>
using namespace std;

struct P{
    int row, col;
};

int N, M;
int Paper[501][501];
bool visited[501][501];
int result = 0;

void input(){
    cin >> N >> M;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> Paper[r][c];
            visited[r][c] = false;
        }
    }
}

vector<P> tblock;
bool temp_visited[501][501];

void show_block(){
    int Map[5][5];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Map[i][j] = 1;
        }
    }
    for(int i = 0; i < tblock.size(); i++){
        Map[tblock[i].row][tblock[i].col] = 0;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }
}

inline bool is_near(int row, int col){
    for(int i = 0; i < tblock.size(); i++){
        int a = abs(tblock[i].row - row);
        int b = abs(tblock[i].col - col);
        if((a == 1 && b == 0) || (a == 0 && b == 1)) return true;
    }
    return false;
}

void dfs(int row, int col, int used_block){
    if(used_block == 4){
        tblock.push_back({row, col});
        int temp_result = 0;
        for(int i = 0; i < 4; i++){
//            cout << tblock[i].row << " " << tblock[i].col << endl;
            temp_result += Paper[tblock[i].row][tblock[i].col];
        }
        
        result = max(result, temp_result);
//        cout << endl;
//        show_block();
        tblock.pop_back();
        return;
    }
    
    temp_visited[row][col] = true;
    tblock.push_back({row, col});
//    show_block();
//    cout << endl;
    for(int r = -1; r <= 1; r++){
        for(int c = -2; c <= 2; c++){
            if(row+r < 0 || col+c < 0 || row+r >= N || col+c >= M || visited[row+r][col+c] || temp_visited[row+r][col+c]) continue;
            if(is_near(row+r, col+c)){
                dfs(row+r, col+c, used_block+1);
            }
        }
    }
    tblock.pop_back();
    temp_visited[row][col] = false;
}

void solve(){
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            visited[r][c] = true;
            dfs(r, c, 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    cout << result;
    
    return 0;
}
