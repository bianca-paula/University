from repository import *
from domain import *

class DTextRepository(DRepository):
    def __init__(self, fileName):
        super().__init__()
        self._fileName=fileName
        self._loadFile()

    def store(self, object):
        DRepository.store(self, object) 
        self._saveFile()
    
    def _loadFile(self):
        f=open(self._fileName, 'r')
        l=f.readline().strip()
        while len(l) >0:
            tokens=l.split(',')
            driver=Driver(tokens[0],tokens[1])
            self.store(driver)
            l=f.readline().strip()
        f.close()

    def _saveFile(self):
        f = open(self._fileName, "w")
        try:
            for p in self.getAll():
                pString = str(p.Id) + "," + str(p.Name) +"\n"
                f.write(pString)
            f.close()
        except Exception as e:
            print("An error occured -" + str(e))

class OTextRepository(ORepository):
    def __init__(self, fileName):
        super().__init__()
        self._fileName=fileName
        self._loadFile()

    def store(self, object):
        ORepository.store(self, object) 
        self._saveFile()
    def income(self, driverId):
        ORepository.income(self, driverId)
    def _loadFile(self):
        f=open(self._fileName, 'r')
        l=f.readline().strip()
        while len(l) >0:
            tokens=l.split(',')
            order=Order(tokens[0],tokens[1])
            self.store(order)
            l=f.readline().strip()
        f.close()

    def _saveFile(self):
        f = open(self._fileName, "w")
        try:
            for p in self.getAll():
                pString = str(p.DriverId) + "," + str(p.Distance) +"\n"
                f.write(pString)
            f.close()
        except Exception as e:
            print("An error occured -" + str(e))