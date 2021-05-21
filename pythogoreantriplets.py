def solve(arr, n):

    for i in range(n):
        arr[i] = arr[i]**2
    
    arr.sort()

    for i in range(n-1, 1, -1):
        j = 0
        k = i-1
        while(j < k):
            if arr[j] + arr[k] == arr[i]:
                return True
            else:
                if arr[j] + arr[k] < arr[i]:
                    j += 1
                else:
                    k -= 1
    return False

arr = [10, 4, 6, 12, 5]
n = len(arr)
print(solve(arr, n))