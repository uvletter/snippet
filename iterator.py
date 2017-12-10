def triangles():
	a = [1]
	yield a
	while True:
		b = [1]
		for i in range(1, len(a)):
			b.append(a[i-1] + a[i])
		b.append(1)

		a = b
		yield a

n=0
for t in triangles():
    print(t)
    n = n + 1
    if n == 10:
        break

g = (x * x for x in range(1, 11))
for x in g:
	print(x)

def iterate():
	i = 2
	while True:
		yield i
		i+=1

def _not_divisible(n):
	return lambda x:x%n>0

def primes():
	prime = 2
	seq = iterate()
	while True:
		yield prime
		seq = filter(_not_divisible(prime), seq)
		prime = next(seq)

for i in primes():
	if i > 1000:
		print()
		break
	print(i, end = " ")

class MyClass(object):
	"""docstring for MyClass"""
	@property
	def something(self):
		return self.__something

	@something.setter
	def something(self, something):
		self.__something = something
		
obj = MyClass()
obj.something = "something" 
print(obj.something)

class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b # 计算下一个值
        if self.a > 100000: # 退出循环的条件
            raise StopIteration()
        return self.a # 返回下一个值

for n in Fib():
    print(n,end = " ")

