#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void deleteTrain(int *a) { delete[] a; }

void displayIt(vector<stack<int> > &all_stack, vector<int> &correct) {
  int stack_id = 1;
  for (auto it = t.begin(); it != t.end(); it++) {
    cout << "Stack " << stack_id << ":";
    if (!it->empty()) {
      cout << it->top() << endl;
    } else {
      cout << "empty" << endl;
    }
    stack_id++;
  }
  cout << "The correct train : ";
  for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  cout << "_________________________________________________________" << endl;
}

void run() {
  int *a;
  int t;
  vector<int> end;
  cout << "The number of carriages : ";
  cin >> t;
  a = new int[t];
  cout << "The order : ";
  for (int i = 0; i < t; ++i) {
    cin >> a[i];
  }
  int head = 0;
  int tcount = 1;
  vector<stack<int> > tv;
  while (tcount <= t) {
    displayIt(tv, end);

    // ��ͷ������ͷ���Ƿ�Ӧֱ�ӽ�վ
    if (a[head] == tcount) {
      end.push_back(tcount);
      tcount++;
      head++;
      continue;
    }

    // ջ�����죩���Ƿ���Ӧ�ý�վ����ջ���ĳ���
    // wheather it can pop
    bool flag1 = false;
    for (auto it = tv.begin(); it != tv.end(); it++) {
      if (!it->empty()) {
        if (it->top() == tcount) {
          it->pop();
          end.push_back(tcount);
          tcount++;
          flag1 = true;
          break;
        }
      }
    }
    if (flag1) continue;

    // ��ͷ������ͷ��Ӧ���ĸ�ջ
    // �Ƿ����Ѵ��ڵ�ջ�ɽ�
    bool flag2 = false;
    for (auto it = tv.begin(); it != tv.end(); it++) {
      // if (!it->empty()) {
      if (a[head] < it->top() || it->empty()) {
        it->push(a[head]);
        head++;
        flag2 = true;
        break;
      }
      //		}
    }
    if (flag2) continue;
    // �Ƿ��п�ջ�ɽ�
    /*bool flag3 = false;
    for (auto it = tv.begin(); it != tv.end(); ++it) {
            if (it->empty()) {
                    it->push(a[head]);
                    head++;
                    flag3 = true;
            }
    }
    if(flag3)
            continue;*/

    // ������ջ~
    stack<int> tstack;
    tstack.push(a[head]);
    tv.push_back(tstack);
    head++;
    tv.size();
  }
  displayIt(tv, end);
  deleteTrain(a);
}

int main() {
  run();
  system("pause");
  return 0;
}
