import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

sender = "Hieu mai <hieumai1905it@gmail.com>"
receiver = "Mai Hieu<maivanhieu19052002@gmail.com>"
subject = "Test mail"

# them header
message = MIMEMultipart()
message["From"] = sender
message["To"] = receiver
message["Subject"] = subject

# them body
body = """\
        Hello, this is a test email"""
html = """\
        <html>
            <body>
                <p>My name is Hieu</p>
                <a href = "https://www.facebook.com">Click me</a>
            </body>
        </html>"""

# Body(Có thể gửi cả text hoặc html)
ms1 = MIMEText(body, "plain")
ms2 = MIMEText(html, "html")
message.attach(ms1)
message.attach(ms2)

with smtplib.SMTP("smtp.mailtrap.io", 2525) as server:
    server.ehlo()
    server.starttls()
    server.ehlo()
    server.login("266002a2cab401", "baaf2d2f1d92fc")
    server.sendmail(sender, receiver, message.as_string())
