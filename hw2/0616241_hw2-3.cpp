#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

struct process{
	int at;
	int bt, btcp;
	int ct;
	int pt;
	int pno;
	int wt;
	int ta;
};
bool cmp_at(process a, process b) 
{ 
	if(a.at == b.at)	return (a.pt < b.pt);
	else	return (a.at < b.at); 
}
bool cmp_pt(process a, process b){
	return (a.pt < b.pt);
}
bool cmp_pno(process a, process b){
	return (a.pno < b.pno);
}
int main(void){
	int n;
	cin >> n;
	process p[n];
	for(int j = 0 ; j < n ; j++){
		cin >> p[j].at;
		p[j].pno = j + 1;
		//cout << p[j][i] << endl;
	}
	for(int j = 0 ; j < n ; j++){
		cin >> p[j].bt;
		p[j].btcp = p[j].bt;
	}
	for(int j = 0 ; j < n ; j++)
		cin >> p[j].pt;       
	sort(p, p+n, cmp_at);
	
//	cout << p[0].at << " " << p[0].bt << endl;
	//cout << p[1].at << " " << p[1].bt << endl;
	//cout << p[2].at << " " << p[2].bt << endl;
	//cout << p[3].at << " " << p[3].bt << endl;
	
	int totalwait = 0, totalt = 0;
	int i = 0, j, pcom = 0;
	while(pcom < n){
	//	cout << "xd i cant get out\n";
		for(j = 0 ; j < n ; j++){
			if(p[j].at > i) break;	
		}
		sort(p, p + j, cmp_pt);
		if(j > 0){
			for(j = 0 ; j < n ; j++){
				if(p[j].bt!=0)	break;
			}
			if(p[j].at>i)	i += p[j].at - i;
			p[j].ct = i + 1;
			//cout << "p[" << j << "].ct = " << p[j].ct << endl;
			p[j].bt--;
			
		}
		i++;
		pcom = 0;
		for(j = 0 ; j < n ; j++){
			if(p[j].bt == 0)	pcom++;
		}
		//cout << "i = " << i << endl;
	}
	for(i = 0 ; i < n ; i++){
		p[i].ta = p[i].ct - p[i].at;
		totalt += p[i].ta;
		p[i].wt = p[i].ta - p[i].btcp;
		totalwait += p[i].wt;
	}
	sort(p, p + n, cmp_pno);
	for(int k = 0 ; k < n ; k++){
		cout << p[k].wt << " " << p[k].ta << endl;
	}
	cout << totalwait << endl << totalt << endl;
}
