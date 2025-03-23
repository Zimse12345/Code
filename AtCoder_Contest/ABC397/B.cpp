#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,ans,t;
char s[N];

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        t^=1;
        if((t==0&&s[i]=='i')||(t==1&&s[i]=='o'))t^=1,++ans;
    }
    if(t)++ans;
    printf("%d\n",ans);
    return 0;
}


