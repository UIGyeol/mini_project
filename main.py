howmany=int(input("How many Mandu do you want to eat?"))

class mandu:
    def __init__(self,sum):
        self.sum=sum
    def get(self):
        print(f"You entered {self.sum}.")

sammy=mandu(howmany)
sammy.get()
