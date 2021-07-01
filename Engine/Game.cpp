/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd (gfx),
	rng(std::random_device()()),
	snake({2,2}),
	goal(rng, brd, snake)
{
	//for (int i = 0l; i < nObstaclesMax; ++i)
	//{
	//	obstacles[i].spawn(rng, brd, snake, goal); 
	//}

	//Test branch changes.
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark(); 

	if (gameIsStarted)
	{
		if (!gameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0, -1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{	//solving the doubling back issue - replicate for all directions. 
				if (delta_loc.y != -1)
				{
					delta_loc = { 0, 1 };
				}
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1, 0 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1, 0 };
			}

			//TODO: Change this so it is tied to score instead - call the following on time intervals (take a now and compare to old, if greater than half a second, move and change interval when eating(?)). 

			SnakeMoveCounter += dt;
			if (SnakeMoveCounter >= SnakeMoveRate)
			{
				SnakeMoveCounter -= SnakeMoveRate;
				const Location Next = snake.GetNextHeadLocation(delta_loc);
				if (!brd.isInsideBoard(Next) ||
					snake.isInTileExceptEnd(Next) ||
					brd.CheckForObstacle (Next))
				{
					gameIsOver = true;
				}
				else
				{
					const bool eating = Next == goal.GetLocation();
					if (eating)
					{
						snake.Grow();
						++score;
						if (score % 3 == 0)
						{
							brd.SpawnObstacle(rng, snake, goal); 
						}
					}
					snake.MoveBy(delta_loc);
					if (eating)
					{
						goal.Respawn(rng, brd, snake);
					}
				}
				//for (int i = 0; i < nObstacles; ++i)
				//{
				//	if (Next == obstacles[i].GetLocation())
				//	{
				//		gameIsOver = true;
				//	}
				//}
			}
			SnakeMoveRate = std::max(SnakeMoveRate - dt * snakeSpeedupFactor, snakeMovePeriodMin);
		}		
	}
	else
	{
		gameIsStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

void Game::ComposeFrame()
{
	if (gameIsStarted)
	{
		//for (int i = 0; i < nObstacles; ++i)
		//{
		//	if (nObstacles < nObstaclesMax)
		//	{
		//		obstacles[i].Draw(brd);
		//	}
		//}
		brd.DrawObstacles();
		snake.Draw(brd);
		goal.Draw(brd);
		if (gameIsOver)
		{
			SpriteCodex::DrawGameOver(200, 200, gfx);
		}
		brd.DrawBorder();
	}
	else
	{
		SpriteCodex::DrawTitle(200, 200, gfx);
	}
}
