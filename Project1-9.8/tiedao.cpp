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
        if (!it->empty()) {
            cout << "Stack " << stack_id << ":";
            // temp1 is an normal order, temp2 is the flashback order
            stack<int> temp1 = *it, temp2;
            while (!temp1.empty()) {
                temp2.push(temp1.top());
                temp1.pop();
            }
            while (!temp2.empty()) {
                cout << temp2.top() << " ";
                temp2.pop();
            }
            cout << endl;
        }
    }
    cout << "The correct train : ";
    for (auto i = correct.begin(); i != correct.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "_________________________________________________________" << endl;
}
void checkout(int* a, int n) {
    //temp is used for bucket sort
    int *temp = new int[n];
    double res;
    //initilize
    for (int i = 0; i < n; i++)
        temp[i] = 0;
    for (int i = 0; i < n; i++) {
        temp[a[i]]++;
        if (a[i] <= 0 || a[i] > n) {
            delete []temp;
            throw res;
        }
        if (temp[a[i]] > 1) {
            delete []temp;
            throw res;
        }
    }
    delete []temp;
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
    // check for whether the number is valid
    try {
        checkout(a, t);
    } catch (double) {
        cout << "the input data is invalid " << endl;
        cout << "Please restart the program " << endl;
        return;
    }
<<<<<<< HEAD
    if (flag1) continue;

    // judge whether it should open a new stack
    bool flag2 = false;
    for (auto it = all_stack.begin(); it != all_stack.end(); ++it) {
      if (it->empty() || a[head] < it->top()) {
        it->push(a[head]);
=======
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
        if (flag1)  {
            displayIt(all_stack, correct);
            continue;
        }
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
        
        if (flag2) {
            displayIt(all_stack, correct);
            continue;
        }
        
        stack<int> new_stack;
        new_stack.push(a[head]);
        all_stack.push_back(new_stack);
        
>>>>>>> a965ceebfa4b8f7c950c6cf7031f2f20ad1a9353
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
