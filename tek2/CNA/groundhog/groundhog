#!/usr/bin/env python3

import sys
import math

liste = []
stop = False
previous_average = None
actual_average = None
total_changes = 0

def calculate_average(liste, period):
    average = 0.0

    for i in liste:
        average += i
    average /= period
    return average

def get_difference_increase_temperature(liste, period):
    temperature_list = []
    liste_copy = liste.copy()

    while len(liste_copy) > period + 1:
        del liste_copy[0]
    if len(liste_copy) < period + 1:
        return None

    for i in range(1, len(liste_copy)):
        if liste_copy[i] - liste_copy[i - 1] >= 0:
            temperature_list.append(round(liste_copy[i] - liste_copy[i - 1], 2))
    return round(calculate_average(temperature_list, period), 2)

def calculate_standard_deviation(liste, period):
    liste_copy = liste.copy()

    while len(liste_copy) > period:
        del liste_copy[0]
    average = calculate_average(liste_copy, period)
    for i in range(0, len(liste_copy)):
        liste_copy[i] -= average
    result = 0.0
    for i in liste_copy:
        result += i ** 2
    result /= len(liste_copy)
    result = math.sqrt(result)

    return round(result, 2)

def calculate_percentage(liste, period):
    global actual_average
    global previous_average

    liste_copy = liste.copy()

    if len(liste_copy) < period + 1:
        return None
    while len(liste_copy) > period + 1:
        del liste_copy[0]

    try:
        result = liste_copy[-1] / liste_copy[0]
    except:
        actual_average = True
        previous_average = True
        return 9999.0
    result *= 100.0
    result -= 100.0

    if result > 0:
        actual_average = True
    else:
        actual_average = False

    return round(result)

def calc(period, liste):
    global previous_average
    global actual_average
    global total_changes

    percentage = calculate_percentage(liste, period)
    ret_average = False

    if previous_average != actual_average:
        if previous_average == None:
            previous_average = actual_average
        else:
            previous_average = actual_average
            ret_average = True
            total_changes += 1

    if period <= len(liste):
        return [get_difference_increase_temperature(liste, period), percentage, calculate_standard_deviation(liste, period), ret_average]
    return [None, None, None, False]

def get_values(period, stop, liste):

    while not stop:
        try:
            val = input()
        except:
            sys.stderr.write("no stop found\n")
            exit(84)
        if val == "STOP":
            stop = True
            continue
        else:
            try:
                value = float(val)
            except:
                sys.stderr.write("index must be float value\n")
                exit(84)
            liste.append(value)
            returned_calc = calc(period, liste)
            resultPercentage = "nan"
            if returned_calc[1] == 9999.0:
                resultPercentage = "+Inf"
            elif returned_calc[1] != None:
                resultPercentage = f'{returned_calc[1]:.0f}'
            print("g=%s\tr=%s%%\ts=%s%s" % (f'{returned_calc[0]:.2f}' if returned_calc[0] != None else "nan", resultPercentage, f'{returned_calc[2]:.2f}' if returned_calc[2] != None else "nan", "\ta switch occurs" if returned_calc[3] else ""))
    if len(liste) >= period:
        print("Global tendency switched %i times" % (total_changes))
        print("5 weirdest values are %s" % (liste[-5:]))
        exit(0)
    else:
        sys.stderr.write("Not enough values\n")
        exit(84)

if len(sys.argv) == 2:
    if sys.argv[1] == "-h":
        print("SYNOPSIS")
        print("\t./groundhog period\n")
        print("DESCRIPTION")
        print("\tperiod\tthe number of days defining a period")
        exit(0)
    else:
        try:
            period = int(sys.argv[1])
        except:
            sys.stderr.write("period must be an integer value\n")
            exit(84)
        if period < 0:
            sys.stderr.write("Value can't be less than 0\n")
            exit(84)
        get_values(period, stop, liste)
        exit(0)
else:
    sys.stderr.write("Not enough arguments. Please type ./groundhog -h\n")
    exit(84)