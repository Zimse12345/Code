#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,c,q;
char s[N];

void ck(int x,int t){
    if(x<1||x+3>n)return;
    if(s[x]=='1'&&s[x+1]=='1'&&s[x+2]=='0'&&s[x+3]=='0')c+=t;
    return;
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        c=0;
        for(int i=1;i<=n;i++)ck(i,1);
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            ck(x-3,-1),ck(x-2,-1),ck(x-1,-1),ck(x,-1);
            s[x]='0'+y;
            ck(x-3,1),ck(x-2,1),ck(x-1,1),ck(x,1);
            if(c)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}


