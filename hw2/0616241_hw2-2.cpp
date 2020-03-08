#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

struct process{
	int at;
	int bt;
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
        	//cout << p[j][i] << endl;
	}
	for(int j = 0 ; j < n ; j++)
		cin >> p[j].pt;       
	sort(p, p+n, cmp_at);
	
//	cout << p[0].at << " " << p[0].bt << endl;
	//cout << p[1].at << " " << p[1].bt << endl;
	//cout << p[2].at << " " << p[2].bt << endl;
	//cout << p[3].at << " " << p[3].bt << endl;
	
	int totalwait = 0, totalt = 0, srvtime = 0;
	p[0].wt = 0;
	srvtime += p[0].bt + p[0].at;
	p[0].ta = srvtime - p[0].at;
	totalt += p[0].ta;
	//check how many process need to cmp
	int i = 1, j;
	while(i < n){
		for(j = i ; j < n ; j++){
			if(p[j].at > srvtime) break;	
		}
		sort(p + i, p + j, cmp_pt);
		if(srvtime - p[i].at > 0)		p[i].wt = srvtime - p[i].at;
		else{
			srvtime = p[i].at;
			p[i].wt = 0;
		}
		totalwait += p[i].wt;
		srvtime += p[i].bt;
		p[i].ta = srvtime - p[i].at;
		totalt += p[i].ta;
		i++;
	}
	sort(p, p + n, cmp_pno);
	for(int k = 0 ; k < n ; k++){
		cout << p[k].wt << " " << p[k].ta << endl;
	}
	cout << totalwait << endl << totalt << endl;
}
