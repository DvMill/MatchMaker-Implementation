#if!defined Card_H
#define Card_H

#include "ICard.h"
//#include "ICardView.h"

class Card : public ICard
{
private:
	int rank;
	suit_t suit;
	color_t color;
	bool faceUp;
	bool selected;
	ICardView* cardView;
public:
	Card(int, suit_t);
	suit_t getSuit();
	virtual int getRank();
	virtual color_t getColor();
	virtual bool isFaceUp();
	virtual void setFaceUp(bool);
	virtual bool isSelected();
	virtual void setSelected(bool);
	virtual void displayCard(int, int);
	virtual ICardView* getCardView();
	~Card();

};
#endif