#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int t;
	for(int i=0; i<n; i++){
		cin>>t;
		int matrix[t][t];
		for(int j=0; j<t; j++){
			for(int k=0; k<t; k++){
				cin>>matrix[j][k];
			} 
		}
		int trace=0;
		for(int m=0; m<t; m++){
			trace=trace+matrix[m][m];
		}
		int numberrow=0;
		int numbercolumn=0;
		for(int y=0; y<t; y++){
			bool rowrepeat[t+1];
			for(int l=0; l<=t; l++) rowrepeat[l]=false;
			for(int z=0; z<t; z++){
				int ele=matrix[y][z];
				if(rowrepeat[ele]==true){
					numberrow++;
					break;
				}
				else {
					rowrepeat[ele]=true;
				}
			}
		}
		for(int y=0; y<t; y++){
			bool columnrepeat[t+1];
			for(int l=0; l<=t; l++) columnrepeat[l]=false;
			for(int z=0; z<t; z++){
				int ele=matrix[z][y];
				if(columnrepeat[ele]==true){
					numbercolumn++;
					break;
				}
				else {
					columnrepeat[ele]=true;
				}
			}
		}
		cout<<"Case #"<<i+1<<": "<<trace<<" "<<numberrow<<" "<<numbercolumn<<endl;		

	}
	return 0;
}
