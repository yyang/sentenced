/*
 * =====================================================================================
 *
 *       Filename:  IDFDict.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/31/2011 12:02:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * 
 * * =====================================================================================
 */
#ifndef IDFDICT_H_
#define IDFDICT_H_
#include<string>
#include<map>
//#include<pthread>
using namespace std;
class IDFDict
{
	public:
		IDFDict();
		~IDFDict();
		bool load(const string&);
		bool load();
		int getFrequency(const string &);
		void release();
		void trainCorpus(const string&, const string&);
		void trainCorpusAsyn(const string&);
		double getTrainProgress();
	private:
		const static string idf_dict_text;
		map<string, int>* idf_dict;
		double train_progress;
};
#endif
