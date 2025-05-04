---
layout: post
title: "An Introduction to Python Type Hints"
date: 2025-05-04 20:15:00 +0200
categories: blog
---

The Python programming language is ever-evolving. In recent times some very useful additions have been made that allow for static type analysis, which is undoubtedly welcomed by C++, Java, and Rust programmers alike. In this post I want to give you an introduction to Python type hints and mypy, along with an overview of some more advanced features like generics.

## A Simple Example

Let's say we want to write a function that returns the square of a number, then call it on some numbers. Without type hints this would look something like this:
```py
def sq(x):
    return x * x

a = sq(5)
b = sq(a)
print(b)
```
Now let's add some types. The function has to have a type for its parameter `x`, as well as a return type. Both of these are `int` here. The variables `a` and `b` both have type `int` as well. We use the following syntax for this:
```py
def sq(x: int) -> int:
    return x * x

a: int = sq(5)
b: int = sq(a)
print(b)
```
Now these type hints can already be very useful by themselves, but they can be even more powerful when used with a static analysis tool like [mypy](https://mypy.readthedocs.io/en/stable/index.html). This way possible type errors can be found without ever having to run the code. If we run mypy on the code above, we get the message
```
Success: no issues found in 1 source file
```
That's what we like to hear! There is a catch, however. When running mypy on the code without type hints, it shows the same message. That's because the types of `sq` are interpreted by mypy to be ``dynamic'', meaning the types will only be known at runtime and should not be checked. So mypy only checks code that has type hints!

Now let's introduce an error to see what happens. If we change the type of `a` to `float`, we get the following message:
```
program.py:5: error: Argument 1 to "sq" has incompatible type "float"; expected "int"  [arg-type]
Found 1 error in 1 file (checked 1 source file)
```
So mypy picked up the problem, pretty nifty! We could also try to assign a float to `a` after it is assigned an int:
```py
def sq(x: int) -> int:
    return x * x

a: int = sq(5)
a = 5.0
b: int = sq(a)
print(b)
```
This will cause the following error:
```
tmp.py:5: error: Incompatible types in assignment (expression has type "float", variable has type "int")  [assignment]
Found 1 error in 1 file (checked 1 source file)
```
Pretty useful to know: According to mypy a variable cannot change types, even though this is possible in normal Python.

As the final part of this example I will point out that the type hints for the variables `a` and `b` are not necessary. The following code still gives the same error as above, because the types of `a` and `b` are inferred from the return type of the `sq` function. If we were to remove the explicit return type of the function as well, the error disappears.
```py
def sq(x: int) -> int:
    return x * x

a = sq(5)
a = 5.0
b = sq(a)
print(b)
```
Along with `int` there are the basic types `str`, `float`, `bool`, `None`, and many more. I want specifically highlight `None` here, which is used when a function doesn't return anything. Also useful to know: If you have a default value for a parameter, this goes after the type hint:
```py
def returns_nothing(x: int = 0) -> None:
    print(x)
```

## More complicated types

Along with the basic types like `int`, we may also want a more complicated types like ``a list of ints''. We can do this by putting the `int` type in square brackets as follows:
```py
x: list[int] = [] # In this case mypy cannot infer the type, so we add it explicitly
x.append(5) # OK
x.append(4.0) # Error!
```
Of course we may want our list to contain both ints and floats. To accomplish this we can use a union type. In the latest version of Python a union type is written as two type names with a vertical bar in between:
```py
x: list[int | float] = []
x.append(5) # OK
x.append(4.0) # Also OK
```
Along with lists you also have dictionaries in Python. These can have a key and a value type:
```py
x: dict[str, int] = {}
x["hello"] = 5 # OK
x["world"] = 5.0 # Not OK: Incorrect value type
x[4] = 4 # Not OK: Incorrect key type
```

## Duck Typing

For some functions you may want the parameters to be of a type ``something that can be iterted over'', without specifying wheter the parameter is a list, tuple, set, etc. For this we have so-called duck types: Types that encompass multiple other types that share certain functionalities. Probably the most useful one is `Iterable`, of which I've put an example below. Note that you need to import these special types before using them.
```py
from typing import Iterable

def has_a_one(x: Iterable[int]) -> bool:
    for item in x:
        if item == 1:
            return True
    return False

has_a_one([5, 6, 7]) # OK, because lists are iterable
has_a_one((1, 2)) # OK, because tuples are iterable
has_a_one(4) # Not OK
```
Another useful one is the `Callable` type, which makes it possible to type hint functions that accept other functions as parameters.
```py
from typing import Callable

def lt(a: int, b: int) -> bool:
    return a < b

def invert(f: Callable[[int, int], bool], a: int, b: int) -> bool:
    return not f(a, b)

invert(lt, 4, 5) # OK because lt has correct signature
invert(lambda x, y: x == y, 5, 6) # OK: Lambda function with correct number of parameters
```
There are plenty of other, so I recommend looking around on the web whenever you need something.

## Custom Classes and Generics

When you create a custom class you can type hint that class when passing it to other functions. Type hints of class methods are similar to the type hints of normal functions.
```py
class A:
    def __init__(self, x: int) -> None:
        self.x = x

def f(a: A) -> int:
    return a.x
```
But what if we want to do something like `list` example before, where we have a class that can have items of a specific type? This is where generics come into play. Suppose we have the class above but want the type of `x` to vary from object to object. We can add a generic type after the class name and use it inside the class as if it was a normal type:
```py
class A[T]:
    def __init__(self, x: T) -> None:
        self.x = x # self.x will have type T

a = A(5) # Will get type A[int]
b = A("b") # Will get type A[str]
c = b.x # Will get type str
```
You can also have generic functions, which have the generic type after the function name:
```py
def f[T1, T2](x: T1, y: T2) -> T2:
    print("Value of x:", x)
    return y

a = f(5, "foo") # a has type str
b = f("bar", 3.2) # b has type float
```

## Function Overloads

In a statically typed language like C++ it's possible to have multiple functions with the same, but with different type signatures. Because Python doesn't use the type hints at runtime, it's not possible to give two completely separate implementations, but it is possible to specify different type signatures. For this we use the `overload` decorator, imported from `typing`.

As an example we will define a function that either adds two floats or concatenates two strings. First you define the different signatures that the function accepts, then you specify the actual implementation:
```py
from typing import overload

@overload
def f(x: float, y: float) -> float: ...
@overload
def f(x: str, y: str) -> str: ...
def f(x, y):
    return x + y

x = f("a", "b") # x has type str
y = f(4.0, 5.0) # y has type float
```
If we now wanted to only return the first argument if the arguments are strings, we could use Python's builtin `isinstance` to separate implementations:
```py
from typing import overload

@overload
def f(x: float, y: float) -> float: ...
@overload
def f(x: str, y: str) -> str: ...
def f(x, y):
    if isinstance(x, str):
        return x # For str types
    return x + y # For float types
```

## Conclusion

As a conclusion I will give you one last tip for when things go wrong: You can always use the comment `# type: ignore` to let mypy ignore types at a certain line of code. For example, this will not cause an error:
```py
x = 5
x = 5.0 # type: ignore
```
Now let's just hope you won't need that too often... Either way types can make existing code a lot clearer, so I hope you see this as an oppotunity to start using them!