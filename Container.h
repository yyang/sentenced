/*
 * =====================================================================================
 *
 *       Filename:  Container.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/13/2011 03:00:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#ifndef CONTAINER_H_
#define CONTAINER_H_
#include<set>
#include<string>
using namespace std;
struct StringComp{
	bool operator()(const string& lhs, const string& rhs) const
	{
		return lhs<rhs;
	}
/* 
	bool operator>(const string& lhs, const string& rhs) const
	{
		return lhs>rhs;
	}
	bool operator==(const string& lhs, const string& rhs) const
	{
		return lhs==rhs;
	}*/
};
class Container{
	public:
		Container();
		~Container();
		bool load(const char*);
		void release();
		bool include(const string &);
	private:
		set<string, StringComp>* dict;
				
};
#endif
