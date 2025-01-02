#include <iostream>
#include "OBJConverter.h"
//#define DEBUGPARSING
int main(int argc, char *argv[])
{
#ifndef DEBUGPARSING
    if (argc < 2) {
        std::cout << "OBJ2RT\nAn OBJ to Raster Tek converter\n";
        std::cout << "Usage: OBJ2RT model.obj out.txt\n";

        return -1;
    }
    else if (argc == 2) {
        std::cout << "Not enough parameters.\n";
        return -1;
    }

    OBJConverter converter;
    converter.Convert(argv[1], argv[2]);
#else
    OBJConverter converter;
    converter.Convert("pyramid.obj", "pyramid.txt");
#endif
}