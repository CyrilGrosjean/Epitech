from sys import argv, stderr
import math

def create_matrix_key(length):
    """Create a square matrix key"""
    global matrix
    global arguments

    index = 0
    matrix.append([])
    for i in arguments[1]:
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

def check_arguments():
    """Function to check all arguments"""
    global arguments

    if len(argv) == 2:
        if argv[1] in "-h":
            print("USAGE\n\t./103cipher message key flag")
            print("\nDESCRIPTION\n\tmessage\ta message, made of ASCII characters")
            print("\tkey\tthe encryption key, made of ASCII characters")
            print("\tflag\t0 for the message to be encrypted, 1 to be decrypted")
            exit(0)
        else:
            stderr.write("Invalid argument, please type './103cipher -h' for help.\n")
            exit(84)
    if len(argv) == 4:
        try:
            arguments.append(str(argv[1]))
            arguments.append(str(argv[2]))
            arguments.append(int(argv[3]))
        except:
            stderr.write("Invalid argument, please type './103cipher -h' for help.\n")
            exit(84)
    else:
        stderr.write("Invalid argument, please type './103cipher -h' for help.\n")
        exit(84)

def calculate_int(matrix_key, matrix_message, x, y):
    """Calculates the integer of the matrix index"""
    nb = 0
    line = 0

    for i in matrix_message[y]:
        nb += int(matrix_key[line][x]) * int(i)
        line += 1
    return (nb)

def encrypt(matrix_key, matrix_message, length):
    """Function to create a new matrix with encrypted message and return str"""
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

# Decrypt functions

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

def decrypt(matrix_key, matrix_message, length):
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
    return (round(nb))

arguments = []
matrix = []

check_arguments()
if arguments[2] != 0 and arguments[2] != 1:
    stderr.write("Invalid argument, please type './103cipher -h' for help.\n")
    exit(84)

message = arguments[0]

len_code = len(arguments[1])
len_matrix = math.sqrt(len_code)
len_matrix = math.ceil(len_matrix)
del len_code
create_matrix_key(len_matrix)

if arguments[2] == 0: # Encrypt
    message_ascii = []
    matrix_message = [[]]
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
    print("Key matrix:")
    for i in matrix:
        text = ""
        text = "\t".join(i)
        print(text)
    encrypt_message = encrypt(matrix, matrix_message, len_matrix)
    print("\nEncrypted message:")
    print(encrypt_message)

else: # Décrypt
    message_split = message.split(" ")
    matrix_message = [[]]
    index = 0
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

    for y in range(0, len(matrix)):
        for x in range(0, len(matrix[y])):
            matrix[y][x] = int(matrix[y][x])
    matrix = get_matrix_invert(matrix)
    print("Key matrix:")
    matrix_printed = []
    for y in range(0, len(matrix)):
        matrix_printed.append([])
        for x in range(0, len(matrix[y])):
            if matrix[y][x] == -0.0:
                matrix[y][x] = 0.0
                matrix_printed[y].append(str(0.0))
            else:
                matrix_printed[y].append(str("%.3f" % matrix[y][x]))
    for i in matrix_printed:
        text = ""
        text = "\t".join(i)
        print(text)
    del matrix_printed
    text = decrypt(matrix, matrix_message, len_matrix)
    print("\nDecrypted message:")
    print(text)