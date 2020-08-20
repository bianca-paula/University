class Student:
    def __init__(self,sid,sname,sgroup):
        self.Id=sid
        self.Name=sname 
        self.Group=sgroup

    @property
    def Id(self):
        return self._sid

    @property
    def Name(self):
        return self._sname

    @property
    def Group(self):
        return self._sgroup

    @Id.setter
    def Id(self, value):
         self._sid=value

    @Name.setter
    def Name(self, value):
         self._sname=value

    @Group.setter
    def Group(self, value):
         self._sgroup=value

    def __str__(self):
        return "Id: " + str(self.Id) + ', Name: ' + str(self.Name) + ", Group:" + str(self.Group)

    def __repr__(self):
        return "Id: " + str(self.Id) + ', Name: ' + str(self.Name) + ", Group:" + str(self.Group)






