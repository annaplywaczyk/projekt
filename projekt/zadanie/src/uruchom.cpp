/*
 * uruchom.cpp
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */
#include "uruchom.hh"


using namespace std;

void zegar::algorytm()
{
	for (unsigned int i=0; i<dane_podstawowe.size(); i++)
	{dane_podstawowe[i]=dane_podstawowe[i]*2;}
}

LARGE_INTEGER zegar::wlaczStoper()
{
 LARGE_INTEGER start;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&start);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return start;
}

LARGE_INTEGER zegar::wylaczStoper()
{
 LARGE_INTEGER stop;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&stop);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return stop;
}


