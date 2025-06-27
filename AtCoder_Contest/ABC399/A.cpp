#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,c;
char s[N],t[N]; 

signed main(){
    cin>>n;
    scanf("%s%s",s+1,t+1);
    for(int i=1;i<=n;i++)if(s[i]!=t[i]){
        ++c;
    }
    printf("%d\n",c);
    return 0;
}


