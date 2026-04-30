#include <bits/stdc++.h>
using namespace std;

int solve(const int* arr, const int l, const int r)
{
    // Base Case
    if (l == r)
        return arr[l];

    const int mid = (l + r) / 2;
    const int left = solve(arr, l, mid);
    const int right = solve(arr, mid + 1, r);

    if (left != -1)
    {
        int count = 0;
        for (int i = l; i <= r; i++)
            if (arr[i] == left) count++;
        if (count > (r - l + 1) / 2.0) return left;
    }


    if (right != -1)
    {
        int count = 0;
        for (int i = l; i <= r; i++)
            if (arr[i] == right) count++;
        if (count > (r - l + 1) / 2.0) return right;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << (solve(arr, 0, n - 1) == -1 ? 0 : 1);
}