//Amanda Tebo, Homework 3
//Main program for the game
//Includes a vector of questions, shuffling questions, and adding up the score

#include<iostream>
#include"triviaQuestion.h"
#include<vector>
#include<algorithm>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	ifstream inputFile;
	inputFile.open("TriviaData.txt");//opens the trivia data
	vector<triviaQuestion> questions;

	string questionAndAnswer;
	getline(inputFile, questionAndAnswer);
	while (getline(inputFile, questionAndAnswer))//assigns questions to a vector
	{
		triviaQuestion TQ;
		TQ.setup(questionAndAnswer);
		questions.push_back(TQ);
	}
	int numOfQuest;
	cout << "How many questions would you like to try?" << endl;
	cin >> numOfQuest;
	int score = 0;
	srand(unsigned(time(0)));
	random_shuffle(questions.begin(), questions.end());//shuffles questions
	for (int i = 0; i < numOfQuest; i++)//loops through how many questions the user wants to do and adds score
	{
		score += questions[i].askQuestion();
		cout << "Your score so far is " << score << "/" << numOfQuest << endl;
	}
	cout << "Your total score was " << score << "/" << numOfQuest << endl;//shows your total score at the end of the game
	system("pause");

}