'''
By: Frank Vanris
Date: 10/1/2024
Desc: Creating a testing environment that will be used to test out given features that will be implemented into the main code.
'''
# test_math_functions.py
import unittest

# Simple test environment (use this when testing out new features for the server)
class TestStringMethods(unittest.TestCase):

    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()


    

