#include <iostream>
#include <vector>
#include "dataHelper.hpp"

int main() {
  dataHelper datahelper;

  auto readResult = datahelper.getSpotData();
  std::cout << "The info in the result" << std::endl;
  for (const auto& per : readResult) {
    std::cout << per << std::endl;
  }

  std::cout << "Test the split" << std::endl;
  auto res = datahelper.splitEachSoptInfo(readResult[0]);
  for (const auto& per : res) {
    std::cout << per << std::endl;
  }

  std::vector<std::string> new_info{
      "\"zhongxinhuatan\", \"5\", \"keyiyuehui\"",
      "\"sanfanxiaoguanchang\", \"3\", \"liveshow\""};

  datahelper.writeSpotData(new_info);
  return 0;
}
