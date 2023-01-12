import requests
from bs4 import BeautifulSoup

if __name__ == '__main__':
    url = 'https://forecast.weather.gov/MapClick.php?lat=36.693760000000054&lon=-121.62482999999997#.Y79Q_HbP2Ht'
    headers = requests.utils.default_headers()
    response = requests.get(url, headers)
    soup = BeautifulSoup(response.content, 'html.parser')

    # lay tat ca anh cua trang website
    images = soup.find_all('img')
    print('Total images: ', len(images))

    for image in images:
        print(image['src'])
