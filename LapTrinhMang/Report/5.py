import requests

url = "https://accounts.google.com/o/oauth2/token"

# gửi data lên server để lấy access_token và refresh_token
data = {
    "client_id": "145704322774-86gqecstgvilqcd95ed5qf58qece8br5.apps.googleusercontent.com",
    "client_secret": "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",
    "redirect_uri": "urn:ietf:wg:oauth:2.0:oob",
    "grant_type": "authorization_code",
    "code": "4/1AWtgzh7n4v1yN5hzWaGr-rnMclEXT5ERVKVQazKj-v1OkSAospg_Bzd_Tt4"
}

# gửi request lên server
response = requests.post(url, data=data)
print(response.status_code)
print(response.text)