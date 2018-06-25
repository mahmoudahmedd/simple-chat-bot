/** 
 *  @file    chatbot.cpp
 *  @author  Mahmoud Ahmed Tawfik (mahmoudahmedd)
 *  @date    21/05/2018 
 *  @version 1.1 
 *
 *  @brief Chatbot using a knowledge in database
 *
 *  @section DESCRIPTION
 *
 *  This is a little program that reads list of data from 
 *	a specified file and process the query and use the knowledge 
 *  in database then return response.
 *
 */

#include "chatbot.h"

using namespace std;


void Chatbot::loadData()
{
	ifstream file;
	file.open(databasePath,ios::in);
	string temp;
	while(getline(file, temp))
	{
		query.push_back(temp);
		for(int i = 0;i < 3;i++)
		{
			getline(file, temp);
			vResponses[i].push_back(temp);
		}
		getline(file, temp);
	}
	file.close();
}

void Chatbot::queryProcessing(string &_query)
{
	int len = _query.length();
	string temp = "";

	// upper case
	for( int i = 0; i < len; i++ )
		_query[i] = toupper(_query[i]);

	//
	temp = "";
	if(len > 1 && _query[0] != ' ' && !isPunctuation(_query[0]))
		temp += _query[0];

	for(int i = 1; i < len; ++i)
		if(!isPunctuation(_query[i]) && !(_query[i] == ' ' && _query[i-1] == ' '))
			temp += _query[i];
	_query = temp;

	
}

bool Chatbot::isPunctuation(char c)
{
	return punctuation.find(c) != string::npos;
}

Chatbot::Chatbot()
{
	status = false;
	cout << "Chatbot::Chatbot() ERROR: Invalid constructor" << endl;
}

Chatbot::Chatbot(string _chatbotName,string _databasePath)
{
	status       = true;
    chatbotName  = _chatbotName;
	databasePath = _databasePath;
	loadData();
	cout << "> Hello. I'm " << chatbotName << "." << endl;
}

string Chatbot::getResponse(string _query)
{
	vector<string> responses;
	srand((unsigned) time(NULL));

	queryProcessing(_query);

	for(unsigned i = 0; i < query.size();  ++i)
		if(query[i] == _query)
		{
			for(int j = 0; j < 3; ++j)
			{
				responses.push_back(vResponses[j][i]);
			}
			break;
		}


	if(_query == "BYE")
    {
		status = false;
        return "> IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!";
    }
	else if(responses.size() == 0 || _query.size() == 0)
    {
        return "> I'M NOT SURE IF I  UNDERSTAND WHAT YOU  ARE TALKING ABOUT." ;
    }
    else
    {
        int nSelection  =   rand() % 3;
		return "> " + responses[nSelection];
    }
}

bool Chatbot::getStatus()
{
	return status;
}

string Chatbot::punctuation = ".?_/,!’<>[](){}-:;”'";