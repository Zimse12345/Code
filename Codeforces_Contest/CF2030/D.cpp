#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,q,p[N],t[N],nd,c;
char s[N];

void ck(int pos,int tt){
    if(pos>=1&&pos<n&&t[pos]>0){
        if(s[pos]=='R'||s[pos+1]=='L')c+=tt;
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>p[i],t[i]=0;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(i<p[i])++t[i],--t[p[i]];
            if(i>p[i])++t[p[i]],--t[i];
        }
        nd=c=0;
        for(int i=1;i<n;i++){
            t[i]+=t[i-1];
            if(t[i]>0)++nd;
            ck(i,1);
        }
        while(q--){
            int pos;
            cin>>pos;
            ck(pos,-1),ck(pos-1,-1);
            if(s[pos]=='L')s[pos]='R';
            else s[pos]='L';
            ck(pos,1),ck(pos-1,1);
            if(c==nd)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}


