#include <bits/stdc++.h>
using namespace std;

#define ARRAYSIZE(a) (sizeof(a)) / (sizeof(a[0]))
static int total_nodes;
bool filled = false;
void printSubset(int A[], int size, int weights[], int s_size)
{
    if (!filled)
    {
        filled = true;
        for (int i = 0; i < s_size; i++)
        {
            bool f = 0;
            for (int j = 0; j < size; j++)
            {
                if (weights[i] == A[j])
                {
                    cout << 1 << " ";
                    f = 1;
                    break;
                }
            }
            if (!f)
                cout << 0 << " ";
        }
        cout << "\n";
    }
}

int comparator(const void *pLhs, const void *pRhs)
{
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return *lhs > *rhs;
}

void subset_sum(int s[], int t[],
                int s_size, int t_size,
                int sum, int ite,
                int const target_sum)
{
    total_nodes++;

    if (target_sum == sum)
    {
        printSubset(t, t_size, s, s_size);

        if (ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum)
        {
            subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        }
        return;
    }
    else
    {
        if (ite < s_size && sum + s[ite] <= target_sum)
        {
            for (int i = ite; i < s_size; i++)
            {
                t[t_size] = s[i];
                if (sum + s[i] <= target_sum)
                {
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}

void generateSubsets(int s[], int size, int target_sum)
{
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    int total = 0;

    qsort(s, size, sizeof(int), &comparator);
    for (int i = 0; i < size; i++)
    {
        total += s[i];
    }
    if (s[0] <= target_sum && total >= target_sum)
    {
        subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    }
    free(tuplet_vector);
}

int main()
{
    int weights[] = {3,4,5,6};
    int target = 13;
    int size = ARRAYSIZE(weights);
    generateSubsets(weights, size, target);
    // cout << "Nodes generated " << total_nodes;
    return 0;
}
