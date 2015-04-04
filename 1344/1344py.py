#!/usr/bin python

if __name__=='__main__':
    n=input()
    temp=0
    Min=0
    for i in range(0,int(n)):
        temp+=int(input())
        if Min>temp:
            Min=temp
    if Min>0:
        print(Min)
    else:
        print(-Min)
