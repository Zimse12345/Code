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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int Q,M[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},m[13];

bool isr(int year){
	if(year<0){
		if((-year-1)%4==0)return 1;
		else return 0;
	}
	if(year<1582){
		if(year%4==0)return 1;
		else return 0;
	}
	if(year%400==0)return 1;
	if(year%100==0)return 0;
	if(year%4==0)return 1;
	return 0;
}

void upm(int year){
	for(int i=1;i<=12;i++)m[i]=M[i];
	if(isr(year))m[2]=29;
	//if(year==1582)m[10]-=10;
	return;
}

void printans(int year,int month,int day){
	if(year>0)printf("%lld %lld %lld\n",day,month,year);
	else printf("%lld %lld %lld BC\n",day,month,-year);
	return;
}

int yd(int year){
	if(year==1582)return 355;
	if(isr(year))return 366;
	return 365; 
}

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	Q=read();
	while(Q--){
		int r=read(),year=-4713,month=1,day=1;
		if(r>=2451545){
			year=2000,month=1,day=1;
			r-=2451545;
			year+=2000*(r/730485),r%=730485;
			if(r>3547273-3182030)r-=3547273-3182030,year+=1000;
		}
		else if(r>=2086308)r-=2086308,year=1000;
		else if(r>=1721424)r-=1721424,year=1;
		else if(r>=1356174)r-=1356174,year=-1000;
		else if(r>=990924)r-=990924,year=-2000;
		else if(r>=625674)r-=625674,year=-3000;
		else if(r>=260424)r-=260424,year=-4000;
		
		while(r>=yd(year)){
			r-=yd(year);
			++year;
			if(year==0)++year;
		}
		upm(year);
		if(year==1582)m[10]-=10;
		while(r>=m[month]){
			r-=m[month];
			++month;
		}
		upm(year);
		while(r){
			if(year==1582&&month==10&&day==4)day=15;
			else ++day;
			--r;
		}
		printans(year,month,day);
	}
	return 0;
}
