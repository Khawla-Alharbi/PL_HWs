

def cardType(n):
    s="Visa"
    if n[0]=="5":
        s="MasterCard"
    return s;
def checkSum(card):
    chksum=0
    f=0
    for x in card:
        if f==0:
            temp= (ord(x)-48)*2
            if temp>9:
                a = str(temp)[0]
                b = str (temp)[1]
                temp= (ord(a)-48) + (ord(b)-48)
            chksum+=temp
            f=1
        else:
             chksum+= (ord(x)-48)
             f=0
       
    
    return chksum;

print("#", "  Credit Card #", "     Type", "      Checksum", " Valid?",'\n')
i=1


file= open('credit.txt','r')
lines= file.readlines()



for index in lines:
        
        ty= cardType(index.strip())
        c= checkSum(index.strip())
        valid= "NO"
        if(c%10 == 0):
            valid="YES"
        if(ty=="Visa"):
                print(i,index.strip(),"   ",ty,"      ",c,"      ",valid,'\n')  
        else: 
             print(i,index.strip(),"   ",ty,c,"      ",valid,'\n')
        i=i+1
        


   
