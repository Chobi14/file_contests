#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string IntToString ( long long num )
{
  ostringstream oss;  
  oss << num;  
  return oss.str();
}

long long StringToInt ( string str )
{
  long long num;
  istringstream ( str ) >> num;
  return num;
}

int main(){
	
	int t = 0; int cont = 1;	
	long long n;
	
	/*ifstream Binput;
	Binput.open("BpracticeLarge.in");
	
	ofstream Boutput;
	Boutput.open("BpracticeLargeo.txt");*/
	
	//Binput >> t;
	cin >> t;
	
	while(t--)	
	{
		bool flag = 0;
		//Binput >> n;
		cin >> n;
		string s = IntToString (n);
		if (s.length() == 1)					
		{
			//(t == 0) ? Boutput << "Case #" << cont << ": " << n : Boutput << "Case #" << cont << ": " << n << endl;
			(t == 0) ? cout << "Case #" << cont << ": " << n : cout << "Case #" << cont << ": " << n << endl;
		}else
		{
			for(int i = (s.length()-1); i >= 1; i--)
			{				
				if((s[i] < s[i-1]) || (s[i] == 48))
				{						
					s[i] = 57;
					if (s[i-1] == 48) 
					{ s[i-1] = 57; flag = 1; }
					else
					{ s[i-1] -= 1; flag = 0;}					
				}else if( s[i] > s[i-1] && s[i-1] == 48 )
				{
					s[i] = 57;
					if (s[i-1] == 48) 
					{ s[i-1] = 57; flag = 1; }
					else
					{ s[i-1] -= 1; flag = 0;}					
				}else if((i == 1) && (flag))				
					s[i-1] -= 1;	
					
				if(i <= (s.length()-2))	{
					if(s[i] > s[i+1])
						s[i+1]=57;
				}					
			}													
			
			n = StringToInt(s);
			//(t == 0) ? Boutput << "Case #" << cont << ": " << n : Boutput << "Case #" << cont << ": " << n << endl;
			(t == 0) ? cout << "Case #" << cont << ": " << n : cout << "Case #" << cont << ": " << n << endl;
		}
		
		++cont;
	}	
	//Binput.close();
	//Boutput.close();
	
	return 0;
}
