/*
Given an array of n positive integers and a positive integer s, f
ind the minimal length of a subarray of which the sum ≥ s.
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

#include<bits/stdc++.h>
using namespace std;

/*void search(vector<int> &ss, int st, int p, int q, int &res, int &s){
        if (ss[q]-ss[st] >= s && p < q){
            res = min(res, q-st);
            int mid = p + (q-p)/2;
            if (ss[mid]-ss[st] >= s){
                search(ss, st, p, mid, res, s);
            }else{
                if (mid != p){
                    search(ss,st, mid ,q,res, s);
                }
          }
        }
    }

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if (n==0) return 0;
    vector<int> ss(n+1,0);
    int res = n;

    for (int i=0;i<n;i++){
        ss[i+1] = ss[i] + nums[i];
    }

    if (ss[n] < s) return 0;

    for (int i=0;i<n;i++){
        search(ss,i, i, n,res,s);
        //cout<<res<<endl;
    }

    return res;
}*/

void bsearch(vector<int> &ss, int st, int p, int q, int &res, int &s){
    if(ss[q] - ss[st] >= s && p < q){
        res = min(res, q-st);
        int mid = (p+q)/2;
        if(ss[mid]-ss[st] >= s){
            bsearch(ss, st, p, mid, res, s);
        }
        else{
            if(p != mid){
                bsearch(ss, st, mid, q, res, s);
            }
        }
    }
}

int minSubArrayLen(int s, vector<int> &nums){
    int n = nums.size();
    vector<int> ss(n+1, 0);

    for(int i=0;i<n;i++){
        ss[i+1] = ss[i] + nums[i];
    }
    int res =n;

    if(s > ss[n])
        return 0;

    for(int i=0;i<n;i++){
        bsearch(ss, i, i, n, res, s);
    }
    return res;
}

int main(){
    int sum;
    cin>>sum;
    vector<int> nums;
    int l;
    cin>>l;
    for(int i=0;i<l;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<minSubArrayLen(sum, nums);
}
