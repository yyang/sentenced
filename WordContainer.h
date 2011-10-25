/*
 * =====================================================================================
 *
 *       Filename:  WordContainer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2011 10:58:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  BiffNetworking.Inc
 *
 * =====================================================================================
 */
#ifndef WORD_CONTAINER_H
#define WORD_CONTAINER_H
#include"Constant.h"
#include<string>
#include"WordSimilarity.h"
#include<map>
using namespace std;
struct WordComp{
	bool operator()(const string& word1, const string& word2)const
	{
		return (WordSimilarity::calc(word1, word2)<MINIMUM_WORD_SIMILARITY && word1<word2);	
		//  return word1<word2;
	}
};
class WordContainer
{
	public:
		WordContainer();
		map<string, int, WordComp>* getMap();
		void release();
	private:
		map<string, int, WordComp>* container;
};
#endif
