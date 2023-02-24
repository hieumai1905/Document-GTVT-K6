# su dung fpt lib de doc file
import ftplib

ftp = ftplib.FTP('127.0.0.1')
ftp.login('hieu201200123', '')
ftp.cwd('url')
data = []
ftp.dir(data.append)
ftp.quit()
for i in data:
    print(i)

