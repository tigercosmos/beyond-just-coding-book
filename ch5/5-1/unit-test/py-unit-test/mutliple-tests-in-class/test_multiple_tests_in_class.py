class TestSimpleClass:
    def test_one(self):
        x = "this"
        assert "h" in x

    def test_two(self):
        x = "hello"
        assert len(x) == 5


import unittest


# 沒有 unittest.TestCase 的話，pytest不會執行
class StringMethodTestClass(unittest.TestCase):
    def test_upper(self):
        self.assertEqual("foo".upper(), "FOO")

    def test_isupper(self):
        self.assertTrue("FOO".isupper())
        self.assertFalse("Foo".isupper())

    def test_split(self):
        s = "hello world"
        self.assertEqual(s.split(), ["hello", "world"])

        with self.assertRaises(TypeError):
            s.split(2)  # split 函式不接受 int 作為參數
