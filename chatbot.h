/**
 *  @file    chatbot.h
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

#ifndef CHATBOT_H_INCLUDED
#define CHATBOT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

class Chatbot
{
private:
    string chatbotName;
    string databasePath;
    vector<string> query;
    vector<string> vResponses[3];
    bool status;
    static string punctuation;
    void loadData();
    void queryProcessing(string &_query);
    bool isPunctuation(char c);
public:
    Chatbot();
    Chatbot(string _chatbotName,string _databasePath);
    string getResponse(string _query);
    bool getStatus();
};

#endif //CHATBOT_H_INCLUDED
