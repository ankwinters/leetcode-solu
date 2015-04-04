#!/usr/bin python
def read():
    A=[]
    for line in open("./1344data",'r'):
        A.append(int(line))
    return A[0],A[1:]


if __name__=='__main__':
    A,B=read()
    Min=0
    temp=0
    Sum=0
    for i in B:
        temp+=i
        if Min>temp:
            Min=temp
        Sum=temp
    temp=-Min
    for i in B:
        temp+=i
        if temp<0:
            print(i)
            print(temp)
            break
    else:
        print(temp)
        
