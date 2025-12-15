#pragma once
// Include the implementation when requested
#ifdef  STB_STATS_IMPLEMENTATION
#define STB_STATS_DEFINE
#endif


// Fix compiler errors (@wolfram77)
#define _USE_MATH_DEFINES
#include <math.h>
#ifndef finite
#define finite(x) isfinite(x)
#endif


// Include the library
#include "stb_stats/stb_stats.h"
