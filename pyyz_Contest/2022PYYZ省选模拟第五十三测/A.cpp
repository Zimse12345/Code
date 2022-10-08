#include"escape.h"
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
void escape(int lm, int lq){
	srand(time(0));
	int P=9;
	int H=query(),from=-1;
	if(-H<=1002)P=2;
	move(0);
	if(query()>H){
		from=0;
	}
	else{
		move(0),move(1);
		if(query()>H){
			from=1;
		}
		else{
			move(1),move(2);
			from=2;
		}
	}
	//printf("*"); 
	H=query();
	while(1){
//		printf("<\n");
		int s[10],ss[10];
		s[0]=from;
		for(int i=1;i<=P;i++){
			s[i]=(s[i-1]+1)%3;
			ss[i]=(s[i]+1)%3;
			if(rand()&1){int tt=s[i];s[i]=ss[i],ss[i]=tt;}
			move(s[i]);
		}
//		printf(">\n");
		int _H=query();//printf("------------ [%d %d (%d %d %d)]\n",H,_H,s[0],s[1],s[2]);
		for(int i=0;i<=P;i++){
			if(i-(P-i)==_H-H){
//				printf("[%d %d %d]\n",i,H,_H);
				for(int j=P;j>i;j--){
					move(s[j]);
				}
				H+=i,from=s[i];
				if(i!=P){
					int to=ss[i+1];
					move(to),H++,from=to;
				}
				
				break;
			}
		}
	}
	return;
}
