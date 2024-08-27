def my_function(x,y):
    if x == y: print("Equal")
    else: print("Not equal")

def another_function(a):
    b = [1, 2, 3, 4, 5] # noqa: F841
    if a: return True
    else: return False
