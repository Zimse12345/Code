#include "s.hpp"
using namespace std;
vector<string> guess(int n,int a,int b,int t)
{
	if(t==1){
		vector<string> ans(n);
		vector<string> q(n);
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(i^j)q[j]="0";
				else q[j]="1";
			}
			ans[i]=prod(q);
		}
		return ans;
	}
	if(t==2||t==3){
		vector<string> ans(n);
		vector<string> q(n);
		for(int i=0;i<24;i+=3){
			for(int j=0;j<25;j++)q[j]="0";
			q[i]="1",q[i+1]="100",q[i+2]="10000";
			string res=prod(q);
			int len=res.size();
			if(len>4){
				if(len==5)ans[i+2]=res[0];
				if(len==6)ans[i+2]=res[0],ans[i+2]+=res[1];
			}
			else ans[i+2]="0";
			if(len>2){
				if(len==3)ans[i+1]=res[0];
				if(len==4)ans[i+1]=res[0],ans[i+1]+=res[1];
				if(len==5){
					if(res[1]=='0')ans[i+1]=res[2];
					else ans[i+1]=res[1],ans[i+1]+=res[2];
				}
				if(len==6){
					if(res[2]=='0')ans[i+1]=res[3];
					else ans[i+1]=res[2],ans[i+1]+=res[3];
				}
			}
			else ans[i+1]="0";
			if(len==1)ans[i]=res;
			else{
				if(res[len-2]=='0')ans[i]=res[len-1];
				else ans[i]=res[len-2],ans[i]+=res[len-1];
			}
		}
		for(int j=0;j<24;j++)q[j]="0";
		q[24]="1";
		ans[24]=prod(q);
		return ans;
	}
	vector<string> v(n,"1");
	if(prod(v)=="0")
		return vector<string>(n,"0");
	//猜不出来，告辞 
	return vector<string>();
}
