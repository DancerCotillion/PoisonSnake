#pragma once
#include <random>
#include "Board.h"
#include "Snake.h"
#include "Goal.h"

class Obstacle
{
public:
	void spawn(std::mt19937& rng, const Board& brd, const Snake& snake, const Goal& goal);

	void Draw(Board& brd) const;
	const Location& GetLocation() const;

private:
	static constexpr Color c = Colors::Gray;
	Location loc;
};