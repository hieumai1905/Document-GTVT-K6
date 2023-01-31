# Sử dụng các lớp trong module email
# gui mail tu hieumai1905it@gmail.com den maivanhieu19052002@gmail.com text plain

import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

sender = "Hieu mai <hieumai1905it@gmail.com>"
receiver = "Mai Hieu<maivanhieu19052002@gmail.com>"
subject = "Test mail"
body = "This is content of mail."

# them header
message = MIMEMultipart()
message["From"] = sender
message["To"] = receiver
message["Subject"] = subject

# them body
message.attach(MIMEText(body, "plain"))

with smtplib.SMTP("smtp.mailtrap.io", 2525) as server:
    server.ehlo()
    server.starttls()
    server.ehlo()
    server.login("266002a2cab401", "baaf2d2f1d92fc")
    server.sendmail(sender, receiver, message.as_string())
