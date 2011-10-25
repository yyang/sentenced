/*
 * =====================================================================================
 *
 *       Filename:  SimilarityCalc.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/05/2011 08:44:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#ifndef SIMILARITYCALC_H_
#define SIMILARITYCALC_H_
#include<string>
#include<map>
#include<cmath>
#include<iostream>
#include"Container.h"
#include"WordsCutter.h"
#include"IDFDict.h"
#include<pthread.h>//use pthread_mutex_lock to support multithread safety
#define DOCUMENT_NUM_ 19264200
using namespace std;
class SimilarityCalc{
	public:
		SimilarityCalc();
		~SimilarityCalc();
		double calc(const string& , const string& );
	private:
		Container stop_words;
		Container symbols;
		WordsCutter cutter;
		IDFDict idf_dict;
		//The mutex_lock to support the multi-thread safety
		static pthread_mutex_t segment_mutex;
};
#endif
