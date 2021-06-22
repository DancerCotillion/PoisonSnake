#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx); 
	void DrawCell(const Location& loc, Color c);
	void DrawBorder(); 

	int GetGridWidth() const;
	int GetGridHeight() const;
	bool isInsideBoard(const Location& loc) const; 

private:
	static constexpr Color borderColor = Colors::Blue; 
	static constexpr int borderPadding = 2; 
	static constexpr int borderWidth = 4;
	static constexpr int cellPadding = 1; 
	static constexpr int dimension = 20;
	static constexpr int width = 37;
	static constexpr int height = 27;
	static constexpr int x = 20;
	static constexpr int y = 20;


	Graphics& gfx; 
};