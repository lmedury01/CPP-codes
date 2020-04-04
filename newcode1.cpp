#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int n;
	cin>>n;
	//int sum=0;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		int len=s.length();
		string result[1000];
		int j=0;
		//int sum=0;
		int lenString=-1;
		int diff=0;
		while(j!=len){
			int ele=int(s[j]-48);
			if(j!=0) diff=ele-int(s[j-1]-48);
			else diff=ele;
			if(diff>0){
				for(int x=0; x<=diff; x++){
					//cout<<"Entered for loop for: "<<x<<" times"<<endl;
					lenString++;
					//cout<<"Value of lenstring: "<<lenString<<endl;
					result[lenString]='(';
					if(x==diff) result[lenString]=s[j];
				}
				j++;
			}
			else{
				for(int x=0; x<=abs(diff); x++){
					lenString++;
					result[lenString]=')';
					if(x==abs(diff)) result[lenString]=s[j];
				}
				j++;	
			}
			
			if(j==len){
				int ele=s[j-1]-48;
				for(int x=0; x<ele; x++){
					lenString++;
					result[lenString]=')';
				}
				
			}
			
		}
		cout<<"Case #"<<i+1<<": ";
		for(int z=0; z<=lenString; z++) cout<<result[z];
		cout<<endl;
	}

	return 0;
}
