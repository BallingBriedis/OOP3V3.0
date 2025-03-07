#ifndef MEINELIB_H
#define MEINELIB_H

// Biblioteku ir pavadinimu header failas.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using hrClock = std::chrono::high_resolution_clock;
using ms = std::chrono::milliseconds;
using sec = std::chrono::duration<double>;


#endif