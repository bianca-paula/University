# name, country_of_origin, price  name unique
import copy
def get_name(coffee):
    return coffee[0]

def get_country_of_origin(coffee):
    return coffee[1]

def get_price(coffee):
    return coffee[2]

def set_name(coffee,name):
    coffee[0]=name

def set_country_of_origin(coffee,country_of_origin):
    coffee[1]=country_of_origin

def set_price(coffee,price):
    coffee[2]=price 

def validate(coffeeList,name):
    for i in coffeeList:
        if str(get_name(i))==str(name):
            return 1
    return 0


def tryfloat(x):
    try:
        float(x)
        return 0
    except ValueError:
        return 1

def create_coffee(name, country_of_origin, price):

    return [name, country_of_origin, price]

def add_coffee(coffeeList,name, country_of_origin, price):
    '''
    Adds a new coffee to the list
    coffeeList=the list of coffees
    name=name of the coffee
    country_of_origin=the country of origin
    price=the price of the coffee
    '''
    c=create_coffee(name, country_of_origin, price)
    coffeeList.append(c)

def filter(coffeeList, country, price):

    copyList=coffeeList.copy()
    coffeeList.clear()
    for i in copyList:
        if str(get_country_of_origin(i))==str(country) and int(get_price(i))<=int(price):
            coffeeList.append(i)
    
def print_country(coffeeList,country):

    for i in coffeeList:
        if str(get_country_of_origin(i))==str(country):
            print(i)
    
def test_add():
    list=[]
    c=create_coffee("Coffee dynasty", "England", 11)
    add_coffee(c, "Coffee dynasty", "England", 11)
    assert get_country_of_origin(c)=='England'
    assert get_name(c)=='Coffee dynasty'
    assert get_price(c)==11


test_add()
