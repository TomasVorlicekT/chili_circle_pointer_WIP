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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	pointerCircle( 40, 1, Vec(400, 300))
{
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
	float dt = ft.Mark();
	timeElapsed += dt;

	mousePosition.Update(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());

	multiplier = wnd.kbd.KeyIsPressed(VK_SHIFT) ? 5 : 1;

	if (timeElapsed > 0.05)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			thicknessPointer += 1 * multiplier;
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN) && thicknessPointer > 0)
		{
			thicknessPointer -= 1 * multiplier;
		}

		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			radiusPointer += 1 * multiplier;
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT) && radiusPointer > 0)
		{
			radiusPointer -= 1 * multiplier;
		}
		timeElapsed = 0.0f;
	}

	pointerCircle.UpdateTopology(radiusPointer, thicknessPointer, mousePosition);

	if (wnd.mouse.LeftIsPressed())
	{
		circles.push_back(PointerCircle(radiusPointer, thicknessPointer, mousePosition));
	}

}

void Game::ComposeFrame()
{
	pointerCircle.DrawPointerCircle(gfx);

	for (PointerCircle circle : circles)
	{
		circle.DrawPointerCircle(gfx);
	}

	gfx.DrawLine(Vec(50, 50), Vec(200, 200), 20, Colors::Blue);
	gfx.DrawLine(Vec(210, 200), Vec(60, 50), 20, Colors::Blue);

	gfx.DrawLine(Vec(40, 400), Vec(500, 400), 20, Colors::Blue);
	gfx.DrawLine(Vec(500, 450), Vec(40, 450), 20, Colors::Blue);
}
