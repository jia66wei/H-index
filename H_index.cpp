#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

map<string,int> FansNum;

void FansHash(map<string,int>&m, char *Fansinfile)
{
	ifstream in(Fansinfile);
	string buffer;
	while(getline(in,buffer))
	{
		int pos = buffer.find("\t");
		string uid = buffer.substr(0,pos);
		string  str_fansNum = buffer.substr(pos+1,buffer.size()-pos-1);
		int fansNum = atoi(str_fansNum.c_str());
		FansNum.insert(make_pair(uid, fansNum));
	}
}

void FansUid_split(string str, vector<string> &v) 
	//http://stackoverflow.com/questions/289347/using-strtok-with-a-stdstring
{
	int pos = str.find("\t");
	v.push_back(str.substr(0,pos));
	istringstream iss(str.substr(pos+1,str.size()-pos-1));
	string token;
	while(getline(iss,token,','))
	{
		v.push_back(token);
	}
}

void mapTraverse(map<string,int>&m)
{
	for(map<string,int>::iterator iter= m.begin(); iter != m.end(); ++iter)
	{
		cout << iter->first << "\t" << iter->second << "\n";
	}
}

template<class T>
void vectorTraverse(vector<T> &v)
{
	//http://bbs.csdn.net/topics/330160034
	//
	for(typename vector<T>::iterator iter = v.begin();iter < v.end(); ++iter)
	{
		cout << *iter <<" ";
	}
	cout << endl;
}

int cmp(int a,int b)
{
	return a > b;
}


void GetH_index(char *Numinfile, map<string,int>&m)
{
	ifstream in(Numinfile);
	string buffer;
	while(getline(in,buffer))
	{
		vector<string>fansUid;
		int pos = buffer.find("\t");
		FansUid_split(buffer,fansUid);
		map<string,int>::iterator fansitera;
		vector<int>fansSort;
		for(vector<string>::iterator iter = fansUid.begin()+1 ; iter < fansUid.end() ; iter++)
		{
			fansitera = FansNum.find(*iter);
			if(fansitera != FansNum.end())
			{
				fansSort.push_back(fansitera->second);
			}
		}
		sort(fansSort.begin(),fansSort.end(),cmp);
		//vectorTraverse(fansSort);
		int i = 0;
		for( vector<int>::iterator ite = fansSort.begin();ite < fansSort.end(); ++ite)
		{
			if(i < *ite)
			{
				++i;
			}
			else
			{
				cout << *(fansUid.begin())<<"\t" << i << endl;
				break;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		cout << "need FansNum Fansuid\n" ;
			return 0;
	}
	FansHash(FansNum, argv[1]);
//	mapTraverse(FansNum);
	GetH_index(argv[2],FansNum);	
	return 0;
}
