import requests
from bs4 import BeautifulSoup

if __name__ == '__main__':
    url = 'https://tuoitre.vn/'
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    # print(soup.prettify())

    # lay link cua bai viet
    tags = soup.findAll('h3', class_='box-title-text')
    # print(tags)
    # soup.findAll() trả về một list các đối tượng có class là box-title-text dưới dạng html sau đó chúng ta sẽ lấy link của các bài viết trong list đó
    # print('the first: ' + str(type(tags[0])))

    links = [link.find('a').attrs['href'] for link in tags]
    # link.find('a') dùng để tìm tất cả các thẻ <a> trong link
    # attrs dùng để lấy ra các thuộc tính của thẻ <a>. Ví dụ: lấy title, href, src, ... của thẻ <a> trong link. attrs trả về một dictionary
    # link.find('a').attrs['href'] dùng để lấy giá trị của thuộc tính href trong thẻ <a>
    # print(links[0])

    # lay du lieu chi tiet cua tung bai viet trong links
    for link in links:
        news = requests.get(url + link)  # url + link để lấy đường dẫn đầy đủ của bài viết và truy cập vào bài viết đó

        soup = BeautifulSoup(news.content, 'html.parser')  # dùng để parse html của bài viết đó

        try:
            title = soup.find('h1', class_='article-title').text  # dùng để lấy tiêu đề của bài viết
            print(title)
        except:
            print(link + ' has no title')
            pass # dùng để bỏ qua lỗi

        
