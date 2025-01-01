#pragma once

#include<string>
#include<vector>

namespace Algernon {
	class ALpipeline {
	public:
		ALpipeline(std::string filePrefix);

	private:
		static std::vector<char> readFile(const std::string& fileName);

		void createGraphicsPipeline() const;

	private:
		std::string filePrefix_;
	};
}