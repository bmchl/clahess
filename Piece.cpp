#include "Piece.h"

bool Piece::validateMove(Position& position)
{
	bool valid = false;
	for (auto& possiblePosition : possiblePositions)
		{
			if ((position.row == possiblePosition->row) &&
				(position.column == possiblePosition->column))
				{
					valid = true;
					std::cout << "move is among the piece's possible positions" << std::endl;
				}
		}
	return valid;
};

void Piece::talk(std::ostream& os) const { os << "plain piece"; };

void Piece::addPossiblePosition(int newX, int newY)
{
	if ((newX <= 7) &&
		(newY <= 7) &&
		(newX >= 0) &&
		(newY >= 0))
		{
			possiblePositions.push_back(new Position{ newX, newY });
		}
}

std::ostream& operator<< (std::ostream& os, const Piece& piece)
{
	piece.talk(os);
	return os;
}

std::ostream& operator<< (std::ostream& os, const Square& square)
{
	os << "square at position (" << square.row_ << "," << square.column_ << ")";
	
	if (square.currentPiece != nullptr)
		{
			os << " with " << *square.currentPiece;
		}
	os << "\n";
	return os;
}
