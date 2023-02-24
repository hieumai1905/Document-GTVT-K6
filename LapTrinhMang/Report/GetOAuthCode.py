# doc file credentials.json
import json

with open("credentials.json") as f:
    token_info = json.load(f)
    for(key, value) in token_info['installed'].items():
        print(key, value)