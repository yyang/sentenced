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
	if(argc<2 || strlen(argv[1])==0 || strlen(argv[2])==0)
	{
		cout<<"Invaid command, please run it in the format: calc s1 s2"<<endl;
		return -1;
	}
	string a=argv[1];
	string b=argv[2];
	SimilarityCalc calc;
	double sim=calc.calc(a, b);
	cout<<"The similarity of "<<a<<" and "<<b<<" is "<<sim<<endl;
}
