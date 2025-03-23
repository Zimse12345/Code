#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,t;
char s[N],stk[N];

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(stk[t]=='('&&s[i]==')')--t;
        else if(stk[t]=='['&&s[i]==']')--t;
        else if(stk[t]=='<'&&s[i]=='>')--t;
        else stk[++t]=s[i];
    }
    if(t)printf("No\n");
    else printf("Yes\n");
    return 0;
}


