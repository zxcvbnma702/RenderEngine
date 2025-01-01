#include "Al_pipeline.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

Algernon::ALpipeline::ALpipeline(std::string filePrefix) :
	filePrefix_(filePrefix)
{
	createGraphicsPipeline();
}

std::vector<char> Algernon::ALpipeline::readFile(const std::string& fileName)
{
	std::ifstream file(fileName, std::ios::ate | std::ios::binary);

	if (!file.is_open()) {
		throw std::runtime_error("failed to open file!" + fileName);
	}

	auto fileSize = file.tellg();
	std::vector<char> buffer(fileSize);

	file.seekg(0);
	file.read(buffer.data(), fileSize);

	file.close();

	return buffer;
}

void Algernon::ALpipeline::createGraphicsPipeline() const
{
	auto vertCode = readFile(filePrefix_ + ".vert.spv");
	auto fragCode = readFile(filePrefix_ + ".frag.spv");

	std::cout << "vertShaderCode size: " << vertCode.size() << '\n';
	std::cout << "fragShaderCode size: " << fragCode.size() << '\n';
}