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
        int tag=0;
        if(s[1]=='1')tag=1;
        if(s[n]=='1')tag=1;
        for(int i=1;i<n;i++)if(s[i]=='1'&&s[i+1]=='1')tag=1;
        if(tag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


