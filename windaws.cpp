#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int inputint;
char inputchar;
string inputstr;

string username="NULL";

string osname("Windaws");
float osver=0.1;
int osverd=1;

bool instantdisplay=false;


long long board[4][4],p1,p2,turn,won;
bool multi;

void desktop();
void displaytext(string t,double delay,bool end){
	int i=0;
	if(instantdisplay){
		cout<<t;
	}else{
		while(t[i]!='\0'){
			cout<<t[i];
			usleep(1000000*delay);
			i++;
		}
	}
	if(end)cout<<endl;
}
int rng(){
	srand(time(NULL));
	int rn=rand()%10;
	return rn;
}
void spincirc(double delay,int repeat){
	while(repeat){
		cout<<"    .       "<<endl<<"           "<<endl<<"            ";
		usleep(1000000*delay);
		system("CLS");
		cout<<"    .  .    "<<endl<<"           "<<endl<<"            ";
		usleep(1000000*delay);
		system("CLS");
		cout<<"    .  .    "<<endl<<"        .  "<<endl<<"            ";
		usleep(1000000*delay);
		system("CLS");
		cout<<"    .  .    "<<endl<<"        .  "<<endl<<"       .    ";
		usleep(1000000*delay);
		system("CLS");
		cout<<"    .  .    "<<endl<<"        .  "<<endl<<"    .  .    ";
		usleep(1000000*delay);
		system("CLS");
		cout<<"    .  .    "<<endl<<"   .    .  "<<endl<<"    .  .    ";
		usleep(1000000*delay);
		system("CLS");
		usleep(1000000*delay*3);
		repeat--;
	}
}
void startos(){
	displaytext("starting "+osname+" operating system",0.05,false);
	system("CLS");
	for(int i=1;i<=3;i++){
		cout<<"starting "+osname+" operating system";
		displaytext(" ...",0.2,false);
		usleep(500000);
		system("CLS");
	}
	spincirc(0.05,4);
	sleep(2);
	sleep(3);
	system("CLS");
}
void restartos(){
	displaytext("restarting",0.1,false);
	sleep(2);
	system("CLS");
	sleep(3);
	startos();
	displaytext("Welcome back "+username+"!",0.01,false);
	sleep(2);
	desktop();
}
void settings(){
	system("CLS");
	displaytext("|SETTINGS|",0.05,true);
	displaytext("1 - username",0.01,true);
	displaytext("2 - color",0.01,true);
	displaytext("3 - instant display mode",0.01,true);
	displaytext("? - exit",0.01,true);
	cin>>inputint;
	system("CLS");
	if(inputint==1){
		displaytext("enter new username -> ",0.03,false);
		cin>>inputstr;
		username=inputstr;
		sleep(1);
		system("CLS");
		displaytext("exiting",0.03,false);
		sleep(1);
		settings();
	}else if(inputint==2){
		displaytext("1 - blue",0.01,true);
		displaytext("2 - green",0.01,true);
		displaytext("3 - aqua",0.01,true);
		displaytext("4 - red",0.01,true);
		displaytext("5 - purple",0.01,true);
		displaytext("6 - yellow",0.01,true);
		displaytext("7 - white",0.01,true);
		displaytext("8 - grey",0.01,true);
		displaytext("9 - light blue",0.01,true);
		displaytext("10 - light green",0.01,true);
		displaytext("11 - light aqua",0.01,true);
		displaytext("12 - light red",0.01,true);
		displaytext("13 - light purple",0.01,true);
		displaytext("14 - light yellow",0.01,true);
		displaytext("15 - bright white",0.01,true);
		displaytext("? - exit",0.01,true);
		displaytext("enter preffered color -> ",0.03,false);
		cin>>inputint;
		system("CLS");
		if(inputint==1)system("Color 01");
		else if(inputint==2)system("Color 02");
		else if(inputint==3)system("Color 03");
		else if(inputint==4)system("Color 04");
		else if(inputint==5)system("Color 05");
		else if(inputint==6)system("Color 06");
		else if(inputint==7)system("Color 07");
		else if(inputint==8)system("Color 08");
		else if(inputint==9)system("Color 09");
		else if(inputint==10)system("Color 0A");
		else if(inputint==11)system("Color 0B");
		else if(inputint==12)system("Color 0C");
		else if(inputint==13)system("Color 0D");
		else if(inputint==14)system("Color 0E");
		else if(inputint==15)system("Color 0F");
		sleep(1);
		displaytext("exiting",0.03,false);
		sleep(1);
		settings();
	}else if(inputint==3){
		displaytext("instant display mode displays text instantly",0.02,true);
		displaytext("0 - turn off",0.01,true);
		displaytext("1 - turn on",0.01,true);
		displaytext("? - exit",0.01,true);
		cin>>inputint;
		if(inputint==0){
			instantdisplay=false;
			displaytext("instant display mode turned off",0.01,true);
			sleep(1);
		}else if(inputint==1){
			instantdisplay=true;
			displaytext("instant display mode turned on",0.01,true);
			sleep(1);
		}
		sleep(1);
		system("CLS");
		displaytext("exiting",0.03,false);
		sleep(1);
		settings();
	}
	system("CLS");
}
void nmg(){
	spincirc(0.1,2);
	system("CLS");
	bool correct=true;
	long long score=0,r=1,num=0,ans;
	displaytext("Hello!",0.1,false);
	usleep(1000000);
	system("CLS");
	displaytext("Welcome to Just a Number Memorising Game!",0.05,false);
	usleep(1000000);
	system("CLS");
	usleep(1000000);
	displaytext("Let's begin!",0.05,false);
	usleep(1000000);
	system("CLS");
	displaytext("[SCORE]: ",0.05,false);
	displaytext(to_string(score),0.05,true);
	for(int i=1;i<=to_string(score).size()+9;i++)displaytext("-",0.03,false);
	while(correct){
		system("CLS");
		num=num*10+rng();
		cout<<"[SCORE]: ";
		displaytext(to_string(score),0.05,true);
		for(int i=1;i<=to_string(score).size()+9;i++)cout<<"-";
		displaytext("-",0.05,true);
		displaytext("MEMORISE THIS --> ",0.05,false);
		displaytext(to_string(num),0.2,false);
		usleep(2000000);
		system("CLS");
		cout<<"[SCORE]: "<<score<<endl;
		for(int i=1;i<=to_string(score).size()+9;i++)cout<<"-";
		cout<<"-"<<endl;
		displaytext("Enter what you memorised: ",0.05,false);
		cin>>ans;
		if(ans==num)score+=r*100;
		else correct=false;
		r++;
		usleep(500000);
		system("CLS");
	}
	displaytext("[GAME OVER]",0.1,true);
	usleep(500000);
	displaytext("[SCORE]: ",0.05,false);
	displaytext(to_string(score),0.05,true);
	sleep(3);
	system("CLS");
}
void updatelogs(){
	system("CLS");
	displaytext("current "+osname+" version: "+to_string(osver)+"."+to_string(osverd),0.02,true);
	displaytext("loading update logs...",0.02,false);
	sleep(1);
	spincirc(0.1,2);
	system("CLS");
	cout<<"current "+osname+" version: "+to_string(osver)+"."+to_string(osverd)<<endl;
	cout<<"update logs loaded!";
	sleep(1);
	system("CLS");
	cout<<"current "+osname+" version: "+to_string(osver)+"."+to_string(osverd)<<endl;
	cout<<"version 0.1.1"<<endl<<"-tic tac toe\n-settings with instant display mode\n-bug fixes"<<endl<<endl;
	cout<<"version 0.1"<<endl<<"-release\n-number memorising game\n-settings with color change and username change"<<endl;
	displaytext("? - exit",0.01,true);
	cin>>inputint;
	system("CLS");
	displaytext("exiting",0.01,false);
}
void gallery(){
	displaytext("? - exit",0.01,true);
	displaytext("coming soon",0.01,true);
	cin>>inputint;
	sleep(2);
	system("CLS");
}
void drawboard(){
	system("CLS");
	displaytext("     |     |     ",0.001,true);
	for(int i=1;i<=3;i++){
		displaytext("  ",0.001,false);
		if(board[1][i]==1)displaytext("X",0.001,false);
		else if(board[1][i]==2)displaytext("O",0.001,false);
		else displaytext(" ",0.001,false);
		if(i!=3)displaytext("  |",0.001,false);
		else displaytext("   ",0.001,false);	
	}
	cout<<endl;
	displaytext("-----|-----|-----",0.001,true);
	for(int i=1;i<=3;i++){
		displaytext("  ",0.001,false);
		if(board[2][i]==1)displaytext("X",0.001,false);
		else if(board[2][i]==2)displaytext("O",0.001,false);
		else displaytext(" ",0.001,false);
		if(i!=3)displaytext("  |",0.001,false);
		else displaytext("   ",0.001,false);	
	}
	cout<<endl;
	displaytext("     |     |     ",0.001,true);
	displaytext("-----|-----|-----",0.001,true);
	for(int i=1;i<=3;i++){
		displaytext("  ",0.001,false);
		if(board[3][i]==1)displaytext("X",0.001,false);
		else if(board[3][i]==2)displaytext("O",0.001,false);
		else displaytext(" ",0.001,false);
		if(i!=3)displaytext("  |",0.001,false);
		else displaytext("   ",0.001,false);	
	}
	cout<<endl;
	displaytext("     |     |     ",0.001,true);
}
bool boardcheck(){
	for(int i=1;i<=3;i++){
		if(board[i][1]==board[i][2]&&board[i][1]==board[i][3]&&board[i][1]!=0){
			won=board[i][1];
			return true;
		}
	}
	for(int i=1;i<=3;i++){
		if(board[1][i]==board[2][i]&&board[i][1]==board[3][i]&&board[1][i]!=0){
			won=board[3][i];
			return true;
		}
	}
	if(board[1][1]==board[2][2]&&board[1][1]==board[3][3]&&board[1][1]!=0){
			won=board[1][1];
			return true;
	}
	if(board[1][3]==board[2][2]&&board[1][3]==board[3][1]&&board[1][3]!=0){
			won=board[1][3];
			return true;
	}
	return false;
}
void ttt(){
	spincirc(0.01,3);
	drawboard();
	while(!boardcheck()){
		turn=1;
		displaytext("|PLAYER ONE|\nenter column number -> ",0.001,false);
		cin>>p1;
		displaytext("|PLAYER ONE|\nenter row number -> ",0.001,false);
		cin>>p2;
		while(board[p2][p1]!=0||p1>3||p2>3){
			displaytext("|PLAYER ONE|\n invalid position",0.001,true);
			displaytext("|PLAYER ONE|\nenter column number -> ",0.001,false);
			cin>>p1;
			displaytext("|PLAYER ONE|\nenter row number -> ",0.001,false);
			cin>>p2;
		}
		board[p2][p1]=turn;
		drawboard();
		if(boardcheck())break;
		turn=2;
		displaytext("|PLAYER TWO|\nenter column number -> ",0.001,false);
		cin>>p1;
		displaytext("|PLAYER TWO|\nenter row number -> ",0.001,false);
		cin>>p2;
		while(board[p2][p1]!=0||p1>3||p2>3){
			displaytext("|PLAYER TWO|\n invalid position",0.001,true);
			displaytext("|PLAYER TWO|\nenter column number -> ",0.001,false);
			cin>>p1;
			displaytext("|PLAYER TWO|\nenter row number -> ",0.001,false);
			cin>>p2;
		}
		board[p2][p1]=turn;
		drawboard();
	}
	if(won==1){
		displaytext("PLAYER ONE WINS",0.01,true);
	}else{
		displaytext("PLAYER TWO WINS",0.01,true);
	}
	sleep(1);
	displaytext("exiting",0.01,true);
	sleep(2);
}
void desktop(){
	system("CLS");
	displaytext("|DESKTOP|",0.05,true);
	displaytext("1 - settings",0.01,true);
	displaytext("2 - number memory game",0.01,true);
	displaytext("3 - "+osname+" update logs",0.01,true);
	displaytext("4 - photo gallery",0.01,true);
	displaytext("5 - tic tac toe",0.01,true);
	displaytext("? - restart/shutdown",0.01,true);
	cin>>inputint;
	system("CLS");
	if(inputint==1){
		settings();
		sleep(1);
		system("CLS");
		desktop();
	}else if(inputint==2){
		nmg();
		sleep(1);
		system("CLS");
		desktop();
	}else if(inputint==3){
		updatelogs();
		sleep(1);
		system("CLS");
		desktop();
	}else if(inputint==4){
		gallery();
		sleep(1);
		system("CLS");
		desktop();
	}else if(inputint==5){
		ttt();
		sleep(1);
		system("CLS");
		desktop();
	}else{	
		displaytext("1 - restart",0.01,true);
		displaytext("? - shutdown",0.01,true);
		cin>>inputint;
		if(inputint==1){
			system("CLS");
			restartos();
		}
	}
}
int main(){
	startos();
	displaytext("enter preffered username -> ",0.03,false);
	cin>>inputstr;
	username=inputstr;
	system("CLS");
	displaytext("Hello "+username+"!",0.01,false);
	sleep(2);
	desktop();
	return 0;
}
