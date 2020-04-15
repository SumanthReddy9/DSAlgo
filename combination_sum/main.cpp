/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]
*/

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int> > &sol, vector<int> &res, vector<int> &com, int i, int n, int k){
    if(n < 0)
        return;
    else{
        if(n == 0 && res.size() == k){
            sol.push_back(res);
        }else{
            for(int j=i; j<com.size();j++){
                res.push_back(com[j]);
                DFS(sol, res, com, j+1, n-com[j], k);
                res.pop_back();
            }
        }
    }
}

void getComSum(int k, int n){
    vector<vector<int> > sol;
    vector<int> res;
    vector<int> com(9);
    for(int i=1;i<=9;i++)
        com[i-1] = i;
    DFS(sol, res, com, 0, n, k);
    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++){
            cout<<sol[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int k, n;
    cin>>k>>n;
    getComSum(k, n
              );
}
