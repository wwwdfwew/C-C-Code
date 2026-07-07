#######################字典
###字典是存储键值对的数据结构
###键：key
###值：value
###作用是通过key可以找到value
# 字典中有很多键值对，在这里面，key不能够重复
# 字典中对key的类型有一些约束，而对value的类型没有约束

###字典的创建和初始化
##创建：
a={}#空字典
b=dict
##创建并初始化
c={
    "id":1,
    "name":"zhangsan"
}

#######################字典的查找
#######in:判断要查找的key是否在字典中存在, not in:判断要查找的key是否在字典中不存在

print("id" in c)
print("name" in c)
print(100 in c)

print("id" not in c)
print("name" not in c)
print(100 not in c)

############使用[]加key的方式查找，得到的是value

print(c["id"])
print(c["name"])


######################字典的增删改
###增加：[]加key=value
c["music"]="隔岸"
print(c)
###修改：[]加字典里要修改的key=想要修改的值
c["music"]="起风了"
print(c)
###删除：使用pop+key的方式删除
c.pop("music")
print(c)

# 可以发现，我们在对字典进行操作的时候，都是围绕着key进行操作的

####可哈希的条件：
# 字典中key不是随便取的，它的要求是必须可以哈希
# 在python中，hash这个函数可以用来计算变量的哈希值
# 一般来说，不可变的对象可以被哈希，可变的对象不能被哈希，因此，key的取值一般要取不可变的对象
print(hash(1))
print(hash(3.14))
print(hash("hello"))