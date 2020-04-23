import re

textFiles = ['Item005.doc', 'Item001.doc', 'Item007.doc', 
'File150.exl', 'File147.exl', 'txt030.os', 'txt025.os', 'txt027.os']

textFiles.sort()

fillRegex = re.compile(r'(.*?)(\d{1,})(.*)')
# Matches:
# (.*?) all string that are not digits
# (\d{1,}) matches onsecutive string of digits that are at length 1 or more
# (.*?) mall strings after the digit
start = 0

for items in textFiles:
    found = fillRegex.search(items).groups()
    if start is 0:
        hold = found[0] # string 1
        pos = int(found[1]) # number
        ext = found[2]  # extension
        start = 1
    else:
        newhold = found[0] # string 1
        newpos = int(found[1]) # number
        newext = found[2]  # extension
        if hold == found[0]:
            while newpos != pos + 1:
                newpos = newpos - 1
            pos = pos + 1
            textFiles.remove(items)
            newName = newhold + str(newpos).zfill(3) + newext
            textFiles.append(newName)
            textFiles.sort()
        else:
            hold = found[0] # string 1
            pos = int(found[1]) # number
            ext = found[2]  # extension
for items in textFiles:
    print(items)
