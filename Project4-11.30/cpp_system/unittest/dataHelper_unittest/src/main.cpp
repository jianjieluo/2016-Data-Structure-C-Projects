#include <iostream>
#include <vector>
#include "dataHelper.hpp"

int main() {
  std::string temp;
  std::cin >> temp;
  dataHelper datahelper(temp);

  auto readResult = datahelper.getSpotData();
  std::cout << "The info in the result" << std::endl;
  for (const auto& per : readResult) {
    std::cout << per << std::endl;
  }

  std::cout << "Test the split" << std::endl;
  for (unsigned int i = 0; i < readResult.size(); ++i) {
    auto res = datahelper.splitEachSoptInfo(readResult[i]);
    for (const auto& per : res) {
      std::cout << per << std::endl;
    }
  }

  // std::vector<std::string> new_info{
  //     "\"zhongxinhuatan\", \"5\", \"keyiyuehui\"",
  //     "\"sanfanxiaoguanchang\", \"3\", \"liveshow\""};
  //
  // datahelper.writeSpotData(new_info);
  return 0;
}
