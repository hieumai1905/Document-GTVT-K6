from urllib.request import Request
from urllib.request import urlopen
import gzip

if __name__ == '__main__':
    response = urlopen("http://www.google.com")
    # mở một kết nối của 1 url sử dụng urllib
    print('mo ket noi')
    print(response.read())
    print(response.getcode())
    # các thành phần của đối tượng response
    print(response.read())
    print(response.readline())
    print(response.url)
    print(response.status)
    print(response.getheaders())

    # response.getheaders() dung de lay cac header cua response
    print(response.getheader("Content-Type"))

    # them header vao requested
    print('add header')
    request = Request("http://www.google.com")

    # user-agent
    print('user-agent')
    urlopen(request)
    print(request.get_header('User-agent'))
    request.add_header("Accept-Language", "vn")
    response = urlopen(request)
    print(response.read())

    # nén/mã hóa dữ liệu
    print('nén dữ liệu')
    # add_header có tác dụng thêm header vào request, nếu tham số thứ 2 là "gzip" thì nó sẽ nén dữ liệu
    request.add_header("Accept-Encoding", "gzip")
    response = urlopen(request)
    print(response.read())

    # khi nay response se tra ve 1 doi tuong gzip
    print(response.read())

    # giai nen gzip
    print('giai nen gzip')

    # data luu tru du lieu doc duoc
    data = response.read()

    # decompress dung de giai nen du lieu. Du lieu tra ve la 1 doi tuong bytes
    content = gzip.decompress(data)

    print(content)
    # b'' nghĩa là chuỗi rỗng. Vì dữ liệu đã được giải nén rồi. Nên không còn dữ liệu nào để đọc nữa. Nếu muốn đọc thì phải giải nén lại.

    # nen lai content. Du lieu tra ve la 1 doi tuong bytes
    data = gzip.compress(content)
    # compress dùng dể nén dữ liệu. Dữ liệu trả về là 1 đối tượng bytes
    print(data)
    # splitlines() : tách chuỗi thành các chuỗi con và trả về một danh sách các chuỗi con đó. Các phần tử con là từng dòng trong đối tượng ban đầu.
    print(content.splitlines()[:5])
