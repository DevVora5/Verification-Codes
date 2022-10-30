def digitSum(num):
	sum=0
	digit=0
	for i in range(16):
		digit=num%10
		num=num//10
		if(i%2==0):
			sum=sum+digit
		else:
			if((digit*2)>8):
				sum+=(digit*2)%10+(digit*2)//10
			else:
				sum+=(digit*2)
	return sum

def checkCard(CardNo):
	if(len(CardNo)!=16):
		print(2)
		return False
	CardNo=int(CardNo)
	if(digitSum(CardNo)%10==0):
		return True
	else:
		print(digitSum(CardNo))
		return False
	
code=input("Enter Credit Card Code: ")
if (checkCard(code)):
	print("This is a Valid Card.")
else:
	print("This is an Invalid Card.")

