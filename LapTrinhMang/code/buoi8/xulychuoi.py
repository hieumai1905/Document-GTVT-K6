s = 'mai van    hieu,  toi    khong    ieT    sHo   . và  ,ngay sau'


def format_string_phay(s):
    s = s.strip()
    list = s.split(' ')
    res = ''
    for i in list:
        if len(i) != 0:
            res += i + ' '
    print(res)
    return res


def format_string_cham(s):
    list = s.split(',')
    res = ''
    for i in list:
        res += format_string_phay(i) + ', '
    return res


def format_string(s):
    s = s.strip()
    list = s.split('.')
    res = ''
    for i in list:
        res += format_string_cham(i) + '. '

    return res


formatted_string = format_string(s)
print(formatted_string)
