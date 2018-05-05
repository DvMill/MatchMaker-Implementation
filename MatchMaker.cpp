#include <iomanip>
#include "MatchMaker.h"
#include "ICardList.h"
#include "Card.h"
#include "CardList.h"
#include <vector>
#include <algorithm>
using namespace std;
MatchMaker l;
/*precondition
CheckCards>=2
Creates a temp cardList and makes it equal to checkCards
Checks if the temp CardList is in order (least to greatest) by calling isOrdered
retrun false: sets the tem cardList to OrderCardList(ICardList checkCards
retrun true: skips callig the OrderCardList
Checks the temp CardList to see if it is in seqential order from Ace to King and returns bool
*/
bool MatchMaker::IsInSequence(ICardList*  checkCards)
{
	ICardList *temp=checkCards;
	if (!IsOrdered(temp))
		return temp = l.OrderCardlist(checkCards);
	ICard* c = temp->getFirst();
	ICard* s = c;
	while (c != 0)
	{
		if (c->getRank() != (s->getRank()+1)&&c != s)
			return false;
		s = c;
		c = temp->getNext();
	}
	delete temp;
	return true; 
}

/*Precondition
CheckCards>=2
Checks the given cardList to ensure that Colors are alternating and returns a bool
*/
bool MatchMaker::AlternatingColors(ICardList* checkCards)
{
	ICard* c = checkCards->getFirst();
	ICard* s = c;
	while (c != 0)
	{
		if (c->getColor() == (s->getColor()) && c != s)
			return false;
		s = c;
		c = checkCards->getNext();

	}
	return true;
}

/*Precondition
CheckCards>=2
Checks the cardList to see if all cards are in the same suit by calling each card 
and comparing if they match the first card's suit and returns a bool
*/
bool MatchMaker::IsSameSuit(ICardList*  checkCards) 
{	
	ICard* c = checkCards->getFirst();
	ICard* s = c;
	while (c != 0)
	{
		if (c->getSuit()!= s->getSuit()&& c != s)
			return false;
		s = c;
		c = checkCards->getNext();
	}
	return true;
}

/*precondition
CheckCards>=2
Checks the character flag to know if the cardList is ordered from least to greatest
to pass on to check if it is in sequence
*/
bool MatchMaker::IsOrdered(ICardList*  checkCards) 
{
	ICard* c = checkCards->getFirst();
	ICard* s = c;
	while (c != 0)
	{
		if (c->getRank() < s->getRank()&& c != s)
			return false;
		s = c;
		c = checkCards->getNext();
	}
	return true;
}

/*Rearranges the cardList in the correct order by using a loop 
to set the card based on rank 
and returns a cardList
*/
ICardList* MatchMaker::OrderCardlist(ICardList*  checkCards) 
{
	ICardList *temp = checkCards;
	CardList *returning = new CardList();
	ICard* c = temp->getFirst();
	ICard* s = c;
	Card::suit_t t=c->getSuit();
	vector<int>v;
	while (c != 0)
	{
		v.push_back(c->getRank());
		c = checkCards->getNext();
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		Card* g = new Card(v[i], t);
		
		returning->addToTop(g);
	}

	return returning;
}

/*takes in 3 different Cards 
to check if it is possible to make a run 
or if they are 3 of a kind
*/
bool MatchMaker::IsMeld3(Card* first, Card* second, Card* third) 
{
	CardList *temp = new CardList();
	temp->addToTop(first);
	temp->addToTop(second);
	temp->addToTop(third);
	if (IsThreeOfAKind(first, second, third))
	{
		delete temp;
		return true;
	}
	if(IsInSequence(temp))
	{
		delete temp;
		return true;
	}
	delete temp;
	return false;
}

/*takes in 4 different Cards
to check if it is possible to make a run
or if they are 4 of a kind
*/
bool MatchMaker::IsMeld4(Card* first, Card* second, Card* third, Card* fourth) 
{
	CardList *temp = new CardList();
	temp->addToTop(first);
	temp->addToTop(second);
	temp->addToTop(third);
	temp->addToTop(fourth);
	if (IsFourOfAKind(first, second, third, fourth))
	{
		delete temp;
		return true;
	}
	if(IsInSequence(temp))
	{
		delete temp;
		return true;
	}
	delete temp;
	return false;
}

/*takes in 5 different Cards
to check if it is possible to make a run
*/
bool MatchMaker::IsMeldOver5(ICardList* checkCards)
{
	if (!IsInSequence(checkCards))
		return false;
	return true;
}

/*Takes in 3 cards objects
and compares if they are all same rank
*/

bool MatchMaker::IsThreeOfAKind(Card *first, Card* second, Card* third) 
{

	if (first->getRank() != second->getRank() || first->getRank() != third->getRank())
		return false;
	return true;
}

/*Takes in 3 cards objects
and compares if they are all same rank
*/
bool MatchMaker::IsFourOfAKind(Card* first, Card* second, Card* third, Card* fourth) 
{
	if (first->getRank() != second->getRank() || first->getRank() != third->getRank()||first->getRank()!=fourth->getRank())
		return false;
	return true;
}