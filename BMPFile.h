#pragma once

#include <string>
#include <cstring> // for memcpy

class BMPFile
{
public:

	/*
		Load / Save BMP files

		example of reading an image in a BMP file and saving it to another file:

			unsigned int width, height;
			unsigned char *imageBuffer = BMPFile::LoadBmp("earth.bmp", width, height);
			BMPFile::SaveBmp("test.bmp",imageBuffer,width,height);
			delete[]imageBuffer;
	*/

	// Save image buffer (each color in BGR format) to a BMP file
	static void saveBmp(std::string fileName, unsigned char* imageBuffer, unsigned int width, unsigned int height);

	// Load a BMP file to a buffer and get its width and height, don't forget to delete buffer after use (see example above)
	static unsigned char* loadBmp(std::string fileName, unsigned int& width, unsigned int& height, bool flipY = true);
};
