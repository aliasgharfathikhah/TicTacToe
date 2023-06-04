#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
string namep1;
string namep2;
char ta[9]={'1','2','3','4','5','6','7','8','9'};
int count=1;
bool tr=true;
string input;
int in;
int number;
bool iswin=false;
bool isfull=false;
int amtiaz1=0,amtiaz2=0;
bool score=true;
bool edame=true;
void getNamePlayer(){
	system("cls");
	system("color B0");
	PlaySound(TEXT("player1.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cout<<" Enter Name Player1 : ";
	getline(cin,namep1);
	PlaySound(TEXT("player2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cout<<" Enter Name Player2 : ";
	getline(cin,namep2);
}
void jadval(){
	system("cls");
	cout<<endl<<endl<<endl<<endl;
	cout<<"                            Player1: "<<namep1<<" : "<<amtiaz1<<"             vs             Player2: "<<namep2<<" : "<<amtiaz2<<endl;
	cout<<"                            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %                 "<<ta[0]<<"     |     "<<ta[1]<<"     |     "<<ta[2]<<"                 %"<<endl;
	cout<<"                            %              ---------|-----------|---------              %"<<endl;
	cout<<"                            %                 "<<ta[3]<<"     |     "<<ta[4]<<"     |     "<<ta[5]<<"                 %"<<endl;
	cout<<"                            %              ---------|-----------|---------              %"<<endl;
	cout<<"                            %                 "<<ta[6]<<"     |     "<<ta[7]<<"     |     "<<ta[8]<<"                 %"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %                                                           %"<<endl;
	cout<<"                            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
}
void Eroor(){
	cout<<"\a";
	cout<<endl<<"                                                           Error! You have chosen the house of choice!";
	Beep(0,2000);
}
void Eroor2(){
	cout<<"\a";
	cout<<endl<<"                                                          Error! You did not choose a house number!";
	Beep(0,2000);
}
void NobatDadan(){
	if(count%2!=0){
		cout<<"                            [Enter number 1-9 "<<namep1<<" = X ~~~>> ";
	}else{
		cout<<"                            [Enter number 1-9 "<<namep2<<" = O ~~~>> ";
	}
}
char NobatChar(){
	if(count%2!=0){
		return 'X';
	}else{
		return 'O';
	}
}
int HowNumber(){
	int count=0;
	for(int i=49 ; i<58 ; i++){
		count++;
		if(in==i){
			return count;
		}
	}
}
void getInputPlayer(){
	NobatDadan();
	cin>>input;
	if(input.size()>1){
		Eroor2();
	}else{
	in=input[0];
		if(in>=49&&in<=57){
			if(ta[HowNumber()-1]!='X'&&ta[HowNumber()-1]!='O'){
				ta[HowNumber()-1]=NobatChar();
			}else if(ta[HowNumber()-1]=='X'||ta[HowNumber()-1]=='O'){
			Eroor();
			}
		}else if(in<49||in>57){
			Eroor2();
		}
	}
	count++;
}
int Countamtiaz(char ta){
	if(ta=='X'){
		amtiaz1++;
	}else if(ta=='O'){
		amtiaz2++;
	}
}
bool isWin(){
	if(ta[0]==ta[1]&&ta[1]==ta[2]){
		Countamtiaz(ta[0]);
		return true;
	}else if(ta[3]==ta[4]&&ta[4]==ta[5]){
		Countamtiaz(ta[3]);
		return true;
	}else if(ta[6]==ta[7]&&ta[7]==ta[8]){
		Countamtiaz(ta[6]);
		return true;
		// <--------->
	}else if(ta[0]==ta[4]&&ta[4]==ta[8]){
		Countamtiaz(ta[0]);
		return true;
	}else if(ta[2]==ta[4]&&ta[4]==ta[6]){
		Countamtiaz(ta[2]);
		return true;
		// *
	}else if(ta[0]==ta[3]&&ta[3]==ta[6]){
		Countamtiaz(ta[0]);
		return true;
	}else if(ta[1]==ta[4]&&ta[4]==ta[7]){
		Countamtiaz(ta[1]);
		return true;
	}else if(ta[2]==ta[5]&&ta[5]==ta[8]){
		Countamtiaz(ta[2]);
		return true;
		// <--------->
	}
}
bool isFull(){
	int fl;
	for(int i=0 ; i<9 ; i++){
		if(ta[i]=='X'||ta[i]=='O'){
			fl++;
		}
	}
	if(fl==9){
		amtiaz1++;
		amtiaz2++;
		return true;
	}else{
		return false;
	}
}
bool TheEnd(){
	if(edame==false){
		edame= !edame;
	}else if(isWin()==true){
		edame=false;	
	}else if(isFull()==true){
		edame=false;
	}else{
		edame=true;
	}
	return edame;
}
void win(){
	if(amtiaz1>amtiaz2){
		cout<<"                           Woooo! "<<namep1<<" is win";
	}else if(amtiaz1<amtiaz2){
		cout<<"                           Woooo! "<<namep2<<" is win";		
	}else if(amtiaz1==amtiaz2){
		cout<<"                           Woooo! "<<namep1<<" and "<<namep2<<" is win";
	}
}
char Updatejadval(){
	ta[0]='1';
	ta[1]='2';
	ta[2]='3';
	ta[3]='4';
	ta[4]='5';
	ta[5]='6';
	ta[6]='7';
	ta[7]='8';
	ta[8]='9';
	count=1;
}
int main() {
	getNamePlayer();
	PlaySound(TEXT("doz.wav"), NULL, SND_ASYNC | SND_LOOP);
	// Start
	while(amtiaz1<3 && amtiaz1<3){	
		jadval();
		while(TheEnd()){
			getInputPlayer();
			jadval();
		}
		Updatejadval();
		PlaySound(TEXT("Victory-Sound-Effect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		win();
		Beep(0,2000); 
		PlaySound(TEXT("doz.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	PlaySound(TEXT("Victory-Sound-Effect.wav"), NULL, SND_ASYNC | SND_LOOP);
	system("cls");
	for(;;){
		system("color 13");
		win();
		system("color 00");
	}
}
