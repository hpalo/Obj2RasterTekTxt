#include <vector>

class OBJConverter
{
public:
	bool Convert(const char* filePath, const char* fileToExport);
	OBJConverter();
	bool ParseOBJ(const char* filePath);
	void ExportOBJasRasterTek(const char* filePath);
	int getVerticesCount();

private:
	std::vector<float> vertexValues;
	std::vector<float> texValues;
	std::vector<float> normalValues;
	std::vector<float> rowValues;	// Contains 3 pos, 2 tex and 3 norm per row
	int verticeCount;
};