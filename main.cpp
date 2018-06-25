/** 
 *  @file    main.cpp
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

#include <iostream>
#include "chatbot.h"

using namespace std;

const string APP_NAME = "Lena";

int main()
{
	Chatbot chatbot(APP_NAME,"database.txt");
	string query;
	while(chatbot.getStatus())
	{
		cout << "> ";
        getline(cin, query);
        cout << chatbot.getResponse(query) << endl;
	}
    return 0;
}