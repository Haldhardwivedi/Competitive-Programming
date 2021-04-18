from decimal import Decimal 

def gcd(a,b): 
	if b==0: 
		return a 
	else: 
		return gcd(b,a%b) 
p = int(input('Enter the value of p ')) 
q = int(input('Enter the value of q ')) 
n = p*q 
t = (p-1)*(q-1) 

for e in range(2,t): 
	if gcd(e,t)== 1: 
		break


for i in range(1,10): 
	x = 1 + i*t 
	if x % e == 0: 
		d = int(x/e) 
		break

print("public key ",e,n)
print("private key ",d,n)

msg=input ("enter your message ")

ctt=[]
for i in msg:
	x=ord(i)
	x=pow(x,e)
	x=x%n
	ctt.append(x)
dtt=[]
for i in ctt :
	x=pow(i,d)
	x=x%n
	dtt.append(x)
print("encrypted message is ",ctt)
nmsg=[]
for i in dtt:
	nmsg.append((chr(i)))
print(nmsg)