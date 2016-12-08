#ifndef DATAHELPER_HPP_
#define DATAHELPER_HPP_

#include <fstream>
#include <string>
#include <vector>

class dataHelper {
 public:
  dataHelper() : m_data_path("./data/data.csv") {}
  dataHelper(const std::string t_data_path) : m_data_path(t_data_path) {}
  ~dataHelper() {}
  /**
   * get the data from the data.csv file
   * return a vector with each spot info in a line
   */
  std::vector<std::string> getData();
  /**
   *好像并不需要写回，尴尬=_=
   */
  bool writeData(const std::vector<std::string> t_info);
  /**
   * 把每一行信息的逗号给分开，把子信息分别存进返回的vector里面
   */
  std::vector<std::string> splitEachInfo(std::string t_spotInfo);

 private:
  const std::string m_data_path;
};

#endif
