import datetime

def get_current_day():
    #Function returns the current day of the month
    date = datetime.date.today()
    return date.day

def get_amount(l,d,nr):
    return l[d][nr][0]

def get_type(l,d,nr):
    return l[d][nr][1]

def set_amount(l,d,nr,val):
    l[d][nr][0] = val

def set_type(l,d,nr,val):
    l[d][nr][1] = val

def add_expense(l, d, am, t):
    '''
    Adds a new expense to the list
    Params:
    l- list of days
    d- the day
    am- the amount of the expense
    t- the type of the expense
    '''
    l[int(d)-1].append([am,t])

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

def new_month():
    '''
    Initializes a new month
    Params:

    Output: returns a list with 30 elements which are empty
    '''
    l = []
    for i in range (30):
        l.append([])
    return l

def init_month(m):
    '''
    Initialize a new month with data
    '''
    add_expense(m,25,100,"food")
    add_expense(m,25,10,"housekeeping")
    add_expense(m,5,80,"food")
    add_expense(m,10,7,"housekeeping")

    add_expense(m,20,90,"others")
    add_expense(m,7,10,"transport")
    add_expense(m,5,70,"clothing")
    add_expense(m,11,20,"housekeeping")

    add_expense(m,2,100,"food")
    add_expense(m,6,12,"food")
    add_expense(m,18,30,"internet")
    add_expense(m,11,29,"others")


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

def removeday(l, d):
        '''
    Removes all expenses from a day
    Params:
    l- list of day
    d - the number of the day
    Output: the list of days without the expenses from that day
    '''
        l[int(d)-1] = []

def remove_d1_to_d2(l, d1, d2):
    '''
    Removes all expenses between two days
    Params:
    l- list of day
    d1 - the number of the first day
    d2 - the number of the second day
    '''
    for i in range(int(d1), int(d2)-1):
        l[i] = []

def remove_type(l,t):
            '''
    Removes all expenses with a specific type
    Params:
    l- list of day
    t- the type of the expense
    '''
            for i in range (len(l)):
                z = []
                for j in range (len(l[i])):
                    if(get_type(l,i,j) != t):
                        z.append(l[i][j])
                l[i] = z


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
        found_all=False
        for i in range (len(l)):
            found=False;
            for j in range (len(l[i])):
                if(get_type(l,i,j) == t):
                    if(get_amount(l,i,j) > int(val)):
                        if(found_all == False):
                            found_all = True
                        if(found == False):
                            print("Day " + str(i+1) + " ")
                            found = True
                            print( "  " + str(j+1) + ") Amount: " +  str(get_amount(l,i,j))  + ", Type: " + str(get_type(l,i,j)))
        if(found_all == False):
            print("Such values have not been found.")

def list_value2(l,t,val):
    '''
    Lists all the expenses which are < than a given value
    Params:
    l- list of days
    t- the type of the expense
    val- the value the amount is compared with
    '''
    found_all=False
    for i in range (len(l)):
        found=False;
        for j in range (len(l[i])):
            if(get_type(l,i,j) == t):
                if(get_amount(l,i,j) < int(val)):
                    if(found_all == False):
                        found_all = True
                    if(found == False):
                        print("Day " + str(i+1) + " ")
                        found = True
                        print( "  " + str(j+1) + ") Amount: " +  str(get_amount(l,i,j))  + ", Type: " + str(get_type(l,i,j)))
    if(found_all == False):
        print("Such values have not been found.")

def list_value3(l,t,val):
    '''
    Lists all the expenses which are equal to a given value
    Params:
    l- list of days
    t- the type of the expense
    val- the value the amount is compared with
    '''
    found_all=False
    for i in range (len(l)):
        found=False;
        for j in range (len(l[i])):
            if(get_type(l,i,j) == t):
                if(get_amount(l,i,j) == int(val)):
                    if(found_all == False):
                        found_all = True
                    if(found == False):
                        print("Day " + str(i+1) + " ")
                        found = True
                        print( "  " + str(j+1) + ") Amount: " +  str(get_amount(l,i,j))  + ", Type: " + str(get_type(l,i,j)))
    if(found_all == False):
        print("Such values have not been found.")

def start():
    m = new_month()
    init_month(m)
    l=[]


    while True:
        cmd = readCommand()
        command = cmd[0]
        params = cmd[1]
        '''
        if command != 'exit' and len(params)==0:
            list_month(m)
            continue
        '''
        to=["to"]
        types=["housekeeping", "food", "transport", "clothing", "internet", "others"]
        days=["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"]
        s=["<","=",">"]
        if command == 'add':
            add_expense(m, get_current_day(), params[0], params[1])
        elif command=='insert':
            add_expense(m, params[0], params[1], params[2])
        elif command=='remove':
            if params[1] in to:
                remove_d1_to_d2(m, params[0],params[2])
            elif params[0] in types:
                remove_type(m,params[0])
            elif params[0] in days:
                removeday(m, params[0])
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
        elif command == 'exit':
            break 
        else:
            print("Invalid command")

start()