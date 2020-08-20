#from domain import *
from functions import *


def list_month(l):
    '''
    Lists all the expenses from a month
    Params:
        l- list of days
    Output: all the expenses from that month
    '''
    for i in range (len(l)):
        print("Day " + str(i+1) + " ")
        for j in range (len(l[i])):
            print( "  " + str(j+1) + ") Amount: " +  str(get_amount(l,i,j))  + ", Type: " + str(get_type(l,i,j)))

def list_type(l,t):
    '''
    Lists all the expenses from a month with a specific type
    Params:
    l- list of days
    t- the type of the expense
    Output: the list of expenses from the month having that type
    '''

    
    for i in range (len(l)):
        found = False
        for j in range (len(l[i])):
            if(get_type(l,i,j) == t):
                if(found == False):
                    print("Day " + str(i+1) + " ")
                    found = True
                print( "  " + str(j+1) + ") Amount: " + str(get_amount(l,i,j)))

def list_value1(l,t,val):
        '''
    Lists all the expenses which are > than a given value
    Params:
    l- list of days
    t- the type of the expense
    val- the value the amount is compared with
    '''
        allnums=False
        for i in range (len(l)):
            found=False
            for j in range (len(l[i])):
                if(str(get_type(l,i,j)) == t):
                    if(int(get_amount(l,i,j)) > int(val)):
                        if(allnums == False):
                            allnums = True
                        if(found == False):
                            print("Day " + str(i+1) + " ")
                            found = True
                            print( "  " + str(j+1) + ") Amount: " +  str(get_amount(l,i,j))  + ", Type: " + str(get_type(l,i,j)))
        if(allnums == False):
            print("No values found.")

def list_value2(l,t,val):
    '''
    Lists all the expenses which are < than a given value
    Params:
    l- list of days
    t- the type of the expense
    val- the value the amount is compared with
    '''
    allnums=False
    for i in range (len(l)):
        found=False
        for j in range (len(l[i])):
            if(str(get_type(l,i,j)) == t):
                if(int(get_amount(l,i,j)) < int(val)):
                    if(allnums == False):
                        allnums = True
                    if(found == False):
                        print("Day " + str(i+1) + " ")
                        found = True
                        print( "  " + str(j+1) + ") Amount: " +  str(get_amount(l,i,j))  + ", Type: " + str(get_type(l,i,j)))
    if(allnums == False):
        print("No values found.")

def list_value3(l,t,val):
    '''
    Lists all the expenses which are equal to a given value
    Params:
    l- list of days
    t- the type of the expense
    val- the value the amount is compared with
    '''
    allnums=False
    for i in range (len(l)):
        found=False
        for j in range (len(l[i])):
            if(str(get_type(l,i,j)) == t):
                if(int(get_amount(l,i,j)) == int(val)):
                    if(allnums == False):
                        allnums = True
                    if(found == False):
                        print("Day " + str(i+1) + " ")
                        found = True
                        print( "  " + str(j+1) + ") Amount: " +  str(get_amount(l,i,j))  + ", Type: " + str(get_type(l,i,j)))
    if(allnums == False):
        print("No values found.")

def max_day(l):
    '''
    Determines the day with the maximum expenses
    params:
    l-the list of expenses
    '''
    max=0
    for i in range(len(l)):
        if get_total_amount_day(l,i)>max:
            max = get_total_amount_day(l,i)
    for i in range(len(l)):
            if get_total_amount_day(l,i)==max:
                print('Day '+str(i+1)+' '+str(max))

def sort_day(l):
    '''
 Writes the total daily expenses in ascending order by amount of money spent.
     params:
    l-the list of expenses

    '''
    z=[]
    for i in range(len(l)):
        z.append(get_total_amount_day(l,i))
    z.sort()
    for k in range(len(z)):
        for i in range(len(l)):
            if get_total_amount_day(l,i)==z[k] and z[k]!=0:
                print('Day '+str(i+1)+' '+str(z[k]))

def sort_category(l,t):
    '''
 Writes the daily expenses for category food in ascending order by amount of money
spent.
     params:
    l-the list of expenses


    '''
    z=[]
    for i in range(len(l)):
        for j in range(len(l[i])):
            if get_type(l,i,j)==t:
                z.append(get_amount(l,i,j))
    z.sort()
    for k in range(len(z)):
        for i in range(len(l)):
            for j in range(len(l[i])):
                if get_amount(l,i,j)==z[k] and get_type(l,i,j)==t and z[k]!=0:
                    print('Day'+str(i+1)+' '+str(z[k]))
        

def readCommand():
    cmd = input("command: ")
    idx = cmd.find(" ")
    if idx == -1:
        return (cmd, [])
    command = cmd[:idx]
    params = cmd[idx+1:]
    params = params.split(" ")
    for i in range(len(params)):
        params[i] = params[i].strip()
    return (command, params)


def start():
    m = new_month()
    history = []
    init_month(m,history)
    l=[]
    
    while True:
        cmd = readCommand()
        command = cmd[0]
        params = cmd[1]
        to=["to"]
        types=["housekeeping", "food", "transport", "clothing", "internet", "others"]
        days=["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"]
        s=["<","=",">"]
        if command == 'add':
            try:
                add_expense(m, get_current_day(), params[0], params[1],history) 
            except ValueError as ve:
                print(ve)

        elif command=='insert':
            add_expense(m, params[0], params[1], params[2],history)
        elif command=='remove':
           # if params[1]=='to':
              #  remove_d1_to_d2(m, params[0],params[2])
            if params[0] in types:
                remove_type(m,params[0],history)
            elif params[0] in days:
                if params[1] in to:
                    remove_d1_to_d2(m, params[0],params[2],history)
                else:
                    removeday(m, params[0],history)
        elif command == 'list':
            if params==[]:
                list_month(m)
            elif params[0] in types and len(params)==1:
                list_type(m, params[0])
            elif params[1] in s:
                if params[1]=='>':
                    list_value1(m,params[0], params[2])
                elif params[1]=='<':
                    list_value2(m,params[0], params[2])
                elif params[1]=='=':
                    list_value3(m,params[0], params[2])
        elif command=='sum':
            print(sum_category(m,params[0]))
        elif command=='filter':
            if params[0] in types and len(params)==1:
                filter_type(m, params[0],history)
            elif params[1]=='<':
                filter_typesmaller(m, params[0], params[2],history)
            elif params[1]=='>':
                filter_typegreater(m, params[0], params[2],history)
            elif params[1]=='=':
                filter_typeequal(m, params[0], params[2],history) 
        elif command=='sort':
            if params[0]=='day':
                sort_day(m)
            elif params[0] in types:
                sort_category(m,params[0])
        elif command=='max':
            if params[0]=='day':
                max_day(m)
        elif command=='undo':
            undo(m,history)
        elif command == 'exit':
            break 
        else:
            print("Invalid command")

start()