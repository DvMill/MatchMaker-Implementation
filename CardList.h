#if !defined(CARDLIST_H)
#define CARDLIST_H

#include "ICardList.h"
#include <vector>
#include "Card.h"

using namespace std;

class CardList : public ICardList
{
public:
	CardList();
	~CardList();
	virtual void WriteFile(ofstream & File);
	virtual void ReadFile(ifstream & File);
	virtual void addToTop(Card*);

	virtual Card* remove(int index);
	virtual Card* removeFromTop();
	virtual ICard* getFirst();  // returns a null pointer when the list is empty
	virtual ICard* getNext(); // returns a null pointer when there are no more elements in the list

private:
	vector<Card*> _theCards;
	vector<Card*> ::iterator _i;
};
#endif