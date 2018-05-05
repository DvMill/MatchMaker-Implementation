#if !defined(ICARDLIST_H)
#define ICARDLIST_H

#include "ICard.h"
#include "ICardCollection.h"

class ICardList : ICardCollection {
public:
	//virtual void Search() = 0;
	virtual void WriteFile(ofstream &) = 0;
	virtual void ReadFile(ifstream &) = 0;
	virtual ICard* getFirst() = 0;
	virtual ICard* getNext() = 0;
	//virtual ICard* getLast() = 0;
	
};
#endif