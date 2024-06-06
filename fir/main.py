def counter(fname):
    num_words=0
    num_lines=0
    num_charc=0
    num_spaces=0
    with open(fname,'r') as f:
        for line in f :
            num_lines+=1
            word='Y'
            for letter in line:
                if(letter !='' & word =='Y'):
                    num_words+=1
                    word='N'
                elif(letter==''):
                    num_spaces+=1
                    word='Y'
                for i in letter:
                    if(i!='' & i!='\n'):
                        num_charc+=1
            print("number of words in the textfile:",num_words)
            print("number of lines in the textfile:",num_lines)
            print("number of characters in the textfile:",num_charc)
            print("number of spaces in the textfile:",num_spaces)
if __name__=='__main__':
    fname="rahul.txt"
    try:
        counter(fname)
    except:
        print("file not found")