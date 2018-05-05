#if !defined (MatchMaker_H)
#define MatchMaker_H

#include "ICardList.h"

class Card;
class MatchMaker
{
public:
	static bool IsInSequence(ICardList* );
	static bool AlternatingColors(ICardList* );
	static bool IsSameSuit(ICardList* );
	static bool IsSameRank(ICardList* );
	static bool IsOrdered(ICardList* );
	ICardList* OrderCardlist(ICardList*);
	static bool IsMeld3(Card* , Card* , Card* );
	static bool IsMeld4(Card* , Card* , Card* , Card* );
	static bool IsMeldOver5(ICardList* );
	static bool IsThreeOfAKind(Card* , Card* , Card* );
	static bool IsFourOfAKind(Card* , Card* , Card* , Card* );
};
#endif
