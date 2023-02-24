import requests

url = "https://www.googleapis.com/gmail/v1/users/me/messages/"
access_token = "ya29.a0AVvZVsoSxO1hbpr9tPIFnrBKIDpMciU5BYrYlEUP5JGOLWrAgTF5B4-Km4ZTZxlitEDHeeUb7EWhbVbp0p-NPCPym6_ERXZHICDB18R8d_xkXcJTptuXup-kA6CnbRi9FRThK9pzQ9xGQ55h1loBPbhxK_mNv3IaCgYKASQSAQASFQGbdwaIgBjMuIvTJYVb5LF9vdFNHQ0166"

headers = {"Authorization": f"Bearer {access_token}"}

response = requests.get(url, headers=headers)
print(response.status_code)
print(response.text)
