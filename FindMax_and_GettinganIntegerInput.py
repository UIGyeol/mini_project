def max(a,b,c):
    maximum=a
    if b>maximum:maximum=b
    if c>maximum:maximum=c
    return maximum
    
print(f"max(3,2,1)={max(3,2,1)}")
print(f"max(1,2,3)={max(1,2,3)}")
print(f"max(2,3,1)={max(2,3,1)}")

n= int (input("정수를 입력하세요"))
if n>0:
    print("이 수는 양수입니다.")

elif n<0:
    print("이 수는 음수입니다.")
else:
    print("이 수는 0입니다.")
