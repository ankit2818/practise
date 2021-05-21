# def solve(arr, n):
#     ans = 0
#     for i in range(n):
#         for j in range(i+1, n):
#             if arr[i] == arr[j]:
#                 ans += 1
#     return ans

def solve(arr, n):
    mp = dict()
    for i in range(n):
        if arr[i] in mp:
            mp[arr[i]] += 1
        else:
            mp[arr[i]] = 1
    ans = 0
    for i in mp:
        count = mp[i]
        ans += (count * (count-1) // 2)
    return ans



arr = [1,1,1,1]
n = len(arr)
print(solve(arr, n))