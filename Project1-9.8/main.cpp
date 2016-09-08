#include <iostream>
#include <queue>
#include <sstream>
#include <stack>

int main(int argc, char const *argv[]) {
  // construct the orignal car information
  std::queue<int> original_line;
  bool judge = true;
  while (judge) {
    std::cout << "Please input the car number and end with -1" << std::endl;
    int car_num;
    std::cin >> car_num;
    if (car_num == -1) {
      judge = false;
    }
    if (judge) original_line.push(car_num);
  }
  int max_length = original_line.size() + 1;

  // begin to sort the car.
  std::stack<int> s1, s2;
  while (!original_line.empty()) {
    // get the car which is ready to go into stack
    int current = original_line.front();
    original_line.pop();

    // top1 is the current s1's top element, top2 is the current s2's top
    // element
    int top1, top2;
    auto updateTop = [&top1, &top2, &s1, &s2, &max_length]() {
      if (s1.empty()) {
        top1 = -1;
      } else {
        top1 = s1.top();
      }
      if (s2.empty()) {
        top2 = max_length;
      } else {
        top2 = s2.top();
      }
    };

    // while top1 < current  < top2, then push the current  to the stack1,
    // otherwise deal with these stacks
    updateTop();
    while (!(top1 < current && current < top2)) {
      if (current < top1) {
        s2.push(s1.top());
        s1.pop();
      } else if (current > top2) {
        s1.push(s2.top());
        s2.pop();
      }
      updateTop();
    }
    s1.push(current);
  }

  while (!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }

  while (!s2.empty()) {
    std::cout << s2.top() << std::endl;
    s2.pop();
  }

  return 0;
}
