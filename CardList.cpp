#include "CardList.h"
#include "Card.h"
#include "ICard.h"
#include "ICardList.h"
#include <fstream>
#include <iostream>
using namespace std;

void CardList::WriteFile(ofstream & outputFile) 
{
	outputFile.open("somefile.txt");

	for (int i = _theCards.size() - 1; i >= 0; i--) 
	{
		if (_theCards[i]->getRank() == 2)
			outputFile << "Two " << endl;
		else if (_theCards[i]->getRank() == 3)
			outputFile << "Three " << endl;
		else if (_theCards[i]->getRank() == 4)
			outputFile << "Four " << endl;
		else if (_theCards[i]->getRank() == 5)
			outputFile << "Five " << endl;
		else if (_theCards[i]->getRank() == 6)
			outputFile << "Six " << endl;
		else if (_theCards[i]->getRank() == 7)
			outputFile << "Seven " << endl;
		else if (_theCards[i]->getRank() == 8)
			outputFile << "Eight " << endl;
		else if (_theCards[i]->getRank() == 9)
			outputFile << "Nine " << endl;
		else if (_theCards[i]->getRank() == 10)
			outputFile << "Ten " << endl;
		else if (_theCards[i]->getRank() == 11)
			outputFile << "Jack " << endl;
		else if (_theCards[i]->getRank() == 12)
			outputFile << "Queen " << endl;
		else if (_theCards[i]->getRank() == 13)
			outputFile << endl << "King ";
		else if (_theCards[i]->getRank() == 1)
			outputFile << endl << "Ace ";
		outputFile << "of ";
		if (_theCards[i]->getSuit() == Card::clubs)
			outputFile << "Clubs\n" << endl;
		else if (_theCards[i]->getSuit() == Card::diamonds)
			outputFile << "Diamonds\n" << endl;
		else if (_theCards[i]->getSuit() == Card::hearts)
			outputFile << "Hearts\n" << endl;
		else if (_theCards[i]->getSuit() == Card::spades)
			outputFile << "Spades\n" << endl;
	}//end for()
	
}//end writeFile()

void CardList::ReadFile(ifstream & f1) 
{
	if (f1.is_open())
		std::cout << f1.rdbuf();
	else
		std::cout << "wrong";
}

void CardList::addToTop(Card* c) 
{
	_theCards.push_back(c);
}

Card* CardList::remove(int index) 
{
	if (_theCards.empty())
		return 0;
	_theCards.erase(_theCards.begin() + index - 1);

	return 0;
}

Card* CardList::removeFromTop() 
{
	if (_theCards.empty())
		return 0;

	Card* c = _theCards.back();
	_theCards.pop_back();
	return c;
}

ICard* CardList::getFirst()
{
	_i = _theCards.begin();
	if (_i == _theCards.end())
		return 0;
	else
		return *_i;
}

ICard* CardList::getNext()
{
	if (_i == _theCards.end())
		return 0;
	else
	{
		_i++;
		if (_i == _theCards.end())
			return 0;
		else
			return *_i;
	}
}

CardList::CardList()
{
	_theCards.clear();
}

CardList::~CardList()
{
}