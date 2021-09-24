import pyttsx3
#import PyPDF2

# book=open('Aditya.pdf','rb')
# pdfReader = PyPDF2.PdfFileReader(book)
# pages = pdfReader.numPages
# print(pages)
speaker = pyttsx3.init()
speaker.say('Delhi Police warns against gatherings as farmers observe black day')
speaker.runAndWait()
# for num in range(1, pages):
#     page = pdfReader.getPage(0)
#     text = page.extractText()
#     speaker.say(text)
#     speaker.runAndWait()





