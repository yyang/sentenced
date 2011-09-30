/*
 * =====================================================================================
 *
 *       Filename:  IDFDict.cc
 *
 *    Description:  		
 *
 *        Version:  1.0
 *        Created:  07/31/2011 12:11:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#include"IDFDict.h"
#include<fstream>
#include<iostream>
#include<cstdlib>
#include"Container.h"
#include"WordsCutter.h"
using namespace std;
const string IDFDict::idf_dict_text="idf_dict.txt";
bool IDFDict::load(const string& file_path)
{
	idf_dict=new map<string, int>();
	ifstream ifs(file_path.c_str());
	string temp;
	string word;
	int freq;
	while(getline(ifs, temp)&&temp.length()!=0)
	{
		word=temp.substr(0, temp.find(" "));
		freq=atoi(temp.substr(temp.find(" ")+1).c_str());
		idf_dict->insert(map<string, int>::value_type(word, freq));		
	}
	//cout<<idf_dict->size()<<endl;
}
bool IDFDict::load()
{
	load(idf_dict_text);
}
int IDFDict::getFrequency(const string& word)
{
	map<string, int>::iterator it=idf_dict->find(word);
	if(it==idf_dict->end())
		return 1;
	else
		return it->second;
}
void IDFDict::release()
{
	delete idf_dict;
}
void IDFDict::trainCorpus(const string& corpus_path, const string& result_path)
{
	ifstream ifs(corpus_path.c_str());
	string temp;
	Container stop_words;
	Container symbols;
	stop_words.load("stop words.txt");	
	symbols.load("symbols.txt");
	map<string, int> words;
	WordsCutter cutter;
	cutter.setStopwords(stop_words);
	cutter.setSymbols(symbols);
	cutter.setContainer(words);
	int i=0;
	while(getline(ifs, temp))
	{
		i++;
		cout<<i<<"	";
		cutter.cut(temp);
	}	
	stop_words.release();
	symbols.release();
	ifs.close();
	ofstream idf_dict_disk(result_path.c_str());
	for(map<string, int>::iterator iter=words.begin();
			iter!=words.end();
			iter++)
		idf_dict_disk<<iter->first<<" "<<iter->second<<"\n";
	idf_dict_disk.close();
}
void IDFDict::trainCorpusAsyn(const string& corpus_path)
{
	/*ifstream ifs(corpus_path.c_str());
	string temp;
	StopWords stop_words;
	stop_words.load("stop words.txt");	
	map<string, int> words;
	WordsCutter cutter;
	cutter.setStopwords(stop_words);
	cutter.setContainer(words);
	int i=0;
	while(getline(ifs, temp))
	{
		i++;
		cout<<i<<"	";
		cutter.cut(temp);
	}	
	stop_words.release();
	ifs.close();
	ofstream idf_dict_disk(idf_dict_text.c_str());
	for(map<string, int>::iterator iter=words.begin();
			iter!=words.end();
			iter++)
		idf_dict_disk<<iter->first<<" "<<iter->second<<"\n";
	idf_dict_disk.close();*/
}
IDFDict::IDFDict()
{}
IDFDict::~IDFDict()
{}
/*
int main()
{
	IDFDict idf;
	//idf.load("idf_dict.txt");
	//cout<<idf.getFrequency("hello")<<endl;
	idf.trainCorpus("tweets.2.data");
}*/
