from domain import *

class DService:
    def __init__(self, repository):
        self.repository=repository

    def store(self, object):
        self.repository.store(object)

    def show(self):
       return self.repository.getAll()

class OService:
    def __init__(self, repository):
        self.repository=repository

    def store(self, object):
        self.repository.store(object)

    def income(self, driverId):
        self.repository.income(driverId)

    def show(self):
       return self.repository.getAll()