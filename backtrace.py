# -*- coding: utf8 -*-

class flag(object):
	def __init__(self, len):
		self.flags = [False] * len

class container(object):
	"""docstring for container"""
	def __init__(self, input, goal):
		super(container, self).__init__()
		self.input = input
		self.goal = goal
		self.stack = []
		self.result = []
		self.counter=0
		self.i = 0;

	def _loopTraceback(self):
		pass
			
		
	def _traceback(self, level):
		self.i+=1;
		if level == len(self.input):
			return

		self._traceback(level + 1)

		self.stack.append(self.input[level])
		if sum(self.stack) == self.goal:
			self._output()
		elif sum(self.stack) < self.goal:
			self._traceback(level + 1)
		self.stack.pop()

	def _output(self):
		self.counter += 1
		print('第{}个满足条件的组合: '.format(self.counter))
		print(self.stack)

	def _dp(self, num, target):
		self.i+=1;
		if not target:
			self._output()
		elif target < 0:
			return
		elif num == len(self.input):
			return;
		else:
			self.stack.append(self.input[num])
			self._dp(num + 1, target - self.input[num])
			self.stack.pop()
			self._dp(num + 1, target)


	def start(self):
		self._traceback(0)
		self._dp(0, self.goal)
		print(self.i)

s = container([1,3,2,1,2,4,2,7,5,6,3,4,8,11,3,15,2,13,14,9,9,7,11,10],15)
s.start()

