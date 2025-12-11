#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,L,R;
char s[N]; 

signed main(){
    cin>>n>>L>>R;
    scanf("%s",s+1);
    for(int i=L;i<=R;i++){
        if(s[i]=='x'){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}


