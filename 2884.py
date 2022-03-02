H, M = input().split()

H = int(H)
M = int(M)
# 문제 풀이
if M >= 45:
    print(H, M-45)
elif H > 0:
    print(H-1, 60-(45-M))
else:
    print(23, 60-(45-M))
