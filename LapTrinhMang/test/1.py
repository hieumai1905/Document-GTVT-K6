import ftplib

ftp = ftplib.FTP('127.0.0.1')
ftp.login('hieu201200123', '')

ftp.encoding = 'utf-8'

filename = '1.py'

with open('3.py', 'rb') as f:
    ftp.storbinary('STOR ' + filename, f)