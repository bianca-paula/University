from service import *
from textrepository import *

class UI:
    def __init__(self, DService,OService):
        self._DService=DService
        self._OService=OService

    def show(self):
        print("--------------DRIVERS------------")
        for p in DService.show():
            print(p)

    def show1(self):
        print("--------------ORDERS-------------")
        for p in OService.show():
            print(p)

    def income(self,driverId):
        for p in DService.show():
            if driverId==p.Id:
                print("Driver's Id: "+str(p.Id)+", Driver's Name: "+str(p.Name))
        self._OService.income(driverId)

    def store(self, orderid, orderd):
        '''
Adds a new order in the repository
params: orderid=the driver's id
orderd=the distance of the order

Raises ValueError if the id of the driver is not found, and in the repository if the distance is less than 1
        '''
        z=[]
        order=Order(orderid, orderd)
        for p in DService.show():
            z.append(p.Id)

        if p not in z:
            raise ValueError("No id found")

        self._OService.store(order)
    
    def readCommand(self):
        cmd=input("command: ")
        idx=cmd.find(" ")
        if idx==-1:
            return (cmd, [])

        command=cmd[:idx]
        params=cmd[idx+1:]

        params=params.split(" ")

        for i in range(len(params)):
            params[i]=params[i].strip()

        return(command, params)

    def start(self):
        print("-------------------------------TAXI COMPANY------------------------------")
        while True:
            cmd=self.readCommand()
            command=cmd[0]
            params=cmd[1]

            if command=='drivers':
                self.show()
            elif command=='orders':
                self.show1()
            elif command=='income':
                self.income(params[0])
            elif command=='add':
                try:
                    self.store(params[0], params[1])
                except ValueError as e:
                    print(e)

            elif command=='exit':
                break

            else:
                print("Invalid command, please enter a valid one")


Repo1=DTextRepository("D:/FACULTATE/An 1 Sem 1/testCheranBiancaPaula/drivers.txt")
DService=DService(Repo1)

Repo2=OTextRepository("D:/FACULTATE/An 1 Sem 1/testCheranBiancaPaula/orders.txt")
OService=OService(Repo2)

ui=UI(DService,OService)
ui.start()

