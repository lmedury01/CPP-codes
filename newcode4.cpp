#include<iostream>

using namespace std;

struct time{
	int start;
	int stop;
}J,C;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		int j[2*a],c[2*a];
		int cindex=-1,jindex=-1;
		string result[a];
		int matrix[a][2];
		result[0]='C';
		int index=0;
		for(int j=0; j<a; j++){
			for(int k=0; k<2; k++){
				cin>>matrix[j][k];
			}
		}
		C.start=matrix[0][0];
		C.stop=matrix[0][1];
		cindex++;
		c[cindex]=C.start;
		cindex++;
		c[cindex]=C.stop;
		J.start=0;
		J.stop=0;
		bool impossible=false;
		for(int k=1; k<a; k++){
			int start=matrix[k][0];
			int stop=matrix[k][1];
			bool overlap=false;
			for(int z=0; z<cindex; z+=2){
				if(start>c[z] && start<c[z+1] || stop>c[z] && stop<c[z+1] || start<=c[z] && stop>=c[z+1]) {
					overlap=true;
				}
			}
			if(overlap==false){
				cindex++;
				c[cindex]=start;
				cindex++;
				c[cindex]=stop;
				index++;
				result[index]='C';
			}
			else{
				if(jindex==-1){
					jindex++;
					j[jindex]=start;
					jindex++;
					j[jindex]=stop;
					index++;
					result[index]='J';
				}
				else{
					bool joverlap=false;
					for(int z=0; z<jindex; z+=2){
						if(start>j[z] && start<j[z+1] || stop>j[z] && stop<j[z+1] || start<=j[z] && stop>=j[z+1]) {
							joverlap=true;
							impossible=true;
						}
					}
					if(!joverlap){
						jindex++;
						j[jindex]=start;
						jindex++;
						j[jindex]=stop;
						index++;
						result[index]='J';

					}
				}
			}
		}
		cout<<"Case #"<<i+1<<": ";
		if(!impossible) for(int z=0; z<=index; z++) cout<<result[z];
		else cout<<"IMPOSSIBLE";
		cout<<endl;
	}
	return 0;
}	
