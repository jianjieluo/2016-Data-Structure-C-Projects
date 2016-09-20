#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Display the current state about the stacks usage and the current output
 * carriages
 * @param all_stack the stacks have been used
 * @param correct the current output carriges num
 */
void displayIt(vector<stack<int> > &all_stack, vector<int> &correct) {
  int stack_id = 1;
  for (auto it = all_stack.begin(); it != all_stack.end(); ++it, ++stack_id) {
    cout << "Stack " << stack_id << ":";
    if (!it->empty()) {
      cout << it->top() << endl;
    } else {
      cout << "empty" << endl;
    }
  }
  cout << "The correct train : ";
  for (auto i = correct.begin(); i != correct.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  cout << "_________________________________________________________" << endl;
}

void run() {
  // initialize
  // t is the carriages total numbers
  int t;
  vector<int> correct;
  cout << "The number of carriages : ";
  cin >> t;
  int *a;
  a = new int[t];
  cout << "The order : ";
  for (int i = 0; i < t; ++i) {
    cin >> a[i];
  }

  // head is the carriages index is going to be dealt with.
  int head = 0;
  int should_out = 1;

  vector<stack<int> > all_stack;
  while (should_out <= t) {
    displayIt(all_stack, correct);

    // if the head didn't need to push into a stack
    if (a[head] == should_out) {
      correct.push_back(should_out);
      should_out++;
      head++;
      continue;
    }

    // judge whether the tops of each stacks can be pop
    bool flag1 = false;
    for (auto it = all_stack.begin(); it != all_stack.end(); ++it) {
      if (!it->empty()) {
        if (it->top() == should_out) {
          it->pop();
          correct.push_back(should_out);
          should_out++;
          flag1 = true;
          break;
        }
      }
    }
    if (flag1) continue;

    // judge whether it should open a new stack
    bool flag2 = false;
    for (auto it = all_stack.begin(); it != all_stack.end(); ++it) {
      if (a[head] < it->top() || it->empty()) {
        it->push(a[head]);
        head++;
        flag2 = true;
        break;
      }
    }
    if (flag2) continue;

    stack<int> new_stack;
    new_stack.push(a[head]);
    all_stack.push_back(new_stack);

    head++;
    all_stack.size();
  }
  displayIt(all_stack, correct);
  delete[] a;
}

int main() {
  run();
  return 0;
}
