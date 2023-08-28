#include <bits/stdc++.h> 
class NStack {
public:
    int *arr;
    int *next;
    int *top;
    int freespot;
    // Constructor - Inalize your Stack
    NStack(int N, int S) {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        for(int i=0; i<N; i++) top[i] = -1; // Top Initilize
        for(int i=0; i<S; i++) next[i] = i+1; // Next Initilize
        next[S-1] = -1; // Update last index to -1.
        freespot = 0;
    }  
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        // Check for overflow.
        if(freespot == -1) return false;
        int index = freespot; // Step 1 - Find Index
        freespot = next[index]; // Step 2 - Update freespot
        arr[index] = x; // Step 3 - Insert element into array
        next[index] = top[m-1]; // Step 4 - Update next
        top[m-1] = index; // Step 5 - Update Top
        return true;
    }
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        // Check for Underflow.
        if(top[m-1] == -1) return -1;
        int index = top[m-1]; // Step 1 - Find Index
        top[m-1] = next[index]; // Step 2 - Update Top
        next[index] = freespot; // Step 3 - Update next
        freespot = index; // Step 4 - Update freespot
        return arr[index];
    }
};


/*



#include <bits/stdc++.h>
using namespace std;

class NStack
{
public:
    vector<int> arr;
    vector<int> top;
    vector<int> next;
    int free;

    NStack(int N, int S)
    {
        arr.resize(N, 0);
        next.resize(N, -1);
        top.resize(S, -1);
        for (int i = 0; i < N - 1; i++)
        {
            next[i] = i + 1;
        }
        next[N - 1] = -1;
        free = 0;
    }

    bool push(int x, int m)
    {
        if (free == -1)
        {
            return false;
        }
        int i = free;
        free = next[i];
        next[i] = top[m - 1];
        top[m - 1] = i;
        arr[i] = x;
        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;
        int i = top[m - 1];
        top[m - 1] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
};

int main()
{
    NStack nStack(10, 3);

    nStack.push(1, 1);
    nStack.push(2, 2);
    nStack.push(3, 3);

    cout << nStack.pop(1) << endl;
    cout << nStack.pop(2) << endl;
    cout << nStack.pop(3) << endl;

    return 0;
}

*/