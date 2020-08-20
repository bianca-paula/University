from domain import *
import copy 

class Service:
    def __init__(self):
        self._students=[]
        self._newList=[]
        self._history=[]
    
    def validate_id(self,student):
        '''
        Validates the id of a student
        params: student-the student whose id is checked
        Raises ValueError if the id is not unique 
        '''
        for s in self._students:
            if int(s.Id)==int(student.Id):
                raise ValueError("This id is already assigned to a student!")
                return 1
        return 0

    def validate_group(self,student):
        '''
        Validates the group of a student
        params: student-the student whose group is checked
        Raises ValueError if the group number is less than 0
        '''
        if int(student.Group)<0:
            raise ValueError("The group number must be a positive one!")
            return 1
        return 0

    def addStudent(self, student):
        '''
        Adds a new student to the list of students
        params: student-the student that will be added
        Raises ValueError if the user does not provide the necessary parameters
        '''
        self._history.append(copy.deepcopy(self._students))
        if len(str(student.Id))==0 or len(str(student.Name))==0 or len(str(student.Group))==0:
            raise ValueError("Please enter the specified parameters")
        if self.validate_id(student)==0 and self.validate_group(student)==0:
            self._students.append(student)

    def undo(self):
        '''
        Undoes the last operation that modified program data
        Raises ValueError if there are no more undoes that can be made
        '''
        if len(self._history)==0:
            raise ValueError("No more undos!")

        self._students.clear()
        self._students.extend(self._history.pop())

    def filter(self,group):
        '''
        Filters the list so that students in a given group are deleted from the list
        params: group=the given group 
        '''
        backup=copy.deepcopy(self._students)
        self._history.append(backup)

        self._students.clear()
        for i in backup:
            if int(i.Group) != int(group):
                self._students.append(i)


def test_addStudent():
    student1=Student(125, 'Sophie',2)
    s=Service()
    s.addStudent(student1)
    assert student1.Id==125 and student1.Name=='Sophie' and student1.Group==2

test_addStudent()
            
