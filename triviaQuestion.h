//Amanda Tebo, Homework 3
//Prototypes for all of the class information used in the program
#ifndef triviaQuestion_h
#define triviaQuestion_h
#include <string>
class triviaQuestion
{
public:
	triviaQuestion();
	triviaQuestion(std::string);
	void setup(std::string);
	int askQuestion();
	std::string checkme();


private:
	std::string question;
	std::string correct;
	std::string incorrect1;
	std::string incorrect2;
	std::string incorrect3;
};
#endif