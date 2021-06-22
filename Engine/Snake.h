#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(Color c);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc); 
		void Draw(Board& brd) const; 
		const Location& GetLocation() const; 
	private: 
		Location loc;
		Color c; 
	};

public:
	Snake(const Location& loc); 
	void MoveBy(const Location& delta_loc); 
	Location GetNextHeadLocation(const Location& delta_loc) const; 
	void Grow();
	void Draw(Board& brd) const;
	bool isInTileExceptEnd(const Location& target) const; 
	bool isInTile(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green; 
	static constexpr int nSegMax = 100;
	Segment segments[nSegMax];
	int nSegments = 1; 
};