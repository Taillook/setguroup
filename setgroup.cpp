#include "bits/stdc++.h"
#include "macros.h"
using namespace std;

int random(int x,int y){srand((unsigned int)time(NULL));return rand()%(y)+(x);}
void shuffle_str_arr(vector< vector<string> > &data,int x,int y);

int main(){
	PRINT("グループ数")INTIN(group_amount)
	PRINT("グループの人数")INTIN(group_member)
	vector< vector<string> > groups;
	groups.resize(group_amount);
	REP(i,group_amount){
		groups[i].resize(group_member);
	}

	REP(i,group_amount){
		REP(j,group_member){
			STRIN(sample_str)
			ASS(groups[i][j],sample_str)
		}
	}
	PRINT("")

	shuffle_str_arr(groups,group_amount,group_member);

	REP(i,group_amount){
		OUT((i+1))OUT(":")
		REP(j,group_member){
			OUT(groups[i][j])
			IF((j<group_member-1),OUT(","))
		}
		PRINT("\n")
	}

	RET(0)
}

void shuffle_str_arr(vector< vector<string> > &data,int x,int y){
	string tmp;
	int randx,randy;

	REP(i,x){
		REP(j,y){
			srand((unsigned int)time(NULL));
			ASS(randx,rand()%x)
			ASS(randy,rand()%y)
			
			ASS(tmp,data[i][j])
			ASS(data[i][j],data[randx][randy])
			ASS(data[randx][randy],tmp)
		}
	}
}