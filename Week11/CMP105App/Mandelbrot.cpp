#include "Mandelbrot.h"

// Import things we need from the standard library
using std::cout;
using std::endl;

// Need to access the concurrency libraries 
using namespace concurrency;

// The size of the image to generate.
const int WIDTH = 1920;
const int HEIGHT = 1200;

// The number of times to iterate before we assume that a point isn't in the
// Mandelbrot set.
// (You may need to turn this up if you zoom further into the set.)
const int MAX_ITERATIONS = 500;

// The image data.
// Each pixel is represented as 0xRRGGBB.
uint32_t image[HEIGHT][WIDTH];

void Mandelbrot::report_accelerator(const accelerator a)
{
	const std::wstring bs[2] = { L"false", L"true" };
	std::wcout << ": " << a.description << " "
		<< endl << "       device_path                       = " << a.device_path
		<< endl << "       dedicated_memory                  = " << std::setprecision(4) << float(a.dedicated_memory) / (1024.0f * 1024.0f) << " Mb"
		<< endl << "       has_display                       = " << bs[a.has_display]
		<< endl << "       is_debug                          = " << bs[a.is_debug]
		<< endl << "       is_emulated                       = " << bs[a.is_emulated]
		<< endl << "       supports_double_precision         = " << bs[a.supports_double_precision]
		<< endl << "       supports_limited_double_precision = " << bs[a.supports_limited_double_precision]
		<< endl;
}

void Mandelbrot::list_accelerators()
{
	//get all accelerators available to us and store in a vector so we can extract details
	std::vector<accelerator> accls = accelerator::get_all();

	// iterates over all accelerators and print characteristics
	for (unsigned i = 0; i < accls.size(); i++)
	{
		accelerator a = accls[i];
		report_accelerator(a);
		//if ((a.dedicated_memory > 0) & (a.dedicated_memory < 0.5*(1024.0f * 1024.0f)))
		//accelerator::set_default(a.device_path);
	}

	accelerator::set_default(accls[2].device_path);
	accelerator acc = accelerator(accelerator::default_accelerator);
	std::wcout << " default acc = " << acc.description << endl;

} // list_accelerators


////// Any use of concurrency::accelerator results in an Exception Thrown.


void Mandelbrot::query_AMP_support()
{
	std::vector<accelerator> accls = accelerator::get_all();
	if (accls.empty())
	{
		cout << "No accelerators found that are compatible with C++ AMP" << std::endl;
	}
	else
	{
		cout << "Accelerators found that are compatible with C++ AMP" << std::endl;
		list_accelerators();
	}
} // query_AMP_support

void Mandelbrot::regular_non()
{
	std::cout << "attempt\n" << endl;

	/*// Local pointer to the globally declared image data.
	uint32_t* pImage = &(image[0][0]);

	// array_view object will permit the image data to be available
	// on the CPU and GPU when needed.
	array_view<uint32_t, 2> a(HEIGHT, WIDTH, pImage);

	// Don't need to transfer data from CPU to GPU as all
	// calculations are done on the GPU.
	a.discard_data(); // a.discard(); ??*/
}