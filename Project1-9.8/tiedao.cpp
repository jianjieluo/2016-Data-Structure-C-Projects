#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int>& getNewStack(vector<stack<int> > &t) {
	stack<int> ts;
	t.push_back(ts);
	auto it = t.end();
	it--;
	return *it;
}

void deleteTrain(int *a) {
	delete[] a;
}

void displayIt(vector<stack<int> > &t, vector<int> &v, int No_) {
	int tm = 1;
	for (auto it = t.begin(); it != t.end(); it++) {
		cout << "Stack " << tm << ":" ;
		if (!it->empty()) {
			cout << it->top() << endl;
		} else {
			cout << "empty" << endl;
		}
		tm ++;
	}
	cout << "The correct train : ";
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
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
	for (int i = 0; i < t; ++i)
	{
		cin >> a[i];
	}
	int count = 0;
	int tcount = 1;
	vector<stack<int> > tv;
	while (tcount <= t) {
		displayIt(tv, end, t);
		if (a[count] == tcount) {
			end.push_back(tcount);
			tcount ++;
			count++;
			continue;
		}
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
		if (flag1)
			continue;
		bool flag2 = false;
		for (auto it = tv.begin(); it != tv.end(); it++) {
			if (!it->empty()) {
				if (a[count] < it->top()) {
							it->push(a[count]);
							count++;
							flag2 = true;
							break;
						}
					}
		}
		if (flag2)
			continue;
		bool flag3 = false;
		for (auto it = tv.begin(); it != tv.end(); ++it) {
			if (it->empty()) {
				it->push(a[count]);
				count++;
				flag3 = true;
			}
		}
		if(flag3)
			continue;
		stack<int> tstack;
		tstack.push(a[count]);
		tv.push_back(tstack);
		count++;
		tv.size();
	}
	displayIt(tv, end, t);
	deleteTrain(a);
}

int main() {
	run();
	return 0;
}
