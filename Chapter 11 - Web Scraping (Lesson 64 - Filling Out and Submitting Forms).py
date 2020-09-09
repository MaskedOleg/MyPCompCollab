Python 3.8.3 (tags/v3.8.3:6f8c832, May 13 2020, 22:37:02) [MSC v.1924 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> from selenium import webdriver
>>> browser = webdriver.Chrome('D:\\Users\\Angelo Michael\\Documents\\#Programming\\Python 3\\chromedriver\\chromedriver.exe')
>>> browser.get('https://login.yahoo.com/')
>>> emailElem = browser.find_element_by_id('login-username')
>>> emailElem.send_keys('zeromegaman74@yahoo.com')
>>> signinElem = browser.find_element_by_id('login-signin')
>>> signinElem.click()
>>> passwordElem = browser.find_element_by_id('login-passwd')
>>> passwordElem.send_keys('O*****e***i**;***e')
>>> signinElem = browser.find_element_by_id('login-signin')
>>> signinElem.click()
>>> 
