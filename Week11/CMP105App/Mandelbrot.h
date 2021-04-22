#pragma once

#include <chrono>
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cstdlib>
#include <complex>

#include <amp.h>
#include <amp_math.h>
#include <time.h>

#include <string>
#include <numeric>

// Need to access the concurrency libraries 
using namespace concurrency;

class Mandelbrot
{
private:
	// List and select the accelerator to use.
	void list_accelerators();
	void report_accelerator(const accelerator a);

public:
	// Query if AMP accelerator exists on hardware.
	void query_AMP_support();
	void regular_non();
};