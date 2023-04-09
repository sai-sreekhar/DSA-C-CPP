/*
    Author: Sai Sreekar
    Created: 2023/04/09 15:25:05
    Last Modified: 2023/04/09 20:57:24
*/

#include <bits/stdc++.h>

using namespace std;

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left;
    MinHeapNode *right;
    MinHeapNode(char data, int freq)
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

void printCodes(struct MinHeapNode *root, string str, unordered_map<char, string> &ump)
{
    if (!root)
    {
        return;
    }

    if (root->data != '$')
    {
        ump[root->data] = str;
        cout << root->data << ": " << str << "\n";
    }

    printCodes(root->left, str + "0", ump);
    printCodes(root->right, str + "1", ump);
}

void decode(MinHeapNode *root, string str, string ans)
{
    MinHeapNode *temp = root;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }

        if (temp->left == NULL && temp->right == NULL)
        {
            ans += temp->data;
            temp = root;
        }
    }
    cout << ans << endl;
}

void getHuffmannCodes(vector<char> arr, vector<int> freq, int n)
{
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(new MinHeapNode(arr[i], freq[i]));
    }

    while (pq.size() >= 2)
    {
        MinHeapNode *top1 = pq.top();
        pq.pop();
        MinHeapNode *top2 = pq.top();
        pq.pop();
        MinHeapNode *temp = new MinHeapNode('$', top1->freq + top2->freq);
        temp->left = top1;
        temp->right = top2;
        pq.push(temp);
    }

    unordered_map<char, string> ump;
    printCodes(pq.top(), "", ump);
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans += (freq[i] * ump[arr[i]].size());
    }
    int totalFreq = 0;
    for (auto i : freq)
    {
        totalFreq += i;
    }
    cout << "Total Bits: " << totalFreq << endl;
    cout << ((double(ans)) / totalFreq) << "\n";
    decode(pq.top(), "11101100", "");
    return;
}

void solve()
{
    int n = 5;
    vector<char> arr = {'P', 'Q', 'R', 'S', 'T'};
    vector<int> freq = {22, 34, 17, 19, 8};
    getHuffmannCodes(arr, freq, n);
}

int main()
{
    solve();
    return 0;
}