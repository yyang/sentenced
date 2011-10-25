/*
 * =====================================================================================
 *
 *       Filename:  WordContainer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2011 11:11:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xing Zhou (GGLouis), zhoux.chn@gmail.com
 *        Company:  BiffNetworking.Inc
 *
 * =====================================================================================
 */
#include"WordContainer.h"
#include<iostream>
using namespace std;
WordContainer::WordContainer()
{
	container=new map<string, int, WordComp>();
}
map<string, int, WordComp>* WordContainer::getMap()
{
	return container;
}
void WordContainer::release()
{
	delete container;
}
/* 
int main()
{
	WordContainer wc;
	++(*(wc.getMap()))["family"];
	++(*(wc.getMap()))["families"];
	cout<<(*(wc.getMap())).find("family")->second<<endl;
	cout<<(*(wc.getMap())).find("families")->second<<endl;
	wc.release();
}*/
