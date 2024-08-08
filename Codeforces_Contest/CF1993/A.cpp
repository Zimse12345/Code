#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,A,B,C,D;
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s+1);
        A=0,B=0,C=0,D=0;
        for(int i=1;i<=n*4;i++){
            if(s[i]=='A')++A;
            if(s[i]=='B')++B;
            if(s[i]=='C')++C;
            if(s[i]=='D')++D;
        }
        printf("%d\n",min(A,n)+min(B,n)+min(C,n)+min(D,n));
    }
    return 0;
}


