#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
#include "Position.h"
#include "Piece.h"


class TemporaryPiece
{
public:
	TemporaryPiece(Piece& piece, Square& position) : piece_(piece), position_(position)
	{
		//piece_.assignToSquare(position_);
	};
	~TemporaryPiece()
	{
		piece_.isDead = true;
		position_.currentPiece = nullptr;
		//piece_.~Piece();
	};
	Piece get() { return piece_; };
	operator Piece() { return get(); };
	
private:
	Piece& piece_;
	Square& position_;
};