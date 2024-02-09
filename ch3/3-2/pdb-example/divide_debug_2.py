import pdb

def divide(a, b):
    # We will set the breakpoint here later in PDB
    result = a / b
    return result

def main():
    print("Welcome to the divide program")

    print("Setting 1st breakpoint")
    pdb.set_trace()  # breakpoint

    num1 = 10
    num2 = 0

    print("Setting 2nd breakpoint")
    pdb.set_trace()  # breakpoint

    try:
        result = divide(num1, num2)
        print(f"The result is: {result}")
    except ZeroDivisionError:
        print("Error: Cannot divide by zero")

if __name__ == "__main__":
    main()