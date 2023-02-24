import requests

url = "https://accounts.google.com/o/oauth2/token"

# gửi data lên server để lấy access_token và thong qua refresh_token
data = {
    "client_id": "145704322774-86gqecstgvilqcd95ed5qf58qece8br5.apps.googleusercontent.com",
    "client_secret": "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",
    "refresh_token": "1//0gXqTnGPFP0DNCgYIARAAGBASNwF-L9IrsSF4cUcU16l3zq6oFhfpvmEAqOMpaD8eGQVezMcRhcg-DrPk3UPen1ugqfPE6g7zAZQ",
    "grant_type": "refresh_token"
}

# gửi request lên server
response = requests.post(url, data=data)
print(response.status_code)
print(response.text)
