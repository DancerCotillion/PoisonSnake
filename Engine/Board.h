#pragma once
#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
public:
	Board(Graphics& gfx); 
	void DrawCell(const Location& loc, Color c);
	void DrawBorder(); 

	int GetGridWidth() const;
	int GetGridHeight() const;
	bool isInsideBoard(const Location& loc) const; 

	int GetContents(const Location& loc) const; 
	void ConsumeContents(const Location& loc);
	void SpawnContents(std::mt19937& rng, const class Snake& snake, int contentsType);
	
	void DrawCells();

private:
	static constexpr Color borderColor = Colors::Blue; 
	static constexpr Color obstacleColor = Colors::Gray;
	static constexpr Color foodColor = Colors::Red;
	static constexpr Color poisonColor = Colors::Magenta;
	static constexpr int borderPadding = 2; 
	static constexpr int borderWidth = 4;
	static constexpr int cellPadding = 1; 
	static constexpr int dimension = 20;
	static constexpr int width = 37;
	static constexpr int height = 27;
	static constexpr int x = 20;
	static constexpr int y = 20;

	//0: empty, 1: obstacle, 2:food, 3: Poision.
	int contents[width * height] = { 0 };

	Graphics& gfx; 
};