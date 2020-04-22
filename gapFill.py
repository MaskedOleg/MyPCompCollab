import re

textFiles = ['Item005', 'Item001', 'Item007', 
'File148', 'File147', 'txt30.os', 'txt25.os', 'txt27.os']

textFiles.sort()

fillRegex = re.compile(r'(.*?)(\d{1,})(.*)')
found = fillRegex.search('batman0077.txt').groups()

print(found)