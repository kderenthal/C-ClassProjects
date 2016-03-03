#include<iostream>
#include<string>
using namespace std; 

bool invalid(string a){
    string team="";
	for(int i=0;i<a.size();i++)
	    if(team.find(a[i])>a.size())
	    	team=team+a[i];
	if(team.size()<=1) 
		return true;
	int* count= new int[team.size()]();
	for(int i=0;i<a.size();i++)
		for(int j=0;j<team.size();j++)
		    if(a[i]==team[j])
		        count[j]++;
	for(int i=1;i<team.size();i++)
	    if(count[i]!=count[0]){
	        delete [] count;
	        return true;
	    }
	return false;
}
void result(string a){
    string team="";
	for(int i=0;i<a.size();i++)
	    if(team.find(a[i])>a.size())
	    	team=team+a[i];
	cout<<"There are "<<team.size()<<" teams."<<endl;
	cout<<"Each team has "<<a.size()/team.size()<<" runners."<<endl;
	int* count= new int[team.size()]();
	for(int i=0;i<a.size();i++)
		for(int j=0;j<team.size();j++)
		    if(a[i]==team[j])
		        count[j]=count[j]+i+1;
	cout<<"Team  Score"<<endl;
	for(int i=0;i<team.size();i++)
	    cout<<"   "<<team[i]<<"  "<<(double)count[i]/(a.size()/team.size())<<endl;
	delete [] count;
}
int main(){ 
	string a;
	cout<<"Please enter the team score, Each team has a name,";
	cout<<" which is one of the uppercase letters A-Z. "<<endl;
	cout<<"No two teams have the same name, ";
	cout<<"so there are a maximum number of 26 teams. "<<endl;
	cout<<"Each team has the same number of members. "<<endl;;
	cout<<"No two runners cross the finish line at the same time – i.e. there are no ties."<<endl;	
	cin>>a;
	while(invalid(a)){
		cout<<"It's invalid input, please re-enter the team score.";
		cin>>a;
	}
	result(a);
	return 0;
}