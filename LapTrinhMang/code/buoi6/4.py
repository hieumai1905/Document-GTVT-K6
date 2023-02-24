# download file
import ftplib

ftp = ftplib.FTP('127.0.0.1')
ftp.login('hieu201200123', '')

# download file index.txt
filename = 'index.txt'
with open(filename, 'wb') as f:
    ftp.retrbinary('RETR ' + filename, f.write)

ftp.quit()

# sau khi download file index.txt, ta se thay file index.txt duoc tao ra trong thu muc chua file 4.py tuc la file 4.py va file index.txt cung thuoc cung 1 thu muc