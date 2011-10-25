#include"WordSimilarity.h"
#include<iostream>
using namespace std;
int min(int ,int ,int );
int calcDiff(const char* ,const char* ,int ,int ,int ,int ,int** & );
WordSimilarity::WordSimilarity(){}
double WordSimilarity::calc(const string& a,const string& b)
{
	if(a.length()==0 || b.length()==0)
		return 0;
	double sim=0;
	int **token=new int *[a.length()];
	for(int i=0;i<a.length();i++)
	{   
		token[i]=new int[b.length()];
		for(int j=0;j<b.length();j++)
			token[i][j]=-1;
	}
	// sim=1/(1+(double)calcDiff(a.c_str(),b.c_str(),0,a.length()-1,0,b.length()-1,token));
	int max=(a.length()>b.length()?a.length():b.length());
	sim=(max-calcDiff(a.c_str(),b.c_str(),0,a.length()-1,0,b.length()-1,token))/(double)max;
	for(int i=0;i<a.length();i++)
	{
		delete []token[i];
	}
	delete []token;
	return sim;
}
int min(int a,int b,int c)
{
	if(a<=b && a<=c)
		return a;
	else if(b<=a && b<=c)
		return b;
	else
		return c;
}
	int calcDiff
(const char* a,const char* b,int a_start,int a_end,int b_start,int b_end,int** & token)
{
	if(a_start>a_end)
		return b_end-b_start+1;
	if(b_start>b_end)
		return a_end-a_start+1;
	if(token[a_start][b_start]!=-1)
		return token[a_start][b_start];
	else
	{
		if(a[a_start]==b[b_start])
			token[a_start][b_start]=
				calcDiff(a,b,a_start+1,a_end,b_start+1,b_end,token);
		else
			token[a_start][b_start]= 
				min(calcDiff(a,b,a_start+1,a_end,b_start,b_end,token),
						calcDiff(a,b,a_start,a_end,b_start+1,b_end,token),
						calcDiff(a,b,a_start+1,a_end,b_start+1,b_end,token))
				+1;
		return token[a_start][b_start];
	}
}
