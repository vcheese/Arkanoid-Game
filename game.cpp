
#define _WINDOWS
#include "Framework.h"
#include <regex>
#include <iostream>

/* Test Framework realization */
class MyFramework : public Framework 
{
public:

	MyFramework(unsigned WindowWidth = 800, unsigned WindowHeight = 600)
		: m_WindowWidth(WindowWidth), m_WindowHeight(WindowHeight)
	{
	}

	virtual void PreInit(int& width, int& height, bool& fullscreen) override
	{
		width = m_WindowWidth;
		height = m_WindowHeight;
		fullscreen = false;
	}

	virtual bool Init() override
	{
		return true;
	}

	virtual void Close() override
	{

	}

	virtual bool Tick() override
	{
        drawTestBackground();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) override
	{

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) override
	{

	}

	virtual void onKeyPressed(FRKey k) override
	{

	}

	virtual void onKeyReleased(FRKey k) override
	{

	}
	
	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}

protected:
	unsigned m_WindowWidth;
	unsigned m_WindowHeight;
};

std::smatch GetWindowSize(std::string WindowSize)
{
	std::regex Pattern("([0-9]+)[x]([0-9]+)");
	std::smatch Size;
	if (!std::regex_match(WindowSize, Size, Pattern))
		std::cout << "Wrong Window Size! Example:   ./game.exe -window 800x600\n";
	return Size;
}

int main(int argc, char* argv[])
{
	if (argc == 3 && strcmp(argv[1], "-window") == 0)
	{
		auto WindowSize = GetWindowSize(argv[2]);
		return run(new MyFramework(stoi(WindowSize[0]), stoi(WindowSize[1])));
	}
	else
		return run(new MyFramework);
}
