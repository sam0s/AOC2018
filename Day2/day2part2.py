f=open("ID_LIST.txt","r")
text=f.read()
text=text.split("\n")
f.close()

theRightStuff=[]
diff = "none"

#compare all entries and find the 2 that have 1 char difference
for first in text:
    for second in text:
        a=0
        for i in range(len(first)):
            if(first[i]==second[i]):
                a+=1
        if(len(first)-a)==1:
            theRightStuff.append(first)

#find the different char
if len(theRightStuff)==2:
    for index in range(len(theRightStuff[0])):
        if theRightStuff[0][index] != theRightStuff[1][index]:
            diff=theRightStuff[0][:index]
            diff+=theRightStuff[0][index+1:]
else:
    print("ERROR")

print(diff)
input()
