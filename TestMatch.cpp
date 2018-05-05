#include "ICard.h"
#include "ICardList.h"
#include "Card.h"
#include "CardList.h"
#include "MatchMaker.h"
#include <iostream>
using namespace std;

int main()
{		
	MatchMaker l;
	//create a card
	Card *card1 = new Card(1, Card::diamonds);
	Card *card2 = new Card(1, Card::clubs);
	Card *card3 = new Card(1, Card::hearts);
	Card *card4 = new Card(2, Card::spades);
	Card *card5 = new Card(3, Card::clubs);
	Card *card6 = new Card(4, Card::hearts);
	Card *card7 = new Card(5, Card::diamonds);
	Card *card8 = new Card(12, Card::clubs);
	Card *card9 = new Card(7, Card::hearts);
	Card *card10 = new Card(1, Card::spades);
	Card *card11 = new Card(9, Card::clubs);
	Card *card12 = new Card(4, Card::spades);
	Card *card13 = new Card(12, Card::diamonds);
	Card *card14 = new Card(3, Card::spades);
	Card *card15 = new Card(13, Card::hearts);
	Card *card16 = new Card(4, Card::diamonds);
	Card *card17 = new Card(6, Card::clubs);
	Card *card18 = new Card(11, Card::spades);
	Card *card19 = new Card(4, Card::clubs);
	Card *card20 = new Card(8, Card::clubs);
	Card *card21 = new Card(2, Card::clubs);

	//create a list of cards

	CardList *outofOrder = new CardList(); // 4,3,2,1,6,5
	outofOrder->addToTop(card6);
	outofOrder->addToTop(card14);
	outofOrder->addToTop(card21);
	outofOrder->addToTop(card1);
	outofOrder->addToTop(card17);
	outofOrder->addToTop(card7);
	CardList *ordercards = new CardList();
	ordercards->addToTop(card3);
	ordercards->addToTop(card4);
	ordercards->addToTop(card5);
	ordercards->addToTop(card6);
	ordercards->addToTop(card7);
	CardList *ordercards2 = new CardList();
	ordercards2->addToTop(card2);
	ordercards2->addToTop(card3);
	ordercards2->addToTop(card4);
	ordercards2->addToTop(card5);
	ordercards2->addToTop(card6);
	ordercards2->addToTop(card7);	
	CardList *ordercards3 = new CardList();
	ordercards3->addToTop(card1);
	ordercards3->addToTop(card12);
	ordercards3->addToTop(card17);
	ordercards3->addToTop(card9);
	ordercards3->addToTop(card13);
	ordercards3->addToTop(card15);
	CardList *suitcards = new CardList();
	suitcards->addToTop(card1);
	suitcards->addToTop(card7);
	suitcards->addToTop(card13);
	suitcards->addToTop(card16);
	CardList *suitcards2 = new CardList();
	suitcards2->addToTop(card2);
	suitcards2->addToTop(card8);
	suitcards2->addToTop(card19);
	suitcards2->addToTop(card20);
	CardList *morecards = new CardList();
	morecards->addToTop(card1);
	morecards->addToTop(card2);
	morecards->addToTop(card3);
	morecards->addToTop(card4);
	CardList *morecard2 = new CardList();
	morecard2->addToTop(card16);
	morecard2->addToTop(card9);
	morecard2->addToTop(card6);
	morecard2->addToTop(card13);
	CardList *cards = new CardList();
	cards->addToTop(card3);
	cards->addToTop(card4);
	cards->addToTop(card5);
	cards->addToTop(card6);
	cards->addToTop(card7);
	CardList *seqcards = new CardList();
	seqcards->addToTop(card3);
	seqcards->addToTop(card4);
	seqcards->addToTop(card5);
	seqcards->addToTop(card6);
	seqcards->addToTop(card7); 
	CardList *oseqcards = new CardList();
	oseqcards->addToTop(card4);
	oseqcards->addToTop(card3);
	oseqcards->addToTop(card5);
	oseqcards->addToTop(card6);
	oseqcards->addToTop(card7);
	CardList *seqcards2 = new CardList();
	seqcards2->addToTop(card7);
	seqcards2->addToTop(card17);
	seqcards2->addToTop(card20);
	seqcards2->addToTop(card11);
	seqcards2->addToTop(card13);
	CardList *seqcards3 = new CardList();
	seqcards3->addToTop(card3);
	seqcards3->addToTop(card4);
	seqcards3->addToTop(card5);
	seqcards3->addToTop(card6);
	seqcards3->addToTop(card7);

	//testing three of a kind using different cards
	cout << "3of a Kind Test: "<< endl << "sending in 1,1,1" << endl;

	if (MatchMaker::IsThreeOfAKind(card1, card2, card3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 1,1,2" << endl;
	if (MatchMaker::IsThreeOfAKind(card1, card2, card4))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 4,1,1" << endl;
	if (MatchMaker::IsThreeOfAKind(card12, card1, card3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 1,11,1" << endl;
	if (MatchMaker::IsThreeOfAKind(card10, card18, card3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 4,4,4" << endl;
	if (MatchMaker::IsThreeOfAKind(card12, card6, card16))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	//four of a kind test
	cout << "4of a Kind Test: " << endl << "sending in 1,1,1,1" << endl;

	if (MatchMaker::IsFourOfAKind(card1, card2, card3,card10))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 1,1,2,1" << endl;
	if (MatchMaker::IsFourOfAKind(card1, card2, card4,card10))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 4,1,1,1" << endl;
	if (MatchMaker::IsFourOfAKind(card12, card1,card10, card3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 1,11,1,1" << endl;
	if (MatchMaker::IsFourOfAKind(card10, card18, card3,card10))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 4,4,4,4" << endl;
	if (MatchMaker::IsFourOfAKind(card12, card6, card16,card19))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	//testing IsSameSuit
	cout << "Testing same suit " << endl; \

		cout << "sending in failure " << endl;
	if (MatchMaker::IsSameSuit(suitcards2))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in random " << endl;
	if (MatchMaker::IsSameSuit(cards))
		cout << "true" << endl;
	else
		cout << "false" << endl; 

	cout << "sending in random " << endl;
	if (MatchMaker::IsSameSuit(seqcards2))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "sending in all diamands" << endl;
	if (MatchMaker::IsSameSuit(suitcards))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	//testing AlternatingColors
	cout << "Testing alternating colors " << endl;\
		
		cout << "sending in red, black, red, black " << endl;
	if(MatchMaker::AlternatingColors(morecards))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in black, red, black, red, red" << endl;
	if (MatchMaker::AlternatingColors(cards))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "sending in red,red,red,red" << endl;
	if (MatchMaker::AlternatingColors(morecard2))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;
	
	
	//testing IsOrdered
	cout << "Testing IsOrdered " << endl; 

		cout << "sending in 1,2,3,4,5" << endl;
	if (MatchMaker::IsOrdered(ordercards))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	cout << "sending in 1,1,2,3,4,5" << endl;
	if (MatchMaker::IsOrdered(ordercards2))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;
	cout << "sending in 1,4,6,7,12,13" << endl;
	if (MatchMaker::IsOrdered(ordercards3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	//testing Sequence
	cout << "Testing Sequence " << endl; 

		cout << "sending in 1,2,3,4,5" << endl;
	if (MatchMaker::IsInSequence(seqcards))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;
	cout <<"sending in 2,1,3,4,5" << endl;
	if (MatchMaker::IsInSequence(oseqcards))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;
	
	cout << "sending in 5,6,8,9,12" << endl;
	if (MatchMaker::IsInSequence(seqcards2))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "sending in 1,4,6,7,12,13" << endl;
	if (MatchMaker::IsInSequence(ordercards3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << endl;

	//testing OrderSorting
	cout << "Testing order " << endl; 
	cout << "Sending in 4,3,2,1,6,5"<<endl;
	ICardList *testingorder = new CardList();
	testingorder = l.OrderCardlist(outofOrder);
	ICard* c = testingorder->getFirst();
	while (c != 0)
	{
		cout << c->getRank()<<","; 
		c = testingorder->getNext();
	}

	cout << endl;


	system("pause");
	return 0;
	

}//end main()