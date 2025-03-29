#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;
enum Difficulty{Easy=60,Medium=40,Hard=10};
const int X=10,Y=4;
int pX=9,pY=0;
int dX=0;
int score=0;
int Y1,Y2,Y3,Y4;
int X1=0,X2=0,X3=0,X4=0;
vector<int>debri;
char Player_Character='O';
char Debris='X';
class Tower{
	private:
	char box[X][Y];
	char direction;
	public:
	void create();
	void display();
	void player();
	void player_movement();
	void Debri();
	void Debri_Fall();
	void Spawner();
	bool Game_Over();
	int chose();
};
int main()
{	
	Tower t;
	int difficulty=t.chose();
	t.create();
	t.Debri();
	t.player();
	while(!t.Game_Over())
	{system("cls");
	t.Debri_Fall();
	t.player_movement();
	t.display();
	t.Spawner();
	Sleep(difficulty);}
	cout<<"\nGAME OVER\t YOU SCORED : "<<score;
	return 0;
}
int Tower::chose(){
	cout<<"\nChose your difficulty \n[1]Easy\n[2]Medium\n[3]Hard";
	char choice;
	Difficulty d;
	choice=getch();
	switch(choice)
	{case '1':d=Easy;return d;break;
	case '2':d=Medium;return d;break;
	case '3': d=Hard;return d;break;
	}
}
	void Tower::create()
	{	
	for(int i=0;i<X;i++)
	{
		for(int k=0;k<Y;k++)
		box[i][k]=' ';
	}
	}
		void Tower::display()
	{
		cout<<"  "<<box[0][0]<<"||"<<box[0][1]<<"    "<<box[0][2]<<"||"<<box[0][3]<<"  "<<endl;
		cout<<"  "<<box[1][0]<<"||"<<box[1][1]<<"    "<<box[1][2]<<"||"<<box[1][3]<<"  "<<endl;
		cout<<"  "<<box[2][0]<<"||"<<box[2][1]<<"    "<<box[2][2]<<"||"<<box[2][3]<<"  "<<endl;
		cout<<"  "<<box[3][0]<<"||"<<box[3][1]<<"    "<<box[3][2]<<"||"<<box[3][3]<<"  "<<endl;
		cout<<"  "<<box[4][0]<<"||"<<box[4][1]<<"    "<<box[4][2]<<"||"<<box[4][3]<<"  "<<endl;
		cout<<"  "<<box[5][0]<<"||"<<box[5][1]<<"    "<<box[5][2]<<"||"<<box[5][3]<<"  "<<endl;
		cout<<"  "<<box[6][0]<<"||"<<box[6][1]<<"    "<<box[6][2]<<"||"<<box[6][3]<<"  "<<endl;
		cout<<"  "<<box[7][0]<<"||"<<box[7][1]<<"    "<<box[7][2]<<"||"<<box[7][3]<<"  "<<endl;
		cout<<"  "<<box[8][0]<<"||"<<box[8][1]<<"    "<<box[8][2]<<"||"<<box[8][3]<<"  "<<endl;
		cout<<"  "<<box[9][0]<<"||"<<box[9][1]<<"    "<<box[9][2]<<"||"<<box[9][3]<<"  "<<endl;
	}
		void Tower::player()
	{
		box[pX][pY]=Player_Character;
	}
	void Tower::player_movement()
	{
		if(_kbhit()){
		direction=_getch();
		box[pX][pY]=' ';}
		switch(direction){
			case 'a':if(pY!=0)box[pX][--pY]=Player_Character;break;
			case 'd':if(pY!=3)box[pX][++pY]=Player_Character;break;
			case 'w':if(pX!=0)box[--pX][pY]=Player_Character;break;
			case 's':if(pX!=9)box[++pX][pY]=Player_Character;break;
			default:break;
		}
		direction=' ';
	}
		void Tower::Debri()
	{	
		srand(time(NULL));
		int count=0;
		for(int i=0;i<4;i++)
		{
			if(rand()%2==0)
			{box[dX][i]=Debris;
			debri.push_back(i);
			count++;}
		}
		if(count==0)
		{box[dX][count]=Debris;
		debri.push_back(count);}
	}
		void Tower::Debri_Fall()
	{
		int check=debri.size();
		switch(check)
		{
		case 1:
		{
		Y1=debri[0];
		box[X1][Y1]=' ';
		box[++X1][Y1]=Debris;	
		break;}
		case 2:
		{
			Y1=debri[0];
			Y2=debri[1];
			box[X1][Y1]=' ';box[X2][Y2]=' ';
			box[++X1][Y1]=Debris; box[++X2][Y2]=Debris;
			break;
		}
		case 3:
		{
			Y1=debri[0];
			Y2=debri[1];
			Y3=debri[2];
			box[X1][Y1]=' ';box[X2][Y2]=' ';box[X3][Y3]=' ';
			box[++X1][Y1]=Debris; box[++X2][Y2]=Debris;box[++X3][Y3]=Debris;
			break;
		}		
		case 4:
		{
			Y1=debri[0];
			Y2=debri[1];
			Y3=debri[2];
			Y4=debri[3];
			box[X1][Y1]=' ';box[X2][Y2]=' ';box[X3][Y3]=' ';box[X4][Y4]=' ';
			box[++X1][Y1]=Debris; box[++X2][Y2]=Debris;box[++X3][Y3]=Debris;box[++X4][Y4]=Debris;
			break;
		}	
	}
}
	void Tower::Spawner()
	{
		if(debri.size()==1&&X1==10)
		{X1=0;
		debri.clear();
		++score;
		Debri();
		}
		else if(debri.size()==2&&X1==10&&X2==10)
		{X1=0,X2=0;
		debri.clear();
		++score;
		Debri();
		}
		else if(debri.size()==3&&X1==10&&X2==10&&X3==10)
		{X1=0,X2=0,X3=0;
		debri.clear();
		++score;
		Debri();}
		else if(debri.size()==3&&X1==10&&X2==10&&X3==10&&X4==10){
		X1=0,X2=0,X3=0,X4=0;
		debri.clear();
		++score;
		Debri();
		}
		else
		{int a=0;
		++a;	
		}	
	}
		bool Tower::Game_Over()
		{
			if((debri.size()==1)&&(box[1+X1][Y1]==Player_Character))
			return true;
			else if((debri.size()==2)&&(box[1+X1][Y1]==Player_Character||box[1+X2][Y2]==Player_Character))
			return true;
			else if((debri.size()==3)&&(box[1+X1][Y1]==Player_Character||box[1+X2][Y2]==Player_Character||box[1+X3][Y3]==Player_Character))
			return true;
			else if((debri.size()==4)&&(box[1+X1][Y1]==Player_Character||box[1+X2][Y2]==Player_Character||box[1+X3][Y3]==Player_Character||box[1+X4][Y4]==Player_Character))
			return true;
			else
			return false;
		}