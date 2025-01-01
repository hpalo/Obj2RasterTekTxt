#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdio.h>
#include "OBJConverter.h"
using namespace std;
namespace fs = std::filesystem;

OBJConverter::OBJConverter() {
	verticeCount = 0;
}

bool OBJConverter::Convert(const char* filePath, const char* fileToExport) {
	if (!fs::exists(filePath)) {
		std::cout << "File '" << filePath << "' does not exist.\n";
		return false;
	}
	ParseOBJ(filePath);
	ExportOBJasRasterTek(fileToExport);
	return true;
}

bool OBJConverter::ParseOBJ(const char *filePath) {
	float x, y, z, s, t;
	char lineBuffer[256];
	FILE* file = NULL;
	errno_t err = fopen_s(&file, filePath, "r");
	if (err != 0 || file == NULL) {
		perror("Error opening file");
		return false;
	}

	while (fgets(lineBuffer, sizeof(lineBuffer), file) != NULL) {
		if (strncmp(lineBuffer, "v ", 2) == 0) {
			char* trimmedBufffer = lineBuffer + 2;
			if (sscanf_s(trimmedBufffer, "%f %f %f", &x, &y, &z) != 3) {
				printf("Error parsing values.\n");
				return false;
			}
			vertexValues.push_back(x);
			vertexValues.push_back(y);
			vertexValues.push_back(z);
		}
		if (strncmp(lineBuffer, "vn", 2) == 0) {
			char* trimmedBufffer = lineBuffer + 2;
			if (sscanf_s(trimmedBufffer, "%f %f %f", &x, &y, &z) != 3) {
				printf("Error parsing values.\n");
				return false;
			}
			normalValues.push_back(x);
			normalValues.push_back(y);
			normalValues.push_back(z);
		}
		if (strncmp(lineBuffer, "vt", 2) == 0) {
			char* trimmedBufffer = lineBuffer + 2;
			if (sscanf_s(trimmedBufffer, "%f %f", &s, &t) != 2) {
				printf("Error parsing values.\n");
				return false;
			}
			texValues.push_back(s);
			texValues.push_back(t);
		}

		unsigned long v, t, n;
		int vertexIndex;
		int texIndex;
		int normIndex;

		if (strncmp(lineBuffer, "f ", 2) == 0) {
			char* trimmedBufffer = lineBuffer + 2;
			
			for (int i = 0; i < 3; ++i) {
				if (sscanf_s(trimmedBufffer, "%lu/%lu/%lu", &v, &t, &n) != 3) {
					printf("Error parsing values.\n");
					return false;
				}
				vertexIndex = (v - 1) * 3;
				texIndex = (t - 1) * 2;
				normIndex = (n - 1) * 3;

				rowValues.push_back(vertexValues[vertexIndex]);
				rowValues.push_back(vertexValues[vertexIndex + 1]);
				rowValues.push_back(vertexValues[vertexIndex + 2]);

				rowValues.push_back(texValues[texIndex]);
				rowValues.push_back(texValues[texIndex + 1]);

				rowValues.push_back(normalValues[normIndex]);
				rowValues.push_back(normalValues[normIndex + 1]);
				rowValues.push_back(normalValues[normIndex + 2]);

				++verticeCount;

				trimmedBufffer += 6;
			}
		}
	}

	fclose(file);
	return true;
}

void OBJConverter::ExportOBJasRasterTek(const char* filePath)
{
	std::ofstream outFile;
	outFile.open(filePath);
	outFile << "Vertex Count: " << getVerticesCount() << "\n\n";
	outFile << "Data:\n\n";
	for (int i = 0; i < getVerticesCount(); ++i) {
		for (int j = 0; j < 8; ++j)
		{
			outFile << rowValues[i*8+j];
			if (j == 7) outFile << "\n";
			else outFile << " ";
		}
	}
	outFile.close();
	cout << "File '" << filePath << "' was created.";
}

int OBJConverter::getVerticesCount() { return verticeCount; }