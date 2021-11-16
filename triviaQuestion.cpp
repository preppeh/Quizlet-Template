//Amanda Tebo, Homework 3
//Defines class and allows questions and answers to be seperated and created
#include "triviaQuestion.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

triviaQuestion::triviaQuestion()
{

}
triviaQuestion::triviaQuestion(string x)//constructs the questions without having to call upon setup in the main program
{
	setup(x);

}
void triviaQuestion::setup(string questionAndAnswer)//parses out question an answers
{
	int place = questionAndAnswer.find("::");
	question = questionAndAnswer.substr(0, place);
	questionAndAnswer.erase(0, place + 2);
	place = questionAndAnswer.find("::");
	correct = questionAndAnswer.substr(0, place);
	questionAndAnswer.erase(0, place + 2);
	place = questionAndAnswer.find("::");
	incorrect1 = questionAndAnswer.substr(0, place);
	questionAndAnswer.erase(0, place + 2);
	place = questionAndAnswer.find("::");
	incorrect2 = questionAndAnswer.substr(0, place);
	questionAndAnswer.erase(0, place + 2);
	incorrect3 = questionAndAnswer;
}
int triviaQuestion::askQuestion()//asks the question, shuffles answers, and allows user to input answer
{
	int chosenValue;
	cout << question << endl;
	vector<string> answers;
	answers.push_back(correct);
	answers.push_back(incorrect1);
	answers.push_back(incorrect2);
	answers.push_back(incorrect3); //creates vector of answers
	random_shuffle(answers.begin(), answers.end());//shuffles the answers

	for (int i = 0; i < 4; i++)//outputs a list of the answers
	{
		cout << i + 1 << ". " << answers[i] << endl;
	}

	cin >> chosenValue;


	if (answers[chosenValue - 1] == correct)//if the answer is correct, returns 1 to the score
	{
		cout << "Correct!" << endl;
		return 1;
	}
	else //if the answer is incorrect, returns 0 to the score
	{
		cout << "Incorrect." << endl << "The correct answer is " << correct << endl;
		return 0;
	}
}

string triviaQuestion::checkme()//used to test the parsing
{
	return question;
}