#include <bits/stdc++.h>

using namespace std;

int R, C, ans = 0;
char alpha;

bool check[27] = {0,};

vector<vector<char>> amap;

void dfs(int i, int j, int len){
    ans = max(ans, len);


    if(j-1>=0){
        int next = amap.at(i).at(j-1) - 'A';
        if(!check[next]){
            check[next] = true;
            dfs(i, j-1, len+1);
            check[next] = false;
        }
    }

    if(j+1<C){
        int next = amap.at(i).at(j+1) - 'A';
        if(!check[next]){
            check[next] = true;
            dfs(i, j+1, len+1);
            check[next] = false;
        }
    }

    if(i-1>=0){
        int next = amap.at(i-1).at(j) - 'A';
        if(!check[next]){
            check[next] =true;
            dfs(i-1, j, len+1);
            check[next] = false;
        }
    }

    if(i+1<R){
        int next = amap.at(i+1).at(j) - 'A';
        if(!check[next]){
            check[next] = true;
            dfs(i+1, j, len+1);
            check[next] = false;
        }
    }





}

int main()
{
   cin >> R >>C;

   amap.resize(R);
   for(auto& row: amap){
    row.resize(C);
    for(auto& c: row) cin >> c;
   }

   int start = amap.front().front() - 'A';
   check[start] = true;
   dfs(0, 0, 1);

   cout << ans;


    return 0;
}
