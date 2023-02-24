import smtplib

sender = "Hieu mai <hieumai1905it@gmail.com>"
receiver = "Mai Hieu<maivanhieu19052002@gmail.com>"

message = f"""\
Subject: Hi Mailtrap
To: {receiver}
From: {sender}
This is content."""

with smtplib.SMTP("smtp.mailtrap.io", 2525) as server:
    server.login("266002a2cab401", "baaf2d2f1d92fc")
    server.sendmail(sender, receiver, message)
