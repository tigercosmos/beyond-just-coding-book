from calculator import add, subtract, multiply, divide


def generate_report(data):
    report = []
    for a, b in data:
        report.append(
            {
                "a": a,
                "b": b,
                "add": add(a, b),
                "subtract": subtract(a, b),
                "multiply": multiply(a, b),
                "divide": divide(a, b),
            }
        )
    return report
