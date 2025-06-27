#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,ans[N];
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s+2);
        int l=1,r=n;
        for(int i=n;i>=2;i--){
            if(s[i]=='<')ans[i]=l++;
            else ans[i]=r--;
        }
        ans[1]=l;
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}


