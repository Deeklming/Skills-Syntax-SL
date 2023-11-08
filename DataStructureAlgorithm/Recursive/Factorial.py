def factorial(n):#재귀 팩토리얼
    if n>0:
        return n*factorial(n-1)
    else:
        return 1
stdin = int(input("input integer: "))
print(f"{stdin}!(factorial) is {factorial(stdin)}")