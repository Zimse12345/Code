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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
const double E=0.00000001;

int T;
double v;

double f(double c,double m,double p){
	double res=1;
	double o=3;
	if(c<=E)o-=1;if(m<=E)o-=1;if(p<=E)o-=1;o-=1;
	
	if(c>E){
		double _c=min(v,c),_m=(m>E)?m+_c/o:0.0,_p=(p>E)?p+_c/o:0.0;_c=c-_c;
		res+=c*f(_c,_m,_p);
	}
	if(m>E){
		double _m=min(v,m),_c=(c>E)?c+_m/o:0.0,_p=(p>E)?p+_m/o:0.0;_m=m-_m;
		res+=m*f(_c,_m,_p);
	}//res+=p;
//	printf("[%.4f %.9f%c %.9f  %.6f <%.1f>]\n",c,m,m<=E?'y':'n',E,res,o);
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		double c,m,p;
		cin>>c>>m>>p>>v;
		double ans=0.0;
		ans=f(c,m,p);
		printf("%.7f\n",ans);
	}
	return 0;
}

