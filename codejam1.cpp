#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		int len=s.length();
		//cout<<"length of string: "<<len<<" size of resulting string: "<<len*len<<endl;
		string result[len*len];
		int j=0;
		int pos=-1;
		bool flag=false;
		if(len==1){
			if(s[j]=='1'){
				cout<<"(1)"<<endl;
			}
			else{
				cout<<"0"<<endl;
			}

			continue;
		}
		
		while(j!=len){
			if(s[j]==s[j+1]){ //if current character same as next
				if(flag==true){
					//cout<<"Prev character same as this character"<<endl;
					pos++; //if prev character same as current
					result[pos]=s[j];		
				}
				else{
					if(s[j]=='0'){
						//cout<<"Element["<<j<<"] is 0 and prev not same as this"<<endl;
						pos++; //storing 0 right away as brackets not required
						result[pos]=s[j];
					}
					else{
						//cout<<"Element["<<j<<"] is 1 and prev not same as this"<<endl;
						pos++;
						result[pos]='('; //Initiating opening parantheses
						pos++;
						result[pos]='1';
						//cout<<"Added opening paranthesis and 1"<<endl;
					}
					flag=true;
					//cout<<"Flag has been modified to true after "<<j<<" iterations"<<endl;
				}
				j++;
			}
			else{
				if(flag==true){ //If last character of series is encountered
					if(s[j]=='1'){ //If last character is 1
						pos++; 
						result[pos]='1'; //Putting 1
						pos++;
						result[pos]=')'; //Closing paranthesis
					}
					else{
						pos++;
						result[pos]='0';
						if(s[j+1]=='1'){
							pos++;
							result[pos]='(';
						}
					}
					j++;
				}
				else{
					if(s[j]=='0'){
						//cout<<"Element["<<j<<"] is 0 and next not the same"<<endl;
						pos++; 
						result[pos]='0'; //0 required no paranthesis
					}
					else{
						//cout<<"Element["<<j<<"] is 1 and next not the same"<<endl;
						pos++; //1 requires opening and closing paranthesis
						result[pos]='(';
						pos++;
						result[pos]='1';
						pos++;
						result[pos]=')';
					}
					j++;
				}
			}
		}
		
		for(int z=0; z<=pos; z++) cout<<result[z];
		cout<<endl;

	}
		return 0;
}
