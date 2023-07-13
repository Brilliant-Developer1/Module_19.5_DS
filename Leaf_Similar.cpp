// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);

    queue<Node *> que;
    if (root)
        que.push(root);
    while (!que.empty())
    {
        // 1. ber kore ana
        Node *f = que.front();
        que.pop();

        // 2. kaaj
        int L, R;
        cin >> L >> R;
        Node *left;
        Node *right;

        if (L == -1)
            left = NULL;
        else
            left = new Node(L);

        if (R == -1)
            right = NULL;
        else
            right = new Node(R);

        f->left = left;
        f->right = right;

        // 3. children pusk kora
        if (f->left)
            que.push(f->left);
        if (f->right)
            que.push(f->right);
    }

    return root;
}

void count_leaf(Node *root, vector<int> &result1)
{

    if (root == NULL)
    {
        return;
    }
    // Leaf node kina check

    if (root->left == NULL && root->right == NULL)
    {
        result1.push_back(root->value);
    }

    // cout << root->value << " "; leaf node bade baki gola
    count_leaf(root->left, result1);
    count_leaf(root->right, result1);
}
int main()
{
    Node *root1 = input_tree();
    Node *root2 = input_tree();

    vector<int> result1;
    vector<int> result2;
    count_leaf(root1, result1);
    count_leaf(root2, result2);
    if (result1 == result2)
        cout << "True";
    else
        cout << "False";
    // cout << count_leaf(root) << endl;
    // for (int i = 0; i < result2.size(); i++)
    // {
    //     cout << result2[i] << " ";
    // }

    return 0;
}

/*
input1
3 5 1 6 2 9 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
input2
3 5 1 6 7 4 2 -1 -1 -1 -1 -1 -1 9 8 -1 -1 -1 -1

input3 1 2 3 -1 -1 -1 -1
input4 1 3 2 -1 -1 -1 -1
output 1&2
True

output 3&4 = False
*/