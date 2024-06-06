/*
    - linked list to create a connection and add basic details [DONE]
    - display of the cases [DONE]
    - add location [DONE]
    - add admin login [DONE]
    - add desctription [DONE]
    - add a system to delete the case files which are solved. - create admin. create user. [DONE]
    - only admin can see all the cases.[DONE]
    - figure out how to store data in excel. [DONE]
    - Can u make the excel responsive? [DONE]
    - make only the admin to view all the cases [DONE]
    - make a FIR output sheet. [DONE]
    - use time library to register time of entry into report. [DONE]
    - make the admin update the time of solving the case. [NOT DONE]
    - if case is solved clear screen and display happy message. [DONE]
    - add time into complaints.[DONE]
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
#include<unistd.h>
#include<ctime>
#include <thread>
#include <chrono>


using namespace std;

string password = "hello";

string get_current_time();

class complaint {
    public:
        int number;
        string name;
        int age;
        string gender;
        string status;
        string loc;
        string description;
        complaint* next;

        complaint(int number,string name,int age , string gender,string status,string loc,string description) {
            this->number = number;
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->status = status;
            this->loc = loc;
            this->description = description;
            this->next = nullptr;
        }
};

class linkedlist {
    private:
        complaint* head;
        complaint* tail;
        int len;

    public:
        linkedlist(int number,string name,int age , string gender,string status,string loc,string description) {
            complaint* newnode = new complaint(number,name,age,gender,status,loc,description);
            head = newnode;
            tail = newnode;
            len++;
        }
    int display() {
        if(head==nullptr) return 0;

        complaint* temp = head;
        while(temp) {
            cout<<"complaint number:"<<temp->number<<endl;
            cout<<"complaint name:"<<temp->name<<endl;
            cout<<"complaint age:"<<temp->age<<endl;
            cout<<"complaint gender:"<<temp->gender<<endl;
            cout<<"complaint status:"<<temp->status<<endl;
            cout<<"location : "<<temp->loc<<endl;
            cout<<"description : "<<temp->description<<endl;
            cout<<"the current time is : "<<get_current_time();
            cout<<endl;
            cout<<"********************************"<<endl;
            cout<<endl;
            cout<<endl;
            temp = temp->next;
        }
        return 0;
    }

    void addatback(int number,string name,int age,string gender , string status,string loc,string description) {
        
        complaint* newnode = new complaint(number,name,age,gender,status,loc,description);

        if(head==nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
        len++;
    }
    void displayupdates(int number) 
    {
        complaint* temp = head;
        while(temp->number != number){
            temp = temp->next;
        }
        cout<<"the current status of the case number"<<number<<" is : "<<temp->status<<endl;
        chrono::seconds sleep_duration(2);
        this_thread::sleep_for(sleep_duration);

        system("clear");

        cout<<"*********** CASE NUMBER"<<temp->number<<" IS SOLVED **********";
        cout<<endl;
        cout<<endl;
    }

    void displayfir() {
    
    int number;
    cout<<"enter case number to get the copy of an FIR : "<<endl;
    cin>>number;

    system("clear");
    complaint* temp = head;
        while(temp->number != number){
            temp = temp->next;
        }
    
    int n = temp->description.size();
    int splitPosition = 35;
    int i = 0;
    int flag = 0;
    string part1,part2,part3,part4,part5,part6,part7,part8,part9;
    
    if(n-splitPosition >35) {
        part1 = temp->description.substr(i,splitPosition);
        i+=35;
        flag++;
        if(n-splitPosition >35) {
            part2 = temp->description.substr(i,splitPosition);
            i+=35;
            flag++;
            if(n-splitPosition >35) {
                part3 = temp->description.substr(i,splitPosition);   
                i+=35;
                flag++;
                if(n-splitPosition >35) {
                    part4 = temp->description.substr(i,splitPosition);
                    i+=35;
                    flag++;
                    if(n-splitPosition >35) {
                        part5 = temp->description.substr(i,splitPosition); 
                        flag++;     
                    }
                    else {
                        part6 = temp->description.substr(splitPosition);
                        flag++;
                        }      
                    }
                else {
                    part7 = temp->description.substr(splitPosition);
                    flag++;
                }   
            }
        }
        else {
            part8 = temp->description.substr(splitPosition);
            flag++;
        }
    }
    else 
    {
        part9 = temp->description.substr(splitPosition);
        flag++;
    }
    string x = get_current_time();
    cout << setfill(' ') << setw(41) << "FIR REPORT\n";
    cout << setfill('-')<< setw(69) << ""<<endl;
	cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"current time : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<x<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
	cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"case number : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<number<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"name : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->name<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"age : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->age<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"gender : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->gender<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"location : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->loc<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;

    cout<<"|"<<setfill(' ')<< setw(15)<<"description : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(1)<<part1<<" |"<<endl;
    if(part2.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part2<<" |"<<endl;
    }
     else if(part9.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part9<<" |"<<endl;
    }
    if(part3.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part3<<" |"<<endl;
    }
    else if(part8.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part8<<" |"<<endl;
    }
    if(part4.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part4<<" |"<<endl;
    }
    else if(part7.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part7<<" |"<<endl;
    }
    if(part5.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part5<<setfill(' ')<< setw(31)<<" |"<<endl;
    }
    else if(part6.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(30)<<part6<<setfill(' ')<< setw(30)<<" |"<<endl;
    }    
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<" |"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    }

    void caseupdates(int number) {
        complaint* temp = head;

        while(temp) {
            if(temp->number == number) {
                cout<<"status of the case has been changed to solved"<<endl;
                temp->status = "solved";
                break;
            }
            else {
                temp = temp->next;
            }
        }
        //cout<<"number not present"<<endl;
    }

    complaint* gethead() {
        if(head==nullptr) 
        return nullptr;
        else
        return head;
    }
    
};

int admin()
{
    string password1;
    system("clear");
    cout<<"enter the password "<<endl;
    cin>>password1;

    if(password1 == password)
        return 0;
    else
        return 1;
}

void writeToFile(linkedlist* ll, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    complaint* temp = ll->gethead(); // Assuming you have a getter for the head in linkedlist class

    while (temp) {
        outFile << temp->number << ',' << temp->name << ',' << temp->age << ',' << temp->gender
                << ',' << temp->status << ',' << temp->loc << ',' << temp->description << '\n';

        temp = temp->next;
    }

    outFile.close();
    cout << "Data written to file successfully." << endl;
}

void readFromFile(linkedlist* ll, const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening the file for reading." << endl;
        return;
    }
    complaint* temp = ll->gethead();
    int num = temp->number;
    int age = temp->age;
    string name = temp->name;
    string gen = temp->gender;
    string status = temp->status;
    string loc = temp->loc;
    string description = temp->description;
    
    while (inFile >> num >> ws && getline(inFile, name, ',') >> ws >> age >> ws
                    && getline(inFile, gen, ',') >> ws && getline(inFile, status, ',') >> ws
                    && getline(inFile, loc, ',') >> ws && getline(inFile, description)) {
        //ll->addatback(num, name, age, gen, status, loc, description);
    }

    inFile.close();
    cout << "Data present in the  file ." << endl;
}

void displayFromFile(linkedlist *ll ,const string& filename , int cases) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening the file for reading." << endl;
        return;
    }

    complaint* temp = ll->gethead();
    int num = temp->number;
    int age = temp->age;
    string name = temp->name;
    string gen = temp->gender;
    string status = temp->status;
    string loc = temp->loc;
    string description = temp->description;
    int j = 0;

    string x = get_current_time();
    string y = get_current_time();

while(temp!= nullptr && j<cases) {
    
    int n = temp->description.size();
    int splitPosition = 35;
    int i = 0;
    int flag = 0;
    string part1,part2,part3,part4,part5,part6,part7,part8,part9;
    
    if(n-splitPosition >35) {
        part1 = temp->description.substr(i,splitPosition);
        i+=35;
        flag++;
        if(n-splitPosition >35) {
            part2 = temp->description.substr(i,splitPosition);
            i+=35;
            flag++;
            if(n-splitPosition >35) {
                part3 = temp->description.substr(i,splitPosition);   
                i+=35;
                flag++;
                if(n-splitPosition >35) {
                    part4 = temp->description.substr(i,splitPosition);
                    i+=35;
                    flag++;
                    if(n-splitPosition >35) {
                        part5 = temp->description.substr(i,splitPosition); 
                        flag++;     
                    }
                    else {
                        part6 = temp->description.substr(splitPosition);
                        flag++;
                        }      
                    }
                else {
                    part7 = temp->description.substr(splitPosition);
                    flag++;
                }   
            }
        }
        else {
            part8 = temp->description.substr(splitPosition);
            flag++;
        }
    }
    else 
    {
        part9 = temp->description.substr(splitPosition);
        flag++;
    }   
    cout << setfill(' ') << setw(41) << "FIR REPORT\n";
    cout << setfill('-')<< setw(69) << ""<<endl;
	cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"case number : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<x<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
	cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"case number : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->number<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"name : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->name<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"age : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->age<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"gender : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->gender<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<< setw(15)<<"location : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(35)<<temp->loc<<" |"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<"|"<<endl;

    cout<<"|"<<setfill(' ')<< setw(15)<<"description : "<<setfill(' ')<< setw(16)<<"|"<<setfill(' ')<< setw(1)<<part1<<" |"<<endl;
    if(part2.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part2<<" |"<<endl;
    }
     else if(part9.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part9<<" |"<<endl;
    }
    if(part3.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part3<<" |"<<endl;
    }
    else if(part8.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part8<<" |"<<endl;
    }
    if(part4.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part4<<" |"<<endl;
    }
    else if(part7.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part7<<" |"<<endl;
    }
    if(part5.size()!=0) {
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(1)<<part5<<setfill(' ')<< setw(31)<<" |"<<endl;
    }
    else if(part6.size()!=0){
        cout<<"|"<<setfill(' ')<< setw(31)<<"|"<<setfill(' ')<< setw(30)<<part6<<setfill(' ')<< setw(30)<<" |"<<endl;
    }    
    cout << "| " <<setfill(' ')<< setw(30)<<"|"<<setfill(' ')<< setw(37)<<" |"<<endl;
    cout << setfill('-')<< setw(69) << ""<<endl;
    cout<<endl;
    
    j++;
    temp = temp->next;

    }

    inFile.close();
    cout << "Data displayed from file successfully." << endl;
}

string get_current_time() {
    time_t raw_time;
    time(&raw_time);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&raw_time));

    return buffer;
}


void frontpage() {
    system("clear");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << setfill(' ')<<setw(50);
    cout<<"FIR REPORT MANAGEMENT SYSTEM"<<endl;
    cout<<endl;
    cout<<endl;
    cout << setfill(' ')<<setw(80)<<"- T RAHUL PRABHU (1DS22AI056)"<<endl;
    cout<<setfill(' ')<<setw(78)<<"ADITHYA H A (1DS22AI004) "<<endl;
    cout<<setfill(' ')<<setw(77)<<"SAMARTH D S (1DS22AI044)"<<endl;
    cout<<setfill(' ')<<setw(80)<<"SNEHA P PRATAP (1DS22AI051)"<<endl;

    int q;
    cout<<"press 1 to continue :"<<endl;
    cin>>q;
    if(q==1) return ;

}

int main() 
{
    system("clear");
    frontpage();
    linkedlist* ll = new linkedlist(101,"rahul D S ",21,"male","unsolved","hanumnathanagar","This is a general case of dowry and hit and run versus Salman Khan murdered a black buck and paid enough money to get his daughter-in-law married.");

    int num,age,n,n1,n2,n3,num12,num123,num1234;
    int cases = 1;
    string gen,name,loc,description;
    string current_time = get_current_time();
    string status = "unsolved";

    //readFromFile(ll, "complaints.txt");
   // displayFromFile(ll,"complaints.txt",cases);

    cout<<"******************************* FIR *******************************"<<endl;
    
    while(1) {
    label3:
    cout<<"enter:\n1 for admin\n2 for user"<<endl;
    cin>>n1;

    if(n1 == 2){
        goto label1;
        }
    else if(n1==1) {
    int val = admin();

    if(val==0){
    cout<<"successful login into admin"<<endl;
    goto label;
    }
    else {
    cout<<"admin login unsuccessful ! "<<endl;
    goto label1;
        }
    }    

    label1:
    cout<<"********************************"<<endl;
    cout<<"enter a choice :\n1)entry of a complaint\n2)checking for updates\n3)display of FIR report \n4)exit"<<endl;
    cout<<"********************************"<<endl;
    cin>>n;
    switch (n)
    {   
    case 1:
    {
        cout<<"enter file number : "<<endl;
        cin>>num;
            cin.ignore();
            cout<<"enter name : "<<endl;
            getline(cin,name);
            cout<<"enter age : "<<endl;
            cin>>age;
            cout<<"enter gender : "<<endl;
            cin>>gen;
            cin.ignore();
            cout<<"enter location : "<<endl;
            getline(cin,loc);
            cin.ignore();
            cout<<"enter description : "<<endl;
            getline(cin,description);
            ll->addatback(num,name,age,gen,status,loc,description);
            writeToFile(ll, "complaints.txt");
            cases++;
            }
            break;
    
         case 2:
            cout<<"enter which case : "<<endl;
            cin>>num1234;
            ll->displayupdates(num1234);
            break;

        case 3:
            
            ll->displayfir();
            break;
    
        case 4:
            exit(0);
            break;
    
        default:
            cout<<"choice error!"<<endl;
            break;
        }
    }

    label:
    
    while(1) {
        cout<<"enter:\n1 to check all the cases\n2 Update the status of the case\n3 to read data from files "<<endl;
        cin>>n2;

        switch(n2)
        {      
            case 1 : 
                ll->display();
                goto label3;
                break;

            case 2:
                cout<<"enter the case number which has to be updates"<<endl;
                cin>>num12;
                ll->caseupdates(num12);
                cout<<endl;
                cout<<"enter:\n1 to continue \n0 to skip"<<endl;
                cin>>n3;
                if(n3==0){
                    goto label1;        
                }
                else {
                continue;
                }
                break;

            case 3:
                displayFromFile(ll,"complaints.txt",cases);
                break;
            default:
                cout<<"error"<<endl;
                break;
        }
    }
    return 0;
}


