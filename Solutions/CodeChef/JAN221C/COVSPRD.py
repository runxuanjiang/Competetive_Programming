

nums = [1]
for i in range(10):
    nums.append(nums[-1] * 2)

while nums[-1] <= 1e8:
    nums.append(nums[-1]*3)

tests = int(input())
for i in range(tests):
    n, d = [int(x) for x in input().split(' ')]
    d = min(d, len(nums) - 1)
    print(min(nums[d], n))