import requests.utils
from bs4 import BeautifulSoup

if __name__ == '__main__':
    headers = requests.utils.default_headers()
    url = 'http://example.com'
    req = requests.get(url, headers)
    s = BeautifulSoup(req.content, 'html.parser')
    print(s.prettify())
