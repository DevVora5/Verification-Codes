def digitSum(num):
	digit=0
	sum=0
	num=num//10
	for i in range(10):
		digit=num%10
		num=num//10
		sum=sum+digit
	return sum;

def isValidUSPMO(uspmo):
	if(len(uspmo)!=11):
		return False
	uspmo=int(uspmo)
	if(digitSum(uspmo)%9==uspmo%10):
		return True
	else:	
		return False

def errorRectifier(num):
	num=int(num)
	print("Possible Valid Code can be (Only if the Last Digit is entered incorrectly):",(num//10)*10 +(digitSum(num)%9))

code=input("Enter a US Postal Money Order Code: ")
if isValidUSPMO(code):
	print("Valid")
else:
	print("Invalid ")
	errorRectifier(code);
	