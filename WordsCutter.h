/*
 * =====================================================================================
 *
 *       Filename:  WOrdsCutter.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2011 04:23:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#ifndef WORDS_CUTTER_H_
#define WORDS_CUTTER_H_
#include<map>
#include<string>
#include<algorithm>
#include<locale>
#include<cctype>
#include"Container.h"
#define DEBUG_CUT_  0
using namespace std;
class WordsCutter
{
	public:
		WordsCutter();
		~WordsCutter();
		void setStopwords(const Container&);
		void setSymbols(const Container&);
		void setContainer(map<string, int>&);
		void cut(const string &);
	private:
		map<string, int>* words;
		Container stop_words;
		Container symbols;
		string toLowerCase(string&);
};
#endif
