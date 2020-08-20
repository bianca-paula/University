from functions import *

def add_coffee_ui(coffeeList):
    name=input("name= ")
    country_of_origin=input("country= ")
    price=float(input("price= "))
    if tryfloat(price)==1 or int(price)<=0:
        raise ValueError("Invalid data")
    if validate(coffeeList, name)==1:
        raise ValueError("Invalid data")
    c=create_coffee(name, country_of_origin, price)
    coffeeList.append(c)

def printmenu():
    print("-----------------COFFEE MENU MANAGER-----------------")
    print("1. Add a new coffee")
    print("2. Show the coffee list")
    print("3. Print coffees sorted")
    print("4. Filter")
    print("5. Delete")
    print("6. Exit")

def show_coffee(coffeeList):
    for c in coffeeList:
        print("Name  "+str(get_name(c))+", Country= "+str(get_country_of_origin(c))+", Price ="+str(get_price(c)))

def print_sort(coffeeList):
    coffeeList.sort(key=lambda x:x[1])
    show_coffee(coffeeList)
def init_coffee():
    res=[]
    c1=create_coffee("Coffee latte", "Spain", 10)
    res.append(c1)

    c2=create_coffee("Mocha", "Italy", 10)
    res.append(c2)

    c3=create_coffee("Queen", "England", 10)
    res.append(c3)

    c4=create_coffee("Coffee dynasty", "England", 11)
    res.append(c4)

    c5=create_coffee("Alpi", "Romania", 10)
    res.append(c5)
    return res

def filter_ui(coffeeList):
    country=input("country= ")
    price=input("price= ")
    if price==None:
        print_type(coffeeList, country)
    elif country==None:
        for i in coffeeList:
            if float(get_price(i))<=float(price):
                print(i)
    else:
        filter(coffeeList,country,price)

def deletec(coffeeList):
    z=[]
    country=input("Country= ")
    for i in coffeeList:
        if str(get_country_of_origin(i))!=str(country):
            z.append(i)
    show_coffee(z)


def start():
    coffeeList=init_coffee()
    #coffeeList=[]
    while True:
        printmenu()
        choice=input("choice = ")
        if choice=='1':
            try:
                add_coffee_ui(coffeeList)
            except ValueError as ve:
                print(ve)
        elif choice=='2':
            show_coffee(coffeeList)
        elif choice=='3':
            print_sort(coffeeList)
        elif choice=='4':
            filter_ui(coffeeList)
        elif choice=='5':
            deletec(coffeeList)
        elif choice=='6':
            break
        else:
            print("Invalid Command")

start()