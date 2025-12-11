#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,tot[N];
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++)tot[s[i]]++;
        while(tot['T']>0)printf("T"),--tot['T'];
        for(char c='A';c<='Z';c++){
            while(tot[c]>0)printf("%c",c),--tot[c];
        }
        printf("\n");
    }
    return 0;
}


