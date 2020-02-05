// Lab_D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Console.h"
#include "stdafx.h"
#include "Bits.h"

#include <Windows.h>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;
using namespace System;

// Initialize my global integer.
unsigned int global = 0;


// Turn on method that will turn on the chosen bit.
void TurnOn(int index)
{
	global |= 1 << -index;
}


// Turn off mehthod that will turn off a chosen bit.
void TurnOff(int index)
{
	global &= ~(1 << -index);
}


// This toggle method will toggle a bit on or off depending on the current state of the bit.
void Toggle(int index)
{
	global ^= 1 << -index;
}


// Negate method will convert all of the bits to their opposite state.
void Negate()
{
	global = ~global;
}


// This left shift method will shift the enitre number or bits as one.
// This will shift over to the left one signle time.
void LeftShift()
{
	global = global << 1;
}


// This right shift method will shift the enitre number or bits as one.
// This will shift over to the right one signle time.
void RightShift()
{
	global = global >> 1;
}

int main()
{

	//For detecting any memory leaks.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); //Important!


	// Initialize a vairable for the caret's X position.
	int caretXPos = 0;


	// Set my window size and buffer size for better viewing.
	Console::SetWindowSize(80, 40);
	Console::SetBufferSize(80, 40);


	// Create a loop to keep looping through options as keys are pressed.
	while (true)
	{
		unsigned int temp = 1 << 31;

		Console::CursorVisible(false);

		// Lock screen until loop is done rendering then unlock the screen to avoid flickering.
		Console::Lock(true);
		Console::Clear();


		// Loop through and compare each temp bit set with the global number.
		Console::SetCursorPosition(Console::WindowWidth() / 4, Console::WindowHeight() / 5);
		cout << "Bits: ";
		for (unsigned int index = 32; index > 0; index--)
		{
			cout << bool(global & temp);
			temp >>= 1;
		}
		cout << endl;


		// Print a caret to the screen.
		Console::SetCursorPosition(caretXPos + 57, Console::WindowHeight() / 5 + 1);
		cout << '^';


		// Display key functions for user convenience.
		Console::SetCursorPosition(0, Console::WindowHeight() / 5 + 5);
		cout << "F1) Turn On bit " << endl;
		cout << "F2) Toggle bit " << endl;
		cout << "F3) Turn Off bit" << endl;
		cout << "F4) Negate all bits " << endl;
		cout << "Left Shift Key) Left Shift all bits " << endl;
		cout << "Right Shift Key) Right Shift all bits " << endl;
		cout << "Left Arrow) Move Caret Left " << endl;
		cout << "Right Arrow) Move Caret Right " << endl;

		Console::Lock(false);

		Sleep(100);


		// Create all GetAsyncKeyState's for all appropriate methods and coorect keys.
		if (GetAsyncKeyState(VK_F1))
		{
			// List methods.
			TurnOn(caretXPos);
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_F2))
		{
			// List methods.
			Toggle(caretXPos);
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_F3))
		{
			// List methods.
			TurnOff(caretXPos);
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_F4))
		{
			// List methods.
			Negate();
			Sleep(30);
		}

		if (GetAsyncKeyState(VK_LSHIFT))
		{
			// List methods.
			LeftShift();
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_RSHIFT))
		{
			// List methods.
			RightShift();
			Sleep(20);
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			// Check to make sure the caret does not move past the first bit displaying.
			if (caretXPos > -31)
			{
				// Move caret left.
				caretXPos--;
				Sleep(20);
			}

		}

		if (GetAsyncKeyState(VK_RIGHT))
		{

			// Check to make sure the caret does not move past the last bit displaying.
			if (caretXPos < 0)
			{
				// Move caret right.
				caretXPos++;
				Sleep(20);
			}

		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
