#include<bits/stdc++.h>
using namespace std;

int cnt1 = 0,cnt2=0;

//function to return a random number:
int randNum(){
    int x = rand() % 3 + 1;
    if(x==0){
        randNum();
    }
    return x;
}

//function to declare the winner:

void winner(int ch,int x) {
    if(ch==1) {
        if(x==1) cout<<"---------------- draw ----------------"<<endl;
        if(x==2){
            cout<<"---------------- player 2 won ----------------"<<endl;
            cnt2++;
        }   
        if(x==3){
            cout<<"---------------- player 1 won ----------------"<<endl;
            cnt1++;
        }
    }
    else if(ch==2) {
        if(x==2) cout<<"---------------- draw ----------------"<<endl;
        if(x==3){
            cout<<"---------------- player 2 won ----------------"<<endl;
            cnt2++;
        }
        if(x==1){
            cout<<"---------------- player 1 won ----------------"<<endl;
            cnt1++;
        }
    }
    else if(ch==3) {
        if(x==3) cout<<"---------------- draw ----------------"<<endl;
        if(x==1){
            cout<<"---------------- player 2 won ----------------"<<endl;
            cnt2++;
        }
        if(x==2){
            cout<<"---------------- player 1 won ----------------"<<endl;
            cnt1++;
        }
    }
}

//function to print rock:
void rock() {
    cout<<"______"<<endl;
    cout<<"---'(__)_"<<endl;
    cout<<"      (___)"<<endl;
    cout<<"      (___)"<<endl;
    cout<<"      (__)"<<endl;
    cout<<"--._(__)"<<endl;
};

//function to print paper:
void paper() {
    cout<<"_________"<<endl;
    cout<<"----' ___)__"<<endl;
    cout<<"      ______)"<<endl;
    cout<<"      ______)"<<endl;
    cout<<"      _____)"<<endl;
    cout<<"---.______)"<<endl;
};

//function to print scissor:
void scissor() {
    cout<<"_________"<<endl;
    cout<<"----' (__)____"<<endl;
    cout<<"      _______)"<<endl;
    cout<<"      _______)"<<endl;
    cout<<"      _(__)"<<endl;
    cout<<"---._(__)"<<endl;
};

//function to print the bots choice:
void bot_choice(int x) {
    if(x==1){
        rock();
    }
    if(x==2){
        paper();
    }
    if(x==3){
        scissor();
    }
}

//function to tell the choice of the bot:
void bot_choice_name(int x) {
    if(x==1){
        cout<<"rock";
    }
    else if(x==2){
        cout<<"paper";
    }
    else if(x==3){
        cout<<"scissor";
    }
}

//main function:
int main() {
    srand(time(NULL));
    system("clear");

    int n;
    cout<<"enter 1 if u have a gf to play with :\nenter 0 if bot is ur only friend : "<<endl;
    cin>>n;

    if(n==0) {
    int t;
    cout<<"enter the number of chances : "<<endl;
    cin>>t;
    while(t--) {
        int x = randNum();
        int choice;
        cout<<"1 for rock"<<endl;
        //rock();
        cout<<"2 for paper"<<endl;
       // paper();
        cout<<"3 for scissor"<<endl;
        //scissor();
        cin>>choice;
        cout<<endl;
        cout<<endl;
        if(choice==1) {
            cout<<"-----your choice : rock"<<endl;
            rock();
            cout<<endl;
            cout<<"-----bots choice : ";
            bot_choice_name(x);
            cout<<endl;
            bot_choice(x);
            cout<<endl;
            winner(choice,x);
        }
        else if(choice==2) {
            cout<<"-----your choice : paper"<<endl;
            paper();
            cout<<endl;
            cout<<"-----bots choice : ";
            bot_choice_name(x);
            cout<<endl;
            bot_choice(x);
            cout<<endl;
            winner(choice,x);
        }
        else if(choice==3) {
            cout<<"-----your choice : scissor"<<endl;
            scissor();
            cout<<endl;
            cout<<"-----bots choice : ";
            bot_choice_name(x);
            cout<<endl;
            bot_choice(x);
            cout<<endl;
            winner(choice,x);
        }

    }
    }
    else if(n==1) {
       int t;
       cout<<"enter the number of chances : "<<endl;
       cin>>t;
       while(t--) {
        int choice1,choice2;
        cout<<setw(10)<<setfill(' ')<<"player 1 choose"<<endl;
        cout<<"1 for rock"<<endl;
        //rock();
        cout<<"2 for paper"<<endl;
       // paper();
        cout<<"3 for scissor"<<endl;
        //scissor();
        cin>>choice1;
        cout<<endl;

        cout<<setw(10)<<setfill(' ')<<"player 2 choose"<<endl;
        cout<<"1 for rock"<<endl;
        //rock();
        cout<<"2 for paper"<<endl;
       // paper();
        cout<<"3 for scissor"<<endl;
        //scissor();
        cin>>choice2;

        cout<<endl;
        cout<<endl;

        if(choice1==1) {
            cout<<"-----your choice : rock "<<endl;
            rock();
            cout<<endl;
            cout<<"-----gf's choice : ";
            bot_choice_name(choice2);
            cout<<endl;
            bot_choice(choice2);
            cout<<endl;
            winner(choice1,choice2);
        }
        else if(choice1==2) {
            cout<<"-----your choice : paper "<<endl;
            paper();
            cout<<endl;
            cout<<"-----gf's choice : ";
            bot_choice_name(choice2);
            cout<<endl;
            bot_choice(choice2);
            cout<<endl;
            winner(choice1,choice2);
        }
        else if(choice1==3) {
            cout<<"-----your choice : scissor "<<endl;
            scissor();
            cout<<endl;
            cout<<"-----bots choice : ";
            bot_choice_name(choice2);
            cout<<endl;
            bot_choice(choice2);
            cout<<endl;
            winner(choice1,choice2);
        }
       }
    }
    cout<<endl;
    cout<<endl;
    //final display of score:
    cout<<"-------------------"<<endl;
    cout<<"|players  |scores |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"|player 1 |  "<<cnt1<<"    |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"|player 2 |  "<<cnt2<<"    |"<<endl;
    cout<<"-------------------"<<endl;


    if(cnt1>cnt2) cout<<"----------------------- player 1 won the series --------------------"<<endl;
    else if(cnt1<cnt2) cout<<"----------------------- player 2 won the series --------------------"<<endl;
} 