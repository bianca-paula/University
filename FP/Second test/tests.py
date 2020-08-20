from repository import *
import unittest
class OrderTest(unittest.TestCase):
    def test_store(self):
        Repo=ORepository()
        o=Order(1,10)
        Repo.store(o)
        self.assertEqual(o.DriverId,1)
        self.assertEqual(o.Distance,10)