def divide(a, b):
    result = a / b
    return result

def main():
    print("Welcome to the divide program")

    num1 = 10
    num2 = 0

    try:
        result = divide(num1, num2)
        print(f"The result is: {result}")
    except ZeroDivisionError:
        print("Error: Cannot divide by zero")

if __name__ == "__main__":
    main()