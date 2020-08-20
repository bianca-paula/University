class Driver:
    def __init__(self, did, name):
        self.Id=did
        self.Name=name

    @property
    def Id(self):
        return self._did

    @property
    def Name(self):
        return self._name


    @Id.setter
    def Id(self, value):
        self._did=value

    @Name.setter
    def Name(self, value):
        self._name=value

    def __str__(self):
        return "Id: "+str(self.Id)+", Name: "+str(self.Name)

class Order:
    def __init__(self, did, distance):
        self.DriverId=did
        self.Distance=distance

    @property
    def DriverId(self):
        return self._did
    
    @property
    def Distance(self):
        return self._distance

    @DriverId.setter
    def DriverId(self, value):
        self._did=value

    @Distance.setter
    def Distance(self, value):
        self._distance=value

    def __str__(self):
        return "Id: "+str(self.DriverId)+", Distance: "+str(self.Distance)
