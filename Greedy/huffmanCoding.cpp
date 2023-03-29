#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root, string str, unordered_map<char, string> &huffmanCodes)
{
    if (!root)
        return;

    if (root->data != '$')
    {
        cout << root->data << ": " << str << "\n";
        huffmanCodes[root->data] = str;
    }

    printCodes(root->left, str + "0", huffmanCodes);
    printCodes(root->right, str + "1", huffmanCodes);
}

void decode(MinHeapNode *root, string str, string ans)
{
    MinHeapNode *currNode = root;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == '1')
        {
            currNode = currNode->right;
        }
        else if (c == '0')
        {
            currNode = currNode->left;
        }

        if (currNode->left == NULL && currNode->right == NULL)
        {
            ans += (currNode->data);
            currNode = root;
        }
    }
    cout << ans << endl;
}

void HuffmanCodes(vector<char> data, vector<int> freq, int size)
{

    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
    {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    unordered_map<char,string> huffmanCodes;
    printCodes(minHeap.top(), "",huffmanCodes);
    int ans = 0;
    // debug(huffmanCodes);
    // for(int i = 0; i < data.size(); i++)
    // {
    //     ans += (freq[i] * huffmanCodes[data[i]].size());
    // }
    // decode(minHeap.top(), "110111100111010", "");
}

int main()
{
    vector<char> arr = {'s', 'y', 'e', 'd'};
    vector<int> freq = {1, 1, 1, 1};
    int size = arr.size();

    HuffmanCodes(arr, freq, size);

    return 0;
}
