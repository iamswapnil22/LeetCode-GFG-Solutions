```
class Solution{   
public:
    void reverse(int arr[], int start, int end)
    {
      while (start <= end)
      {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
      }
    }
    void leftRotate(int arr[], int n, int k) {
          reverse(arr, 0, k - 1);
          // Reverse last n-k elements
          reverse(arr, k, n - 1);
          // Reverse whole array
          reverse(arr, 0, n - 1);
    }
};
```
