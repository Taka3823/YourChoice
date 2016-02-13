#pragma once
#include "Common.h"

const bool IS_FULL_SCREEN = false;
const bool IS_DYNAMIC_SIZE = true;

class CApp
{
private:
	CApp(){}
	
public:
	static AppEnv& Get()
	{
		static AppEnv env(Window::WIDTH, Window::HEIGHT, IS_FULL_SCREEN, IS_DYNAMIC_SIZE);
		return env;
	}
};