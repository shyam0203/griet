//new version 1
#include <stdio.h>
#include <stdc++.h>
// int maxSubArray(const int *A, int n1)
// {
//     int i = 0, j = 0, sum = 0, max_sum = -99999;
//     for (i = 0; i < n1; i++)
//     {
//         sum = sum + A[i];
//         if (sum > max_sum)
//         {
//             max_sum = sum;
//         }
//         if (sum < 0)
//         {
//             sum = 0;
//         }
//     }
//     return max_sum;
// }

//approach2
// int maxSubArray(const int *A, int n1)
// {
//     int s[n1];
//     s[0] = A[0];

//     int i, max = A[0];
//     for (i = 1; i < n1; i++)
//     {
//         if (s[i - 1] < 0)
//         {
//             s[i] = A[i];
//         }
//         else
//         {
//             s[i] = A[i] + s[i - 1];
//         }
//         if (max < s[i])
//         {
//             max = s[i];
//         }
//     }
//     return max;
// }

//approach3
int maxSubArray(const int *A, int n1)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    int i;
    for (i = 0; i < n1; i++)
    {
        max_ending_here = max_ending_here + A[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

// int maxSubArraySum(int a[], int size)
// {
//     int max_so_far = INT_MIN, max_ending_here = 0,
//         start = 0, end = 0, s = 0;

//     for (int i = 0; i < size; i++)
//     {
//         max_ending_here += a[i];

//         if (max_so_far < max_ending_here)
//         {
//             max_so_far = max_ending_here;
//             start = s;
//             end = i;
//         }

//         if (max_ending_here < 0)
//         {
//             max_ending_here = 0;
//             s = i + 1;
//         }
//     }
//     cout << "Maximum contiguous sum is "
//          << max_so_far << endl;
//     cout << "Starting index " << start
//          << endl
//          << "Ending index " << end << endl;
// }

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArray(a, n);
    printf("Maximum contiguous sum is %d", max_sum);
    return 0;
}