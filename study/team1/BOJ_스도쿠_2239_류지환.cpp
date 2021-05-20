#include <bits/stdc++.h>

using namespace std;

bool** checkRow;
bool** checkCol;
bool** checkBox;

int num;
string str;

vector<vector<int>> sudoku;

void input(){
    sudoku.resize(9);
    for(int i=0; i<9; i++){
         cin >> str;
         sudoku.at(i).resize(9);
         for(int j=0; j<9; j++){
            num = str.at(j) - '0';
            sudoku.at(i).at(j) = num;


            checkRow[i][num] = true;
            checkCol[j][num] = true;
            checkBox[(i/3 * 3)+j/3][num] = true;

         }
    }
}

void Init(){
    checkRow = new bool*[9];
    checkCol = new bool*[9];
    checkBox = new bool*[9];

    for(int i=0; i<9; i++){
        checkRow[i] = new bool[10]{};
        checkCol[i] = new bool[10]{};
        checkBox[i] = new bool[10]{};

    }

    input();
}

void End(){
    for(int i=0; i<9; i++){
        delete(checkRow[i]);
        delete(checkCol[i]);
        delete(checkBox[i]);
    }

    delete(checkRow);
    delete(checkCol);
    delete(checkBox);

    exit(0);

}

void run(int i, int j){

    if(i == 9){
        for(auto row: sudoku){
            for(auto n: row) cout << n;
            cout << endl;
        }

        End();

        return;
    }

    int now = sudoku.at(i).at(j);

    if(now == 0){
        for(int next=1; next<10; next++){
            int boxIdx = (i/3 * 3)+j/3;
            if(!checkRow[i][next] && !checkCol[j][next] &&
               !checkBox[boxIdx][next]){
                checkRow[i][next]      = true;
                checkCol[j][next]      = true;
                checkBox[boxIdx][next] = true;
                sudoku.at(i).at(j) = next;

                if(j+1 < 9) run(i  , j+1);
                else        run(i+1, 0  );

                checkRow[i][next]      = false;
                checkCol[j][next]      = false;
                checkBox[boxIdx][next] = false;
                sudoku.at(i).at(j) = 0;
            }
        }
    }

    else if(j+1 < 9) run(i  , j+1);
    else             run(i+1, 0  );

}




int main()
{


    Init();

    run(0,0);

    return 0;
}
