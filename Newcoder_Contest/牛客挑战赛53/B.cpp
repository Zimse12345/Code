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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int T,s,ans[N],t;
int pr[N],prime[N],pt;

void InitPrime(){
	for(int i=2;i<N;i++){
		if(pr[i]==0)pr[i]=i,prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<N;j++){
			pr[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
    }
}

int main(){
    InitPrime();//printf("(%d)",pt);
	T=read(),prime[0]=1,pr[1]=1;
	while(T--){
        s=read(),t=0;
        int S=s;
        if(s==0){
            printf("1\n0 = 0\n");
            continue;
        }
        if(s==1){
            printf("1\n1 = 1\n");
            continue;
        }
        if(s==2){
            printf("1\n2 = 2\n");
            continue;
        }
        if(pr[s]==s){
        	printf("1\n%d = %d\n",s,s);
        	continue;
		}
        if(s%2==0){
        	int L=0,R=pt,c=0;
            while(L<=R){
                int M=(L+R)>>1;
                if(s>=prime[M])c=M,L=M+1;
                else R=M-1;
            }
            if(s==prime[c]){
        		printf("1\n%d = %d\n",s,s);
        		continue;
			}
			while(pr[s-prime[c]]!=s-prime[c])--c;
        	printf("%d\n",2);
        	printf("%d + %d = %d\n",min(prime[c],s-prime[c]),max(prime[c],s-prime[c]),S);
        	continue;
		}
        if(pr[s-2]==s-2){
        	printf("2\n2 + %d = %d\n",s-2,s);
        	continue;
		}
		else{
			s-=3;
        	int L=0,R=pt,c=0;
            while(L<=R){
                int M=(L+R)>>1;
                if(s>=prime[M])c=M,L=M+1;
                else R=M-1;
            }
            if(s==prime[c]){
        		printf("1\n%d = %d\n",s,s);
        		continue;
			}
			while(pr[s-prime[c]]!=s-prime[c])--c;
        	printf("%d\n",3);
        	ans[1]=3,ans[2]=prime[c],ans[3]=s-prime[c];
        	sort(ans+1,ans+4);
        	printf("%d + %d + %d = %d\n",ans[1],ans[2],ans[3],S);
        	continue;
		}
	}
	return 0;
}
