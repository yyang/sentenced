/*
 * =====================================================================================
 *
 *       Filename:  Stopwords.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/13/2011 03:22:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#include"Container.h"
#include<fstream>
#include<iostream>
using namespace std;
Container::Container()
{

}
Container::~Container()
{}
bool Container::load(const char* file_path)
{
	dict=new set<string,StringComp>();
	ifstream ifs(file_path);
	string temp;
	while(getline(ifs, temp)&&temp.length()!=0)
	{
		//To split out the space character
		//		cout<<temp.length()<<", "<<temp<<endl;
		dict->insert(temp.substr(0, temp.length()));
	}
	//cout<<dict->size()<<endl;
}
void Container::release()
{
	delete dict;
}
bool Container::include(const string & des)
{
	if(dict->find(des)!=dict->end())
		return true;
	else
		return false;
}
/*
   int main()
   {
   Container con;
   con.load("symbols.txt");
   string temp;
   cout<<con.include(string("0"))<<endl;
   cout<<con.include(string("1"))<<endl;
   cout<<con.include("+")<<endl;
   cout<<con.include("^")<<endl;
   con.release();
   }*/
