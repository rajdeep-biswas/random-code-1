from wordcloud import WordCloud, STOPWORDS 
import matplotlib.pyplot as plt 
import pandas as pd 

def hastags_search(file_name):
    """ Check if any line in the file contains given string """
    # Open the file in read only mode
    with open(file_name, 'r') as read_obj:
        # Read all lines in the file one by one
        for line in read_obj:
            res =line.split()
            for i in res:
                result= i.startswith('#')
                if result is True:
                    print(i)
    return False


def WC(text):
	# Reads 'Youtube04-Eminem.csv' file 

	wordcloud = WordCloud(width = 900, height = 500, background_color ='#DCE1DE', min_font_size = 10).generate(text) 

	# plot the WordCloud image                   
	plt.figure(figsize = (9, 5), facecolor = None) 
	plt.imshow(wordcloud) 
	plt.axis("off") 
	plt.tight_layout(pad = 0) 

	plt.savefig("images/save")


def Freq_Counter(file_name,no):
    str1=[]
    str2=[]
    feq=[]
    """ Check if any line in the file contains given string """
    # # Open the file in read only mode
    with open(file_name, 'r') as read_obj:
        # Read all lines in the file one by one
        for line in read_obj:
            res =line.split()
            for i in res:
                #converting the string to list
                str1.append(i)
        #removing duplicacy from the list
        for i in str1:
            if i not in str2:
                str2.append(i)

        for i in range(0,len(str2)):
            feq.append([str2[i],str1.count(str2[i])])
            
        #print(feq[1])
        for i in range(0,len(feq)):
            if feq[i][1] >= no:
                print(feq[i][0])
    return False
    


def main(): 
    f_name='soham.txt'
    n= int(input("Enter the Frequency Rate "))
    st = ''
    with open('soham.txt', 'r') as text:
        for line in text:
            st += line + '. '

    WC(st)

    Freq_Counter(f_name,n)
    hastags_search(f_name)

main()
