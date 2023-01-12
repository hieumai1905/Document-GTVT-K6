from bs4 import BeautifulSoup
import requests

if __name__ == '__main__':
    response = requests.get(
        'https://tuoitre.vn/lao-to-chuc-le-don-trong-the-thu-tuong-pham-minh-chinh-20230111104027294.htm')
    soup = BeautifulSoup(response.content, 'html.parser') # cos tác dung parse html của bài viết đó
    print(soup)
    print(soup.prettify) # prettify là một attribute của BeautifulSoup nó sẽ trả về một string
    # soup.prettify khác soup.prettify() vì soup.prettify() là một method của BeautifulSoup còn soup.prettify là một attribute của BeautifulSoup

# chương trình này có tác dụng lấy dữ liệu từ trang web và in ra màn hình dưới dạng html sau đó BeautifulSoup sẽ parse html đó và trả về một đối tượng soup
# đối tượng soup này có thể được sử dụng để truy xuất các thành phần trong html
# ví dụ: soup.title, soup.p, soup.a, soup.find_all('a'), soup.find_all('a', href=True), soup.find_all('a', href=True)[0], soup.find_all('a', href=True)[0].get('href'), soup.find_all('a', href=True)[0].get('href').split('/')[-1]