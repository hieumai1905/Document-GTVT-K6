import requests

response = requests.get('https://tuoitre.vn/lao-to-chuc-le-don-trong-the-thu-tuong-pham-minh-chinh-20230111104027294.htm')
print(response) # <Response [200]>

# The response object has a text attribute that contains the content of the response in unicode:
print(response.text) # <!DOCTYPE html>...

# The response object also has a content attribute that contains the content of the response in bytes:
print(response.content) # b'<!DOCTYPE html>...'