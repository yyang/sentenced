/*
 * =====================================================================================
 *
 *       Filename:  Run.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2011 04:29:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#include"SimilarityCalc.h"
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	string a;
	string b;
	double sim;
	cout<<endl<<"Welcome to the sentences' similarity calculation module!"<<endl;
	cout<<"Input sentence A and B or type quit to exit~"<<endl;
	cout<<"Loading ..."<<endl;
	SimilarityCalc calc;
	while(1)
	{
		cout<<"Sentence A>";
		getline(cin,a);
		if(a=="quit")
			break;
		cout<<"Sentence B>";
		getline(cin,b);
		if(b=="quit")
			break;
		if( a.length()==0 || b.length()==0)
			cout<<"Invalid Input!"<<endl;
		else 
		{
			sim=calc.calc(a,b);	
			cout<<endl<<"The similarity of '"<<a<<"'"<<" and '"<<b<<"'"<<endl<<"is "<<sim<<endl;
		}
	}
	cout<<"bye~"<<endl;
}
