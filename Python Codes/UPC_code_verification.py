def isValidUPS(ups):
    if(len(ups) != 12):
        return False
    ups = int(ups)
    sum = 0
    digit = 0
    num = ups
    for i in range(13):
        digit = num % 10
        if(i % 2 == 0):
            sum = sum+digit*1
        else:
            sum = sum+digit*3
        num = num//10
    if(sum % 10 == ups % 10):
        return True
    else:
        return False


code = input("Enter the code to be verified: ")
if isValidUPS(code):
    print('Valid')
else:
    print("Invalid")
