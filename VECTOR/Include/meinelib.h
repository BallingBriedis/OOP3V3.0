#ifndef MEINELIB_H
#define MEINELIB_H

// Biblioteku ir pavadinimu header failas.

#include <iostream>
#include <iomanip>
#include <string>
#include "vector.h"
#include <deque>
#include <list>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::deque;
using std::list;
using std::fixed;
using std::setprecision;
using std::sort;
using hrClock = std::chrono::high_resolution_clock;
using ms = std::chrono::milliseconds;
using sec = std::chrono::duration<double>;


#endif