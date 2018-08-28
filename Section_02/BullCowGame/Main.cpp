#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //Instantiate a new game

int main ()
{
	bool bPlayAgain = false;

	do {

		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

	} while (bPlayAgain);


	return 0;
}


void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
 
	}

	PrintGameSummary();

	return;
}

void PrintIntro() {

	//Introduce the game
		
	BCGame.Reset();

		std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
		std::cout << std::endl;
		std::cout << "          }   {         ___ " << std::endl;
		std::cout << "          (o o)        (o o) " << std::endl;
		std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
		std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
		std::cout << " *  |-,--- |              |------|  * " << std::endl;
		std::cout << "    ^      ^              ^      ^ " << std::endl;
		std::cout << std::endl;

		std::cout << "The rules are simple :\n\n";
		std::cout << "You have to find the hidden word, and the bulls and the cows are here to help you!\n";
		std::cout << "You have to enter your guess below and:\n";
		std::cout << "When you get a bull: It means that you entered one of the right letters at the right place\n";
		std::cout << "When you get a cow: It means that you entered one of the right letters, but at the wrong place\n";
		std::cout << "There are 30 different words to find in the program's library\n";
		std::cout << "(It is possible that you get the same word 2 times in a row)\n";
		std::cout << "It is as simple as that! So let's go!\n\n";
		std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
		std::cout << " letter isogram I'm thinking of?\n";
		std::cout << std::endl;

		return;

}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		// check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {

		case EGuessStatus::Wrong_Length:

			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;

		case EGuessStatus::Not_Isogram:

			std::cout << "Please enter a word witout repeating letters.\n\n";
			break;

		case EGuessStatus::Not_Lowercase:

			std::cout << "Please enter all lowercase letters.\n\n";
			break;

		default:
			// assume the guess is valid
			break;
		}
		
	} while (Status != EGuessStatus::Ok); // keep looping until we get no errors
	
	return Guess;
}



bool AskToPlayAgain() {

	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";

	getline(std::cin, Response);

	std::cout << std::endl;

	return (Response[0] == 'y' || Response[0] == 'Y');

	std::cout << std::endl;
}

void PrintGameSummary()
{

	if (BCGame.IsGameWon()) {

		std::cout << "You found the Hidden Word! Well Done!" << std::endl << std::endl;

	}
	else{

		std::cout << "You lose! :( The hidden word was '" << BCGame.MyHiddenWord << "'"<< std::endl << std::endl;

	}

}