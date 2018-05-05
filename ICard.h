#if!defined ICard_H
#define ICard_H
#define ACE = 1;
#define JACK = 11;
#define QUEEN = 12;
#define KING = 13;

#include "ICardView.h"

class ICard
{
public:
	typedef enum 
	{
		hearts, diamonds, clubs, spades
	} suit_t;

	typedef enum
	{
		red, black
	} color_t;

	virtual suit_t getSuit() = 0;
	virtual int getRank() = 0;
	virtual color_t getColor() = 0;
	virtual bool isFaceUp() = 0;
	virtual void setFaceUp(bool) = 0;
	virtual bool isSelected() = 0;
	virtual void setSelected(bool) = 0;
	virtual ICardView* getCardView() = 0;
	//virtual ~ICard()= 0;

};
#endif