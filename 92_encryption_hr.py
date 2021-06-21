def encryption(s):
    #s = input()
    s = s.replace(" ", "")
    l = len(s)
    rootl = math.sqrt(l)
    col = row = int(rootl)
    if(l > col * row):
        col += 1
        if(l > col * row):
            row += 1    
    if(col > row):
        row += 1
        
    x = ""
    for i in range(col):
        output = s[i::row]
        x =  x + " " + output
    return x[1:]
