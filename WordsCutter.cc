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
#include"Constant.h"
using namespace std;
WordsCutter::WordsCutter(){precise=true;}
WordsCutter::~WordsCutter(){}
void WordsCutter::setStopwords(const Container& stop_words)
{
	this->stop_words=stop_words;
}
void WordsCutter::setContainer(map<string, int> &src)
{
	this->words=&src;
}
void WordsCutter::setContainer(map<string, int, WordComp>& src)
{
	this->words_beta=&src;
}
void WordsCutter::setSymbols(const Container& symbols)
{
	this->symbols=symbols;
}
void WordsCutter::setPrecise(bool s)
{
	//This flag is set manually 
	if(s)
		precise=true;
	else
		precise=false;
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
			if(STOPWORD_CHECK)
			{
				if(!stop_words.include(s))
				{
#if DEBUG_CUT_
					cout<<s<<" ";
#endif
					if(precise)
						++(*words)[s];
					else
						++(*words_beta)[s];
				}
			}
			else
			{
#if DEBUG_CUT_
				cout<<s<<" ";
#endif
				if(precise)
					++(*words)[s];
				else
					++(*words_beta)[s];
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
		string des="I like chinese chinesees";
		Container stop_words;
		Container symbols;
		stop_words.load("stop words.txt");	
		symbols.load("symbols.txt");
		WordContainer words;
		WordsCutter cutter;
		cutter.setStopwords(stop_words);
		cutter.setSymbols(symbols);
		cutter.setContainer(words);
		cutter.cut(des);
		for(map<string, int>::iterator iter=words.getMap()->begin();
		iter!=words.getMap()->end();
		iter++)
		cout<<iter->first<<"-> "<<iter->second<<endl;

		}*/
