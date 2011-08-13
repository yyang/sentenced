/*
 * =====================================================================================
 *
 *       Filename:  SplitNullInStopWords.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/2011 10:25:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
  	
 	ifstream ifs("stop words.txt");
	ofstream ofs("stop words_beat.txt");
	string temp;
	while(getline(ifs, temp)&&temp.length()!=0)
	{
		//To split out the NULL character in stopwords which has null character(downloaded from internet)
		cout<<temp.length()<<", "<<temp<<endl;
		ofs<<temp.substr(0, temp.length()-1)<<"\n";
		
	}
	ifs.close();
	ofs.close();
	//cout<<dict->size()<<endl;
}
