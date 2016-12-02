#include "dataHelper.hpp"
#include <iostream>
#include <sstream>

std::vector<std::string> dataHelper::getData() {
  std::ifstream input;
  std::cout << "Begin to get the data from " << m_data_path << std::endl;
  input.open(m_data_path);
  if (!input) {
    std::cout << "Can't read the file" << std::endl;
    exit(1);
  }

  std::string buffer;
  std::vector<std::string> read_result;
  while (getline(input, buffer)) {
    read_result.push_back(buffer);
  }
  input.close();
  return read_result;
}

bool dataHelper::writeData(const std::vector<std::string> t_info) {
  std::ofstream output(m_data_path);
  if (!output) {
    std::cout << "Open the data file while writing back failed" << std::endl;
    exit(1);
  }

  try {
    for (const auto& perRecord : t_info) {
      output << perRecord << std::endl;
    }
  } catch (...) {
    std::cout << "writing error" << std::endl;
    return false;
  }
  output.close();
  std::cout << "Write back the data successfully" << std::endl;
  return true;
}

std::vector<std::string> dataHelper::splitEachInfo(std::string t_spotInfo) {
  std::istringstream ss(t_spotInfo);
  std::string buffer;
  std::vector<std::string> res;

  while (std::getline(ss, buffer, ',')) {
    res.push_back(buffer);
  }

  return res;
}
