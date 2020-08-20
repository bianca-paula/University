from service import *
from domain import *
import copy


class UI:
    def __init__(self, service):
        self._service=service
        self._service.addStudent(Student(111,"Clare",1))
        self._service.addStudent(Student(112,"Julia",1))
        self._service.addStudent(Student(113,"Ada",1))
        self._service.addStudent(Student(114,"Maggie",1))
        self._service.addStudent(Student(115,"Anne",1))
        self._service.addStudent(Student(116,"Paula",2))
        self._service.addStudent(Student(117,"Joy",2))
        self._service.addStudent(Student(118,"Raquel",2))
        self._service.addStudent(Student(119,"Serene",2))
        self._service.addStudent(Student(120,"Mona",2))



    def print_menu(self):
        print("1. Add a new student to the list")
        print("2. Show the list of students")
        print("3. Filter the list of students")
        print("4. Undo")
        print("5. Exit")

    def undo(self):
        try:
            self._service.undo()
        except ValueError as e:
            print(e)
    
    def filter(self):
        group=input('Group=')
        self._service.filter(group)



    def addStudent(self):
        sid=input('Id:')
        sname= input('Name:')
        sgroup=input('Group:')
        try:
            self._service.addStudent(Student(sid,sname,sgroup))
        except ValueError as e:
            print(e)

    
    def showStudent(self):
        '''
        Prints the list of students
        '''
        for i in self._service._students:
            print("Id: "+str(i.Id)+" Name: "+ str(i.Name) +"  Group: "+ str (i.Group))
            
    
    def invalid(self):
        print("Invalid command")

    def start(self):
        while True:
            self.print_menu()
            choice=input("choice: ")
            if choice=='1':
                self.addStudent()
            elif choice=='2':
                self.showStudent()
            elif choice=='3':
                self.filter()
            elif choice=='4':
                self.undo()
            elif choice=='5':
                break 
            else:
                self.invalid()


s=Service()
ui=UI(s)
ui.start()
