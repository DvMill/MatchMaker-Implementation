#include "Card.h"
#include "CardList.h"
#include "ICardList.h"
#include "ICardView.h"
#include "ICard.h"

Card::Card(int r, suit_t s)
{
	rank = r;
	suit = s;
	if (s == hearts || s == diamonds)
	{
		color = red;
	}
	else
	{
		color = black;
	}
	faceUp = false;
	selected = false;
	// this is supposed to be created by CardAreaView
	cardView = 0; // new CardView(rank, suit);
}

Card::suit_t Card::getSuit()
{
	return suit;
}

int Card::getRank()
{
	return rank;
}


Card::color_t Card::getColor()
{
	return color;
}

bool Card::isFaceUp()
{
	return faceUp;
}

void Card::setFaceUp(bool input)
{
	faceUp = input;
}

bool Card::isSelected()
{
	return selected;
}

void Card::setSelected(bool input)
{
	selected = input;
}

ICardView* Card::getCardView()
{
	return cardView;
}

void Card::displayCard(int x, int y)
{
	cardView->drawCard("Hi", 'A', faceUp, selected, x, y);
}

Card::~Card()
{
	delete cardView;
	cardView = nullptr;
}