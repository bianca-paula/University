from domain import *

class DRepository:
    def __init__(self):
        self._objects=[]

    def store(self, object):
        self._objects.append(object)

    def getAll(self):
        return self._objects

    
class ORepository:
    def __init__(self):
        self._objects=[]

    def store(self, object):
        '''
Adds a new order in the repository
params: orderid=the driver's id
orderd=the distance of the order

Raises ValueError if the id of the driver is not found, and in the repository if the distance is less than 1
        '''
        if int(object.Distance)<=1:
            raise ValueError("Distance too small")
        self._objects.append(object)
    def income(self, driverId):
        z=[]
        distance=0
        income=0
        for i in self.getAll():
            if i.DriverId==driverId:
                z.append(i)
        for d in z:
            distance=float(distance)+float(d.Distance)
            income=float(2.5)*float(distance)

        print(str(income)+" RON")


    def getAll(self):
        return self._objects