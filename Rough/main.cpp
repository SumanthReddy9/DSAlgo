#include<bits/stdc++.h>

using namespace std;

class base{
public:
    base(){
        cout<<"Hello"<<endl;
    }
    virtual void print(){
        cout<<"Print base class"<<endl;
    }
    void show(){
        cout<<"Show base class"<<endl;
    }
};

class derived : public base{
public:
    derived() : base(){
        cout<<"Hi"<<endl;
    }
    virtual void print(){
        cout<<"Print derived class"<<endl;
    }
    void show(){
        cout<<"Show derived class"<<endl;
    }
};

int main() {
      //base *b = new derived();
      //b->print();
      //b->show();
      derived d;
      d.print();
}
