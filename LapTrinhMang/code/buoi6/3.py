import ftplib

ftp = ftplib.FTP('127.0.0.1')
ftp.login('hieu201200123', '')

ftp.encoding = 'utf-8'

filename = 'index.txt'

with open('index.txt', 'rb') as f:
    ftp.storbinary('STOR ' + filename, f)

data = []
ftp.dir(data.append)
ftp.quit()
for i in data:
    print(i)
