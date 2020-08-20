import datetime
import copy
def get_current_day():
    #Function returns the current day of the month
    date = datetime.date.today()
    return date.day
def get_amount(l,d,nr):
    return l[int(d)][nr][0]
def get_type(l,d,nr):
    return l[d][nr][1]
def get_total_amount_day(l,d):
    s=0
    for j in range(len(l[int(d)])):
        s=s+int(get_amount(l,d,j))
    return s 
def new_month():
    '''
    Initializes a new month
    '''
    l = []
    for i in range (30):
        l.append([])
    return l
def init_month(m,history):
    add_expense(m,25,100,"food",history)
    add_expense(m,5,80,"food",history)
    add_expense(m,10,7,"housekeeping",history)

    add_expense(m,20,90,"others",history)
    add_expense(m,7,10,"transport",history)
    add_expense(m,5,70,"clothing",history)
    add_expense(m,11,20,"housekeeping",history)

    add_expense(m,2,100,"food",history)
    add_expense(m,6,12,"food",history)
    add_expense(m,18,30,"internet",history)
    add_expense(m,11,29,"others",history)


def add_expense(l, d, am, t, history):
    history.append(copy.deepcopy(l))
    correct=["housekeeping", "food", "transport", "clothing", "internet", "others"]
    if t not in correct or d in correct:
        raise ValueError("Invalid input data!")
    if str(am).isdigit()==False:
        raise ValueError("Amount must be a number!")
    l[int(d)-1].append([int(am),t])
    


def removeday(l, d,history):
    history.append(copy.deepcopy(l))
    l[int(d)-1] = []
def remove_d1_to_d2(l, d1, d2,history):
    '''
    Removes all expenses between two days
    Params:
    l- list of day
    d1 - the number of the first day
    d2 - the number of the second day
    '''
    history.append(copy.deepcopy(l))
    for i in range(int(d1), int(d2)-1):
        l[i] = []
def remove_type(l,t,history):
    history.append(copy.deepcopy(l))
    for i in range (len(l)):
        z = []
        for j in range (len(l[i])):
            if(get_type(l,i,j) != t):
                z.append(l[i][j])
        l[i] = z
def sum_category(l,t):
    s=0
    for i in range (len(l)):
        for j in range(len(l[i])):
            if str(get_type(l,i,j))==t:
                s=s+get_amount(l,i,j)
    return s
def filter_type(l,t,history):
    history.append(copy.deepcopy(l))
    for i in range(len(l)):
        for j in range(len(l[i])):
            if str(get_type(l,i,j))!=t:
                remove_type(l, get_type(l,i,j))
def filter_typesmaller(l,t,val,history):
    history.append(copy.deepcopy(l))
    for i in range (len(l)):
        z = []
        for j in range (len(l[i])):
            if str(get_type(l,i,j))==t:
                if int(get_amount(l,i,j))<int(val):
                    z.append(l[i][j])
        l[i] = z
def filter_typegreater(l,t,val,history):
    history.append(copy.deepcopy(l))
    for i in range (len(l)):
        z = []
        for j in range (len(l[i])):
            if str(get_type(l,i,j))==t:
                if int(get_amount(l,i,j))>int(val):
                    z.append(l[i][j])
        l[i] = z
def filter_typeequal(l,t,val,history):
    history.append(copy.deepcopy(l))
    for i in range (len(l)):
        z = []
        for j in range (len(l[i])):
            if str(get_type(l,i,j))==t:
                if int(get_amount(l,i,j))==int(val):
                    z.append(l[i][j])
        l[i] = z


def undo(l, history):
    if len(history) == 0:
        raise ValueError("No more undos!")
    l.clear()
    l.extend(history.pop())



