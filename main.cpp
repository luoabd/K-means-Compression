#include <stdio.h>
#include<vector>

void readData(std::vector<std::pair<float,float>>& vInputData);
void compressData(std::vector<std::pair<float, float>>&, std::vector<bool>&);
void executeKMeans(std::vector<std::pair<float, float>>&, std::vector<std::pair<float, float>>&);

int main ()
{
	std::vector<std::pair<float, float>> InputData;
	std::vector<bool>OutputBitStream;

	readData(InputData);
	compressData(InputData, OutputBitStream);

	return 0;
}

void initClusterCenter(std::vector<std::pair<float, float>>& vInputData, std::vector<std::pair<float, float>>& voClusterCenter)
{
	for (int i=0; i<8; i++)
	{
		voClusterCenter.push_back(vInputData[i]);
	}
}

void executeKMeans(std::vector<std::pair<float, float>>& vInputData, std::vector<std::pair<float, float>>& voClusterCenter)
{
	initClusterCenter(vInputData, voClusterCenter);
}
void compressData(std::vector<std::pair<float, float>>& vInputData, std::vector<bool>& vOutputBitStream)
{
	std::vector<std::pair<float, float>> ClusterCenter;
	executeKMeans(vInputData, ClusterCenter);
}
void readData(std::vector<std::pair<float, float>>& vInputData)
{
	FILE *fp = fopen("UniformData.txt", "r");
	_ASSERTE(fp);

	int NumData;
	fscanf(fp,"%d\n", &NumData);

	for (int i=0; i<NumData; i++)
	{
		float w, h;
		fscanf(fp, "%f %f\n", &w, &h);
		vInputData.push_back(std::make_pair(w, h));
	}
	fclose(fp);
}