#include<iostream>
#include<cstdlib>
#include<direct.h>
#include<fstream>
#include<iostream>
using namespace std;
void removeHash(string path){
	ofstream fio(path,ios::in,ios::out);
	if(fio.is_open()){
		string find=path+":";
		remove(find);
	}
}
bool isPasswordCracked() {
    ifstream file("passworddd.txt");
    string line;
    while (getline(file, line)) {
        if (line.find("No password hashes left to crack") != std::string::npos) {
            return true;  
        }
    }
    return false;  
}
int main(){
	int opt,type;
	string path,command,pass;
	char data;
	cout<<"\033[0;31m";
    cout<<"---------------------------------------------------------------------------------------------------- \n";
    cout<<
        "TTTTTTTTTTTTTTTTTTTTTT TRRRRRRRRRRRRRRRRR    EEEEEEEEEEEEEEEEEEEEEE  XXXXXXX       XXXXXXX\n"
        "T:::::::::::::::::::::T R::::::::::::::::R   E::::::::::::::::::::E  X:::::X       X:::::X\n"
        "T:::::TT:::::::TT:::::T RR:::::R     R:::::R EE::::::EEEEEEEEE::::E  X::::::X     X::::::X\n"
        "TTTTTT  T:::::T  TTTTTT   R::::R     R:::::R  E:::::E       EEEEEE    XXX:::::X   X:::::XX\n"
        "        T:::::T           R::::R     R:::::R  E:::::E                  X:::::X X:::::X    \n"
        "        T:::::T           R::::RRRRRR:::::R   E::::::EEEEEEEEEE         X:::::X:::::X     \n"
        "        T:::::T           R::::RRRRRR:::::R   E:::::::::::::::E          X:::::::::X      \n"
        "        T:::::T           R::::R     R:::::R  E::::::EEEEEEEEEE         X:::::X:::::X     \n"
        "        T:::::T           R::::R     R:::::R  E:::::E                  X:::::X X:::::X    \n"
        "        T:::::T           R::::R     R:::::R  E:::::E       EEEEEE    XXX:::::X   X:::::XX\n"
        "      TT:::::::TT       RR:::::R     R:::::R  EE::::::EEEEEEEE::::E  X::::::X     X::::::X\n"
        "      T:::::::::T       R::::::R     R:::::R  E::::::::::::::::::::E X:::::X       X:::::X\n"
        "      TTTTTTTTTTT       RRRRRRRR     RRRRRRR  EEEEEEEEEEEEEEEEEEEEEE XXXXXXX       XXXXXXX\n"
    ;
    cout<<"---------------------------------------------------------------------------------------------------- \n";
    cout<<"\033[0m";
	cout<<"\033[3;33m\n\t select your file type \n\033[0m";
	cout<<"\033[34m\n \t\t 1)pdf \n \t\t 2)zip \n \t\t 3)7zip\033[0m";
	cout<<"\n \033[34mTREX $\033[0m Enter Option : ";
	cin>>opt;
	cout<<"\033[3;33m\n\t select type of attack \n\033[0m";
	cout<<"\033[34m\n \t\t 1)Dictionary \n \t\t 2)Brute Force \033[0m";
	cout<<"\n \033[34mTREX $\033[0m Enter Option : ";
	cin>>type;
	switch(opt){
		case 1:
			switch(type){
				case 1:
					cout<<"\n \033[34mTREX $\033[0m Enter Path of the pdf file : ";
					cin>>path;
					if (_chdir("john\\run") != 0) {
		                cerr << "Error: Could not change directory to john\\run\n";
		                return 1;
		            }
					command =command = "perl pdf2john.pl \"" + path + 
          "\" | (Get-Content hash.txt) -replace "path+':'", "" | Set-Content hash.txt\"";

		    		if(system(command.c_str())==0){
		    			cout<<"Hash Extracted \n";	
					}
					system("john --wordlist=pas.txt hash.txt > passworddd.txt");
					if(isPasswordCracked()){
						system("john --show hash.txt");
					}
					if(!isPasswordCracked()){
						system("type passworddd.txt");
					}
					system("del passworddd.txt");
					system("del hash.txt");
					break;
				case 2:
					cout<<"\n \033[34mTREX $\033[0m Enter Path of the pdf file : ";
					cin>>path;
					if (_chdir("john\\run") != 0) {
		                cerr << "Error: Could not change directory to john\\run\n";
		                return 1;
		            }
		            command = "perl pdf2john.pl \"" + path + "\" | powershell -Command \"$input -split ':',2 | Select -Last 1 | Set-Content hash.txt\"";
		    		if(system(command.c_str())==0){
		    			cout<<"Hash Extracted \n";	
					}
					cout<<"\n \033[34mTREX $\033[0m Do you know any clues about password \033[1;33m[y/n]\033[0m : ";
					cin>>data;
					if(data=='y'){
						cout<<"what do you know about password enter like an example [4-digits,4-numbers as AAAA0000] :";
					}
					else{
						system("john --incremental hash.txt");
					}
					break;
			}
			break;
	}
	
}
