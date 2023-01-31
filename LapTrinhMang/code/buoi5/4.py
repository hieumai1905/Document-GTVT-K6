# attach file to mail
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase

sender = "Hieu mai <hieumai1905it@gmail.com>"
receiver = "Mai Hieu<maivanhieu19052002@gmail.com>"
subject = "attach file"

# them header
message = MIMEMultipart()
message["From"] = sender
message["To"] = receiver
message["Subject"] = subject

# them body
body = "This is content of mail."
message.attach(MIMEText(body, "plain"))

# them file
filename = "main.py"
attachment = open(filename, "rb")
p = MIMEBase("application", "octet-stream")
p.set_payload(attachment.read())


encoders.encode_base64(p)

p.add_header("Content-Disposition", f"attachment; filename={filename}")
message.attach(p)

with smtplib.SMTP("smtp.mailtrap.io", 2525) as server:
    server.login("266002a2cab401", "baaf2d2f1d92fc")
    server.sendmail(sender, receiver, message)