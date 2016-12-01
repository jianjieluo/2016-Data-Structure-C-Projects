#ifndef DATAHELPER_HPP_
#define DATAHELPER_HPP_

#include <fstream>
#include <string>
#include <vector>

class dataHelper {
 public:
  dataHelper() = default;
  ~dataHelper() {}
  std::vector<std::string> getSpotData();
  bool writeSpotData(const std::vector<std::string> t_info);
  std::vector<std::string> splitEachSoptInfo(std::string t_spotInfo);

 private:
  const std::string m_data_path = "./data/data.csv";
};

#endif
