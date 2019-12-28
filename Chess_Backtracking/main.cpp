#include<bits/stdc++.h>
using namespace std;
int ch[100][100];

bool isSafe(int n, int row, int col){
    for(int i=0;i<n;i++){
        if(ch[row][i] == 1){
            return false;
        }
    }
    for(int i=row, j=col; i>=0, j>=0; i--, j--){
        if(ch[i][j] == 1){
            return false;
        }
    }
    for(int i=row, j=col; i<n, j>=0; i++, j--){
        if(ch[i][j] == 1){
            return false;
        }
    }
    return true;
}

bool placeQueens(int n, int col){
    if(col >= n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(n, i, col)){
            ch[i][col] = 1;
            if(placeQueens(n, col+1)){
                for(int x=0;x<n;x++){
                    for(int y=0;y<n;y++){
                        cout<<ch[x][y]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                //return true;
            }
            ch[i][col] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            ch[i][j] = 0;
        }
    }
    placeQueens(n, 0);
}
