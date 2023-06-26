### Riccardo Manoni 20-03-2023 -> Teorema Di Wilson per Numeri Primi <- ###

def Module(a, b):
	# print("a:"+str(a)+" b:"+str(b))
	if(a >= 0):
		while(a-b >= 0):
			a -= b
		return a
	else:
		while(a+b <= 0):
			a += b
		return a

#print(module(-7, 2))

def russianMultiply(a, b, p):
	# print("a:"+ str(a) + ",b:" + str(b) + " p=" + str(p))
	if(a >=1):
		if(Module(a, 2) != 0):
			p += b
		return russianMultiply(a>>1, b<<1, p)
	else:
		return p

# print("result: " + str(russianMultiply(2, 3, 0)))

def Multiply(a, b):
	return russianMultiply(a, b, 0)

def Factorial(a):
	result = 1
	for i in range(a, 1, -1):
		if(i == a): # al primo giro moltiplico i primi due numeri
			result = Multiply(i, i-1)
		else: # poi moltiplico il risultato ottenuto per i numeri fino al 2
			result = Multiply(result, i-1)
		print(result)
	return result

def Wilson(a):
	return True if(Module(Factorial(a-2), a) == 1) else False

print("primo:"+ str(Wilson(20)))





