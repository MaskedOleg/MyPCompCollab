import re

textFiles = ['Item005.doc', 'Item001.doc', 'Item007.doc', 
'File148.exl', 'File147.exl', 'txt30.os', 'txt25.os', 'txt27.os']

textFiles.sort()

fillRegex = re.compile(r'(.*?)(\d{1,})(.*)')
# Matches:
# (.*?) all string that are not digits
# (\d{1,}) matches onsecutive string of digits that are at length 1 or more
# (.*?) mall strings after the digit
counter = 0

for items in textFiles:
    found = fillRegex.search(items).groups()
    if counter is 0:
        hold = found[0] # string 1
        pos = int(found[1]) # number
        ext = found[2]  # extension
        counter = counter + 1
    else:
        newhold = found[0] # string 1
        newpos = int(found[1]) # number
        newext = found[2]  # extension
        if hold == found[0]:
            while newpos != pos + 1:
                newpos = newpos - 1
            counter = 0
            textFiles.remove(items)
        else:
            continue

#print(found[0])
