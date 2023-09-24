# D-Flat

Welcome to D-Flat! D-Flat is planned to be an interpreted programming language. Currently in
production. Outlined below are the intentions for how the language will be designed.

## Example Syntax

D-Flat syntax takes consideration from C++, Javascript, and Python. In this section, I will
go over some example scenarios that D-Flat will (eventually) cover.

### Declaring Variables

Simple variables have the following structure: `<name_of_variable>: <type> => <value_to_assign>`
Some of the basic types are outlined below:

```
int_var: int => 3
float_var: float => 3.2
string_var: str => "Hello, World!"
```

For more complex types like a list, you can declare it in a similar way:

```
list_str_var: list[str] => ("Hello", "World")
list_int_var: list[int] => (3, 42, 12)
```

In either case, you can describe the process as so:
`int_var is an integer type assigned by this variable.`
To see how the assignment works, see the [Declaring a Class](#declaring-a-class) section.

### Declaring a Class

For variable assignment, all variable types should be treated as a class. A class has a
constructor, which takes in a set of parameters to set the class. The structure is as follows:

```df
MyClass: Class => {
    construct: () => {}
}
```

Member functions are by default private. The constructor must be private. If you want to set
member variables or pass in variables to the constructor, it can look like:

```df
construct: (name: str, age: int) => {
    member name => name
    member age => age
}
```

The code above takes in two parameters with the constructor and assigns them to their respective
member variables within the constructed class. Member variables are also private by default.

### Member Functions in a Class

Here is the following way you can declare a public member function in a class:

```df
MyClass: Class => {
    construct: () => {}

    public print_name: (name: str) => {
        print => "Hello, " + name + "!"
    }

    public get_greeting: (name: str) -> str => {
        print => "Hello, " + name + "!"
    }
}
```

Function declarations have the following structure: 

```df
<func_name>: (<inputs>) -> <type> => {
    return <type>
}
```

The parens indicate a function declaration. Types inside of the parens are inputs the
function needs in order to execute. The arrow operator `->` shows what type the function returns.
The assignment operator `=>` binds the declared type to its implementation or declaration.

Calling the function works as follows:

```df
<func_name> => <inputs>

// or if multiple inputs

<func_name> => (<inputs>)
```

## List of Tokens

| Token Name | Syntax |
| --- | --- |
| OPERATOR_PLUS     | +
| OPERATOR_MINUS    | -
| OPERATOR_MULTIPLY | *
| OPERATOR_DIVIDE   | /
| OPERATOR_ASSIGN   | =>
| OPERATOR_TYPE     | :
| OPEN_PAREN        | (
| CLOSE_PAREN       | )
| OPEN_BRACKET      | {
| CLOSE_BRACKET     | }
| IDENTIFIER        | <characters that don't start with a number>