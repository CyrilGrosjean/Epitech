import math

def cesar_encryption(text, dec):
    new_text = ""

    for i in text:
        if (ord(i) >= 65 and ord(i) <= 90):
            if (ord(i) + dec > 90):
                new_text += chr(ord(i) + dec - 90 + 65)
            else:
                new_text += chr(ord(i) + dec)
        elif (ord(i) >= 97 and ord(i) <= 122):
            if (ord(i) + dec > 122):
                new_text += chr(ord(i) + dec - 122 + 97)
            else:
                new_text += chr(ord(i) + dec)
        else:
            new_text += i
    return (new_text)

def progressive_cesar_encryption(text, dec):
    new_text = ""
    init_dec = dec
    change = 0

    for i in text:
        if (ord(i) >= 65 and ord(i) <= 90):
            if ord(i) + dec > 90:
                change = ord(i) + dec
                while change > 90:
                    change -= 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) + dec)
            dec += init_dec
        elif (ord(i) >= 97 and ord(i) <= 122):
            if ord(i) + dec > 122:
                change = ord(i) + dec
                while change > 122:
                    change -= 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) + dec)
            dec += init_dec
        else:
            new_text += i
    return (new_text)

def vigenere_encryption(text, key):
    new_text = ""
    nb = len(key)
    index = 0
    change = 0
    key_list = []

    for k in key:
        key_list.append(k)
    for i in text:
        if index == nb:
            index = 0
        if (ord(i) >= 65 and ord(i) <= 90):
            if ord(i) + ord(key_list[index]) > 90:
                change = ord(i) + ord(key_list[index])
                while (change > 90):
                    change -= 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) + ord(key_list[index]))
            index += 1
        elif (ord(i) >= 97 and ord(i) <= 122):
            if ord(i) + ord(key_list[index]) > 122:
                change = ord(i) + ord(key_list[index])
                while (change > 122):
                    change -= 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) + ord(key_list[index]))
            index += 1
        else:
            new_text += i
    return (new_text)

def rail_fence_encryption(text, lines):
    rail_list = []
    index = 0

    for i in range(0, lines):
        rail_list.append([])

    for i in text:
        if index == lines:
            index = 0
        rail_list[index].append(i)
        index += 1
    unique_list = []
    for i in rail_list:
        unique_list.append("".join(i))
    new_text = "".join(unique_list)
    return (new_text)

# Cipher encryption functions

def create_key_matrix(arguments):
    """Create a square matrix key"""
    matrix = []
    index = 0
    length = math.ceil(math.sqrt(len(arguments)))

    matrix.append([])
    for i in arguments:
        if len(matrix[index]) == length:
            matrix.append([])
            index += 1
        matrix[index].append(str(ord(i)))
    if len(matrix[index]) != length:
        while len(matrix[index]) != length:
            matrix[index].append(str(0))
    if len(matrix) != length:
        while len(matrix) != length:
            matrix.append([])
            index += 1
            for i in range(0, length):
                matrix[index].append(str(0))
    return matrix

def calculate_int(matrix_key, matrix_message, x, y):
    """Calculates the integer of the matrix index"""
    nb = 0
    line = 0

    for i in matrix_message[y]:
        nb += int(matrix_key[line][x]) * int(i)
        line += 1
    return (nb)

def cipher_encryption(matrix_key, message):
    """Function to create a new matrix with encrypted message and return str"""
    message_split = message.split(" ")
    len_matrix = len(matrix_key)
    matrix_message = [[]]
    message_ascii = []
    index = 0
    for i in message:
        message_ascii.append(str(ord(i)))
    del message
    for i in range(0, len(message_ascii)):
        if i % len_matrix == 0 and i != 0:
            index += 1
            matrix_message.append([])
        matrix_message[index].append(message_ascii[i])
    if len(matrix_message[index]) != len_matrix:
        while len(matrix_message[index]) != len_matrix:
            matrix_message[index].append(str(0))
    del message_ascii
    del index

    new_matrix = []
    index = -1
    x = 0

    for line in matrix_message:
        new_matrix.append([])
        index += 1
        x = 0
        for i in line:
            new_matrix[index].append(str(calculate_int(matrix_key, matrix_message, x, index)))
            x += 1
    my_list = []
    for i in new_matrix:
        my_list.append(" ".join(i))
    text = " ".join(my_list)
    return (text)

# Uncrypting functions

def cesar_uncryption(text, dec):
    new_text = ""

    for i in text:
        if (ord(i) >= 65 and ord(i) <= 90):
            if (ord(i) - dec < 65):
                new_text += chr(ord(i) - dec + 25)
            else:
                new_text += chr(ord(i) - dec)
        elif (ord(i) >= 97 and ord(i) <= 122):
            if (ord(i) - dec < 97):
                new_text += chr(ord(i) - dec + 25)
            else:
                new_text += chr(ord(i) - dec)
        else:
            new_text += i
    return (new_text)

def progressive_cesar_uncryption(text, dec):
    new_text = ""
    init_dec = dec
    change = 0

    for i in text:
        if (ord(i) >= 65 and ord(i) <= 90):
            if ord(i) - dec < 65:
                change = ord(i) - dec
                while change < 65:
                    change += 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) - dec)
            dec += init_dec
        elif (ord(i) >= 97 and ord(i) <= 122):
            if ord(i) - dec < 97:
                change = ord(i) - dec
                while change < 97:
                    change += 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) - dec)
            dec += init_dec
        else:
            new_text += i
    return (new_text)

def vigenere_uncryption(text, key):
    new_text = ""
    nb = len(key)
    index = 0
    change = 0
    key_list = []

    for k in key:
        key_list.append(k)
    for i in text:
        if index == nb:
            index = 0
        if (ord(i) >= 65 and ord(i) <= 90):
            if ord(i) - ord(key_list[index]) < 65:
                change = ord(i) - ord(key_list[index])
                while (change < 65):
                    change += 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) - ord(key_list[index]))
            index += 1
        elif (ord(i) >= 97 and ord(i) <= 122):
            if ord(i) - ord(key_list[index]) < 97:
                change = ord(i) - ord(key_list[index])
                while (change < 97):
                    change += 25
                new_text += chr(change)
            else:
                new_text += chr(ord(i) - ord(key_list[index]))
            index += 1
        else:
            new_text += i
    return (new_text)

def rail_fence_uncryption(text, lines):
    rail_list = []
    index = 0
    count = 0
    length = len(text) / 2
    new_text = ""

    for i in range(0, lines):
        rail_list.append([])

    for i in text:
        if count == length:
            index += 1
        rail_list[index].append(i)
        count += 1

    count = 0
    while (count < length):
        try:
            new_text += str(rail_list[0][count])
            new_text += str(rail_list[1][count])
        except:
            pass
        count += 1
    return new_text

# Uncrypting Cipher

def matrix_transposition(matrix):
    return list(map(list,zip(*matrix)))

def get_minor(matrix, i, j):
    return [row[:j] + row[j + 1:] for row in (matrix[:i] + matrix[i + 1:])]

def matrix_determinant(matrix):
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    determinant = 0
    for c in range(len(matrix)):
        determinant += ((-1) ** c) * matrix[0][c] * matrix_determinant(get_minor(matrix, 0, c))
    return determinant

def get_matrix_invert(matrix):
    for y in range(0, len(matrix)):
        for x in range(0, len(matrix[y])):
            matrix[y][x] = int(matrix[y][x])
    determinant = matrix_determinant(matrix)
    if len(matrix) == 2:
        return [[matrix[1][1] / determinant, -1 * matrix[0][1] / determinant],
                [-1*matrix[1][0] / determinant, matrix[0][0] / determinant]]
    cofactors = []
    for r in range(len(matrix)):
        cofactorRow = []
        for c in range(len(matrix)):
            minor = get_minor(matrix, r, c)
            cofactorRow.append(((-1) ** (r + c)) * matrix_determinant(minor))
        cofactors.append(cofactorRow)
    cofactors = matrix_transposition(cofactors)
    for r in range(len(cofactors)):
        for c in range(len(cofactors)):
            cofactors[r][c] = cofactors[r][c] / determinant
    return cofactors

def cipher_uncryption(matrix_key, message):
    message_split = message.split(" ")
    matrix_message = [[]]
    index = 0
    len_matrix = len(matrix_key)

    for i in range(0, len(message_split)):
        if i % len_matrix == 0 and i != 0:
            index += 1
            matrix_message.append([])
        matrix_message[index].append(message_split[i])
    if len(matrix_message[index]) != len_matrix:
        while len(matrix_message[index]) != len_matrix:
            matrix_message[index].append(str(0))
    del message_split
    del index

    new_matrix = []
    index = -1
    x = 0

    for line in matrix_message:
        new_matrix.append([])
        index += 1
        x = 0
        for i in line:
            new_matrix[index].append(chr(calculate_float(matrix_key, matrix_message, x, index)))
            x += 1
    my_list = []
    while (ord(new_matrix[-1][-1]) == 0):
        del new_matrix[-1][-1]
    for i in new_matrix:
        my_list.append("".join(i))
    text = "".join(my_list)
    return (text)

def calculate_float(matrix_key, matrix_message, x, y):
    """Calculates the integer of the matrix index"""
    nb = 0
    line = 0

    for i in matrix_message[y]:
        nb += float(matrix_key[line][x]) * int(i)
        line += 1
    if (nb < 32  or nb > 127):
        nb = 0
    return (round(nb))