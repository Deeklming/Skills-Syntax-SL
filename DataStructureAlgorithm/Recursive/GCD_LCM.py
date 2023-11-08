def gcd(a, b):#유클리드 호제법(Euclidean method of mutual division)
    if b==0:
        return a
    else:
        return gcd(b, a%b)
def lcm(a, b):#최소공배수 활용
    return int(abs(a*b) / gcd(a, b))

x, y = 7, 5
print(f"({x}, {y}) Greatest Common Divisor {gcd(x ,y)}")
print(f"({x}, {y}) Least Common Multiple {lcm(x, y)}")