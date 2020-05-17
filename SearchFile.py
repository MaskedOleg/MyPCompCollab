#! python3
# fileSearcher.py - Searches for file by supplied string
# might add to return absolute path of file/s

import re, os

os.chdir('C:\\Users\\Angelo Michael\\Downloads\\')
filenames = input('Enter the filename or a part of the filename: ')
searchThis = '(.*?)(' + filenames.lower() + ')(.*?)'
fileSearch = re.compile(searchThis)

matched = []
num = 1
for mainfolders, subfolders, files in os.walk(os.getcwd()):
    for items in files:
            try:
                found = fileSearch.search(items.lower()).group()
                matched.append(items)
            except AttributeError:
                #num = num + 1
                #print(num)
                continue
            
if len(matched) > 0:
    print('This are the files that contains that string:')
    for items in matched:
        print(items)
else:
    print('There is no file containing "' + filenames + '" in your computer.')
