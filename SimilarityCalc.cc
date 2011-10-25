/*
 * =====================================================================================
 *
 *       Filename:  SimilarityCalc.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/05/2011 09:02:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#include"SimilarityCalc.h"
#include"WordContainer.h"
#include<ctime>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
pthread_mutex_t SimilarityCalc::segment_mutex= PTHREAD_MUTEX_INITIALIZER;
SimilarityCalc::SimilarityCalc()
{
	stop_words.load("stop words.txt");
	symbols.load("symbols.txt");
	idf_dict.load("idf_dict.txt");
}
SimilarityCalc::~SimilarityCalc()
{
	stop_words.release();
	symbols.release();
	idf_dict.release();
}
double SimilarityCalc::calc(const string& str_a, const string& str_b)
{
	if(str_a=="" || str_b=="" || str_a.length()==0 || str_b.length()==0)
		return 0;
	WordContainer result_a, result_b;
	pthread_mutex_lock(&segment_mutex);//Lock
	cutter.setPrecise(false);
	cutter.setStopwords(stop_words);
	cutter.setSymbols(symbols);
	cutter.setContainer(*(result_a.getMap()));
	cutter.cut(str_a);
	cutter.setContainer(*(result_b.getMap()));
	cutter.cut(str_b);
	pthread_mutex_unlock(&segment_mutex);//release the lock
	double cross_product=0;
	double length_a=0, length_b=0;
	double v;
	if(result_a.getMap()->size()<result_b.getMap()->size())
	{
		for(map<string, int>::iterator it=result_a.getMap()->begin();it!=result_a.getMap()->end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_a+=pow(v, 2);
			if(result_b.getMap()->find(it->first)!=result_b.getMap()->end())
				cross_product+=
					v*(result_b.getMap()->find(it->first)->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(result_b.getMap()->find(it->first)->first)));
		}
		for(map<string, int>::iterator it=result_b.getMap()->begin();it!=result_b.getMap()->end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_b+=pow(v, 2);			
		}
	}
	else
	{
		for(map<string, int>::iterator it=result_b.getMap()->begin();it!=result_b.getMap()->end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_b+=pow(v, 2);
			if(result_a.getMap()->find(it->first)!=result_a.getMap()->end())
				cross_product+=
					v*(result_a.getMap()->find(it->first)->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(result_a.getMap()->find(it->first)->first)));
		}
		for(map<string, int>::iterator it=result_a.getMap()->begin();it!=result_a.getMap()->end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_a+=pow(v, 2);			
		}
	}
	result_a.release();
	result_b.release();
	if(length_a==0||length_b==0)
		return 0;
	else
		return cross_product/(sqrt(length_a)*sqrt(length_b));
	/* 
		 for(map<string, int>::iterator iter=words.begin();
		 iter!=words.end();
		 iter++)
		 cout<<iter->first<<"-> "<<iter->second<<endl;*/
}
struct Unit
{
	SimilarityCalc *calculator;
	string * a;
	string * b;
};
void * calc_func(void* ptr)
{
	Unit* data=(Unit*)ptr;
	double sim=data->calculator->calc(*(data->a), *(data->b));
	cout<<*(data->a)<<", "<<*(data->b)<<": "<<sim<<endl;
}
/*   
int main()
{
	
 	SimilarityCalc sc;
	vector<string> v(20, "I love chinese");
	for(int i=0;i<v.size();i++)
	{
		pthread_t thread1;
		Unit u;
		u.calculator=&sc;
		u.a=&v[i];
		u.b=&v[i];
		pthread_create(&thread1, NULL, calc_func, (void*)&u);
	}
	while(true);
}*/
