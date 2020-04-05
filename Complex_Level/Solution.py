import os
def morganAndString(a, b):
    i = 0
    j = 0
    val = ""
    a += "z"
    b += "z"    
    while ((i<len(a)) and (j <len(b))):
        if(a[i]<b[j]):
            val+=a[i]
            i+=1
        elif(a[i]==b[j]):
            if(a[i+1:]<b[j+1:]):
                val+=a[i]
                i+=1
            else:
                val += b[j]
                j+=1
        else:
            val+=b[j]
            j+=1
    while i<len(a):
        val += a[i]
        i+=1
    while j<len(b):
        val += b[j]
        j+=1
    return val[:-2]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        a = input()

        b = input()

        result = morganAndString(a, b)
                
        fptr.write(result + '\n')

    fptr.close()
