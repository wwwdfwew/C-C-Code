############################################# 关闭文件
# flie=[]
# count=0
# while True:
#     f=open('E:\\python\\text.txt','r')
#     flie.append(f)
#     count+=1
#     print(count)
# ######python有一个垃圾处理机制，当创建的变量不使用时，python的垃圾处理机制就会自动释放这个变量

############################################写文件
# 写文件使用的都是write方法，每次以'w'写方式打开文件，都会先清理掉文件内的内容再进行写入新内容
f=open("test.txt","w")
f.write("hello world")
f.close()

f=open("test.txt","w")
f.write("23456")
f.close()

#以'a'写方式打开，是在文件内容末尾写入新内容，并不会清理掉原来的内容
f=open("test.txt","a")
f.write("hello world")
f.close()

f=open("test.txt","a")
f.write("2345")
f.close()
##########################################读文件
######读文件使用的是read方法，可以规定读取多少个字符的文件内容
f=open("test.txt","r")
ret=f.read(10)
print(ret)
f.close()
#######如果读取的是中文，就涉及到文件内容编码和代码编码匹配的问题，如果两者编码不匹配，则会报错
f=open("test.txt","w")
f.write("世界，你好")
f.close()
f=open("test.txt","r")
ret=f.read()
print(ret)
f.close()
######这里显然代码的编码和文件的编码是一种类型

########这里就会报错，所以上面为什么没有报错，是因为我们在python中进行写操作写入中文，编译器应该会自动适配，而在这里，是从文件中写进中文
# 内容，然后只让python读取，所以会出现这样的报错冲突
# f=open("E:\\python\\text.txt","r")
# ret=f.read()
# print(ret)
# f.close()

######为了解决这样的问题，我们就需要让两者的编码方式一致：这样就没有问题了
f=open("text.txt","r",encoding="utf-8")
ret=f.read()
print(ret)
f.close()

##########################################上下文管理器
# 上下文管理器是自动帮助我们关闭文件的
# 使用：
with open("text.txt","r",encoding="utf-8") as f:
    ret=f.read()
    print(ret)
#####它会在代码块出了上下文管理器作用域关闭该文件