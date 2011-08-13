/*
 * =====================================================================================
 *
 *       Filename:  TrainCorpus.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/2011 10:48:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  Biff Networking.Inc
 *
 * =====================================================================================
 */
#include"IDFDict.h"
#include<cstring>
#include<iostream>
using namespace std;
int main(int argc, char * argv[])
{
	if(argc<2 || strlen(argv[1])==0 || strlen(argv[2])==0)
	{
		cout<<"Invaid command, please run it in the format: trainCorpus train_data result_file"<<endl;
		return -1;
	}
	IDFDict idf;
	idf.trainCorpus(argv[1], argv[2]);
}
