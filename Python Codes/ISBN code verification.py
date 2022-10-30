def isValidISBN(isbn):
	if len(isbn) != 10:
		return False
	
	sum = 0
	for i in range(9):
		sum += int(isbn[i]) * (10 - i)
	
	if(isbn[9] == 'X'):
		sum+=10
	else:
		sum+=int(isbn[9])*10
	
	return (sum % 11 == 0)

code = input("Enter the code to be verified: ")
if isValidISBN(code):
	print('Valid')
else:
	print("Invalid")