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
		string result[a];
		int matrix[a][2];
		result[0]='J';
		int index=0;
		for(int j=0; j<a; j++){
			for(int k=0; k<2; k++){
				cin>>matrix[j][k];
			}
		}
		J.start=matrix[0][0];
		J.stop=matrix[0][1];
		C.start=0;
		C.stop=0;
		for(int k=1; k<a; k++){
			if(matrix[k][0]>=J.stop || matrix[k][1]<=J.start){
				index++;
				result[index]='J';
				J.start=matrix[k][0];
				J.stop=matrix[k][1];
			}
			else if(matrix[k][0]>=C.stop || matrix[k][1]<=C.start){
				index++;
				result[index]='C';
				C.start=matrix[k][0];
				C.stop=matrix[k][1];
			}
		}
		cout<<"Case #"<<i+1<<": ";
		for(int z=0; z<=index; z++) cout<<result[z];
		cout<<endl;	
		
	}
	return 0;
}
