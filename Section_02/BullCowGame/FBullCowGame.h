#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {

	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus {

	Invalid_Status,
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase

};

class FBullCowGame {

public:

	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	FString MyHiddenWord;

	EGuessStatus CheckGuessValidity(FString);
	void Reset();

	FBullCowCount SubmitValidGuess(FString);

private:

	int32 MyCurrentTry;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

};