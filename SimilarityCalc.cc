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
#include<ctime>
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
	 map<string, int> result_a, result_b;
	 cutter.setStopwords(stop_words);
	 cutter.setSymbols(symbols);
	 cutter.setContainer(result_a);
	 cutter.cut(str_a);
	 cutter.setContainer(result_b);
	 cutter.cut(str_b);
	 double cross_product=0;
	 double length_a=0, length_b=0;
	 double v;
	 if(result_a.size()<result_b.size())
	 {
	 	for(map<string, int>::iterator it=result_a.begin();it!=result_a.end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_a+=pow(v, 2);
			if(result_b.find(it->first)!=result_b.end())
				cross_product+=
					v*(result_b.find(it->first)->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first)));
		}
	 	for(map<string, int>::iterator it=result_b.begin();it!=result_b.end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_b+=pow(v, 2);			
		}
	 }
	 else
	 {
	 	for(map<string, int>::iterator it=result_b.begin();it!=result_b.end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_b+=pow(v, 2);
			if(result_a.find(it->first)!=result_a.end())
				cross_product+=
					v*(result_a.find(it->first)->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first)));
		}
	 	for(map<string, int>::iterator it=result_a.begin();it!=result_a.end();it++)
		{
			v=it->second*log(DOCUMENT_NUM_/idf_dict.getFrequency(it->first));
			length_a+=pow(v, 2);			
		}
	 }
	 if(length_a==0||length_b==0)
		 return 0;
	 else
		 return cross_product/(sqrt(length_a)*sqrt(length_b));
	 /* 
	 for(map<string, int>::iterator iter=words.begin();
	 iter!=words.end();
	 iter++)
	 cout<<iter->first<<"-> "<<iter->second<<endl;*/
}/*
int main()
{
	long s1=time(NULL);
	SimilarityCalc sc;
	long s2=time(NULL);
	string a="English is different from Chinese";
	string b="The Chinsese loves English";
	double sim=sc.calc(a,b);
	long s3=time(NULL);
	cout<<(s2-s1)<<" "<<(s3-s2)<<endl;
  cout<<a<<endl<<b<<endl<<sim<<endl;
}*/
