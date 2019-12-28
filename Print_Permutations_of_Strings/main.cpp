#include<bits/stdc++.h>
using namespace std;

void getPermutations(string str, int l, int r){
    if(l == r){
        cout<<str<<endl;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(str[i], str[l]);
            getPermutations(str, l+1, r);
            swap(str[i], str[l]);
        }
    }
}

int main(){
    string str;
    cin>>str;
    int l = str.length();
    getPermutations(str, 0, l-1);
    cout<<endl;
    do{
        cout<<str<<endl;
    }while(next_permutation(str.begin(), str.end()));
}
