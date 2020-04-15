#include<bits/stdc++.h>
using namespace std;

void getSize(string str){
    vector<char> vec;
    vector<int> ans;
    for(int i=0;i<str.length();i++){
        int tempIdx = 0;
        if(i == str.length() - 1){
            ans.push_back(1);
        }
        else{
            for(int j=i+1; j<str.length();j++){
                if(str[i] == str[j]){
                    tempIdx = j;
                }
            }
            if(tempIdx == 0){
                ans.push_back(1);
            }
            else if(tempIdx == str.length()-1){
                ans.push_back(str.length() - i);
                break;
            }
            else{
                for(int k=i;k<=tempIdx;k++){
                    vec.push_back(str[k]);
                }
                int t = tempIdx+1;
                int tempt = tempIdx+1;
                for(int k = tempIdx+1; k<str.length(); k++){
                    if(find(vec.begin(), vec.end(), str[k]) != vec.end()){
                        t = k+1;
                    }
                }
                ans.push_back(t - i);
                i = t-1;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
}

int main(){
    string str;
    cin>>str;
    getSize(str);
}
