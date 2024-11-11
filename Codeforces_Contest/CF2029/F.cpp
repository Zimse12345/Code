#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];
char s[N];
int ans[N];

signed main(){
//    freopen("t.ans","r",stdin);
//    for(int i=1;i<=1000;i++){
//        scanf("%s",s);
//        if(s[0]=='Y')ans[i]=1;
//    }
//    fclose(stdin);
//    freopen("t.in","r",stdin);
//    freopen("t.out","w",stdout);
    cin>>T;
    for(int tt=1;tt<=T;tt++){
        cin>>n;
        scanf("%s",s);
        int iR=0,iB=0,ir=0,ib=0;
        for(int i=0;i<n;i++){
            if(s[i]==s[(i+1)%n]){
                if(s[i]=='R')iR=1;
                if(s[i]=='B')iB=1; 
            }
            if(s[i]=='R')ir=1;
            if(s[i]=='B')ib=1;
        }
        if(iB&&iR){
            printf("NO\n");
            continue;
        }
        if(ir==0||ib==0){
            printf("YES\n");
            continue;
        }
        char c=(iR?'R':'B');
        int m=0,c0=0,c1=0;
        for(int i=0;i<n;i++)if(s[i]!=c){
            int p=(i+1)%n,cnt=0;
            while(s[p]==c)p=(p+1)%n,++cnt;
            a[++m]=cnt;
            if(cnt&1)++c1;
            else ++c0; 
        }
//        if(ans[tt])printf("YES ");
//        else printf("NO ");
//        if(m>2)for(int i=1;i<=m;i++)printf("%d ",a[i]);
//        printf("\n");
        if(c0>1||(c0==0&&c1>1))printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}


