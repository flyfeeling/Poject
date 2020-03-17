#ifndef Solution_h__
#define Solution_h__
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <unordered_set>
#include <stack>
#include <map>
#include <unordered_map>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif
using namespace std;
class Solution
{
public:
	virtual void  Excute() = 0;
};



#endif // Solution_h__
