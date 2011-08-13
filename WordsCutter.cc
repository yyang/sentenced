/*
 * =====================================================================================
 *
 *       Filename:  WordsCutter.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2011 04:23:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#include"WordsCutter.h"
#include<iostream>
using namespace std;
WordsCutter::WordsCutter(){}
WordsCutter::~WordsCutter(){}
void WordsCutter::setStopwords(const Container& stop_words)
{
	this->stop_words=stop_words;
}
void WordsCutter::setContainer(map<string, int>& src)
{
	this->words=&src;
}
void WordsCutter::setSymbols(const Container& symbols)
{
	this->symbols=symbols;
}
string WordsCutter::toLowerCase(string & src)
{
	//std::transform(src.begin(), src.end(), src.begin(), tolower);
	for(int i=0;i<src.length();i++)
	{
		src[i]=tolower(src[i]);
	}
	return src;	
}
void WordsCutter::cut(const string & des)
{
	const int n=des.size();
	int start=0;
	for(int i=0;i<n;)
	{
		while((i<n)&&symbols.include(des.substr(i, 1)))
			i++;
		start=i;
		while((i<n)&&!symbols.include(des.substr(i, 1)))
			i++;
		if(start<i)
		{
		  //cout<<start<<", "<<i<<endl;
			string s(des.substr(start, i-start).c_str());
			toLowerCase(s);
			if(!stop_words.include(s))
			{
#if DEBUG_CUT_
				cout<<s<<" ";
#endif
				++(*words)[s];
			}
		}
	}
#if DEBUG_CUT_
	cout<<endl;
#endif
}
/* 
int main()
{
	string des="I like chinese";
	Container stop_words;
	Container symbols;
	stop_words.load("stop words.txt");	
	symbols.load("symbols.txt");
	map<string, int> words;
	WordsCutter cutter;
	cutter.setStopwords(stop_words);
	cutter.setSymbols(symbols);
	cutter.setContainer(words);
	cutter.cut(des);
	for(map<string, int>::iterator iter=words.begin();
			iter!=words.end();
			iter++)
		cout<<iter->first<<"-> "<<iter->second<<endl;

}*/
