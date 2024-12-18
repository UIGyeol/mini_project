from datetime import datetime
i = 5
login = 0
def CheckPassword(n):
    key = "Mandu"
    global login  
    if n == key:
        login = 1
        return True
    else:
        print("wrong!")
        return False
    
def luckycharm():
    today = datetime.today().strftime("%Y%m%d")
    digit_sum = sum(int(digit) for digit in today)
    if digit_sum%2==0 or digit_sum%7==0:
        print("Today's fortune is up to you.")
    elif digit_sum%2!=0 and digit_sum%3==0:
        print("You can show yourself to others beyond your abilities.")
    elif digit_sum%2==0 and digit_sum%3==0:
        print("The person you helped in the past helps you today.")
    elif digit_sum%5==0:
        print("A good opportunity comes.")
    else:
        print("... \n")
        print("... \n")
        print("... Don't go outside today.\n")




while i > 0:
    ans = input("Enter the password >> ")
    if CheckPassword(ans):  
        break
    i -= 1 
    if i == 0:
        print("No chance left.")
    else:
        print(f"{i} chance(s) left.")

if login == 1: 
    print("Welcome!\n")
    name = input("Please enter your name: ")  
    print(f"Hello, {name}.")
    print(f"\n{name} This note is for you. Check it.")
    print("...\n")
    luckycharm()
    



