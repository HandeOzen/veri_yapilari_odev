#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool Parantez(char pacma,char pkapama)
{
	if(pacma == '(' && pkapama == ')') return true;
	else if(pacma == '{' && pkapama == '}') return true;
	else if(pacma == '[' && pkapama == ']') return true;
	return false;
}
bool ParantezKullanimi(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !Parantez(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	string expression;
	cout<<"Bir ifade giriniz:  "; 
	cin>>expression;
	if(ParantezKullanimi (expression))
		cout<<"Parantez kullanimi dogru\n";
	else
		cout<<"Parantez kullanimi yanlis\n";
}

