#include<bits/stdc++.h>
using namespace std;

int arr[100][100];

void initVal(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            arr[i][j] = 0;
        }
    }
}

void goRight(int x, int y, int& temps1, int& temps2, int& temps3, int& temps4, int n){
    //cout<<"Hello1"<<endl;
    for(int i=0;i<x+1;i++){
        temps1 += arr[i][y];
        temps2 -= arr[i][y];
    }
    for(int i = x+1; i < n; i++){
        temps3 += arr[i][y];
        temps4 -= arr[i][y];
    }
}

void goLeft(int x, int y, int &temps1, int &temps2, int &temps3, int &temps4, int n){
    //cout<<"Hello2"<<endl;
    for(int i=0;i<x+1;i++){
        temps1 -= arr[i][y];
        temps2 += arr[i][y];
    }
    for(int i=x+1;i<n;i++){
        temps3 -= arr[i][y];
        temps4 += arr[i][y];
    }
}

void goDownL(int x, int y, int &temps1, int &temps2, int &temps3, int &temps4, int n){
    //cout<<"Hello3"<<endl;
    temps1 += arr[x+1][y];
    for(int i=1;i<n;i++){
        temps2 += arr[x+1][i];
    }
    temps3 -= arr[x+1][y];
    for(int i=1;i<n;i++){
        temps4 -= arr[x+1][i];
    }
}

void goDownR(int x, int y, int &temps1, int &temps2, int &temps3, int &temps4, int n){
    //cout<<"Hello4"<<endl;
    temps2 += arr[x+1][y];
    for(int i=0;i<n-1;i++){
        temps1 += arr[x+1][i];
    }
    temps4 -= arr[x+1][y];
    for(int i=0;i<n-1;i++){
        temps3 -= arr[x+1][i];
    }
}

int getabs(int s1, int s2, int s3, int s4){
    return (abs(s1) + abs(s2) + abs(s3) + abs(s4));
}

int main(){
    int n;
    cin>>n;
    initVal();
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    s1 = arr[0][0];
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            s4 += arr[i][j];
        }
        s2 += arr[0][i];
        s3 += arr[i][0];
    }
    int temps1 = s1, temps2 = s2, temps3 = s3, temps4 = s4;
    int f = 1, r = 0, l = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(i + j != 0){
                if(f == 1){
                    if(r == 0){
                        //cout<<"Hello1"<<endl;
                        goRight(i, j, temps1, temps2, temps3, temps4, n);
                    }
                    else
                        r = 0;
                }
                else{
                    if(l == 0){
                        //cout<<"Hello2"<<endl;
                        goLeft(i, n-j-1, temps1, temps2, temps3, temps4, n);
                    }
                    else
                        l = 0;
                }
                if(getabs(temps1, temps2, temps3, temps4) > getabs(s1, s2, s3, s4)){
                        s1 = temps1;
                        s2 = temps2;
                        s3 = temps3;
                        s4 = temps4;
                }
            }
            //cout<<temps1<<" "<<temps2<<" "<<temps3<<" "<<temps4<<endl;
        }
        if(i < n-2){
            if(f == 1){
                goDownR(i, n-1, temps1, temps2, temps3, temps4, n);
                f = 0;
                l = 1;
            }
            else{
                goDownL(i, 0, temps1, temps2, temps3, temps4, n);
                f = 1;
                r = 1;
            }
        }
        if(getabs(temps1, temps2, temps3, temps4) > getabs(s1, s2, s3, s4)){
                s1 = temps1;
                s2 = temps2;
                s3 = temps3;
                s4 = temps4;
        }
        //cout<<temps1<<" "<<temps2<<" "<<temps3<<" "<<temps4<<endl;
    }
    //cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
    cout<<getabs(s1, s2, s3, s4);
}
