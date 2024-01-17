#pragma once
#include <chrono>
#include <vector>

using namespace std;

constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char SCREEN_RESIZE = 2;

constexpr unsigned short SCREEN_HEIGHT = 1920;
constexpr unsigned short SCREEN_WIDTH = 1080;

constexpr chrono::microseconds FRAME_DURATION(16667);

enum Cell
{
	Empty,
	Wall
};

typedef vector<array<Cell, SCREEN_HEIGHT / CELL_SIZE>> Map;