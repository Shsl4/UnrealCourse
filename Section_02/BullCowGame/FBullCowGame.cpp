#include "FBullCowGame.h"
#include <map>
#include <time.h>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	
	TMap<int32, int32> WordLengthToMaxTries{ {3, 6}, {4, 6}, {5, 8}, {6, 14}, {7, 17}, {8, 21} };
	return WordLengthToMaxTries[MyHiddenWord.length()];

}

void FBullCowGame::Reset() {

	bGameIsWon = false;
	FString myWords[] = { "planet", "plane", "dwarfs", "pen", "monster", "ant", "pearl", "help", "jacket", "table", "mouse","isogram","organism","bug","browser","card","boat","flour","sugar","desktop","chair","unreal","virtual","snow","pot","computer","display","lamp","castle","bar" };
	MyHiddenWord = myWords[rand() % 9]; srand(time(NULL));
	MyCurrentTry = 1;
	return;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); 

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {

				if (MHWChar == GChar) { 

					BullCowCount.Bulls++;
				}

				else {

					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {

		bGameIsWon = true;
	}

	else

	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{

	if (Word.length() <= 1) { return true; }

	TMap <char, bool> LetterSeen;

	for (char Letter : Word) {

		Letter = tolower(Letter);

		if (LetterSeen[Letter]) { return false;	}
		else { LetterSeen[Letter] = true;  }
	}
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) {

		if (!islower(Letter)) {

			return false;

		}

	}

	return true;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) {

	if (!IsIsogram(Guess)) {

		return EGuessStatus::Not_Isogram;

	}
	else if (!IsLowercase(Guess)) {

		return EGuessStatus::Not_Lowercase;

	}
	else if (GetHiddenWordLength() != Guess.length()) {

		return EGuessStatus::Wrong_Length;

	}
	else {

		return EGuessStatus::Ok;

	}

}