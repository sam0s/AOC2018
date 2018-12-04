f=open("ID_LIST.txt",'r')
text=f.read()
text=text.split('\n')
f.close()

set2=set3=0


for ln in text:
    #Create a list of duplicated chars per line
    dupe_list=[]
    for i in ln:
        if ln.count(i)>1:
            dupe_list.append(i)

    #Prvent multiple detection of dupes
    set2flag=False
    set3flag=False

    #Test for sets of 2 and 3 only once
    for i in dupe_list:
        if dupe_list.count(i) == 2 and not set2flag:
            set2+=1
            set2flag=True
        if dupe_list.count(i) == 3 and not set3flag:
            set3+=1
            set3flag=True

#Checksum
print(set2*set3)
input()
