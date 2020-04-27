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

void getSize2(string str){
    int l = str.length();
    map<char, int> m;
    vector<pair<int, pair<int, int> > > vec;
    if(l == 1){
        cout<<"1";
        return;
    }
    //m[str[0]] = 1;
    int k = 1;
    for(int i=0;i<l;i++){
        if(m.count(str[i]) == 0){
            if(i == l-1){
                m[str[i]] == k;
                vec.push_back(make_pair(i, make_pair(-1, k)));
            }
            else {
                m[str[i]] = k;
                vec.push_back(make_pair(i, make_pair(-1, k)));
                k++;
            }
            /*else{
                m[str[i]] = k;
                vec.push_back(make_pair(i, make_pair(m[str[i+1]], k)));
                k++;
            }*/
        }
        else{
            vec.push_back(make_pair(i, make_pair(m[str[i]], m[str[i]])));
        }
    }
    for(int i=0;i<l;i++){
        cout<<vec[i].first<<"  "<<vec[i].second.first<<"  "<<vec[i].second.second<<endl;
    }
    vector<pair<int, pair<int, int> > > adj;
    int temp = -1;
    for(int i=l-1;i>=0;i--){
        if(vec[i].second.second == vec[i].second.first){
            temp = vec[i].second.second;
        }
        else if(vec[i].second.second > vec[i].second.first && vec[i].second.second >= temp){
            vec[i].second.first = temp;
        }
    }

}

int main(){
    string str;
    cin>>str;
    //getSize(str);
    getSize2(str);
}
