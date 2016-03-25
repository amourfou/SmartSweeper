#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <random>

#define RANDOM_MAX			0x7FFFFFFF

using namespace std;

extern default_random_engine g_engine;
//----------------------------------------------------------------------------
//	some random number functions.
//----------------------------------------------------------------------------

//returns a random integer between x and y
inline int RandInt(int x, int y)
{
	uniform_int_distribution<int> distribution(x, y);
	return distribution(g_engine);

	//return rand() % (y - x + 1) + x;
}

//returns a random float between zero and 1
inline double RandFloat()
{
	uniform_int_distribution<int> distribution(1, RANDOM_MAX);
	return double(distribution(g_engine)) / double(RANDOM_MAX + 1.0);

	//return double(rand()) / (RAND_MAX + 1.0);
}

//returns a random bool
inline bool RandBool()
{
	if (RandInt(0,1))
		return true;
	else
		return false;
}

//returns a random float in the range -1 < n < 1
inline double RandomClamped()
{
	return RandFloat() - RandFloat();
}


//-----------------------------------------------------------------------
//	
//	some handy little functions
//-----------------------------------------------------------------------

//converts an integer to a std::string
string itos(int arg);

//converts an float to a std::string
string ftos (float arg);

//	clamps the first argument between the second two
void Clamp(double &arg, double min, double max);

/////////////////////////////////////////////////////////////////////
//
//	Point structure
//
/////////////////////////////////////////////////////////////////////
struct SPoint
{
	float x, y;
	
	SPoint() {}
	SPoint(float a, float b) : x(a) , y(b) {}
};




#endif