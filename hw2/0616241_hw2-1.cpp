#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

struct process{
	int at, bt, pno, wt, ta;
};
bool cmp_at(process a, process b){
	return (a.at < b.at);
}
bool cmp_pno(process a, process b){
	return (a.pno < b.pno);
}
int main(void){
	int n;
	cin >> n;
	process p[n]; //n process arrival time and burst time
	for(int j = 0 ; j < n ; j++){
		cin >> p[j].at;
		//cout << p[j][i] << endl;
		p[j].pno = j + 1;
	}
	for(int j = 0 ; j < n ; j++){
		cin >> p[j].bt;
        	//cout << p[j][i] << endl;
	}
	sort(p, p+n, cmp_at);
	/*cout << p[0].at << " " << p[0].bt << endl;
	cout << p[1].at << " " << p[1].bt << endl;	
	cout << p[2].at << " " << p[2].bt << endl;
	cout << p[3].at << " " << p[3].bt << endl;
	*/
	int totalwait = 0, totalt = 0, srvtime = 0;
	for(int i = 0 ; i < n ; i++){
		if(i == 0){	
			p[i].wt = 0;
			p[i].ta = p[i].bt;
			totalt += p[i].ta;
			srvtime += p[i].bt + p[i].at;			
		}else{
			if(srvtime - p[i].at > 0)	p[i].wt = srvtime - p[i].at;
			else{
				p[i].wt = 0;
				srvtime = p[i].at;
			}
			srvtime += p[i].bt;
			p[i].ta = srvtime - p[i].at;
			totalwait += p[i].wt;
			totalt += p[i].ta;
		}
	}
	sort(p,p + n, cmp_pno);
	for(int i = 0 ; i < n ; i++)
		cout << p[i].wt << " " << p[i].ta << endl;
	cout << totalwait << endl << totalt << endl;	
}
