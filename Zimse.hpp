struct Zimse:VirtualPlayer{

const double INF=1e6;

struct Rating{
    double rat[20][20];
    void Init(){
        for(int x=1;x<=SIZE;x++){
            for(int y=1;y<=SIZE;y++){
                rat[x][y]=0;
            }
        }
    }
    void Show(){
        for(int x=1;x<=SIZE;x++){
            for(int y=1;y<=SIZE;y++)printf("%6.3lf ",rat[x][y]);
             printf("\n");
        }
        std::cin>>rat[0][0];
    }
};

inline double CalcLine(int* a,int len,unsigned short My){
	double res=0;
	int cnt1=0,cnt2=0;
	a[len+1]=My==1?2:1;
	for(int i=1,s=0;i<=len+1;i++){
		if(i>=1&&i+3<=len){
			int pl=0;
			if(i-1>=1&&a[i-1]==0)++pl;
			if(i+4<=len&&a[i+4]==0)++pl;
			if(a[i]==My&&a[i+3]==My&&((a[i+1]==My&&a[i+2]==0)||(a[i+2]==My&&a[i+1]==0))){
				if(pl==2)res+=0.6,++cnt2;
				else if(pl==1)res+=0.15;
			}
		}
		if(i>=1&&i+4<=len){
			int pl=0;
			if(i-1>=1&&a[i-1]==0)++pl;
			if(i+5<=len&&a[i+5]==0)++pl;
			if(a[i]==My&&a[i+4]==My&&((a[i+1]==My&&a[i+2]==My&&a[i+3]==0)||(a[i+1]==0&&a[i+2]==My&&a[i+3]==My)||(a[i+1]==My&&a[i+2]==0&&a[i+3]==My))){
				if(pl==2)res+=0.7,++cnt1;
				else if(pl==1)res+=0.25,++cnt2;
			}
		}
		if(a[i]==My)++s;
		else{
			int pl=0,ppl=0;
			if(i-s-1>=1&&a[i-s-1]==0)++pl;
			if(i<=len&&a[i]==0)++pl;
			if(i-s-2>=1&&a[i-s-2]==0)++ppl;
			if(i+1<=len&&a[i+1]==0)++ppl;
            if(s>=5)res+=INF;
            else if(s==4){
                if(pl==2)res+=INF*0.1;
                else if(pl==1)res+=1.2,++cnt1;
            }
            else if(s==3){
                if(pl==2)res+=1,++cnt2;
				else if(pl==1&&ppl>=1)res+=0.25;
            }
            else if(s==2){
                if(pl==2&&ppl>=1)res+=0.15;
                else if(pl==1&&ppl>=2)res+=0.04;
            }
            else if(s==1){
                if(pl==2&&ppl>=2)res+=0.04;
                else if(pl==1&&ppl>=2)res+=0.003;
            }
			s=0;
		}
	}
	return res;
}

inline double CalcVal(const ChessBoard& sta,unsigned short My){
    double res=0;
    for(int x=1;x<=SIZE;x++){
        for(int y=1;y<=SIZE;y++)if(sta.board[x][y]==My){
            res+=double((SIZE-1)-abs((1+SIZE)/2.0-x)-abs((1+SIZE)/2.0-y))/double(SIZE*6.4);
        }
    }
    int line[20],len;
    for(int x=1;x<=SIZE;x++){
    	len=0;
    	for(int y=1;y<=SIZE;y++)line[++len]=sta.board[x][y];
    	res+=CalcLine(&line[0],len,My);
	}
    for(int y=1;y<=SIZE;y++){
    	len=0;
    	for(int x=1;x<=SIZE;x++)line[++len]=sta.board[x][y];
    	res+=CalcLine(&line[0],len,My);
	}
	for(int x=1;x<=SIZE;x++){
		len=0;
		for(int y=0;y<x;y++)line[++len]=sta.board[x-y][y+1];
		res+=CalcLine(&line[0],len,My);
	}
	for(int y=2;y<=SIZE;y++){
		len=0;
		for(int x=y;x<=SIZE;x++)line[++len]=sta.board[SIZE-x+y][x];
		res+=CalcLine(&line[0],len,My);
	}
	for(int x=1;x<=SIZE;x++){
		len=0;
		for(int y=0;x+y<=SIZE;y++)line[++len]=sta.board[x+y][y+1];
		res+=CalcLine(&line[0],len,My);
	}
	for(int y=2;y<=SIZE;y++){
		len=0;
		for(int x=y;x<=SIZE;x++)line[++len]=sta.board[x-y+1][x];
		res+=CalcLine(&line[0],len,My);
	}
    return res;
}

inline double CalcRat(const ChessBoard& sta,const Rating& dec){
    double MaxRating=-INF,SeRating=-INF;
    for(int x=1;x<=SIZE;x++){
        for(int y=1;y<=SIZE;y++)if(!sta.board[x][y]){
             double val=dec.rat[x][y];
             if(val>MaxRating)SeRating=MaxRating,MaxRating=val;
             else if(val>SeRating)SeRating=val;
        }
    }
    return MaxRating*0.9+SeRating*0.1;
}

inline Rating GetVal(const ChessBoard& _sta,unsigned short My,int cnt){
    Rating res;
    res.Init();
    ChessBoard sta=_sta;
    int sum=0;
	for(int x=1;x<=SIZE;x++){
		for(int y=1;y<=SIZE;y++)if(sta.board[x][y])++sum;
	}
	if(!sum){
		res.rat[SIZE/2+(rand()&1)][SIZE/2+(rand()&1)]=INF;
		return res;
	}
    for(int x=1;x<=SIZE;x++){
        for(int y=1;y<=SIZE;y++){
            if(!sta.board[x][y]){
            	int _sum=0;
            	for(int _x=std::max(1,x-2);_x<=std::min(SIZE,x+2);_x++){
            		for(int _y=std::max(1,y-2);_y<=std::min(SIZE,y+2);_y++)_sum+=sta.board[_x][_y];
				}
				res.rat[x][y]=-INF;
				if(!_sum)continue;
                sta.board[x][y]=My;
                if(cnt==0){
                	double val1=CalcVal(sta,My),val2=CalcVal(sta,My==1?2:1);
                	if(val2>INF*0.8)res.rat[x][y]=-INF;
                	else if(val1>INF*0.8)res.rat[x][y]=INF;
                    else res.rat[x][y]=val1-val2*1.12;
                }
                else{
                    Rating _res=GetVal(sta,My==1?2:1,cnt-1);
                    res.rat[x][y]=1-CalcRat(sta,_res);
                }
                sta.board[x][y]=0;
            }
        }
    }
    return res;
}

Location Decision(const ChessBoard& sta,unsigned short My){
    Rating dec=GetVal(sta,My,1);
//    dec.Show();
    Location res,_res;
    double MaxRating=-INF,SeRating=-INF;
    for(int x=1;x<=SIZE;x++){
        for(int y=1;y<=SIZE;y++)if(!sta.board[x][y]){
        	double val=dec.rat[x][y];
        	if(val>MaxRating)SeRating=MaxRating,_res=res,MaxRating=val,res=Location(x,y);
        	else if(val>SeRating)SeRating=val,_res=Location(x,y);
        }
    }
    if(MaxRating-SeRating<0.16)if(rand()%3==0)res=_res;
    return res;
}

};
