#include<bits/stdc++.h>
using namespace std;

bool deer_mutex	=	true;
bool elf_mutex	=	true;
bool santa_awake	=	false;
int deer_wait	=	0;
int hitch_to_sleigh	= 0;
bool toys_delivered	= false;
bool elves_enter	= false;
int elf_group	=	2;
bool question_asked	= false;
bool got_answer	=	false;


int deer_count	=	0;
int elf_count =	0;

void raindeer(){
    if(deer_count == 8){
        cout<<"Santa goes for gift distribution"<<endl;
        deer_count = 0;
        cout<<"Toys delivered"<<endl;
    }
    else{
        deer_count++;
    }
}

void elfdoubt(){
    if(elf_count == elf_group){
        cout<<"Elfs doubts got cleared"<<endl;
        elf_count = 0;
    }
    else{
        elf_count++;
    }
}

int main(){
    int input;
    while(1){
        cout<<"1.Raindeer Returns\n2. Elf doubt\n3. End\n";
        cin>>input;
        if(input == 1){
            cout<<"Raindeer Returned\n";
            raindeer();
        }
        else if(input == 2){
            cout<<"Elf got a doubt"<<endl;
            elfdoubt();
        }
        else{
            break;
        }
    }
}
