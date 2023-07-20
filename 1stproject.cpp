#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp{
    string userName,Email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signup();
    void forget();
    
}obj;



int main(){ // Here user selecting a option.
    char choice;
    cout<<"\n-1 Login";
    cout<<"\n-2 Sign-up";
    cout<<"\n-3 Forgot Password";
    cout<<"\n-4 Exit";
    cout<<"\n Enter your choice :: ";
    cin>>choice;
    
    switch (choice){
        case '1':
            obj.login();
        break;
            
        case '2':
            obj.signUp();
        break;
        
        case '3':
            obj.forgot();
        break;
        
        case '4':
            return 0;
        break;
        defualt:
            cout<<"Invalid Selection...!";
    }
}



void temp :: signup(){
    cout<<"\nEnter your User name :: ";
    getline(cin,userName);
    
    cout<<"\nEnter your email address :: ";
    getline(cin,Email);
    
    cout<<"\nEnter your password :: ";
    getline(cin,password);
    
    file.open("loginData.text",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    fileclose();
    
    
}

void temp :: login(){
    
    cout<<".........LOGIN...........";
    cout<<"Enter your user name :: ";
    getline(cin,searchName);
    cout<<"Enter your password :: ";
    getline(cin,searchpass);
    
    file.open("loginData.txt"ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if (userName==searchName){
            if(password==searchpass){
                cout<<"\n Account Login Successfull...!";
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            }else{
                cout<<"Password is incorrect..!"
            }
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    
        
    }
    file.close();
    
    
    
}

void forgot(){
    cout<<"\nEnter your user name :: ";
    getline(cin,searchName);
    cout<<"\nEnter your Email address :: ";
    getline(cin,searchEmail);
    
    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    
    while(!file.eof()){
        if (userName==searchName){
            if (Email==searchEmail){
                cout<<"\nAccount found...";
                cout<<"Your password :: "<<password<<endl;
            }else{
                ciut<<"Account not found...!\n";
            }
        }else{
            cout<<"\nAccount not found..!\n";
        }
    }
    file.close();
}
