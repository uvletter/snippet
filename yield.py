#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def reader():
    # 模拟从文件读取数据的生成器
    a = "init"
    while True:
	    a = yield a
	    print('yield',a)
	    if not a:
		    return True


def reader_wrapper(g):
    # 循环迭代从reader产生的数据 
    a = yield from g
    print(a)
    yield a
    return 'end'

wrap = reader_wrapper(reader())
print(wrap.send(None))
print(next(wrap))
print(wrap.send(0))
# print(wrap.send(0))

def zip(instr):
	n=1
	outstr =''
	current = instr[0]
	for c in instr:
		if c == current:
			n += 1
		else:
			outstr += current + str(n)
			current = c
			n = 1
	outstr += current + str(n)
	if len(instr) <= len(outstr):
		return instr
	return outstr

print(zip('abbbbbccccdddcccccc'))
