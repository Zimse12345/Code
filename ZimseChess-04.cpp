#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE=15;
const int System=1;
//Linux 0
//Window 1 

inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<48||57<c){if(c==45)y=-1;c=getchar();}
	while(47<c&&c<58)x=x*10+c-48,c=getchar();
	return x*y;
}

int lx=0,ly=0; 
struct Location{
    int x,y;
    Location(int x=0,int y=0):x(x),y(y){}
};

struct ChessBoard{
    unsigned short board[20][20];
    
    void Init(){
    	board[0][0]=0; 
        for(int x=1;x<=SIZE;x++)board[0][x]=board[x][0]=x;
        for(int x=1;x<=SIZE;x++){
            for(int y=1;y<=SIZE;y++){
                board[x][y]=0;
            }
        }
    }
    
    void Show(){
    	if(System==0)system("clear");
    	if(System==1)system("cls");
        for(int x=0;x<=SIZE;x++){
            for(int y=0;y<=SIZE;y++){
            	if(!x||!y)printf("%2d ",signed(board[x][y]));
            	else{
            		if(board[x][y]==0)printf("   ");
            		else if(board[x][y]==1)printf(" O ");
            		else{
            			if(lx==x&&ly==y)printf(" \033[36mX\033[0m ");
            			else printf(" X ");
					}
				}
			}
            printf("\n");
        }
    }
    
    bool win(unsigned short My){
    	for(int x=1;x<=SIZE;x++){
    		for(int y=1,s=0;y<=SIZE;y++){
    			if(board[x][y]==My)++s;
    			else s=0;
    			if(s==5)return true;
			}
		}
    	for(int y=1;y<=SIZE;y++){
    		for(int x=1,s=0;x<=SIZE;x++){
    			if(board[x][y]==My)++s;
    			else s=0;
    			if(s==5)return true;
			}
		}
		for(int x=1;x<=SIZE;x++){
			for(int y=0,s=0;y<x;y++){
    			if(board[x-y][y+1]==My)++s;
    			else s=0;
    			if(s==5)return true;
			}
		}
		for(int y=2;y<=SIZE;y++){
			for(int x=y,s=0;x<=SIZE;x++){
    			if(board[SIZE-x+y][x]==My)++s;
    			else s=0;
    			if(s==5)return true;
			}
		}
		for(int x=1;x<=SIZE;x++){
			for(int y=0,s=0;x+y<=SIZE;y++){
    			if(board[x+y][y+1]==My)++s;
    			else s=0;
    			if(s==5)return true;
			}
		}
		for(int y=2;y<=SIZE;y++){
			for(int x=y,s=0;x<=SIZE;x++){
    			if(board[x-y+1][x]==My)++s;
    			else s=0;
    			if(s==5)return true;
			}
		}
		return false;
	}
};

struct VirtualPlayer{
	virtual Location Decision(const ChessBoard& ,unsigned short )=0;
};

#include "Zimse.hpp"

int main(){
	srand(time(0));
while(1){
    ChessBoard game;
    game.Init();
    Zimse z;
    int fr;
    system("cls"),printf("AI First(0),You First(1) : ");
    fr=read();
//    z.Init();
//    z.Show_Arg();
    while(1){
    	if(fr){
    		game.Show();
    		int x,y;
        	x=read(),y=read();
        	while(x<1||x>SIZE||y<1||y>SIZE||game.board[x][y]){
        		printf("\033[31mWrong\033[0m\n");
        		x=read(),y=read();
			}
        	game.board[x][y]=1;
		}
        else fr=1;
        if(game.win(1)){
        	game.Show();
        	printf("\033[33mYou Win!\033[0m\n");
        	break;
		}
        Location p=z.Decision(game,2);
        game.board[p.x][p.y]=2;
        lx=p.x,ly=p.y;
        game.Show();
        printf("(%d,%d)\n",p.x,p.y);
        if(game.win(2)){
        	printf("\033[31mYou Lose!\033[0m\n");
        	break;
		}
    }
    printf("play again? (y=1,n=0) : ");
    int tag;
    std::cin>>tag;
    if(!tag)break;
}
    return 0;
}
