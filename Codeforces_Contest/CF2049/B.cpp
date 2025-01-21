#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
char s[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s+1);
        int l=0,r=n+1;
        for(int i=1;i<=n;i++){
            if(s[i]=='s')l=i;
            if(s[i]=='p'){
                if(r==n+1)r=i;
            }
        }
        if((l>=0&&r>=n)||(l<=1&&r<=n+1))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


