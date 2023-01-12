import requests.utils
from bs4 import BeautifulSoup

if __name__ == '__main__':
    headers = requests.utils.default_headers()
    # utils.default_headers dùng để tạo ra một dictionary chứa các header mặc định của một request
    url = 'http://example.com'
    req = requests.get(url, headers)
    # req = requests.get(url, headers) tương đương với req = requests.get(url)
    # vì headers mặc định của requests.get là utils.default_headers vậy nên không cần phải truyền vào headers có giá trị mặc định
    s = BeautifulSoup(req.content, 'html.parser')
    print(s.prettify())
