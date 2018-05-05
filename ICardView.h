#include<string>

#if !defined ICARDVIEW_H
#define ICARDVIEW_H

using namespace std;

class ICardView 
{
public:
	virtual bool sendCardImage(string, char) = 0; // abstract method for CardView class
	virtual void drawCard(string, char, bool, bool, int, int) = 0; // abstract method for CardView class
};
#endif