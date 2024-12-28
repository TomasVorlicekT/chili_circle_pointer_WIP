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
	pointerCircle( 40, 1, Vec(400, 300)),
	pointerRectangle(50, 30, 1, Vec(400, 300)),
	mousePosition(Vec(400,300))
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::HandleInputLogic(float timeElapsed)
{
	if (wnd.kbd.KeyIsPressed('C'))
	{
		currentObject = 'C';
	}
	else if (wnd.kbd.KeyIsPressed('R'))
	{
		currentObject = 'R';
	}

	if (timeElapsed > 0.05)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			thicknessPointer += 1 * multiplierInput;
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN) && thicknessPointer > 1)
		{
			thicknessPointer -= 1 * multiplierInput;
		}

		// input for circle attributes
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			radiusPointer += 1 * multiplierInput;
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT) && radiusPointer > 1)
		{
			radiusPointer -= 1 * multiplierInput;
		}
		//input for rectangle attributes
		if (wnd.kbd.KeyIsPressed('W'))
		{
			heightPointer += 1 * multiplierInput;
		}
		else if (wnd.kbd.KeyIsPressed('S') && heightPointer > 1)
		{
			heightPointer -= 1 * multiplierInput;
		}

		if (wnd.kbd.KeyIsPressed('D'))
		{
			widthPointer += 1 * multiplierInput;
		}
		else if (wnd.kbd.KeyIsPressed('A') && widthPointer > 1)
		{
			widthPointer -= 1 * multiplierInput;
		}

		// Rotation of rectangle
		if (wnd.kbd.KeyIsPressed('Q'))
		{
			orientationAngle = (orientationAngle < 360) ? orientationAngle + 1 : 0;
		}
		else if (wnd.kbd.KeyIsPressed('E'))
		{
			orientationAngle = (orientationAngle >= 0) ? orientationAngle - 1 : 359;
		}

		timeElapsed = 0.0f;
	}
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	timeElapsed += dt;

	mousePosition.Update(static_cast<float>(wnd.mouse.GetPosX()), static_cast<float>(wnd.mouse.GetPosY()));

	multiplierInput = wnd.kbd.KeyIsPressed(VK_SHIFT) ? 5 : 1;

	HandleInputLogic(timeElapsed);

	switch (currentObject)
	{
	case 'C':
		pointerCircle.UpdateTopology(radiusPointer, thicknessPointer, mousePosition);
		break;
	case 'R':
		pointerRectangle.UpdateTopology(widthPointer, heightPointer, thicknessPointer, mousePosition);
		pointerRectangle.UpdateOrientation(orientationAngle);
		break;
	}

	if (wnd.mouse.LeftIsPressed())
	{
		switch (currentObject)
		{
		case 'C':
			circles.push_back(PointerCircle(radiusPointer, thicknessPointer, mousePosition));
			break;
		case 'R':
			rectangles.push_back(PointerRect(widthPointer, heightPointer, thicknessPointer, orientationAngle, mousePosition));
			break;
		}
	}

}


void Game::ComposeFrame()
{
	switch (currentObject)
	{
	case 'C':
		pointerCircle.DrawPointerCircle(gfx);
		break;
	case 'R':
		pointerRectangle.DrawPointerRect(gfx);
		break;
	}

	for (PointerCircle circle : circles)
	{
		circle.DrawPointerCircle(gfx);
	}

	for (PointerRect rectangle : rectangles)
	{
		rectangle.DrawPointerRect(gfx);
	}

	//gfx.DrawRect(Vec(400, 300), 0, 100, 50, 5, Colors::Cyan);
	//gfx.DrawRect(Vec(400, 300), 30, 100, 50, 5, Colors::Green);
	//gfx.DrawRect(Vec(400, 300), 60, 100, 50, 5, Colors::Red);
	//gfx.DrawRect(Vec(400, 300), 90, 100, 50, 5, Colors::Magenta);
	//gfx.DrawRect(Vec(400, 300), 120, 100, 50, 5, Colors::Cyan);
	//gfx.DrawRect(Vec(400, 300), 150, 100, 50, 5, Colors::Green);
	//gfx.DrawRect(Vec(400, 300), 180, 100, 50, 5, Colors::Red);
	//gfx.DrawRect(Vec(400, 300), 210, 100, 50, 5, Colors::Magenta);
	//gfx.DrawRect(Vec(400, 300), 240, 100, 50, 5, Colors::Green);
	//gfx.DrawRect(Vec(400, 300), 270, 100, 50, 5, Colors::Red);
	//gfx.DrawRect(Vec(400, 300), 300, 100, 50, 5, Colors::Magenta);
	//gfx.DrawRect(Vec(400, 300), 330, 100, 50, 5, Colors::Magenta);
	//gfx.DrawRect(Vec(400, 300), 360, 100, 50, 5, Colors::Magenta);
}
