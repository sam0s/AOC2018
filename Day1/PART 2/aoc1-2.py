
sum = 0

prev=[]

reached=False



while not reached:
    f = open('input.txt', 'r')
    for ln in f:
        ln = ln.strip()
        if ln:
            sum = sum+int(ln)
            if sum in prev:
                reached = True
                print("REACHED FIRST DUPE: "+str(sum))
                break
            prev.append(sum)
    f.close()

input()
