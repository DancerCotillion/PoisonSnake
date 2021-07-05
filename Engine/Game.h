/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Obstacle.h"
#include <random>
#include "FrameTimer.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft; 
	Board brd; 
	Snake snake; 
	Location delta_loc = { 1,0 };
	std::mt19937 rng;
	static constexpr int nObstaclesMax = 10; 
	Obstacle obstacles[nObstaclesMax];
	int nObstacles = 0; 
	static constexpr float snakeMovePeriodMin = 0.040f; 
	static constexpr float snakeMovePeriodSpeedUp = 0.15f; 
	int score = 1;

	float SnakeMoveRate = 0.4f;
	float SnakeMoveCounter = 0.0f;
	float snakeSpeedupFactor = 0.93f;

	static constexpr float nPoison = 240; 
	static constexpr float nFood = 12; 
	bool gameIsOver = false; 
	bool gameIsStarted = false; 
	/********************************/
};